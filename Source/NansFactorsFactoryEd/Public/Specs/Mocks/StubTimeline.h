// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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
	virtual const TArray<FNEventSave> GetEvents() const override
	{
		return TArray<FNEventSave>({});
	}
	virtual void PreDelete() override {}
	virtual void Archive(FArchive& Ar) override {}
	virtual TMap<FString, TSharedPtr<NEventInterface>> GetEventObjects() override
	{
		return TMap<FString, TSharedPtr<NEventInterface>>();
	}
	virtual TSharedPtr<NEventInterface> GetEvent(FString _UID) override
	{
		TSharedPtr<NEventInterface> Event;
		return Event;
	}
};
