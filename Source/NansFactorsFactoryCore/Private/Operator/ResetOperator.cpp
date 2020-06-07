#include "Operator/ResetOperator.h"

#include "Factor.h"
#include "FactorStack.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "Operator/FactorOperator.h"

#include <typeinfo>

const FName NResetOperator::Name(TEXT("Reset"));

TSharedPtr<FactorOperatorInterface> NResetOperatorBase::GetInverse()
{
	static TSharedPtr<FactorOperatorInterface> Operator = MakeShareable(new NNullOperator());
	return Operator;
}

FString NResetOperatorBase::GetResetIdFlag(TSharedRef<NFactorInterface> Factor)
{
	const FString Prefix = TEXT("Reset_list_");
	return FString::Format(TEXT("{0}{1}"), {Prefix, Factor->GetUID()});
}

float NResetOperator::Compute(float Lh, float Rh)
{
	mycheck(MyStack != nullptr);
	uint32 MaxAttempt = 10;

	float NullOperationResult = GetInverse()->Compute(Lh, Rh);
	TSharedRef<NFactorInterface> Factor = MyStack->GetFactor(KeyInStack);

	TSharedRef<NFactorInterface> ResetFactor = Factor;
	while (MaxAttempt > 0 && (!ResetFactor->IsActivated() || OperatorUtils::IsOperatorWithStack(ResetFactor->GetOperator().Get()) ||
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

TSharedPtr<FactorOperatorInterface> NResetOperator::GetInverse()
{
	static TSharedPtr<FactorOperatorInterface> Operator = MakeShareable(new NNullOperator());
	return Operator;
}

void NResetOperator::SetKeyInStack(uint32 Key)
{
	mycheck(MyStack != nullptr);
	KeyInStack = Key;
}

void NResetOperator::SetStack(NFactorStackInterface* Stack)
{
	MyStack = Stack;
}

NResetOperator::~NResetOperator() {}
