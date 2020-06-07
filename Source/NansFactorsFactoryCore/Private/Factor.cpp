#include "Factor.h"

#include "FactorEvent.h"
#include "NansTimelineSystemCore/public/Event.h"
#include "Operator/FactorOperator.h"
#include "Operator/Interfaces.h"

NFactor::NFactor(float _FactorValue,
	TSharedPtr<FactorOperatorInterface> _Operator,
	float _Duration,
	FName _Reason,
	float _Delay,
	TSharedPtr<NEventInterface> _Event)
{
	FactorValue = _FactorValue;
	Operator = _Operator;
	Event = _Event;
	if (!_Event.IsValid())
	{
		Event = MakeShareable(new NFactorEvent());
	}

	Event->SetEventLabel(_Reason);
	Event->SetDuration(_Duration);
	Event->SetDelay(_Delay);
}

const FString NFactor::GetUID() const
{
	return Event->GetUID();
}

void NFactor::SetOperator(TSharedPtr<FactorOperatorInterface> _Operator)
{
	Operator = _Operator;
}

FName NFactor::GetReason() const
{
	return Event->GetEventLabel();
}

bool NFactor::IsActivated() const
{
	return bIsActivated && Event.IsValid() && !Event->IsExpired();
}

TSharedPtr<FactorOperatorInterface> NFactor::GetOperator() const
{
	if (!IsActivated())
	{
		return MakeShareable(new NNullOperator());
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

void NFactor::SetFactorValue(float _Value)
{
	FactorValue = _Value;
}

void NFactor::Activate(bool _bIsActivated)
{
	bIsActivated = _bIsActivated;
}

TSharedPtr<NEventInterface> NFactor::GetEvent()
{
	return Event;
}

NFactor::~NFactor()
{
	Event.Reset();
}
