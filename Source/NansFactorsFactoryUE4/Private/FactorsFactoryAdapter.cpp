#include "FactorClientAdapter.h"
#include "NansFactorsFactoryCore/Public/FactorInterface.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"

UNFactorClientAdapter::UNFactorClientAdapter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    Client = MakeShareable(new NFactorsFactoryClient());
}

void UNFactorClientAdapter::CreateStack(FName StackName)
{
    Client->CreateStack(StackName);
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

void UNFactorClientAdapter::AddFactor(FName StackName, INFactorInterface* Factor)
{
    Client->AddFactor(StackName, Factor);
}

void UNFactorClientAdapter::AddTime(float Seconds)
{
    Client->AddTime(Seconds);
}

void UNFactorClientAdapter::SetDebug(const TArray<FName> StackNames, bool bDebug)
{
    Client->SetDebug(StackNames, bDebug);
}

void UNFactorClientAdapter::AddFactor(TArray<FName> StackNames, INFactorInterface* Factor)
{
    Client->AddFactor(StackNames, Factor);
}
