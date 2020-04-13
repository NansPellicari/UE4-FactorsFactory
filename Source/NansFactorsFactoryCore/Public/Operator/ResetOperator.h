#pragma once

#include "CoreMinimal.h"
#include "Operator/Interfaces.h"

class INDifficultyInterface;
class NDifficultyStack;

class NANSFACTORSFACTORYCORE_API NResetOperatorBase : public IDifficultyOperator
{
public:
    virtual IDifficultyOperator* GetInverse() override;
    static FString GetResetIdFlag(INDifficultyInterface* Difficulty);
};

// TODO create ResetByReasonOperator ResetWithRangeOperator ResetAllOperator
class NANSFACTORSFACTORYCORE_API NResetOperator : public NResetOperatorBase, public IDifficultyOperatorWithStack
{
public:
    virtual float Compute(float Lh, float Rh) override;
    virtual IDifficultyOperator* GetInverse() override;
    virtual void SetStack(NDifficultyStack* Stack) override;
    virtual void SetKeyInStack(uint32 Key) override;
    static const FName Name;
    virtual const FName GetName() override
    {
        return Name;
    }

protected:
    NDifficultyStack* MyStack;
    uint32 KeyInStack;
};
