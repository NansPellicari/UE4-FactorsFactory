#include "DifficultyState.h"

#include "Difficulty.h"
#include "NansCommon/Public/Misc/NansAssertionMacros.h"
#include "Operator/Interfaces.h"
#include "UObject/UObjectBaseUtility.h"

FNDifficultyStateOperator::FNDifficultyStateOperator(const UNDifficulty* Difficulty)
{
    Value = Difficulty->GetDifficultyValue();
    Operator = Difficulty->GetOperator();
    Reason = Difficulty->GetReason();
    Activate = Difficulty->IsActivate();
}

UNDifficultyState* UNDifficultyState::Initialize(float _Time)
{
    Time = _Time;
    return this;
}
void UNDifficultyState::AddDifficulty(const UNDifficulty* Difficulty)
{
    mycheck(Time != -1.f);

    Operators.Add(FNDifficultyStateOperator(Difficulty));
}

float UNDifficultyState::GetTime() const
{
    return Time;
}

float UNDifficultyState::Compute()
{
    mycheck(Time != -1.f);
    for (FNDifficultyStateOperator Operation : Operators)
    {
        float Value = Operation.Operator->Compute(DifficultyValue, Operation.Value);
        if (bDebug)
        {
            UE_LOG(LogTemp,
                Warning,
                TEXT("Compute with Previous value: %f Operator: %s Operation Value: %f results to: %f"),
                DifficultyValue,
                *Cast<UObject>(Operation.Operator)->GetName(),
                Operation.Value,
                Value);
        }
        DifficultyValue = Value;
    }
    return DifficultyValue;
}
