#include "FactorClientAdapter.h"

#include "Factor/FactorAdapterAbstract.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"
#include "NansTimelineSystemUE4/Public/Attribute/ConfiguredTimeline.h"
#include "NansTimelineSystemUE4/Public/Manager/TimelineManagerBaseDecorator.h"
#include "NansTimelineSystemUE4/Public/TimelineBlueprintHelpers.h"
#include "Settings/FactorSettings.h"

UNFactorClientAdapter::UNFactorClientAdapter()
{
	Client = MakeShareable(new NFactorsFactoryClient());

	TArray<FNFactorSettings> ConfigList;
	UFactorSettings::GetConfigs(ConfigList);
	UE_LOG(LogTemp, Warning, TEXT("%s"), ANSI_TO_TCHAR(__FUNCTION__));

	for (auto& Conf : ConfigList)
	{
		FConfiguredTimeline TimelineConf;
		TimelineConf.Name = Conf.TimelineName;
		UNTimelineManagerBaseDecorator* Timeline = UNTimelineBlueprintHelpers::GetTimeline(this, TimelineConf);
		if (Timeline != nullptr)
		{
			CreateStack(Conf.Name, Timeline);
		}
	}
}

void UNFactorClientAdapter::CreateStack(FName StackName, UNTimelineManagerBaseDecorator* _Timeline)
{
	Client->CreateStack(StackName, _Timeline->GetTimeline());
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

void UNFactorClientAdapter::AddFactor(FName StackName, UNFactorAdapterAbstract* Factor)
{
	Client->AddFactor(StackName, Factor->GetFactor());
}

void UNFactorClientAdapter::SetDebug(const TArray<FName> StackNames, bool bDebug)
{
	Client->SetDebug(StackNames, bDebug);
}

void UNFactorClientAdapter::AddFactor(TArray<FName> StackNames, UNFactorAdapterAbstract* Factor)
{
	Client->AddFactor(StackNames, Factor->GetFactor());
}
