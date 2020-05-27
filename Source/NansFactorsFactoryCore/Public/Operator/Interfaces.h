#pragma once

#include "CoreMinimal.h"
#include "FactorStack.h"

class IFactorOperator
{
public:
    virtual float Compute(float Lh, float Rh) = 0;
    virtual IFactorOperator* GetInverse() = 0;
    virtual const FName GetName() = 0;
    virtual void InIteration(NFactorStack* Stack) {}
};

class IFactorOperatorWithStack
{
public:
    virtual void SetStack(NFactorStack* Stack) = 0;
    virtual void SetKeyInStack(uint32 Key) = 0;
};

class OperatorUtils
{
public:
    template <typename T>
    static bool IsOperatorWithStack(T Operator)
    {
        return dynamic_cast<IFactorOperatorWithStack*>(Operator) != nullptr;
    }
};
