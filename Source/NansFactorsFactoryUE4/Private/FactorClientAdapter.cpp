#include "FactorClientAdapter.h"

#include "NansFactorsFactoryCore/Public/FactorInterface.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "NansTimelineSystemUE4/Public/Attribute/ConfiguredTimeline.h"
#include "NansTimelineSystemUE4/Public/Event/UnrealEventProxy.h"
#include "NansTimelineSystemUE4/Public/TimelineBlueprintHelpers.h"
#include "NansTimelineSystemUE4/Public/UnrealTimelineProxy.h"
#include "Settings/FactorSettings.h"

UNFactorClientAdapter::UNFactorClientAdapter() {}

void UNFactorClientAdapter::Init()
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

void UNFactorClientAdapter::CreateStack(TArray<FName> StackNames, TSharedPtr<NTimelineInterface> Timeline)
{
	Client->CreateStack(StackNames, Timeline);
}

void UNFactorClientAdapter::CreateStack(FName StackName, TSharedPtr<NTimelineInterface> Timeline)
{
	UE_LOG(LogTemp,
		Warning,
		TEXT("%s 3 %i"),
		ANSI_TO_TCHAR(__FUNCTION__),
		dynamic_cast<NUnrealTimelineProxy*>(Timeline.Get()) != nullptr);

	Client->CreateStack(StackName, Timeline);
}

void UNFactorClientAdapter::RemoveStack(FName StackName)
{
	Client->RemoveStack(StackName);
}

NFactorState* UNFactorClientAdapter::GetState(FName StackName)
{
	return Client->GetState(StackName);
}

TArray<NFactorState*> UNFactorClientAdapter::GetStates(TArray<FName> StackNames)
{
	return Client->GetStates(StackNames);
}

void UNFactorClientAdapter::AddFactor(FName StackName, TSharedPtr<INFactorInterface> Factor)
{
	Client->AddFactor(StackName, Factor);
}

void UNFactorClientAdapter::SetDebug(const TArray<FName> StackNames, bool bDebug)
{
	Client->SetDebug(StackNames, bDebug);
}

void UNFactorClientAdapter::AddFactor(TArray<FName> StackNames, TSharedPtr<INFactorInterface> Factor)
{
	Client->AddFactor(StackNames, Factor);
}
