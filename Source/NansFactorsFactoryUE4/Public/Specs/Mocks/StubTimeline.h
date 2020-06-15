#pragma once

#include "CoreMinimal.h"
#include "NansTimelineSystemCore/Public/EventInterface.h"
#include "NansTimelineSystemCore/Public/TimelineInterface.h"

class NStubTimeline : public NTimelineInterface
{
public:
	FNTimelineEventDelegate EventExpired;
	virtual ~NStubTimeline()
	{
		EventExpired.Clear();
	}

	virtual bool Attached(TSharedPtr<NEventInterface> Event) override
	{
		Event->Start(0.f);
		return true;
	}
	virtual void Attached(TArray<TSharedPtr<NEventInterface>> EventsCollection) override {}
	virtual void SetTickInterval(float _TickInterval) override {}
	virtual void SetCurrentTime(float _CurrentTime) override {}
	virtual float GetCurrentTime() const override
	{
		return 1.0f;
	}
	virtual void SetLabel(FName _Label) override {}
	virtual FName GetLabel() const override
	{
		return FName("A name");
	}
	virtual void Clear() override {}
	virtual void NotifyTick() override {}
	virtual FNTimelineEventDelegate& OnEventExpired() override
	{
		return EventExpired;
	};
};
