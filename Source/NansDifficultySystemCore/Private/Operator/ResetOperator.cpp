#include "Operator/ResetOperator.h"

#include "Difficulty.h"
#include "DifficultyStack.h"
#include "NansCommon/Public/Misc/NansAssertionMacros.h"
#include "Operator/DifficultyOperator.h"

#include <typeinfo>

const FName NResetOperator::Name(TEXT("Reset"));

IDifficultyOperator* NResetOperatorBase::NResetOperatorBase::GetInverse()
{
    return new NNullOperator();
}

FString NResetOperatorBase::GetResetIdFlag(INDifficultyInterface* Difficulty)
{
    const FString Prefix = TEXT("Reset_list_");
    return FString::Format(TEXT("{0}{1}"), {Prefix, FString::FromInt(Difficulty->GetUID())});
}

float NResetOperator::Compute(float Lh, float Rh)
{
    uint32 MaxAttempt = 10;
    float NullOperationResult = GetInverse()->Compute(Lh, Rh);
    INDifficultyInterface* Diff = MyStack->GetDifficulty(KeyInStack);
    // Means KeyInStack set is invalid
    mycheck(Diff != nullptr);

    INDifficultyInterface* ResetDiff = Diff;
    while (MaxAttempt > 0 && (!ResetDiff->IsActivate() || OperatorUtils::IsOperatorWithStack(ResetDiff->GetOperator()) ||
                                 MyStack->HasFlag(NResetOperatorBase::GetResetIdFlag(ResetDiff))))
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

    if (!MyStack->HasFlag(NResetOperatorBase::GetResetIdFlag(ResetDiff)) ||
        !MyStack->GetFlag(NResetOperatorBase::GetResetIdFlag(ResetDiff)))
    {
        MyStack->SetFlag(NResetOperatorBase::GetResetIdFlag(ResetDiff), true);
    }
    return ResetDiff->GetOperator()->GetInverse()->Compute(Lh, ResetDiff->GetDifficultyValue());
}

IDifficultyOperator* NResetOperator::GetInverse()
{
    return new NNullOperator();
}

void NResetOperator::SetKeyInStack(uint32 Key)
{
    mycheck(MyStack != nullptr);
    KeyInStack = Key;
}

void NResetOperator::SetStack(NDifficultyStack* Stack)
{
    MyStack = Stack;
}