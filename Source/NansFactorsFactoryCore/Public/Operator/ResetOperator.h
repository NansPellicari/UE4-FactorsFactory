#pragma once

#include "CoreMinimal.h"
#include "Operator/Interfaces.h"

class NFactorUnitInterface;
class NFactorInterface;

class NANSFACTORSFACTORYCORE_API NResetOperatorBase : public NFactorOperatorInterface
{
public:
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	static FString GetResetIdFlag(TSharedRef<NFactorUnitInterface> FactorUnit);
};

// TODO create ResetByReasonOperator ResetWithRangeOperator ResetAllOperator
class NANSFACTORSFACTORYCORE_API NResetOperator : public NResetOperatorBase, public NFactorOperatorWithFactorInterface
{
public:
	virtual ~NResetOperator();
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	virtual void SetFactor(NFactorInterface* Factor) override;
	virtual void SetKeyInFactor(uint32 Key) override;

protected:
	NFactorInterface* MyFactor;
	uint32 KeyInFactor;
};
