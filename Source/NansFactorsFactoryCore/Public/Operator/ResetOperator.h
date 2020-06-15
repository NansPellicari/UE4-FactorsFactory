#pragma once

#include "CoreMinimal.h"
#include "Operator/Interfaces.h"

class NFactorUnitInterface;
class NFactorInterface;

class NANSFACTORSFACTORYCORE_API NResetOperatorBase : public NFactorOperatorInterface
{
public:
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	static FString GetResetIdFlag(TSharedPtr<NFactorUnitInterface> FactorUnit);
};

// TODO create ResetByReasonOperator ResetWithRangeOperator ResetAllOperator
/**
 * This class find a previous FactorUnit and try to reset it.
 * The Rh parameter of the Compute() method determines the previous position
 * (The Index of the FactorUnit which embeds this Operator - Rh)
 * of the FactorUnit you want to reset.
 */
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
