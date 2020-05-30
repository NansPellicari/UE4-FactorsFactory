#pragma once

#include "CoreMinimal.h"
#include "Operator/Interfaces.h"

class NFactorInterface;
class NFactorStackInterface;

class NANSFACTORSFACTORYCORE_API NResetOperatorBase : public FactorOperatorInterface
{
public:
	virtual TSharedPtr<FactorOperatorInterface> GetInverse() override;
	static FString GetResetIdFlag(TSharedRef<NFactorInterface> Factor);
};

// TODO create ResetByReasonOperator ResetWithRangeOperator ResetAllOperator
class NANSFACTORSFACTORYCORE_API NResetOperator : public NResetOperatorBase, public FactorOperatorInterfaceWithStack
{
public:
	virtual ~NResetOperator();
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<FactorOperatorInterface> GetInverse() override;
	virtual void SetStack(NFactorStackInterface* Stack) override;
	virtual void SetKeyInStack(uint32 Key) override;

protected:
	NFactorStackInterface* MyStack;
	uint32 KeyInStack;
};
