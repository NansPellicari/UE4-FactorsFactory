// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "FactorsFactoryBlueprintHelpers.h"

#include "Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "FactorUnit/FactorUnitAdapter.h"
#include "FactorUnit/UnrealFactorUnitProxy.h"
#include "FactorsFactoryClientAdapter.h"
#include "FactorsFactoryGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/FactorUnit.h"
#include "NansFactorsFactoryCore/Public/FactorUnitInterface.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"
#include "NansFactorsFactoryCore/Public/Operator/ResetOperator.h"

UNFactorsFactoryClientAdapter* UNFactorsFactoryBlueprintHelpers::GetFactorUnitClient(UObject* WorldContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!World) return nullptr;

	UGameInstance* GI = World->GetGameInstance();

	mycheckf(GI->GetClass()->ImplementsInterface(UNFactorsFactoryGameInstance::StaticClass()),
		TEXT("The game instance should implements INFactorsFactoryGameInstance to works"));

	UNFactorsFactoryClientAdapter* Client = INFactorsFactoryGameInstance::Execute_GetFactorsFactoryClient(GI);
	return Client;
}

void UNFactorsFactoryBlueprintHelpers::Debug(
	UObject* WorldContextObject, const TArray<FFactorAttribute> FactorNames, const bool Debug)
{
	UNFactorsFactoryClientAdapter* Client = GetFactorUnitClient(WorldContextObject);
	if (Client == nullptr) return;
	TArray<FName> Names;
	for (const FFactorAttribute& FactorName : FactorNames)
	{
		Names.Add(FactorName.Name);
	}
	Client->SetDebug(Names, Debug);
}

FNFactorStateResult UNFactorsFactoryBlueprintHelpers::GetFactorState(
	FFactorAttribute FactorName, UNFactorsFactoryClientAdapter* Client)
{
	NFactorStateInterface* State = new NFactorState();
	Client->GetState(FactorName.Name, *State);
	TArray<FName> Reasons;

	const TArray<FNFactorStateOperator> Operators = State->GetOperators();
	for (FNFactorStateOperator Op : Operators)
	{
		// TODO Should be great to get the number of time the same reason has been added
		Reasons.AddUnique(Op.Reason);
	}

	return FNFactorStateResult(State->Compute(), Reasons, State->GetTime());
}
FNFactorStateResult UNFactorsFactoryBlueprintHelpers::GetFactorState(UObject* WorldContextObject, FFactorAttribute FactorName)
{
	UNFactorsFactoryClientAdapter* Client = GetFactorUnitClient(WorldContextObject);
	if (Client == nullptr) return FNFactorStateResult();

	return UNFactorsFactoryBlueprintHelpers::GetFactorState(FactorName, Client);
}

TMap<FName, FNFactorStateResult> UNFactorsFactoryBlueprintHelpers::GetFactorStates(
	UObject* WorldContextObject, TArray<FFactorAttribute> FactorNames)
{
	TMap<FName, FNFactorStateResult> Results;
	UNFactorsFactoryClientAdapter* Client = GetFactorUnitClient(WorldContextObject);

	if (Client == nullptr) return Results;

	for (const FFactorAttribute& FactorName : FactorNames)
	{
		Results.Add(FactorName.Name, UNFactorsFactoryBlueprintHelpers::GetFactorState(FactorName, Client));
	}
	return Results;
}

void UNFactorsFactoryBlueprintHelpers::Clear(UObject* WorldContextObject, TArray<FFactorAttribute> FactorNames)
{
	UNFactorsFactoryClientAdapter* Client = GetFactorUnitClient(WorldContextObject);

	if (Client == nullptr) return;

	for (const FFactorAttribute& FactorName : FactorNames)
	{
		Client->RemoveFactor(FactorName.Name);
	}
}

UNFactorUnitAdapter* UNFactorsFactoryBlueprintHelpers::AddFactorUnit(
	UObject* WorldContextObject, UNFactorUnitAdapter* FactorUnit, FFactorAttribute Factor)
{
	UNFactorsFactoryClientAdapter* Client = GetFactorUnitClient(WorldContextObject);

	if (Client == nullptr) return FactorUnit;

	Client->AddFactorUnit(Factor.Name, FactorUnit);

	return FactorUnit;
}

UNFactorUnitAdapter* UNFactorsFactoryBlueprintHelpers::CreateFactorUnit(
	UObject* WorldContextObject, UClass* Class, FFactorAttribute Factor)
{
	UNFactorsFactoryClientAdapter* Client = GetFactorUnitClient(WorldContextObject);
	mycheckf(Client != nullptr, TEXT("It's not possible to create a factor unit without a FactorsFactory client!"));
	return Client->CreateFactorUnit(Factor.Name, Class);
}

UNOperatorProviderBase* UNFactorsFactoryBlueprintHelpers::CreateOperatorProvider(
	UObject* WorldContextObject, UClass* OperatorProviderClass, FFactorAttribute Factor)
{
	UNFactorsFactoryClientAdapter* Client = GetFactorUnitClient(WorldContextObject);
	mycheckf(Client != nullptr, TEXT("It's not possible to create a factor unit without a FactorsFactory client!"));
	return Client->CreateOperatorProvider(Factor.Name, OperatorProviderClass);
}
