#pragma once

#include "CoreMinimal.h"
#include "NansTimelineSystemCore/public/Event.h"

class NANSFACTORSFACTORYCORE_API NFactorEvent : public NEvent
{
public:
	NFactorEvent(uint32 _Id) : Id(_Id) {}

protected:
	const uint32 Id;
};
