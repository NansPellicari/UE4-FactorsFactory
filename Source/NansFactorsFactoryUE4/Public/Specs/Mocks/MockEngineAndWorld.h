#pragma once

#include "CoreMinimal.h"
#include "FactorsFactoryClientAdapter.h"
#include "FactorsFactoryGameInstance.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NansUE4TestsHelpers/Public/Mock/FakeGameInstance.h"

#include "MockEngineAndWorld.generated.h"

UCLASS()
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

UCLASS()
class UFactorFakeGameInstance : public UFakeGameInstance, public INFactorsFactoryGameInstance
{
	GENERATED_BODY()
public:
	UFactorFakeGameInstance()
	{
		FactorsFactoryClient = NewObject<UNFactorsFactoryClientAdapter>();
	}
	virtual UNFactorsFactoryClientAdapter* GetFactorsFactoryClient() const override
	{
		return FactorsFactoryClient;
	}

protected:
	UPROPERTY()
	UNFactorsFactoryClientAdapter* FactorsFactoryClient;
};
