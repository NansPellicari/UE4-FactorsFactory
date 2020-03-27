#include "Difficulty.h"

#include "NansCommon/Public/Misc/NansAssertionMacros.h"
#include "Operator/DifficultyOperator.h"
#include "Operator/Interfaces.h"

void UNDifficulty::Initialize(int32 _DiffValue, IDifficultyOperator* _Operator, float _Duration)
{
    DifficultyValue = _DiffValue;
    Operator = _Operator;
    Duration = _Duration;
}

bool UNDifficulty::IsActivate()
{
    mycheck(Operator != nullptr);
    return Duration == 0 || DurationSinceActivation <= Duration;
}

IDifficultyOperator* UNDifficulty::GetOperator()
{
    mycheck(Operator != nullptr);
    if (!IsActivate())
    {
        return NewObject<UNNullOperator>();
    }
    return Operator;
}

int32 UNDifficulty::GetDifficultyValue()
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