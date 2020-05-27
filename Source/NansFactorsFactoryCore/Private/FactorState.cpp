#include "FactorState.h"

#include "Factor.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "Operator/FactorOperator.h"
#include "Operator/Interfaces.h"

#include <typeinfo>

FNFactorStateOperator::FNFactorStateOperator()
{
    Operator = new NNullOperator();
}
FNFactorStateOperator::FNFactorStateOperator(const INFactorInterface* Factor)
{
    Value = Factor->GetFactorValue();
    Operator = Factor->GetOperator();
    Reason = Factor->GetReason();
    Activate = Factor->IsActivate();
}

NFactorState::NFactorState(float _Time)
{
    Time = _Time;
}

void NFactorState::AddFactor(const INFactorInterface* Factor)
{
    mycheck(Time != -1.f);

    Operators.Add(FNFactorStateOperator(Factor));
}

float NFactorState::GetTime() const
{
    return Time;
}

float NFactorState::Compute()
{
    mycheck(Time != -1.f);
    // Reset the value
    FactorValue = 0;
    for (FNFactorStateOperator Operation : Operators)
    {
        float Value = Operation.Operator->Compute(FactorValue, Operation.Value);
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
