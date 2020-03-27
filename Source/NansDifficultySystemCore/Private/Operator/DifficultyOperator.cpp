#include "Operator/DifficultyOperator.h"

int32 UNNullOperator::Compute(int32 Lh, int32 Rh)
{
    return Lh;
}

IDifficultyOperator* UNNullOperator::GetInverse()
{
    return this;
}

int32 UNAddOperator::Compute(int32 Lh, int32 Rh)
{
    return Lh + Rh;
}

IDifficultyOperator* UNAddOperator::GetInverse()
{
    return NewObject<UNSubsctractOperator>(this);
}

int32 UNSubsctractOperator::Compute(int32 Lh, int32 Rh)
{
    return Lh - Rh;
}

IDifficultyOperator* UNSubsctractOperator::GetInverse()
{
    return NewObject<UNAddOperator>(this);
}

int32 UNMultiplyOperator::Compute(int32 Lh, int32 Rh)
{
    return Lh * Rh;
}

IDifficultyOperator* UNMultiplyOperator::GetInverse()
{
    return NewObject<UNDividerOperator>(this);
}

int32 UNDividerOperator::Compute(int32 Lh, int32 Rh)
{
    return FMath::DivideAndRoundNearest<int32>(Lh, Rh);
}

IDifficultyOperator* UNDividerOperator::GetInverse()
{
    return NewObject<UNMultiplyOperator>(this);
}