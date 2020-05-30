#include "Operator/FactorOperator.h"

const FName NNullOperator::Name(TEXT("Null"));
const FName NAddOperator::Name(TEXT("Add"));
const FName NSubsctractOperator::Name(TEXT("Subsctract"));
const FName NMultiplyOperator::Name(TEXT("Multiply"));
const FName NDividerOperator::Name(TEXT("Divider"));

float NNullOperator::Compute(float Lh, float Rh)
{
	return Lh;
}

TSharedPtr<FactorOperatorInterface> NNullOperator::GetInverse()
{
	return MakeShareable(this);
}

float NAddOperator::Compute(float Lh, float Rh)
{
	return Lh + Rh;
}

TSharedPtr<FactorOperatorInterface> NAddOperator::GetInverse()
{
	static TSharedPtr<FactorOperatorInterface> Operator = MakeShareable(new NSubsctractOperator());
	return Operator;
}

float NSubsctractOperator::Compute(float Lh, float Rh)
{
	return Lh - Rh;
}

TSharedPtr<FactorOperatorInterface> NSubsctractOperator::GetInverse()
{
	static TSharedPtr<FactorOperatorInterface> Operator = MakeShareable(new NAddOperator());
	return Operator;
}

float NMultiplyOperator::Compute(float Lh, float Rh)
{
	return Lh * Rh;
}

TSharedPtr<FactorOperatorInterface> NMultiplyOperator::GetInverse()
{
	static TSharedPtr<FactorOperatorInterface> Operator = MakeShareable(new NDividerOperator());
	return Operator;
}

float NDividerOperator::Compute(float Lh, float Rh)
{
	return Lh / Rh;
}

TSharedPtr<FactorOperatorInterface> NDividerOperator::GetInverse()
{
	static TSharedPtr<FactorOperatorInterface> Operator = MakeShareable(new NMultiplyOperator());
	return Operator;
}
