#include "FactorsFactoryBlueprintHelpers.h"

#include "Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Factor/FactorAdapters.h"
#include "Factor/UnrealFactorProxy.h"
#include "FactorsFactoryClientAdapter.h"
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

UNFactorsFactoryClientAdapter* UNFactorsFactoryBlueprintHelpers::GetFactorClient(UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!World) return nullptr;

	INFactorsFactoryGameInstance* GI = Cast<INFactorsFactoryGameInstance>(World->GetGameInstance());
	mycheckf(GI != nullptr, TEXT("The game instance should implements INFactorsFactoryGameInstance to works"));

	UNFactorsFactoryClientAdapter* Client = GI->GetFactorsFactoryClient();
	return Client;
}

void UNFactorsFactoryBlueprintHelpers::Debug(UObject* WorldContextObject, const TArray<FFactorStackAttribute> StackNames, const bool Debug)
{
	UNFactorsFactoryClientAdapter* Client = GetFactorClient(WorldContextObject);
	if (Client == nullptr) return;
	TArray<FName> Names;
	for (const FFactorStackAttribute& StackName : StackNames)
	{
		Names.Add(StackName.Name);
	}
	Client->SetDebug(Names, Debug);
}

FNFactorStateResult UNFactorsFactoryBlueprintHelpers::GetFactorState(FFactorStackAttribute StackName, UNFactorsFactoryClientAdapter* Client)
{
	NFactorState* State = Client->GetState(StackName.Name);
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
FNFactorStateResult UNFactorsFactoryBlueprintHelpers::GetFactorState(UObject* WorldContextObject, FFactorStackAttribute StackName)
{
	UNFactorsFactoryClientAdapter* Client = GetFactorClient(WorldContextObject);
	if (Client == nullptr) return FNFactorStateResult();

	return UNFactorsFactoryBlueprintHelpers::GetFactorState(StackName, Client);
}

TMap<FName, FNFactorStateResult> UNFactorsFactoryBlueprintHelpers::GetFactorStates(
	UObject* WorldContextObject, TArray<FFactorStackAttribute> StackNames)
{
	TMap<FName, FNFactorStateResult> Results;
	UNFactorsFactoryClientAdapter* Client = GetFactorClient(WorldContextObject);

	if (Client == nullptr) return Results;

	for (const FFactorStackAttribute& StackName : StackNames)
	{
		Results.Add(StackName.Name, UNFactorsFactoryBlueprintHelpers::GetFactorState(StackName, Client));
	}
	return Results;
}

void UNFactorsFactoryBlueprintHelpers::Clear(UObject* WorldContextObject, TArray<FFactorStackAttribute> StackNames)
{
	UNFactorsFactoryClientAdapter* Client = GetFactorClient(WorldContextObject);

	if (Client == nullptr) return;

	for (const FFactorStackAttribute& StackName : StackNames)
	{
		Client->RemoveStack(StackName.Name);
	}
}

UNFactorAdapterAbstract* UNFactorsFactoryBlueprintHelpers::AddFactor(UObject* WorldContextObject, UNFactorAdapterAbstract* Factor)
{
	UNFactorsFactoryClientAdapter* Client = GetFactorClient(WorldContextObject);

	if (Client == nullptr) return Factor;

	Factor->Init();
	Client->AddFactor(Factor->InStack.Name, MakeShareable(new UnrealFactorProxy(*Factor)));

	return Factor;
}

UNFactorAdapterAbstract* UNFactorsFactoryBlueprintHelpers::CreateFactor(UObject* WorldContextObject, UClass* Class)
{
	UNFactorsFactoryClientAdapter* Client = GetFactorClient(WorldContextObject);
	return Cast<UNFactorAdapterAbstract>(UGameplayStatics::SpawnObject(Class, Client));
}
