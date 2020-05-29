#pragma once

#include "CoreMinimal.h"
#include "NansTimelineSystemCore/public/Event.h"

class IFactorOperator;

class NANSFACTORSFACTORYCORE_API NFactorInterface
{
public:
	virtual IFactorOperator* GetOperator() const = 0;
	virtual float GetFactorValue() const = 0;
	virtual FName GetReason() const = 0;
	virtual bool IsActivated() const = 0;
	virtual uint32 GetUID() const = 0;
	virtual TSharedPtr<NEventInterface> GetEvent() = 0;
};
