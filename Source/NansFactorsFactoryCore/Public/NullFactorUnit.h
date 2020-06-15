#pragma once

#include "CoreMinimal.h"
#include "FactorUnitInterface.h"

class NFactorOperatorInterface;
class NEventInterface;

class NANSFACTORSFACTORYCORE_API NNullFactorUnit : public NFactorUnitInterface
{
public:
	NNullFactorUnit();
	virtual ~NNullFactorUnit();
	virtual bool IsActivated() const override;
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() const override;
	virtual void SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator) override;
	virtual float GetFactorUnitValue() const override;
	virtual void SetFactorUnitValue(float _Value) override;
	virtual FName GetReason() const override;
	virtual const FString GetUID() const override;
	virtual TSharedPtr<NEventInterface> GetEvent() override;
	virtual void Activate(bool _bIsActivated) override;
};
