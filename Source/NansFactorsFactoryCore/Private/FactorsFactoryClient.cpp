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

#include "FactorsFactoryClient.h"

#include "Factor.h"
#include "FactorInterface.h"
#include "FactorState.h"
#include "FactorStateInterface.h"
#include "FactorUnitInterface.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "NansTimelineSystemCore/Public/TimelineInterface.h"

void NFactorsFactoryClient::RemoveFactor(FName FactorName)
{
	if (myensureMsgf(FactorsList.Contains(FactorName), TEXT("The factor \"%s\" does not exists"), *FactorName.ToString()))
	{
		FactorsList.Remove(FactorName);
	}
}

void NFactorsFactoryClient::CreateFactor(FName FactorName, TSharedPtr<NTimelineInterface> _Timeline)
{
	if (myensureMsgf(!FactorsList.Contains(FactorName), TEXT("The factor \"%s\" has been already created"), *FactorName.ToString()))
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
	if (myensureMsgf(!FactorsList.Contains(Factor->GetName()),
			TEXT("The factor \"%s\" has been already added"),
			*Factor->GetName().ToString()))
	{
		FactorsList.Add(Factor->GetName(), Factor);
	}
}

void NFactorsFactoryClient::GetState(FName FactorName, NFactorStateInterface& State)
{
	if (FactorsList.Contains(FactorName))
	{
		TSharedPtr<NFactorInterface> Factor = FactorsList[FactorName];
		mycheckf(Factor.IsValid(), TEXT("The factor '%s' existed in the factor list but has been removed"), *FactorName.ToString());
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

int32 NFactorsFactoryClient::AddFactorUnit(FName FactorName, TSharedPtr<NFactorUnitInterface> FactorUnit)
{
	mycheck(FactorName != NAME_None);
	mycheckf(FactorsList.Contains(FactorName), TEXT("Factor %s does not exists"), *FactorName.ToString());
	TSharedPtr<NFactorInterface> Factor = FactorsList[FactorName];

	if (!Factor.IsValid() || !FactorUnit.IsValid())
	{
		return -1;
	}
	return Factor->AddFactorUnit(FactorUnit);
}

TSharedPtr<NFactorUnitInterface> NFactorsFactoryClient::GetFactorUnit(FName FactorName, int32 Key)
{
	mycheck(FactorName != NAME_None);
	mycheckf(FactorsList.Contains(FactorName), TEXT("Factor %s does not exists"), *FactorName.ToString());

	TSharedPtr<NFactorInterface> Factor = FactorsList[FactorName];

	return Factor->GetFactorUnit(Key);
}

void NFactorsFactoryClient::SetDebug(const TArray<FName> FactorNames, bool bDebug)
{
	for (FName FactorName : FactorNames)
	{
		mycheckf(FactorsList.Contains(FactorName), TEXT("Factor %s does not exists"), *FactorName.ToString());

		if (!ensureMsgf(
				FactorsList.Contains(FactorName), TEXT("Can not debug an inexistant factor named \"%s\""), *FactorName.ToString()))
			return;

		TSharedPtr<NFactorInterface> Factor = FactorsList[FactorName];
		Factor->Debug(bDebug);
	}
}
