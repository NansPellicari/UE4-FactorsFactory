#include "Difficulty.h"

#include "NansCommon/Public/Misc/NansAssertionMacros.h"
#include "Operator/DifficultyOperator.h"
#include "Operator/Interfaces.h"

UNDifficulty* UNDifficulty::Initialize(float _DiffValue, IDifficultyOperator* _Operator, float _Duration, FName _Reason)
{
    DifficultyValue = _DiffValue;
    Operator = _Operator;
    Duration = _Duration;
    Reason = _Reason;
    return this;
}

FName UNDifficulty::GetReason() const
{
    mycheck(Operator != nullptr);
    return Reason;
}

bool UNDifficulty::IsActivate() const
{
    mycheck(Operator != nullptr);
    return Duration == 0 || DurationSinceActivation <= Duration;
}

IDifficultyOperator* UNDifficulty::GetOperator() const
{
    mycheck(Operator != nullptr);
    if (!IsActivate())
    {
        return NewObject<UNNullOperator>();
    }
    return Operator;
}

float UNDifficulty::GetDifficultyValue() const
{
    mycheck(Operator != nullptr);
    if (!IsActivate())
    {
        return 0;
    }
    return DifficultyValue;
}

void UNDifficulty::AddTime(float Time)
{
    mycheck(Operator != nullptr);
    DurationSinceActivation += Time;
}