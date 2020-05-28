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

	INFactorsFactoryGameInstance* GI = Cast<INFactorsFactoryGameInstance>(World->GetGameInstance());
	mycheckf(GI != nullptr, TEXT("The game instance should implements INFactorsFactoryGameInstance to works"));

	UNFactorClientAdapter* Client = GI->GetFactorsFactoryClient();
	return Client;
}

void UNFactorFactory::Debug(UObject* WorldContextObject, const TArray<FFactorStackAttribute> StackNames, const bool Debug)
{
	UNFactorClientAdapter* Client = GetFactorClient(WorldContextObject);
	if (Client == nullptr) return;
	TArray<FName> Names;
	for (const FFactorStackAttribute& StackName : StackNames)
	{
		Names.Add(StackName.Name);
	}
	Client->SetDebug(Names, Debug);
}

FNFactorStateResult UNFactorFactory::GetFactorState(FFactorStackAttribute StackName, UNFactorClientAdapter* Client)
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
FNFactorStateResult UNFactorFactory::GetFactorState(UObject* WorldContextObject, FFactorStackAttribute StackName)
{
	UNFactorClientAdapter* Client = GetFactorClient(WorldContextObject);
	if (Client == nullptr) return FNFactorStateResult();

	return UNFactorFactory::GetFactorState(StackName, Client);
}

TMap<FName, FNFactorStateResult> UNFactorFactory::GetFactorStates(
	UObject* WorldContextObject, TArray<FFactorStackAttribute> StackNames)
{
	TMap<FName, FNFactorStateResult> Results;
	UNFactorClientAdapter* Client = GetFactorClient(WorldContextObject);

	if (Client == nullptr) return Results;

	for (const FFactorStackAttribute& StackName : StackNames)
	{
		Results.Add(StackName.Name, UNFactorFactory::GetFactorState(StackName, Client));
	}
	return Results;
}

void UNFactorFactory::Clear(UObject* WorldContextObject, TArray<FFactorStackAttribute> StackNames)
{
	UNFactorClientAdapter* Client = GetFactorClient(WorldContextObject);

	if (Client == nullptr) return;

	for (const FFactorStackAttribute& StackName : StackNames)
	{
		Client->RemoveStack(StackName.Name);
	}
}

UNFactorAdapterAbstract* UNFactorFactory::AddFactor(UObject* WorldContextObject, UNFactorAdapterAbstract* Factor)
{
	UNFactorClientAdapter* Client = GetFactorClient(WorldContextObject);

	if (Client == nullptr) return Factor;

	Client->AddFactor(Factor->InStack.Name, Factor);

	return Factor;
}

UNFactorAdapterAbstract* UNFactorFactory::CreateFactor(UObject* WorldContextObject, UClass* Class)
{
	UNFactorClientAdapter* Client = GetFactorClient(WorldContextObject);
	return Cast<UNFactorAdapterAbstract>(UGameplayStatics::SpawnObject(Class, Client));
}
