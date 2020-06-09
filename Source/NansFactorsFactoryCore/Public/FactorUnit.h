#pragma once

#include "CoreMinimal.h"
#include "FactorUnitInterface.h"

class NFactorOperatorInterface;
class NEventInterface;

namespace NFactorUnitGUID
{
	static uint32 sNextId = 0;
}

class NANSFACTORSFACTORYCORE_API NFactorUnit : public NFactorUnitInterface
{
public:
	NFactorUnit(float _FactorUnitValue,
		TSharedPtr<NFactorOperatorInterface> _Operator,
		float _Duration,
		FName Reason,
		float _Delay = 0.f,
		TSharedPtr<NEventInterface> _Event = NULL);
	NFactorUnit(float _FactorUnitValue, TSharedPtr<NFactorOperatorInterface> _Operator, TSharedPtr<NEventInterface> _Event);
	virtual ~NFactorUnit();
	virtual bool IsActivated() const override;
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() const override;
	virtual void SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator) override;
	virtual float GetFactorUnitValue() const override;
	virtual FName GetReason() const override;
	virtual void SetFactorUnitValue(float _Value) override;
	virtual const FString GetUID() const override;
	virtual TSharedPtr<NEventInterface> GetEvent() override;
	void Activate(bool _bIsActivated);

protected:
	TSharedPtr<NEventInterface> Event;
	bool bIsActivated = true;
	float FactorUnitValue;
	TSharedPtr<NFactorOperatorInterface> Operator;
};
