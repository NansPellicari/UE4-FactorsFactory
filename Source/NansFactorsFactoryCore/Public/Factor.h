#pragma once

#include "CoreMinimal.h"
#include "FactorInterface.h"

class NFactorOperatorInterface;
class NEventInterface;

namespace NFactorGUID
{
	static uint32 sNextId = 0;
}

class NANSFACTORSFACTORYCORE_API NFactor : public NFactorInterface
{
public:
	NFactor(float _FactorValue,
		TSharedPtr<NFactorOperatorInterface> _Operator,
		float _Duration,
		FName Reason,
		float _Delay = 0.f,
		TSharedPtr<NEventInterface> _Event = NULL);
	virtual ~NFactor();
	virtual bool IsActivated() const override;
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() const override;
	virtual void SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator) override;
	virtual float GetFactorValue() const override;
	virtual FName GetReason() const override;
	virtual void SetFactorValue(float _Value) override;
	virtual const FString GetUID() const override;
	virtual TSharedPtr<NEventInterface> GetEvent() override;
	void Activate(bool _bIsActivated);

protected:
	TSharedPtr<NEventInterface> Event;
	bool bIsActivated = true;
	float FactorValue;
	TSharedPtr<NFactorOperatorInterface> Operator;
};
