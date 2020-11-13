// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "FactorState.h"

#include "FactorUnit.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "Operator/FactorOperator.h"
#include "Operator/Interfaces.h"

#include <iostream>
#include <typeinfo>

FNFactorStateOperator::FNFactorStateOperator()
{
	Operator = MakeShareable(new NNullOperator());
}
FNFactorStateOperator::FNFactorStateOperator(TSharedPtr<NFactorUnitInterface> _FactorUnit)
{
	FactorUnit = _FactorUnit;
	Value = FactorUnit->GetFactorUnitValue();
	Operator = FactorUnit->GetOperator();
	Reason = FactorUnit->GetReason();
	Activate = FactorUnit->IsActivated();
}

int32 NFactorState::AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit)
{
	return Operators.Add(FNFactorStateOperator(FactorUnit));
}

float NFactorState::GetTime() const
{
	return Time;
}

void NFactorState::SetTime(float _Time)
{
	Time = _Time;
}

void NFactorState::Clear()
{
	Operators.Empty();
	Time = -1.f;
	FactorUnitValue = 0;
}

NFactorStateInterface* NFactorState::Clone()
{
	return new NFactorState(*this);
}

float NFactorState::Compute()
{
	// Reset the value
	FactorUnitValue = 0;
	TMap<int32, TSharedPtr<NFactorUnitInterface>> PersistentUnits;
	// Start at One, the 0 is dedicated for the operation retrieve by the Operators loop
	int32 PersistentIndex = 1;
	for (const FNFactorStateOperator& Operation : Operators)
	{
		if (!Operation.Activate)
		{
			continue;
		}

		PersistentUnits.Add(0, Operation.FactorUnit);

		for (int32 Index = 0; Index < PersistentUnits.Num(); ++Index)
		{
			const TSharedPtr<NFactorUnitInterface> Unit = PersistentUnits[Index];
			float Value = FactorUnitValue;

			if (Index == 0)
			{
				Value = Unit->GetOperator()->Compute(Value, Unit->GetFactorUnitValue());
			}
			else
			{
				NFactorOperatorPersistentInterface* Persistent =
					dynamic_cast<NFactorOperatorPersistentInterface*>(Unit->GetOperator().Get());
				Value = Persistent->PersistentCompute(Value, Unit->GetFactorUnitValue(), PersistentUnits[0]);
			}

			if (bDebug)
			{
				UE_LOG(LogTemp,
					Warning,
					TEXT("Compute with Previous value: %f - Operator: %s - Operation Value: %f - results to: %f"),
					FactorUnitValue,
					*Unit->GetOperator()->GetName().ToString(),
					Unit->GetFactorUnitValue(),
					Value);
			}

			FactorUnitValue = Value;

			NFactorOperatorBreakerInterface* Breaker = dynamic_cast<NFactorOperatorBreakerInterface*>(Unit->GetOperator().Get());
			if (Breaker != nullptr)
			{
				bool bBreak = Breaker->IsBreaking();
				if (bBreak) goto EndOfLoop;
			}
		}

		NFactorOperatorPersistentInterface* Persistent =
			dynamic_cast<NFactorOperatorPersistentInterface*>(Operation.Operator.Get());
		if (Persistent != nullptr)
		{
			PersistentUnits.Add(PersistentIndex++, Operation.FactorUnit);
		}
	}
EndOfLoop:
	PersistentUnits.Empty();
	return FactorUnitValue;
}

const TArray<FNFactorStateOperator> NFactorState::GetOperators() const
{
	return Operators;
}

void NFactorState::Debug(bool _bDebug)
{
	bDebug = _bDebug;
}
