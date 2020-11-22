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

#include "Operator/CleanerOperator.h"

#include "Factor.h"
#include "FactorUnit.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "Operator/FactorOperator.h"
#include "Operator/ResetOperator.h"

#include <iostream>

const FName NCleanerOperator::Name(TEXT("Cleaner"));
const FName NReducersCleanerOperator::Name(TEXT("Reducers Cleaner"));
const FName NIncreasersCleanerOperator::Name(TEXT("Increasers Cleaner"));
const FName NReducersCleanerPersistentOperator::Name(TEXT("Reducers Persistent Cleaner"));
const FName NIncreasersCleanerPersistentOperator::Name(TEXT("Increasers Persistent Cleaner"));

float NCleanerOperator::Compute(float Lh, float Rh)
{
	mycheck(MyFactor != nullptr);

	// Means no one has been set previously
	if (KeyInFactor <= 0)
	{
		return Lh;
	}

	if (Rh > 0)
	{
		FactorUnitsNumber = FMath::RoundToInt(Rh);
	}

	int32 ActualKey = KeyInFactor - 1;
	float ValueReturned = Lh;

	while (ActualKey >= 0 && (Rh == 0 || FactorUnitsNumber > 0))
	{
		TSharedPtr<NFactorUnitInterface> FactorUnit = MyFactor->GetFactorUnit(ActualKey);
		if (IsShouldClean(FactorUnit))
		{
			ValueReturned = Clean(FactorUnit, ValueReturned);
		}
		--ActualKey;
	}

	return ValueReturned;
}

TSharedPtr<NFactorOperatorInterface> NCleanerOperator::GetInverse()
{
	static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NNullOperator());
	return Operator;
}

void NCleanerOperator::SetKeyInFactor(uint32 Key)
{
	mycheck(MyFactor != nullptr);
	KeyInFactor = Key;
}

bool NCleanerOperator::IsShouldClean(TSharedPtr<NFactorUnitInterface> FactorUnit) const
{
	return FactorUnit->IsActivated();
}

float NCleanerOperator::Clean(TSharedPtr<NFactorUnitInterface> FactorUnit, float Lh)
{
	// Cause the previous operator have already takes effect on this factor computation
	// this reverse its influence:
	Lh = FactorUnit->GetOperator()->GetInverse()->Compute(Lh, FactorUnit->GetFactorUnitValue());
	// Deactivate should stop the event. It will remove it from the Timeline Events queue at the next timeline ticking.
	// The Factor will be notified by the event expiration and remove the FactorUnit accordingly.
	FactorUnit->Activate(false);

	if (FactorUnitsNumber > 0)
	{
		--FactorUnitsNumber;
	}

	return Lh;
}

void NCleanerOperator::SetFactor(NFactorInterface* Factor)
{
	MyFactor = Factor;
}

bool NReducersCleanerOperator::IsShouldClean(TSharedPtr<NFactorUnitInterface> FactorUnit) const
{
	if (!FactorUnit->IsActivated())
	{
		return false;
	}
	float Value = FactorUnit->GetOperator()->Compute(2.f, FactorUnit->GetFactorUnitValue());
	// remove only if the FactorUnit reduce the factor value.
	return Value < 2.f;
}
bool NIncreasersCleanerOperator::IsShouldClean(TSharedPtr<NFactorUnitInterface> FactorUnit) const
{
	if (!FactorUnit->IsActivated())
	{
		return false;
	}
	float Value = FactorUnit->GetOperator()->Compute(2.f, FactorUnit->GetFactorUnitValue());
	// remove only if the FactorUnit increase the factor value.
	return Value > 2.f;
}

float NReducersCleanerPersistentOperator::PersistentCompute(float Lh, float Rh, TSharedPtr<NFactorUnitInterface> ActualUnit)
{
	// The amount of FUs cleared is reached
	if (FactorUnitsNumber == 0)
	{
		return Lh;
	}

	float Value = Lh;
	if (IsShouldClean(ActualUnit))
	{
		Value = Clean(ActualUnit, Lh);
	}
	return Value;
}

float NIncreasersCleanerPersistentOperator::PersistentCompute(float Lh, float Rh, TSharedPtr<NFactorUnitInterface> ActualUnit)
{
	// The amount of FUs cleared is reached
	if (FactorUnitsNumber == 0)
	{
		return Lh;
	}

	float Value = Lh;
	if (IsShouldClean(ActualUnit))
	{
		Value = Clean(ActualUnit, Lh);
	}
	return Value;
}
