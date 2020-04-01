#include "Operator/DifficultyOperator.h"

float NNullOperator::Compute(float Lh, float Rh)
{
    return Lh;
}

IDifficultyOperator* NNullOperator::GetInverse()
{
    return this;
}

float NAddOperator::Compute(float Lh, float Rh)
{
    return Lh + Rh;
}

IDifficultyOperator* NAddOperator::GetInverse()
{
    return new NSubsctractOperator();
}

float NSubsctractOperator::Compute(float Lh, float Rh)
{
    return Lh - Rh;
}

IDifficultyOperator* NSubsctractOperator::GetInverse()
{
    return new NAddOperator();
}

float NMultiplyOperator::Compute(float Lh, float Rh)
{
    return Lh * Rh;
}

IDifficultyOperator* NMultiplyOperator::GetInverse()
{
    return new NDividerOperator();
}

float NDividerOperator::Compute(float Lh, float Rh)
{
    return Lh / Rh;
}

IDifficultyOperator* NDividerOperator::GetInverse()
{
    return new NMultiplyOperator();
}
