#pragma once

#include "CoreMinimal.h"
#include "NansTimelineSystemCore/public/Event.h"

class NFactorOperatorInterface;

class NANSFACTORSFACTORYCORE_API NFactorUnitInterface
{
public:
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() const = 0;
	virtual void SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator) = 0;
	virtual float GetFactorUnitValue() const = 0;
	virtual FName GetReason() const = 0;
	virtual void SetFactorUnitValue(float _Value) = 0;
	virtual bool IsActivated() const = 0;
	virtual const FString GetUID() const = 0;
	virtual TSharedPtr<NEventInterface> GetEvent() = 0;
	virtual void Activate(bool _bIsActivated) = 0;
};
