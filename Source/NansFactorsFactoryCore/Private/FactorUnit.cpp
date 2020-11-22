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

#include "FactorUnit.h"

#include "NansTimelineSystemCore/public/Event.h"
#include "Operator/FactorOperator.h"
#include "Operator/Interfaces.h"

NFactorUnit::NFactorUnit(float _FactorUnitValue, TSharedPtr<NFactorOperatorInterface> _Operator, TSharedPtr<NEventInterface> _Event)
{
	FactorUnitValue = _FactorUnitValue;
	Operator = _Operator;
	Event = _Event;
}

NFactorUnit::NFactorUnit(float _FactorUnitValue,
	TSharedPtr<NFactorOperatorInterface> _Operator,
	float _Duration,
	FName _Reason,
	float _Delay,
	TSharedPtr<NEventInterface> _Event)
{
	FactorUnitValue = _FactorUnitValue;
	Operator = _Operator;
	Event = _Event;
	if (!_Event.IsValid())
	{
		Event = MakeShareable(new NEvent());
	}

	Event->SetEventLabel(_Reason);
	Event->SetDuration(_Duration);
	Event->SetDelay(_Delay);
}

const FString NFactorUnit::GetUID() const
{
	return Event->GetUID();
}

void NFactorUnit::SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator)
{
	Operator = _Operator;
}

FName NFactorUnit::GetReason() const
{
	return Event->GetEventLabel();
}

bool NFactorUnit::IsActivated() const
{
	return bIsActivated && Event.IsValid() && !Event->IsExpired();
}

TSharedPtr<NFactorOperatorInterface> NFactorUnit::GetOperator()
{
	return Operator;
}

float NFactorUnit::GetFactorUnitValue() const
{
	return FactorUnitValue;
}

void NFactorUnit::SetFactorUnitValue(float _Value)
{
	FactorUnitValue = _Value;
}

void NFactorUnit::Activate(bool _bIsActivated)
{
	bIsActivated = _bIsActivated;
	if (bIsActivated == false) Event->Stop();
}

TSharedPtr<NEventInterface> NFactorUnit::GetEvent()
{
	return Event;
}

NFactorUnit::~NFactorUnit()
{
	Event.Reset();
}

void NFactorUnit::PreDelete() {}

void NFactorUnit::Archive(FArchive& Ar)
{
	Ar << bIsActivated;
	Ar << FactorUnitValue;
}
