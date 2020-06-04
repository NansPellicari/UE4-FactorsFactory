#pragma once

#include "CoreMinimal.h"
#include "FactorsFactoryClientAdapter.h"
#include "FactorsFactoryGameInstance.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NansTimelineSystemUE4/Public/Specs/FakeTimelineGameInstance.h"
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
class UFactorFakeGameInstance : public UNFakeTimelineGameInstance, public INFactorsFactoryGameInstance
{
	GENERATED_BODY()
public:
	UFactorFakeGameInstance() {}
	virtual void Init() override
	{
		Super::Init();
		FactorsFactoryClient = NewObject<UNFactorsFactoryClientAdapter>(this, FName("MyFakeFactorsFactoryClient"));
		FactorsFactoryClient->Init();
	}
	virtual UNFactorsFactoryClientAdapter* GetFactorsFactoryClient() const override
	{
		return FactorsFactoryClient;
	}

protected:
	UPROPERTY()
	UNFactorsFactoryClientAdapter* FactorsFactoryClient;
};
