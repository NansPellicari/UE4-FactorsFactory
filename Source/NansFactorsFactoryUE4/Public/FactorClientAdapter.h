#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"

#include "FactorClientAdapter.generated.h"

class INFactorInterface;
class NFactorState;

UCLASS(BlueprintType)
class NANSFACTORSFACTORYUE4_API UNFactorClientAdapter : public UObject
{
    GENERATED_BODY()

public:
    UNFactorClientAdapter(const FObjectInitializer& ObjectInitializer);
    void CreateStack(FName StackName);
    void RemoveStack(FName StackName);
    NFactorState* GetState(FName StackName);
    TArray<NFactorState*> GetStates(TArray<FName> StackNames);
    void AddFactor(FName StackName, INFactorInterface* Factor);
    void AddFactor(TArray<FName> StackNames, INFactorInterface* Factor);
    void AddTime(float Seconds);
    void SetDebug(const TArray<FName> StackNames, bool bDebug);

protected:
    TSharedPtr<NFactorsFactoryClient> Client;
};
