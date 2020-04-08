#pragma once

#include "CoreMinimal.h"
#include "DifficultyStack.h"

class IDifficultyOperator
{
public:
    virtual float Compute(float Lh, float Rh) = 0;
    virtual IDifficultyOperator* GetInverse() = 0;
    virtual const FName GetName() = 0;
    virtual void InIteration(NDifficultyStack* Stack) {}
};

class IDifficultyOperatorWithStack
{
public:
    virtual void SetStack(NDifficultyStack* Stack) = 0;
    virtual void SetKeyInStack(uint32 Key) = 0;
};

class OperatorUtils
{
public:
    template <typename T>
    static bool IsOperatorWithStack(T Operator)
    {
        return dynamic_cast<IDifficultyOperatorWithStack*>(Operator) != nullptr;
    }
};