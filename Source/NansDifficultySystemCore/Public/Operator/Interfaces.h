#pragma once

#include "CoreMinimal.h"
#include "DifficultyStack.h"
#include "UObject/Interface.h"

#include "Interfaces.generated.h"

UINTERFACE(MinimalApi)
class UDifficultyOperator : public UInterface
{
    GENERATED_BODY()
};

class IDifficultyOperator
{
    GENERATED_BODY()

public:
    virtual float Compute(float Lh, float Rh) PURE_VIRTUAL(IDifficultyOperator::Compute, return 0.f;);
    virtual IDifficultyOperator* GetInverse() PURE_VIRTUAL(IDifficultyOperator::GetInverse, return this;);
};

UINTERFACE(MinimalApi)
class UDifficultyOperatorWithStack : public UInterface
{
    GENERATED_BODY()
};

class IDifficultyOperatorWithStack
{
    GENERATED_BODY()

public:
    virtual void SetStack(UNDifficultyStack* Stack) PURE_VIRTUAL(IDifficultyOperatorWithStack::SetStack, );
    virtual void SetKeyInStack(uint32 Key) PURE_VIRTUAL(IDifficultyOperatorWithStack::SetKeyInStack, );
};
