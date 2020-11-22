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

#include "FactorsFactoryClientAdapter.h"

#include "Factor/UnrealFactorProxy.h"
#include "FactorUnit/FactorUnitView.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/FactorInterface.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/FactorStateInterface.h"
#include "NansFactorsFactoryCore/Public/FactorUnitInterface.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "NansTimelineSystemUE4/Public/Attribute/ConfiguredTimeline.h"
#include "NansTimelineSystemUE4/Public/TimelineBlueprintHelpers.h"
#include "Operator/OperatorProviders.h"
#include "Settings/FactorSettings.h"

UNFactorsFactoryClientAdapter::UNFactorsFactoryClientAdapter() {}

void UNFactorsFactoryClientAdapter::Init()
{
	Client = MakeShareable(new NFactorsFactoryClient());

	TArray<TSharedPtr<FNFactorSettings>> ConfigList;
	UFactorSettings::GetConfigs(ConfigList);
	for (auto& Conf : ConfigList)
	{
		CreateFactor(Conf->Name, Conf->Timeline, Conf->FactorClass);
	}
}

UNFactorUnitView* UNFactorsFactoryClientAdapter::CreateFactorUnit(const FName& FactorName, const UClass* Class)
{
	mycheckf(UEFactors.Contains(FactorName), TEXT("The factor %s doesn't exists!"), *FactorName.ToString());
	return UEFactors[FactorName]->CreateFactorUnit(Class);
}

UNOperatorProviderBase* UNFactorsFactoryClientAdapter::CreateOperatorProvider(const FName& FactorName,
	const UClass* Class)
{
	mycheckf(UEFactors.Contains(FactorName), TEXT("The factor %s doesn't exists!"), *FactorName.ToString());
	return UEFactors[FactorName]->CreateOperatorProvider(Class);
}

void UNFactorsFactoryClientAdapter::CreateFactor(
	const TArray<FName> FactorNames, FConfiguredTimeline Timeline, const UClass* FactorClass)
{
	for (const FName& FactorName : FactorNames)
	{
		CreateFactor(FactorName, Timeline, FactorClass);
	}
}

void UNFactorsFactoryClientAdapter::CreateFactor(const FName& FactorName, FConfiguredTimeline Timeline,
	const UClass* FactorClass)
{
	mycheckf(
		FactorClass->IsChildOf(UNFactorDecorator::StaticClass()),
		TEXT("%s - The class should be a child of UNFactorDecorator"),
		ANSI_TO_TCHAR(__FUNCTION__)
	);

	UNTimelineManagerDecorator* TimelineManager = UNTimelineBlueprintHelpers::GetTimeline(this, Timeline);
	mycheckf(IsValid(TimelineManager), TEXT("Timeline manager %s does not exists"), *Timeline.Name.ToString());

	UNFactorDecorator* UFactor = NewObject<UNFactorDecorator>(this, FactorClass, FactorName);
	UFactor->Init(FactorName, TimelineManager->GetTimeline());
	UEFactors.Add(UFactor->GetName(), UFactor);
	TSharedPtr<NFactorInterface> Factor = MakeShareable(new NUnrealFactorProxy(*UFactor));
	Client->AddFactor(Factor);
}

int32 UNFactorsFactoryClientAdapter::AddFactorUnit(FName FactorName, UNFactorUnitView* FactorUnit)
{
	return UEFactors[FactorName]->AddFactorUnit(FactorUnit);
}

UNFactorUnitView* UNFactorsFactoryClientAdapter::GetFactorUnit(FName FactorName, int32 FactorIndex)
{
	return UEFactors[FactorName]->GetGCFactorUnit(FactorIndex);
}

void UNFactorsFactoryClientAdapter::RemoveFactor(const FName& FactorName)
{
	Client->RemoveFactor(FactorName);
}

bool UNFactorsFactoryClientAdapter::HasFactor(const FName& FactorName) const
{
	return Client->HasFactor(FactorName);
}

void UNFactorsFactoryClientAdapter::GetState(FName FactorName, NFactorStateInterface& State)
{
	return Client->GetState(FactorName, State);
}

TArray<NFactorStateInterface*> UNFactorsFactoryClientAdapter::GetStates(
	TArray<FName> FactorNames, NFactorStateInterface* StateTemplate)
{
	return Client->GetStates(FactorNames, StateTemplate);
}

void UNFactorsFactoryClientAdapter::SetDebug(const TArray<FName> FactorNames, bool bDebug)
{
	Client->SetDebug(FactorNames, bDebug);
}

void UNFactorsFactoryClientAdapter::Serialize(FArchive& Ar)
{
	if (Ar.IsSaving())
	{
		UEFactors.GetKeys(UEFactorsNames);
	}

	if (Ar.IsLoading())
	{
		for (auto& It : UEFactors)
		{
			It.Value->ConditionalBeginDestroy();
		}
		// Refresh factors data, in case data has been set from previous load or during game play.
		UEFactors.Empty();
		Init();
	}

	Ar << UEFactorsNames;

	for (const FName& Name : UEFactorsNames)
	{
		mycheckf(UEFactors.Contains(Name), TEXT("The factor \"%s\" doesn't exists anymore"), *Name.ToString());

		UNFactorDecorator* Factor = UEFactors[Name];
		Factor->Serialize(Ar);
	}
	UEFactorsNames.Empty();
}
