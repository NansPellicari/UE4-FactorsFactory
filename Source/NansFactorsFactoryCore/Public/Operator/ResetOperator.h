#pragma once

#include "CoreMinimal.h"
#include "Operator/Interfaces.h"

class INFactorInterface;
class NFactorStack;

class NANSFACTORSFACTORYCORE_API NResetOperatorBase : public IFactorOperator
{
public:
    virtual IFactorOperator* GetInverse() override;
    static FString GetResetIdFlag(INFactorInterface* Factor);
};

// TODO create ResetByReasonOperator ResetWithRangeOperator ResetAllOperator
class NANSFACTORSFACTORYCORE_API NResetOperator : public NResetOperatorBase, public IFactorOperatorWithStack
{
public:
    virtual float Compute(float Lh, float Rh) override;
    virtual IFactorOperator* GetInverse() override;
    virtual void SetStack(NFactorStack* Stack) override;
    virtual void SetKeyInStack(uint32 Key) override;
    static const FName Name;
    virtual const FName GetName() override
    {
        return Name;
    }

protected:
    NFactorStack* MyStack;
    uint32 KeyInStack;
};
