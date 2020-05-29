#pragma once

#include "CoreMinimal.h"
#include "NansTimelineSystemCore/public/TimelineEventBase.h"

class NANSFACTORSFACTORYCORE_API NFactorEvent : public NTimelineEventBase
{
public:
	NFactorEvent(uint32 _Id) : Id(_Id) {}

protected:
	const uint32 Id;
};