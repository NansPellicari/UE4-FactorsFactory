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
	virtual void SetOperator(TSharedPtr<FactorOperatorInterface> _Operator) override;
	virtual float GetFactorValue() const override;
	virtual void SetFactorValue(float _Value) override;
	virtual FName GetReason() const override;
	virtual const FString GetUID() const override;
	virtual TSharedPtr<NEventInterface> GetEvent() override;
};
