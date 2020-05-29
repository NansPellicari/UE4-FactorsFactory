#include "Factor.h"

#include "FactorEvent.h"
#include "NansTimelineSystemCore/public/TimelineEventBase.h"
#include "Operator/FactorOperator.h"
#include "Operator/Interfaces.h"

NFactor::NFactor(float _FactorValue,
	IFactorOperator* _Operator,
	float _Duration,
	FName _Reason,
	float _Delay,
	TSharedPtr<NTimelineEventInterface> _Event)
{
	FactorValue = _FactorValue;
	Operator = _Operator;
	Id = ++NFactorGUID::sNextId;
	Event = _Event;
	if (!_Event.IsValid())
	{
		Event = MakeShareable(new NFactorEvent(Id));
	}

	Event->SetEventLabel(_Reason);
	Event->SetDuration(_Duration);
	Event->SetDelay(_Delay);
}

uint32 NFactor::GetUID() const
{
	return Id;
}

FName NFactor::GetReason() const
{
	return Event->GetEventLabel();
}

bool NFactor::IsActivated() const
{
	return bIsActivated && Event.IsValid() && !Event->IsExpired();
}

IFactorOperator* NFactor::GetOperator() const
{
	if (!IsActivated())
	{
		return new NNullOperator();
	}
	return Operator;
}

float NFactor::GetFactorValue() const
{
	if (!IsActivated())
	{
		return 0;
	}
	return FactorValue;
}

void NFactor::Activate(bool _bIsActivated)
{
	bIsActivated = _bIsActivated;
}

TSharedPtr<NTimelineEventInterface> NFactor::GetEvent()
{
	return Event;
}

NFactor::~NFactor()
{
	Event.Reset();
}
