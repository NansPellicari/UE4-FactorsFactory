#include "Operator/ResetOperator.h"

#include "Difficulty.h"
#include "DifficultyStack.h"
#include "NansCommon/Public/Misc/NansAssertionMacros.h"
#include "Operator/DifficultyOperator.h"

IDifficultyOperator* UNResetOperatorBase::UNResetOperatorBase::GetInverse()
{
    return NewObject<UNNullOperator>(this);
}

FString UNResetOperatorBase::GetResetIdFlag(UNDifficulty* Difficulty)
{
    const FString Prefix = TEXT("Reset_list_");
    return FString::Format(TEXT("{0}{1}"), {Prefix, FString::FromInt(Difficulty->GetUniqueID())});
}

float UNResetOperator::Compute(float Lh, float Rh)
{
    uint32 MaxAttempt = 10;
    UNDifficulty* Diff = MyStack->GetDifficulty(KeyInStack);
    // Means KeyInStack set is invalid
    mycheck(Diff != nullptr);

    UNDifficulty* ResetDiff = Diff;
    uint32 Id = ResetDiff->GetUniqueID();
    float NullOperationResult = GetInverse()->Compute(Lh, Rh);

    while (MaxAttempt > 0 && (!ResetDiff->IsActivate() || Cast<UNResetOperatorBase>(ResetDiff->GetOperator()) != nullptr ||
                                 MyStack->HasFlag(UNResetOperatorBase::GetResetIdFlag(ResetDiff))))
    {
        uint32 ResetKey = KeyInStack - (Rh + (10 - MaxAttempt));
        if (ResetKey < 0) return NullOperationResult;

        ResetDiff = MyStack->GetDifficulty(ResetKey);
        MaxAttempt--;
    }

    if (ResetDiff == Diff)
    {
        UE_LOG(LogTemp, Warning, TEXT("Can not reset a value"));
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
    return NewObject<UNNullOperator>(this);
}

void UNResetOperator::SetKeyInStack(uint32 Key)
{
    mycheck(MyStack != nullptr);
    KeyInStack = Key;
}

void UNResetOperator::SetStack(UNDifficultyStack* Stack)
{
    MyStack = Stack;
}