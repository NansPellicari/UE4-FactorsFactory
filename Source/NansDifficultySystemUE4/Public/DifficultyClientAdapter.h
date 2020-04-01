#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NansDifficultySystemCore/Public/DifficultySystemClient.h"

#include "DifficultyClientAdapter.generated.h"

class INDifficultyInterface;
class NDifficultyState;

UCLASS(BlueprintType)
class NANSDIFFICULTYSYSTEMUE4_API UNDifficultyClientAdapter : public UObject
{
    GENERATED_BODY()

public:
    UNDifficultyClientAdapter(const FObjectInitializer& ObjectInitializer);
    void CreateStack(FName StackName);
    NDifficultyState* GetState(FName StackName);
    TArray<NDifficultyState*> GetStates(TArray<FName> StackNames);
    void AddDifficulty(FName StackName, INDifficultyInterface* Difficulty);
    void AddDifficulty(TArray<FName> StackNames, INDifficultyInterface* Difficulty);
    void AddTime(float Seconds);
    void SetDebug(const TArray<FName> StackNames, bool bDebug);

protected:
    TSharedPtr<NDifficultySystemClient> Client;
};