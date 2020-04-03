#include "DifficultyState.h"

#include "Difficulty.h"
#include "NansCommon/Public/Misc/NansAssertionMacros.h"
#include "Operator/DifficultyOperator.h"
#include "Operator/Interfaces.h"

#include <typeinfo>

FNDifficultyStateOperator::FNDifficultyStateOperator()
{
    Operator = new NNullOperator();
}
FNDifficultyStateOperator::FNDifficultyStateOperator(const INDifficultyInterface* Difficulty)
{
    Value = Difficulty->GetDifficultyValue();
    Operator = Difficulty->GetOperator();
    Reason = Difficulty->GetReason();
    Activate = Difficulty->IsActivate();
}

NDifficultyState::NDifficultyState(float _Time)
{
    Time = _Time;
}

void NDifficultyState::AddDifficulty(const INDifficultyInterface* Difficulty)
{
    mycheck(Time != -1.f);

    Operators.Add(FNDifficultyStateOperator(Difficulty));
}

float NDifficultyState::GetTime() const
{
    return Time;
}

float NDifficultyState::Compute()
{
    mycheck(Time != -1.f);
    // Reset the value
    DifficultyValue = 0;
    for (FNDifficultyStateOperator Operation : Operators)
    {
        float Value = Operation.Operator->Compute(DifficultyValue, Operation.Value);
        if (bDebug)
        {
            UE_LOG(LogTemp,
                Warning,
                TEXT("Compute with Previous value: %f Operator: %s Operation Value: %f results to: %f"),
                DifficultyValue,
                typeid(Operation.Operator).name(),
                Operation.Value,
                Value);
        }
        DifficultyValue = Value;
    }
    return DifficultyValue;
}

const TArray<FNDifficultyStateOperator> NDifficultyState::GetOperators() const
{
    return Operators;
}
