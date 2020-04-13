#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"

#include "DifficultyClientAdapter.generated.h"

class INDifficultyInterface;
class NDifficultyState;

UCLASS(BlueprintType)
class NANSFACTORSFACTORYUE4_API UNDifficultyClientAdapter : public UObject
{
    GENERATED_BODY()

public:
    UNDifficultyClientAdapter(const FObjectInitializer& ObjectInitializer);
    void CreateStack(FName StackName);
    void RemoveStack(FName StackName);
    NDifficultyState* GetState(FName StackName);
    TArray<NDifficultyState*> GetStates(TArray<FName> StackNames);
    void AddDifficulty(FName StackName, INDifficultyInterface* Difficulty);
    void AddDifficulty(TArray<FName> StackNames, INDifficultyInterface* Difficulty);
    void AddTime(float Seconds);
    void SetDebug(const TArray<FName> StackNames, bool bDebug);

protected:
    TSharedPtr<NFactorsFactoryClient> Client;
};
