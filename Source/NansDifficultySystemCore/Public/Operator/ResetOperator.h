#pragma once

#include "CoreMinimal.h"
#include "Operator/Interfaces.h"

class INDifficultyInterface;
class NDifficultyStack;

class NANSDIFFICULTYSYSTEMCORE_API NResetOperatorBase : public IDifficultyOperator
{
public:
    virtual IDifficultyOperator* GetInverse() override;
    static FString GetResetIdFlag(INDifficultyInterface* Difficulty);
};

// TODO create ResetByReasonOperator ResetWithRangeOperator ResetAllOperator
class NANSDIFFICULTYSYSTEMCORE_API NResetOperator : public NResetOperatorBase, public IDifficultyOperatorWithStack
{
public:
    virtual float Compute(float Lh, float Rh) override;
    virtual IDifficultyOperator* GetInverse() override;
    virtual void SetStack(NDifficultyStack* Stack) override;
    virtual void SetKeyInStack(uint32 Key) override;

protected:
    NDifficultyStack* MyStack;
    uint32 KeyInStack;
};
