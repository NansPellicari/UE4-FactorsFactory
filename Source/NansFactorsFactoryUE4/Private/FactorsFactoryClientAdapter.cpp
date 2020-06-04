#include "FactorsFactoryClientAdapter.h"

#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/FactorInterface.h"
#include "NansFactorsFactoryCore/Public/FactorStackInterface.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/FactorStateInterface.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "NansTimelineSystemUE4/Public/Attribute/ConfiguredTimeline.h"
#include "NansTimelineSystemUE4/Public/Event/UnrealEventProxy.h"
#include "NansTimelineSystemUE4/Public/TimelineBlueprintHelpers.h"
#include "NansTimelineSystemUE4/Public/UnrealTimelineProxy.h"
#include "Settings/FactorSettings.h"
#include "Stack/FactorStackDecorator.h"
#include "Stack/UnrealFactorStackProxy.h"

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
			CreateStack(Conf.Name, TimelineManager->GetTimeline());
		}
	}
}

void UNFactorsFactoryClientAdapter::CreateStack(TArray<FName> StackNames, TSharedPtr<NTimelineInterface> Timeline)
{
	for (auto& Name : StackNames)
	{
		CreateStack(Name, Timeline);
	}
}

void UNFactorsFactoryClientAdapter::CreateStack(FName StackName, TSharedPtr<NTimelineInterface> Timeline)
{
	UNFactorStackDecorator* UStack = NewObject<UNFactorStackDecorator>(this, StackName);
	UStack->Init(StackName, Timeline);
	TSharedPtr<NFactorStackInterface> Stack = MakeShareable(new UNUnrealFactorStackProxy(*UStack));

	AddStack(Stack);
}

void UNFactorsFactoryClientAdapter::AddStack(TSharedPtr<NFactorStackInterface> Stack)
{
	auto Proxy = dynamic_cast<UNUnrealFactorStackProxy*>(Stack.Get());
	mycheckf(Proxy != nullptr, TEXT("You should passed UNUnrealFactorStackProxy inherited stack only"));
	mycheckf(Proxy->GetUnrealObject() != nullptr,
		TEXT("You should instanciate your stack proxy with a UNFactorStackDecorator inherited stack"));

	UEStacks.Add(Proxy->GetUnrealObject());
	Client->AddStack(Stack);
}

void UNFactorsFactoryClientAdapter::RemoveStack(FName StackName)
{
	Client->RemoveStack(StackName);
}

void UNFactorsFactoryClientAdapter::GetState(FName StackName, NFactorStateInterface& State)
{
	return Client->GetState(StackName, State);
}

TArray<NFactorStateInterface*> UNFactorsFactoryClientAdapter::GetStates(
	TArray<FName> StackNames, NFactorStateInterface* StateTemplate)
{
	return Client->GetStates(StackNames, StateTemplate);
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
