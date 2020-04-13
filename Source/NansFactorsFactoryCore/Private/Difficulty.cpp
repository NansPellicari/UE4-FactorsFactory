#include "Difficulty.h"

#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "Operator/DifficultyOperator.h"
#include "Operator/Interfaces.h"

NDifficulty::NDifficulty(float _DiffValue, IDifficultyOperator* _Operator, float _Duration, FName _Reason)
{
    DifficultyValue = _DiffValue;
    Operator = _Operator;
    Duration = _Duration;
    Reason = _Reason;
    Id = ++NDifficultyGUID::sNextId;
}

uint32 NDifficulty::GetUID() const
{
    return Id;
}

FName NDifficulty::GetReason() const
{
    mycheck(Operator != nullptr);
    return Reason;
}

bool NDifficulty::IsActivate() const
{
    mycheck(Operator != nullptr);
    return Duration == 0 || DurationSinceActivation <= Duration;
}

IDifficultyOperator* NDifficulty::GetOperator() const
{
    mycheck(Operator != nullptr);
    if (!IsActivate())
    {
        return new NNullOperator();
    }
    return Operator;
}

float NDifficulty::GetDifficultyValue() const
{
    mycheck(Operator != nullptr);
    if (!IsActivate())
    {
        return 0;
    }
    return DifficultyValue;
}

void NDifficulty::AddTime(float Time)
{
    mycheck(Operator != nullptr);
    DurationSinceActivation += Time;
}
