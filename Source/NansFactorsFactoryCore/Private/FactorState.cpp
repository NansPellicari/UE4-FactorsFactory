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
	TArray<TSharedPtr<NFactorUnitInterface>> PersistentUnit;
	for (const FNFactorStateOperator& Operation : Operators)
	{
		TArray<TSharedPtr<NFactorUnitInterface>> ActualUnit;

		if (Operation.Activate)
		{
			ActualUnit.Add(Operation.FactorUnit);
			ActualUnit += PersistentUnit;
		}

		for (int32 Index = 0; Index < ActualUnit.Num(); ++Index)
		{
			const TSharedPtr<NFactorUnitInterface> Unit = ActualUnit[Index];
			float Value = FactorUnitValue;

			if (Index == 0)
			{
				Value = Unit->GetOperator()->Compute(Value, Unit->GetFactorUnitValue());
			}
			else
			{
				NFactorOperatorPersistentInterface* Persistent =
					dynamic_cast<NFactorOperatorPersistentInterface*>(Unit->GetOperator().Get());
				Value = Persistent->Compute(Value, Unit->GetFactorUnitValue(), *ActualUnit[0].Get());
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
		}

		NFactorOperatorPersistentInterface* Persistent =
			dynamic_cast<NFactorOperatorPersistentInterface*>(Operation.Operator.Get());
		if (Operation.Activate && Persistent != nullptr)
		{
			PersistentUnit.Add(Operation.FactorUnit);
		}

		ActualUnit.Empty();
	}
	PersistentUnit.Empty();
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
