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

#include "Factor.h"

#include "FactorState.h"
#include "FactorUnitInterface.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "Operator/Interfaces.h"

NFactor::~NFactor()
{
	IterationFlags.Empty();
	Factors.Empty();
	Timeline.Reset();
}

// TODO create a Restart(), Restart doesn't have to reset NAME_None, but Clear does.
void NFactor::Clear()
{
	Name = NAME_None;
	IterationFlags.Empty();
	Factors.Empty();
}

NFactor::NFactor(FName _Name, TSharedPtr<NTimelineInterface> _Timeline)
{
	Name = _Name;
	Timeline = _Timeline;
	// TODO create an event when timeline is clear and attach to it
	_Timeline->OnEventExpired().AddRaw(this, &NFactor::OnTimelineEventExpired);
}

void NFactor::OnTimelineEventExpired(TSharedPtr<NEventInterface> Event, const float& ExpiredTime, const int32& Index)
{
	const FString& UId = Event->GetUID();
	int32 FactorUnitIndex = Factors.IndexOfByPredicate(
		[UId](const TSharedPtr<NFactorUnitInterface> Record) { return Record.IsValid() && Record->GetUID() == UId; });

	// It could be an event from an another factor or an another type
	if (FactorUnitIndex == INDEX_NONE) return;

	TSharedPtr<NFactorUnitInterface> FactorUnit = Factors[FactorUnitIndex];

	NFactorOperatorStopperInterface* Stopper = dynamic_cast<NFactorOperatorStopperInterface*>(FactorUnit->GetOperator().Get());

	if (Stopper != nullptr)
	{
		RemoveFlag(ENFactorFlag::CanNotAddNewUnit);
		FactorUnit->GetEvent()->OnStart().RemoveAll(this);
	}

	Factors.RemoveAt(FactorUnitIndex);
}

FName NFactor::GetName() const
{
	mycheck(Name != NAME_None);
	return Name;
}

void NFactor::SetName(FName _Name)
{
	Name = _Name;
}

TSharedPtr<NTimelineInterface> NFactor::GetTimeline() const
{
	return Timeline;
}

float NFactor::GetTime() const
{
	mycheck(Name != NAME_None);
	return Timeline->GetCurrentTime();
}

TSharedPtr<NFactorUnitInterface> NFactor::GetFactorUnit(uint32 Key) const
{
	mycheck(Name != NAME_None);
	mycheck(Factors.IsValidIndex(Key));

	return Factors[Key].ToSharedRef();
}

void NFactor::AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit)
{
	mycheck(Name != NAME_None);
	mycheck(Timeline.IsValid());

	if (HasFlag(ENFactorFlag::CanNotAddNewUnit)) return;

	if (FactorUnit->GetEvent().IsValid())
	{
		// This allow to notify time
		Timeline->Attached(FactorUnit->GetEvent());
	}
	Factors.Add(FactorUnit);

	NFactorOperatorStopperInterface* Stopper = dynamic_cast<NFactorOperatorStopperInterface*>(FactorUnit->GetOperator().Get());
	if (Stopper != nullptr)
	{
		FactorUnit->GetEvent()->OnStart().AddRaw(this, &NFactor::OnStopperStart);
	}
}

void NFactor::OnStopperStart(NEventInterface* Event, const float& StartTime)
{
	AddFlag(ENFactorFlag::CanNotAddNewUnit);
}

bool NFactor::HasStateFlag(FString Flag) const
{
	mycheck(Name != NAME_None);
	return IterationFlags.Contains(Flag);
}

bool NFactor::GetStateFlag(FString Flag) const
{
	mycheck(Name != NAME_None);
	mycheck(IterationFlags.Contains(Flag));
	return IterationFlags[Flag];
}

void NFactor::SetStateFlag(FString Flag, bool value)
{
	mycheck(Name != NAME_None);
	IterationFlags.Add(Flag, value);
}

void NFactor::RemoveStateFlag(FString Flag)
{
	mycheck(Name != NAME_None);
	IterationFlags.Remove(Flag);
}

bool NFactor::HasFlag(ENFactorFlag Flag) const
{
	mycheck(Name != NAME_None);
	return OwnFlags.Contains(Flag);
}

void NFactor::AddFlag(ENFactorFlag Flag)
{
	mycheck(Name != NAME_None);
	OwnFlags.Add(Flag);
}

void NFactor::RemoveFlag(ENFactorFlag Flag)
{
	mycheck(Name != NAME_None);
	int32 IndexLast = OwnFlags.FindLast(Flag);
	if (IndexLast != INDEX_NONE)
	{
		OwnFlags.RemoveAt(IndexLast);
	}
}

void NFactor::AddFactorsToState(NFactorStateInterface& State)
{
	for (int32 Index = 0; Index < Factors.Num(); ++Index)
	{
		TSharedPtr<NFactorUnitInterface> FactorUnit = Factors[Index];
		if (!FactorUnit.IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("%s: FactorUnit is invalid"), ANSI_TO_TCHAR(__FUNCTION__));
			continue;
		}

		// do not add delayed factor
		if (FactorUnit->GetEvent()->GetStartedAt() < 0.f)
		{
			continue;
		}

		mycheck(FactorUnit->GetOperator().IsValid());

		NFactorOperatorWithFactorInterface* Operator =
			dynamic_cast<NFactorOperatorWithFactorInterface*>(FactorUnit->GetOperator().Get());
		if (Operator != nullptr)
		{
			Operator->SetFactor(this);
			Operator->SetKeyInFactor(Index);
		}

		State.AddFactorUnit(FactorUnit);

		NFactorOperatorBreakerInterface* Breaker = dynamic_cast<NFactorOperatorBreakerInterface*>(FactorUnit->GetOperator().Get());
		if (Breaker != nullptr)
		{
			bool bBreak = Breaker->IsBreaking();
			if (bBreak) break;
		}
	}
}

TArray<TSharedPtr<NFactorUnitInterface>> NFactor::GetFactors() const
{
	return Factors;
}

void NFactor::SupplyStateWithCurrentData(NFactorStateInterface& State)
{
	mycheckf(Name != NAME_None, TEXT("Should set a name before calling %s"), ANSI_TO_TCHAR(__FUNCTION__));
	State.Clear();
	State.SetTime(GetTime());
	State.Debug(bDebug);
	// Need to reset it, values should depend on iteration scope
	IterationFlags.Empty();

	AddFactorsToState(State);
}
void NFactor::Debug(bool _bDebug)
{
	bDebug = _bDebug;
}
