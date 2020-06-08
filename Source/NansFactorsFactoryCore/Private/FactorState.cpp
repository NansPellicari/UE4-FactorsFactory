#include "FactorState.h"

#include "Factor.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "Operator/FactorOperator.h"
#include "Operator/Interfaces.h"

#include <typeinfo>

FNFactorStateOperator::FNFactorStateOperator()
{
	Operator = MakeShareable(new NNullOperator());
}
FNFactorStateOperator::FNFactorStateOperator(TSharedPtr<NFactorInterface> _Factor)
{
	Factor = _Factor;
	Value = Factor->GetFactorValue();
	Operator = Factor->GetOperator();
	Reason = Factor->GetReason();
	Activate = Factor->IsActivated();
}

void NFactorState::AddFactor(TSharedPtr<NFactorInterface> Factor)
{
	Operators.Add(FNFactorStateOperator(Factor));
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
	FactorValue = 0;
}

NFactorStateInterface* NFactorState::Clone()
{
	return new NFactorState(*this);
}

float NFactorState::Compute()
{
	// Reset the value
	FactorValue = 0;
	for (FNFactorStateOperator Operation : Operators)
	{
		float Value = Operation.Activate ? Operation.Operator->Compute(FactorValue, Operation.Value) : FactorValue;
		if (bDebug)
		{
			UE_LOG(LogTemp,
				Warning,
				TEXT("Compute with Previous value: %f - Operator: %s - Operation Value: %f - results to: %f"),
				FactorValue,
				*Operation.Operator->GetName().ToString(),
				Operation.Value,
				Value);
		}
		FactorValue = Value;
	}
	return FactorValue;
}

const TArray<FNFactorStateOperator> NFactorState::GetOperators() const
{
	return Operators;
}

void NFactorState::Debug(bool _bDebug)
{
	bDebug = _bDebug;
}
