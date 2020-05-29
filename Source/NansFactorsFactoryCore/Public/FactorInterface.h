#pragma once

#include "CoreMinimal.h"
#include "NansTimelineSystemCore/public/TimelineEventBase.h"

class IFactorOperator;

class NANSFACTORSFACTORYCORE_API INFactorInterface
{
public:
	virtual IFactorOperator* GetOperator() const = 0;
	virtual float GetFactorValue() const = 0;
	virtual FName GetReason() const = 0;
	virtual bool IsActivated() const = 0;
	virtual uint32 GetUID() const = 0;
	virtual TSharedPtr<NTimelineEventInterface> GetEvent() = 0;
};
