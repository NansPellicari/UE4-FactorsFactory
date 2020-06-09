#include "FactorState.h"

#include "FactorUnit.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "Operator/FactorOperator.h"
#include "Operator/Interfaces.h"

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

void NFactorState::AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit)
{
	Operators.Add(FNFactorStateOperator(FactorUnit));
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
	for (FNFactorStateOperator Operation : Operators)
	{
		float Value = Operation.Activate ? Operation.Operator->Compute(FactorUnitValue, Operation.Value) : FactorUnitValue;
		if (bDebug)
		{
			UE_LOG(LogTemp,
				Warning,
				TEXT("Compute with Previous value: %f - Operator: %s - Operation Value: %f - results to: %f"),
				FactorUnitValue,
				*Operation.Operator->GetName().ToString(),
				Operation.Value,
				Value);
		}
		FactorUnitValue = Value;
	}
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
