#include "FactorsFactoryClientAdapter.h"

#include "NansFactorsFactoryCore/Public/FactorInterface.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "NansTimelineSystemUE4/Public/Attribute/ConfiguredTimeline.h"
#include "NansTimelineSystemUE4/Public/Event/UnrealEventProxy.h"
#include "NansTimelineSystemUE4/Public/TimelineBlueprintHelpers.h"
#include "NansTimelineSystemUE4/Public/UnrealTimelineProxy.h"
#include "Settings/FactorSettings.h"

UNFactorsFactoryClientAdapter::UNFactorsFactoryClientAdapter() {}

void UNFactorsFactoryClientAdapter::Init()
{
	Client = MakeShareable(new NFactorsFactoryClient());

	TArray<FNFactorSettings> ConfigList;
	UFactorSettings::GetConfigs(ConfigList);
	UE_LOG(LogTemp, Warning, TEXT("%s"), ANSI_TO_TCHAR(__FUNCTION__));

	for (auto& Conf : ConfigList)
	{
		FConfiguredTimeline TimelineConf;
		TimelineConf.Name = Conf.TimelineName;
		UNTimelineManagerDecorator* TimelineManager = UNTimelineBlueprintHelpers::GetTimeline(this, TimelineConf);
		if (TimelineManager != nullptr)
		{
			CreateStack(Conf.Name, TimelineManager->GetTimeline());
		}
	}
}

void UNFactorsFactoryClientAdapter::CreateStack(TArray<FName> StackNames, TSharedPtr<NTimelineInterface> Timeline)
{
	Client->CreateStack(StackNames, Timeline);
}

void UNFactorsFactoryClientAdapter::CreateStack(FName StackName, TSharedPtr<NTimelineInterface> Timeline)
{
	Client->CreateStack(StackName, Timeline);
}

void UNFactorsFactoryClientAdapter::RemoveStack(FName StackName)
{
	Client->RemoveStack(StackName);
}

NFactorState* UNFactorsFactoryClientAdapter::GetState(FName StackName)
{
	return Client->GetState(StackName);
}

TArray<NFactorState*> UNFactorsFactoryClientAdapter::GetStates(TArray<FName> StackNames)
{
	return Client->GetStates(StackNames);
}

void UNFactorsFactoryClientAdapter::AddFactor(FName StackName, TSharedPtr<NFactorInterface> Factor)
{
	Client->AddFactor(StackName, Factor);
}

void UNFactorsFactoryClientAdapter::SetDebug(const TArray<FName> StackNames, bool bDebug)
{
	Client->SetDebug(StackNames, bDebug);
}

void UNFactorsFactoryClientAdapter::AddFactor(TArray<FName> StackNames, TSharedPtr<NFactorInterface> Factor)
{
	Client->AddFactor(StackNames, Factor);
}
