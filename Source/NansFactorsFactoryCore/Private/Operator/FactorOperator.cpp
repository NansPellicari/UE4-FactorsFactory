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

TSharedPtr<IFactorOperator> NNullOperator::GetInverse()
{
	return MakeShareable(this);
}

float NAddOperator::Compute(float Lh, float Rh)
{
	return Lh + Rh;
}

TSharedPtr<IFactorOperator> NAddOperator::GetInverse()
{
	static TSharedPtr<IFactorOperator> Operator = MakeShareable(new NSubsctractOperator());
	return Operator;
}

float NSubsctractOperator::Compute(float Lh, float Rh)
{
	return Lh - Rh;
}

TSharedPtr<IFactorOperator> NSubsctractOperator::GetInverse()
{
	static TSharedPtr<IFactorOperator> Operator = MakeShareable(new NAddOperator());
	return Operator;
}

float NMultiplyOperator::Compute(float Lh, float Rh)
{
	return Lh * Rh;
}

TSharedPtr<IFactorOperator> NMultiplyOperator::GetInverse()
{
	static TSharedPtr<IFactorOperator> Operator = MakeShareable(new NDividerOperator());
	return Operator;
}

float NDividerOperator::Compute(float Lh, float Rh)
{
	return Lh / Rh;
}

TSharedPtr<IFactorOperator> NDividerOperator::GetInverse()
{
	static TSharedPtr<IFactorOperator> Operator = MakeShareable(new NMultiplyOperator());
	return Operator;
}
