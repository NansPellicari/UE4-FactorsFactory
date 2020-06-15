#include "Operator/ResetOperator.h"

#include "Factor.h"
#include "FactorUnit.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "Operator/FactorOperator.h"

#include <typeinfo>

const FName NResetOperator::Name(TEXT("Reset"));

TSharedPtr<NFactorOperatorInterface> NResetOperatorBase::GetInverse()
{
	static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NNullOperator());
	return Operator;
}

FString NResetOperatorBase::GetResetIdFlag(TSharedPtr<NFactorUnitInterface> FactorUnit)
{
	const FString Prefix = TEXT("Reset_list_");
	return FString::Format(TEXT("{0}{1}"), {Prefix, FactorUnit->GetUID()});
}

float NResetOperator::Compute(float Lh, float Rh)
{
	mycheck(MyFactor != nullptr);
	uint32 MaxAttempt = 10;

	float NullOperationResult = GetInverse()->Compute(Lh, Rh);
	TSharedPtr<NFactorUnitInterface> FactorUnit = MyFactor->GetFactorUnit(KeyInFactor);

	TSharedPtr<NFactorUnitInterface> ResetFactorUnit = FactorUnit;
	while (MaxAttempt > 0 &&
		   (!ResetFactorUnit->IsActivated() || NOperatorUtils::IsOperatorWithFactor(ResetFactorUnit->GetOperator().Get()) ||
			   MyFactor->HasStateFlag(NResetOperatorBase::GetResetIdFlag(ResetFactorUnit))))
	{
		int32 ResetKey = KeyInFactor - (Rh + (10 - MaxAttempt));
		if (ResetKey < 0) return NullOperationResult;
		ResetFactorUnit = MyFactor->GetFactorUnit(ResetKey);
		MaxAttempt--;
	}

	if (ResetFactorUnit == FactorUnit)
	{
		return NullOperationResult;
	}

	if (!MyFactor->HasStateFlag(NResetOperatorBase::GetResetIdFlag(ResetFactorUnit)) ||
		!MyFactor->GetStateFlag(NResetOperatorBase::GetResetIdFlag(ResetFactorUnit)))
	{
		MyFactor->SetStateFlag(NResetOperatorBase::GetResetIdFlag(ResetFactorUnit), true);
	}
	return ResetFactorUnit->GetOperator()->GetInverse()->Compute(Lh, ResetFactorUnit->GetFactorUnitValue());
}

TSharedPtr<NFactorOperatorInterface> NResetOperator::GetInverse()
{
	static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NNullOperator());
	return Operator;
}

void NResetOperator::SetKeyInFactor(uint32 Key)
{
	mycheck(MyFactor != nullptr);
	KeyInFactor = Key;
}

void NResetOperator::SetFactor(NFactorInterface* Factor)
{
	MyFactor = Factor;
}

NResetOperator::~NResetOperator() {}
