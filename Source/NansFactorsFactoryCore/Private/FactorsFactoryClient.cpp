#include "FactorsFactoryClient.h"

#include "FactorUnitInterface.h"
#include "Factor.h"
#include "FactorInterface.h"
#include "FactorState.h"
#include "FactorStateInterface.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "NansTimelineSystemCore/Public/TimelineInterface.h"

void NFactorsFactoryClient::RemoveFactor(FName FactorName)
{
	if (myensureMsgf(FactorsList.Contains(FactorName), TEXT("The stack \"%s\" does not exists"), *FactorName.ToString()))
	{
		FactorsList.Remove(FactorName);
	}
}

void NFactorsFactoryClient::CreateFactor(FName FactorName, TSharedPtr<NTimelineInterface> _Timeline)
{
	if (myensureMsgf(!FactorsList.Contains(FactorName), TEXT("The stack \"%s\" has been already created"), *FactorName.ToString()))
	{
		TSharedPtr<NFactorInterface> Factor = MakeShareable(new NFactor(FactorName, _Timeline));
		AddFactor(Factor);
	}
}

void NFactorsFactoryClient::CreateFactor(TArray<FName> FactorNames, TSharedPtr<NTimelineInterface> Timeline)
{
	for (FName Name : FactorNames)
	{
		CreateFactor(Name, Timeline);
	}
}

void NFactorsFactoryClient::AddFactor(TSharedPtr<NFactorInterface> Factor)
{
	if (myensureMsgf(
			!FactorsList.Contains(Factor->GetName()), TEXT("The stack \"%s\" has been already added"), *Factor->GetName().ToString()))
	{
		FactorsList.Add(Factor->GetName(), Factor);
	}
}

void NFactorsFactoryClient::GetState(FName FactorName, NFactorStateInterface& State)
{
	if (FactorsList.Contains(FactorName))
	{
		TSharedPtr<NFactorInterface> Factor = FactorsList[FactorName];
		mycheckf(Factor.IsValid(), TEXT("The stack '%s' existed in the stack list but has been removed"), *FactorName.ToString());
		Factor->SupplyStateWithCurrentData(State);
	}
}

TArray<NFactorStateInterface*> NFactorsFactoryClient::GetStates(TArray<FName> FactorNames, NFactorStateInterface* StateTemplate)
{
	TArray<NFactorStateInterface*> States;
	for (FName Name : FactorNames)
	{
		NFactorStateInterface* State = StateTemplate->Clone();
		GetState(Name, *State);
		if (State != nullptr)
		{
			States.Add(State);
		}
	}
	StateTemplate = nullptr;
	return States;
}

void NFactorsFactoryClient::AddFactorUnit(FName FactorName, TSharedPtr<NFactorUnitInterface> FactorUnit)
{
	mycheck(FactorName != NAME_None);
	mycheckf(FactorsList.Contains(FactorName), TEXT("Factor %s does not exists"), *FactorName.ToString());
	TSharedPtr<NFactorInterface> Factor = FactorsList[FactorName];

	if (!Factor.IsValid() || !FactorUnit.IsValid())
	{
		return;
	}
	Factor->AddFactorUnit(FactorUnit);
}

void NFactorsFactoryClient::SetDebug(const TArray<FName> FactorNames, bool bDebug)
{
	for (FName FactorName : FactorNames)
	{
		mycheckf(FactorsList.Contains(FactorName), TEXT("Factor %s does not exists"), *FactorName.ToString());

		if (!ensureMsgf(
				FactorsList.Contains(FactorName), TEXT("Can not debug an inexistant stack named \"%s\""), *FactorName.ToString()))
			return;

		TSharedPtr<NFactorInterface> Factor = FactorsList[FactorName];
		Factor->Debug(bDebug);
	}
}
