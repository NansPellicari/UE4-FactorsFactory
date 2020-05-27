#include "Operator/ResetOperator.h"

#include "Factor.h"
#include "FactorStack.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "Operator/FactorOperator.h"

#include <typeinfo>

const FName NResetOperator::Name(TEXT("Reset"));

IFactorOperator* NResetOperatorBase::NResetOperatorBase::GetInverse()
{
    return new NNullOperator();
}

FString NResetOperatorBase::GetResetIdFlag(INFactorInterface* Factor)
{
    const FString Prefix = TEXT("Reset_list_");
    return FString::Format(TEXT("{0}{1}"), {Prefix, FString::FromInt(Factor->GetUID())});
}

float NResetOperator::Compute(float Lh, float Rh)
{
    uint32 MaxAttempt = 10;
    float NullOperationResult = GetInverse()->Compute(Lh, Rh);
    INFactorInterface* Factor = MyStack->GetFactor(KeyInStack);
    // Means KeyInStack set is invalid
    mycheck(Factor != nullptr);

    INFactorInterface* ResetFactor = Factor;
    while (MaxAttempt > 0 && (!ResetFactor->IsActivated() || OperatorUtils::IsOperatorWithStack(ResetFactor->GetOperator()) ||
                                 MyStack->HasFlag(NResetOperatorBase::GetResetIdFlag(ResetFactor))))
    {
        int32 ResetKey = KeyInStack - (Rh + (10 - MaxAttempt));
        if (ResetKey < 0) return NullOperationResult;
        ResetFactor = MyStack->GetFactor(ResetKey);
        MaxAttempt--;
    }

    if (ResetFactor == Factor)
    {
        return NullOperationResult;
    }

    if (!MyStack->HasFlag(NResetOperatorBase::GetResetIdFlag(ResetFactor)) ||
        !MyStack->GetFlag(NResetOperatorBase::GetResetIdFlag(ResetFactor)))
    {
        MyStack->SetFlag(NResetOperatorBase::GetResetIdFlag(ResetFactor), true);
    }
    return ResetFactor->GetOperator()->GetInverse()->Compute(Lh, ResetFactor->GetFactorValue());
}

IFactorOperator* NResetOperator::GetInverse()
{
    return new NNullOperator();
}

void NResetOperator::SetKeyInStack(uint32 Key)
{
    mycheck(MyStack != nullptr);
    KeyInStack = Key;
}

void NResetOperator::SetStack(NFactorStack* Stack)
{
    MyStack = Stack;
}
