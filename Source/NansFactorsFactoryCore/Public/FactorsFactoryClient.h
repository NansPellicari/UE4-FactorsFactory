#pragma once

#include "CoreMinimal.h"

class NFactorStack;
class NFactorState;
class INFactorInterface;

class NANSFACTORSFACTORYCORE_API NFactorsFactoryClient
{
public:
    void CreateStack(FName StackName);
    void RemoveStack(FName StackName);
    NFactorState* GetState(FName StackName);
    TArray<NFactorState*> GetStates(TArray<FName> StackNames);
    void AddFactor(FName StackName, INFactorInterface* Factor);
    void AddFactor(TArray<FName> StackNames, INFactorInterface* Factor);
    void AddTime(float Seconds);
    void SetDebug(const TArray<FName> StackNames, bool bDebug);

protected:
    UPROPERTY()
    TMap<FName, NFactorStack*> StacksList;

private:
};