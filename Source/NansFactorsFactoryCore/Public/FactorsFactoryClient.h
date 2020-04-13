#pragma once

#include "CoreMinimal.h"

class NDifficultyStack;
class NDifficultyState;
class INDifficultyInterface;

class NANSFACTORSFACTORYCORE_API NFactorsFactoryClient
{
public:
    void CreateStack(FName StackName);
    void RemoveStack(FName StackName);
    NDifficultyState* GetState(FName StackName);
    TArray<NDifficultyState*> GetStates(TArray<FName> StackNames);
    void AddDifficulty(FName StackName, INDifficultyInterface* Difficulty);
    void AddDifficulty(TArray<FName> StackNames, INDifficultyInterface* Difficulty);
    void AddTime(float Seconds);
    void SetDebug(const TArray<FName> StackNames, bool bDebug);

protected:
    UPROPERTY()
    TMap<FName, NDifficultyStack*> StacksList;

private:
};
