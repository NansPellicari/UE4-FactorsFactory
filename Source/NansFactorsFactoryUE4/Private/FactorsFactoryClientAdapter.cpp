#include "FactorsFactoryClientAdapter.h"

#include "FactorUnit/FactorUnitAdapterAbstract.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/FactorUnitInterface.h"
#include "NansFactorsFactoryCore/Public/FactorInterface.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/FactorStateInterface.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "NansTimelineSystemUE4/Public/Attribute/ConfiguredTimeline.h"
#include "NansTimelineSystemUE4/Public/Event/UnrealEventProxy.h"
#include "NansTimelineSystemUE4/Public/TimelineBlueprintHelpers.h"
#include "NansTimelineSystemUE4/Public/UnrealTimelineProxy.h"
#include "Settings/FactorSettings.h"
#include "Factor/FactorDecorator.h"
#include "Factor/UnrealFactorProxy.h"

UNFactorsFactoryClientAdapter::UNFactorsFactoryClientAdapter() {}

void UNFactorsFactoryClientAdapter::Init()
{
	Client = MakeShareable(new NFactorsFactoryClient());

	TArray<FNFactorSettings> ConfigList;
	UFactorSettings::GetConfigs(ConfigList);
	for (auto& Conf : ConfigList)
	{
		FConfiguredTimeline TimelineConf;
		TimelineConf.Name = Conf.TimelineName;
		UNTimelineManagerDecorator* TimelineManager = UNTimelineBlueprintHelpers::GetTimeline(this, TimelineConf);
		if (TimelineManager != nullptr)
		{
			CreateFactor(Conf.Name, TimelineManager->GetTimeline());
		}
	}
}

void UNFactorsFactoryClientAdapter::CreateFactor(TArray<FName> FactorNames, TSharedPtr<NTimelineInterface> Timeline)
{
	for (auto& Name : FactorNames)
	{
		CreateFactor(Name, Timeline);
	}
}

UNFactorUnitAdapterAbstract* UNFactorsFactoryClientAdapter::CreateFactorUnit(const FName& FactorName, const UClass* Class)
{
	mycheckf(UEFactors.Contains(FactorName), TEXT("The stack %s doesn't exists!"), *FactorName.ToString());
	return UEFactors[FactorName]->CreateFactorUnit(Class);
}

void UNFactorsFactoryClientAdapter::CreateFactor(FName FactorName, TSharedPtr<NTimelineInterface> Timeline)
{
	UNFactorDecorator* UFactor = NewObject<UNFactorDecorator>(this, FactorName);
	UFactor->Init(FactorName, Timeline);
	TSharedPtr<NFactorInterface> Factor = MakeShareable(new NUnrealFactorProxy(*UFactor));
	AddFactor(Factor);
}

void UNFactorsFactoryClientAdapter::AddFactor(TSharedPtr<NFactorInterface> Factor)
{
	auto Proxy = dynamic_cast<NUnrealFactorProxy*>(Factor.Get());
	mycheckf(Proxy != nullptr, TEXT("You should passed NUnrealFactorProxy inherited stack only"));
	mycheckf(Proxy->GetUnrealObject() != nullptr,
		TEXT("You should instanciate your stack proxy with a UNFactorDecorator inherited stack"));

	UEFactors.Add(Proxy->GetName(), Proxy->GetUnrealObject());
	Client->AddFactor(Factor);
}

void UNFactorsFactoryClientAdapter::RemoveFactor(FName FactorName)
{
	Client->RemoveFactor(FactorName);
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

void UNFactorsFactoryClientAdapter::AddFactorUnit(FName FactorName, TSharedPtr<NFactorUnitInterface> FactorUnit)
{
	Client->AddFactorUnit(FactorName, FactorUnit);
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
		// Refresh stacks data, in case data has been set from previous load or during game play.
		UEFactors.Empty();
		Init();
	}

	Ar << UEFactorsNames;

	for (const FName& Name : UEFactorsNames)
	{
		mycheckf(UEFactors.Contains(Name), TEXT("The stack \"%s\" doesn't exists anymore"), *Name.ToString());

		UNFactorDecorator* Factor = UEFactors[Name];
		Factor->Serialize(Ar);
	}
	UEFactorsNames.Empty();
}
