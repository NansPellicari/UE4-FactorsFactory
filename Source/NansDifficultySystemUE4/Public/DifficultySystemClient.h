#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

#include "DifficultySystemClient.generated.h"

class UNDifficultyStack;
class UNDifficultyState;
class UNDifficulty;

UCLASS()
class NANSDIFFICULTYSYSTEMUE4_API UNDifficultySystemClient : public UObject
{
    GENERATED_BODY()
public:
    void CreateStack(FName StackName);
    UNDifficultyState* GetState(FName StackName);
    TArray<UNDifficultyState*> GetStates(TArray<FName> StackNames);
    void AddDifficulty(FName StackName, UNDifficulty* Difficulty);
    void AddDifficulty(TArray<FName> StackNames, UNDifficulty* Difficulty);

protected:
    TMap<FName, UNDifficultyStack*> StacksList;

private:
};
