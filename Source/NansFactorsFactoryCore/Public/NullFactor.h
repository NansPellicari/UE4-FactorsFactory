#pragma once

#include "CoreMinimal.h"
#include "FactorInterface.h"

class FactorOperatorInterface;
class NEventInterface;

class NANSFACTORSFACTORYCORE_API NNullFactor : public NFactorInterface
{
public:
	NNullFactor();
	virtual ~NNullFactor();
	virtual bool IsActivated() const override;
	virtual TSharedPtr<FactorOperatorInterface> GetOperator() const override;
	virtual float GetFactorValue() const override;
	virtual FName GetReason() const override;
	virtual uint32 GetUID() const override;
	virtual TSharedPtr<NEventInterface> GetEvent() override;
};
