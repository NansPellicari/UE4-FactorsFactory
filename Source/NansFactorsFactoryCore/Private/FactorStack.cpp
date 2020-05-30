#include "FactorStack.h"

#include "FactorInterface.h"
#include "FactorState.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "Operator/Interfaces.h"

#include <typeinfo>

NFactorStack::~NFactorStack()
{
	IterationFlags.Empty();
	Factors.Empty();
	Timeline.Reset();
}

void NFactorStack::Reset()
{
	Name = NAME_None;
	IterationFlags.Empty();
	Factors.Empty();
}

NFactorStack::NFactorStack(FName _Name, TSharedPtr<NTimelineInterface> _Timeline)
{
	Name = _Name;
	Timeline = _Timeline;
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
	// This allow to notify time
	Timeline->Attached(Factor->GetEvent());
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

void NFactorStack::AddFactorsToState(NFactorState* State)
{
	for (int32 Index = 0; Index < Factors.Num(); ++Index)
	{
		TSharedPtr<NFactorInterface> Factor = Factors[Index];
		if (!Factor.IsValid())
		{
			UE_LOG(LogTemp, Warning, TEXT("%s: Factor is invalid"), ANSI_TO_TCHAR(__FUNCTION__));
			continue;
		}

		IFactorOperatorWithStack* Operator = dynamic_cast<IFactorOperatorWithStack*>(Factor->GetOperator());
		if (Operator != nullptr)
		{
			Operator->SetStack(this);

			Operator->SetKeyInStack(Index);
		}
		State->AddFactor(Factor);
	}
}

NFactorState* NFactorStack::GetCurrentState()
{
	mycheckf(Name != NAME_None, TEXT("Should set a name before calling %s"), ANSI_TO_TCHAR(__FUNCTION__));
	NFactorState* State = new NFactorState(GetTime());
	State->bDebug = bDebug;
	// Need to reset it, values should depend on iteration scope
	IterationFlags.Empty();

	AddFactorsToState(State);

	return State;
}
