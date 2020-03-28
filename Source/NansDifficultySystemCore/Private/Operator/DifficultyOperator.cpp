#include "Operator/DifficultyOperator.h"

float UNNullOperator::Compute(float Lh, float Rh)
{
    return Lh;
}

IDifficultyOperator* UNNullOperator::GetInverse()
{
    return this;
}

float UNAddOperator::Compute(float Lh, float Rh)
{
    return Lh + Rh;
}

IDifficultyOperator* UNAddOperator::GetInverse()
{
    return NewObject<UNSubsctractOperator>(this);
}

float UNSubsctractOperator::Compute(float Lh, float Rh)
{
    return Lh - Rh;
}

IDifficultyOperator* UNSubsctractOperator::GetInverse()
{
    return NewObject<UNAddOperator>(this);
}

float UNMultiplyOperator::Compute(float Lh, float Rh)
{
    return Lh * Rh;
}

IDifficultyOperator* UNMultiplyOperator::GetInverse()
{
    return NewObject<UNDividerOperator>(this);
}

float UNDividerOperator::Compute(float Lh, float Rh)
{
    return Lh / Rh;
}

IDifficultyOperator* UNDividerOperator::GetInverse()
{
    return NewObject<UNMultiplyOperator>(this);
}