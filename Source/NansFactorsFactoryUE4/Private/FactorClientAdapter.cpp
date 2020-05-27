#include "FactorClientAdapter.h"

#include "Factor/FactorAdapterAbstract.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"
#include "NansTimelineSystemUE4/Public/Manager/TimelineManagerBaseDecorator.h"

UNFactorClientAdapter::UNFactorClientAdapter()
{
	Client = MakeShareable(new NFactorsFactoryClient());
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
