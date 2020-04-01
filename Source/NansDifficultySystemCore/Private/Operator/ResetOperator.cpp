#include "Operator/ResetOperator.h"

#include "Difficulty.h"
#include "DifficultyStack.h"
#include "NansCommon/Public/Misc/NansAssertionMacros.h"
#include "Operator/DifficultyOperator.h"

#include <typeinfo>

IDifficultyOperator* UNResetOperatorBase::UNResetOperatorBase::GetInverse()
{
    return new NNullOperator();
}

FString UNResetOperatorBase::GetResetIdFlag(INDifficultyInterface* Difficulty)
{
    const FString Prefix = TEXT("Reset_list_");
    return FString::Format(TEXT("{0}{1}"), {Prefix, FString::FromInt(Difficulty->GetUID())});
}

float UNResetOperator::Compute(float Lh, float Rh)
{
    uint32 MaxAttempt = 10;
    float NullOperationResult = GetInverse()->Compute(Lh, Rh);
    INDifficultyInterface* Diff = MyStack->GetDifficulty(KeyInStack);
    // Means KeyInStack set is invalid
    mycheck(Diff != nullptr);

    INDifficultyInterface* ResetDiff = Diff;
    while (MaxAttempt > 0 && (!ResetDiff->IsActivate() || OperatorUtils::IsOperatorWithStack(ResetDiff->GetOperator()) ||
                                 MyStack->HasFlag(UNResetOperatorBase::GetResetIdFlag(ResetDiff))))
    {
        int32 ResetKey = KeyInStack - (Rh + (10 - MaxAttempt));
        if (ResetKey < 0) return NullOperationResult;
        ResetDiff = MyStack->GetDifficulty(ResetKey);
        MaxAttempt--;
    }

    if (ResetDiff == Diff)
    {
        return NullOperationResult;
    }

    if (!MyStack->HasFlag(UNResetOperatorBase::GetResetIdFlag(ResetDiff)) ||
        !MyStack->GetFlag(UNResetOperatorBase::GetResetIdFlag(ResetDiff)))
    {
        MyStack->SetFlag(UNResetOperatorBase::GetResetIdFlag(ResetDiff), true);
    }
    return ResetDiff->GetOperator()->GetInverse()->Compute(Lh, ResetDiff->GetDifficultyValue());
}

IDifficultyOperator* UNResetOperator::GetInverse()
{
    return new NNullOperator();
}

void UNResetOperator::SetKeyInStack(uint32 Key)
{
    mycheck(MyStack != nullptr);
    KeyInStack = Key;
}

void UNResetOperator::SetStack(NDifficultyStack* Stack)
{
    MyStack = Stack;
}