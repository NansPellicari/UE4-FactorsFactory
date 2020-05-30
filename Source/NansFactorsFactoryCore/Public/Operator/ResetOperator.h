#pragma once

#include "CoreMinimal.h"
#include "Operator/Interfaces.h"

class NFactorInterface;
class NFactorStack;

class NANSFACTORSFACTORYCORE_API NResetOperatorBase : public IFactorOperator
{
public:
	virtual TSharedPtr<IFactorOperator> GetInverse() override;
	static FString GetResetIdFlag(TSharedRef<NFactorInterface> Factor);
};

// TODO create ResetByReasonOperator ResetWithRangeOperator ResetAllOperator
class NANSFACTORSFACTORYCORE_API NResetOperator : public NResetOperatorBase, public IFactorOperatorWithStack
{
public:
	virtual ~NResetOperator();
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<IFactorOperator> GetInverse() override;
	virtual void SetStack(NFactorStack* Stack) override;
	virtual void SetKeyInStack(uint32 Key) override;

protected:
	NFactorStack* MyStack;
	uint32 KeyInStack;
};
