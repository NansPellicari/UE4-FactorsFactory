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

#pragma once

#include "CoreMinimal.h"
#include "FactorsFactoryClientAdapter.h"
#include "FactorsFactoryGameInstance.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NansTimelineSystemEd/Public/Specs/FakeTimelineGameInstance.h"
#include "NansUE4TestsHelpers/Public/Mock/FakeGameInstance.h"

#include "MockEngineAndWorld.generated.h"

UCLASS(NotBlueprintable, NotPlaceable)
class UMockObject : public UObject
{
	GENERATED_BODY()
public:
	void SetMyWorld(TSharedPtr<UWorld> World)
	{
		Myworld = World;
	}

	virtual class UWorld* GetWorld() const override
	{
		return Myworld.Get();
	}

private:
	TSharedPtr<UWorld> Myworld;
};

UCLASS(NotBlueprintable, NotPlaceable)
class UFactorUnitFakeGameInstance : public UNFakeTimelineGameInstance, public INFactorsFactoryGameInstance
{
	GENERATED_BODY()
public:
	UFactorUnitFakeGameInstance() {}
	virtual void Init() override
	{
		Super::Init();
		FactorsFactoryClient = NewObject<UNFactorsFactoryClientAdapter>(this, FName("MyFakeFactorsFactoryClient"));
		FactorsFactoryClient->Init();
	}
	virtual UNFactorsFactoryClientAdapter* GetFactorsFactoryClient_Implementation() const override
	{
		return FactorsFactoryClient;
	}

protected:
	UPROPERTY()
	UNFactorsFactoryClientAdapter* FactorsFactoryClient;
};
