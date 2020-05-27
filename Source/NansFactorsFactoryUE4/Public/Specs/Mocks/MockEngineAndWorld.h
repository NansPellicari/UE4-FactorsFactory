#pragma once

#include "CoreMinimal.h"
#include "FactorClientAdapter.h"
#include "FactorsFactoryGameInstance.h"
#include "Kismet/BlueprintFunctionLibrary.h"

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
class UMockGameInstance : public UGameInstance, public INFactorsFactoryGameInstance
{
    GENERATED_BODY()
public:
    UMockGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
    {
        FactorsFactoryClient = NewObject<UNFactorClientAdapter>();
    }
    virtual UNFactorClientAdapter* GetFactorsFactoryClient_Implementation() const override
    {
        return FactorsFactoryClient;
    }

protected:
    UPROPERTY()
    UNFactorClientAdapter* FactorsFactoryClient;
};
