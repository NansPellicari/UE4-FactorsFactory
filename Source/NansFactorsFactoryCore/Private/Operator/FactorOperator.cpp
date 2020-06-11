#include "Operator/FactorOperator.h"

const FName NNullOperator::Name(TEXT("Null"));
const FName NAddOperator::Name(TEXT("Add"));
const FName NSubtractOperator::Name(TEXT("Subsctract"));
const FName NMultiplyOperator::Name(TEXT("Multiply"));
const FName NDividerOperator::Name(TEXT("Divider"));

float NNullOperator::Compute(float Lh, float Rh)
{
	return Lh;
}

TSharedPtr<NFactorOperatorInterface> NNullOperator::GetInverse()
{
	static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NNullOperator());
	return Operator;
}

float NAddOperator::Compute(float Lh, float Rh)
{
	return Lh + Rh;
}

TSharedPtr<NFactorOperatorInterface> NAddOperator::GetInverse()
{
	static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NSubtractOperator());
	return Operator;
}

float NSubtractOperator::Compute(float Lh, float Rh)
{
	return Lh - Rh;
}

TSharedPtr<NFactorOperatorInterface> NSubtractOperator::GetInverse()
{
	static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NAddOperator());
	return Operator;
}

float NMultiplyOperator::Compute(float Lh, float Rh)
{
	return Lh * Rh;
}

TSharedPtr<NFactorOperatorInterface> NMultiplyOperator::GetInverse()
{
	static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NDividerOperator());
	return Operator;
}

float NDividerOperator::Compute(float Lh, float Rh)
{
	return Lh / Rh;
}

TSharedPtr<NFactorOperatorInterface> NDividerOperator::GetInverse()
{
	static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NMultiplyOperator());
	return Operator;
}
