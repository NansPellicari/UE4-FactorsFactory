#include "FactorStack.h"

#include "FactorInterface.h"
#include "FactorState.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "Operator/Interfaces.h"

NFactorStack::~NFactorStack()
{
	IterationFlags.Empty();
	Factors.Empty();
	Timeline.Reset();
}

void NFactorStack::Clear()
{
	Name = NAME_None;
	IterationFlags.Empty();
	Factors.Empty();
}

NFactorStack::NFactorStack(FName _Name, TSharedPtr<NTimelineInterface> _Timeline)
{
	Name = _Name;
	Timeline = _Timeline;
	_Timeline->OnEventExpired().AddRaw(this, &NFactorStack::OnTimelineEventExpired);
}

void NFactorStack::OnTimelineEventExpired(TSharedPtr<NEventInterface> Event, const float& ExpiredTime, const int32& Index)
{
	const FString& UId = Event->GetUID();
	int32 FactorIndex =
		Factors.IndexOfByPredicate([UId](const TSharedPtr<NFactorInterface> Record) { return Record->GetUID() == UId; });

	// It could be an event from an another stack or an another type
	if (FactorIndex == INDEX_NONE) return;

	Factors.RemoveAt(FactorIndex);
}

FName NFactorStack::GetName() const
{
	mycheck(Name != NAME_None);
	return Name;
}

void NFactorStack::SetName(FName _Name)
{
	Name = _Name;
}

TSharedPtr<NTimelineInterface> NFactorStack::GetTimeline() const
{
	return Timeline;
}

float NFactorStack::GetTime() const
{
	mycheck(Name != NAME_None);
	return Timeline->GetCurrentTime();
}

TSharedRef<NFactorInterface> NFactorStack::GetFactor(uint32 Key) const
{
	mycheck(Name != NAME_None);
	mycheck(Factors.IsValidIndex(Key));

	return Factors[Key].ToSharedRef();
}

void NFactorStack::AddFactor(TSharedPtr<NFactorInterface> Factor)
{
	mycheck(Name != NAME_None);
	mycheck(Timeline.IsValid());
	if (Factor->GetEvent().IsValid())
	{
		// This allow to notify time
		Timeline->Attached(Factor->GetEvent());
	}
	Factors.Add(Factor);
}

bool NFactorStack::HasFlag(FString Flag) const
{
	mycheck(Name != NAME_None);
	return IterationFlags.Contains(Flag);
}

bool NFactorStack::GetFlag(FString Flag) const
{
	mycheck(Name != NAME_None);
	mycheck(IterationFlags.Contains(Flag));
	return IterationFlags[Flag];
}

void NFactorStack::SetFlag(FString Flag, bool value)
{
	mycheck(Name != NAME_None);
	IterationFlags.Add(Flag, value);
}

void NFactorStack::AddFactorsToState(NFactorStateInterface& State)
{
	for (int32 Index = 0; Index < Factors.Num(); ++Index)
	{
		TSharedPtr<NFactorInterface> Factor = Factors[Index];
		if (!Factor.IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("%s: Factor is invalid"), ANSI_TO_TCHAR(__FUNCTION__));
			continue;
		}

		mycheck(Factor->GetOperator().IsValid());

		NFactorOperatorInterfaceWithStack* Operator = dynamic_cast<NFactorOperatorInterfaceWithStack*>(Factor->GetOperator().Get());
		if (Operator != nullptr)
		{
			Operator->SetStack(this);
			Operator->SetKeyInStack(Index);
		}
		State.AddFactor(Factor);
	}
}

TArray<TSharedPtr<NFactorInterface>> NFactorStack::GetFactors() const
{
	return Factors;
}

void NFactorStack::SupplyStateWithCurrentData(NFactorStateInterface& State)
{
	mycheckf(Name != NAME_None, TEXT("Should set a name before calling %s"), ANSI_TO_TCHAR(__FUNCTION__));
	State.Clear();
	State.SetTime(GetTime());
	State.Debug(bDebug);
	// Need to reset it, values should depend on iteration scope
	IterationFlags.Empty();

	AddFactorsToState(State);
}
void NFactorStack::Debug(bool _bDebug)
{
	bDebug = _bDebug;
}
