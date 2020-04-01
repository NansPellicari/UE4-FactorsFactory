#pragma once

#include "CoreMinimal.h"
#include "DifficultyClientAdapter.h"
#include "DifficultySystemGameInstance.h"
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
class UMockGameInstance : public UGameInstance, public INDifficultySystemGameInstance
{
    GENERATED_BODY()
public:
    UMockGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
    {
        DifficultySystemClient = NewObject<UNDifficultyClientAdapter>();
    }
    virtual UNDifficultyClientAdapter* GetDifficultySystemClient_Implementation() const override
    {
        return DifficultySystemClient;
    }

protected:
    UPROPERTY()
    UNDifficultyClientAdapter* DifficultySystemClient;
};