#include "FactorFactory.h"

#include "Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Factor/FactorAdapters.h"
#include "FactorClientAdapter.h"
#include "FactorsFactoryGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/FactorInterface.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/NullFactorState.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"
#include "NansFactorsFactoryCore/Public/Operator/ResetOperator.h"

UNFactorClientAdapter* UNFactorFactory::GetFactorClient(UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!World) return nullptr;

	UGameInstance* GI = World->GetGameInstance();
	if (!myensureMsgf(GI, TEXT("Should have a game instance to works"))) return nullptr;

	bool bIsImplementedFactorGI = GI->Implements<UNFactorsFactoryGameInstance>();
	if (myensureMsgf(bIsImplementedFactorGI, TEXT("The game instance should implements INFactorsFactoryGameInstance to works")))
	{
		UNFactorClientAdapter* Client = INFactorsFactoryGameInstance::Execute_GetFactorsFactoryClient(GI);
		return Client;
	}
	return nullptr;
}

void UNFactorFactory::Debug(UObject* WorldContextObject, const TArray<FName> StackNames, const bool Debug)
{
	UNFactorClientAdapter* Client = GetFactorClient(WorldContextObject);
	if (Client == nullptr) return;

	Client->SetDebug(StackNames, Debug);
}

FNFactorStateResult UNFactorFactory::GetFactorState(FName StackName, UNFactorClientAdapter* Client)
{
	NFactorState* State = Client->GetState(StackName);
	TArray<FName> Reasons;
	if (State == nullptr)
	{
		State = new NNullFactorState();
	}

	const TArray<FNFactorStateOperator> Operators = State->GetOperators();
	for (FNFactorStateOperator Op : Operators)
	{
		// TODO Should be great to get the number of time the same reason has been added
		Reasons.AddUnique(Op.Reason);
	}

	return FNFactorStateResult(State->Compute(), Reasons, State->GetTime());
}
FNFactorStateResult UNFactorFactory::GetFactorState(UObject* WorldContextObject, FName StackName)
{
	UNFactorClientAdapter* Client = GetFactorClient(WorldContextObject);
	if (Client == nullptr) return FNFactorStateResult();

	return UNFactorFactory::GetFactorState(StackName, Client);
}

TMap<FName, FNFactorStateResult> UNFactorFactory::GetFactorStates(UObject* WorldContextObject, TArray<FName> StackNames)
{
	TMap<FName, FNFactorStateResult> Results;
	UNFactorClientAdapter* Client = GetFactorClient(WorldContextObject);

	if (Client == nullptr) return Results;

	for (FName StackName : StackNames)
	{
		Results.Add(StackName, UNFactorFactory::GetFactorState(StackName, Client));
	}
	return Results;
}

void UNFactorFactory::Clear(UObject* WorldContextObject, TArray<FName> StackNames)
{
	UNFactorClientAdapter* Client = GetFactorClient(WorldContextObject);

	if (Client == nullptr) return;

	for (FName StackName : StackNames)
	{
		Client->RemoveStack(StackName);
	}
}

UNFactorAdapterAbstract* UNFactorFactory::AddFactor(UObject* WorldContextObject, UNFactorAdapterAbstract* Factor)
{
	UNFactorClientAdapter* Client = GetFactorClient(WorldContextObject);

	if (Client == nullptr) return Factor;

	Client->AddFactor(Factor->InStack, Factor);

	return Factor;
}

UNFactorAdapterAbstract* UNFactorFactory::CreateFactor(UObject* WorldContextObject, UClass* Class)
{
	UNFactorClientAdapter* Client = GetFactorClient(WorldContextObject);
	return Cast<UNFactorAdapterAbstract>(UGameplayStatics::SpawnObject(Class, Client));
}
