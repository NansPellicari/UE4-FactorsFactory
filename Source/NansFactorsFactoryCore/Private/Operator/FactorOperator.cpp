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

IFactorOperator* NNullOperator::GetInverse()
{
    return this;
}

float NAddOperator::Compute(float Lh, float Rh)
{
    return Lh + Rh;
}

IFactorOperator* NAddOperator::GetInverse()
{
    return new NSubsctractOperator();
}

float NSubsctractOperator::Compute(float Lh, float Rh)
{
    return Lh - Rh;
}

IFactorOperator* NSubsctractOperator::GetInverse()
{
    return new NAddOperator();
}

float NMultiplyOperator::Compute(float Lh, float Rh)
{
    return Lh * Rh;
}

IFactorOperator* NMultiplyOperator::GetInverse()
{
    return new NDividerOperator();
}

float NDividerOperator::Compute(float Lh, float Rh)
{
    return Lh / Rh;
}

IFactorOperator* NDividerOperator::GetInverse()
{
    return new NMultiplyOperator();
}
