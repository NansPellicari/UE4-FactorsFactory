#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"

#include "FactorClientAdapter.generated.h"

class UNFactorAdapterAbstract;
class NFactorState;
class UNTimelineManagerBaseDecorator;

UCLASS(BlueprintType)
class NANSFACTORSFACTORYUE4_API UNFactorClientAdapter : public UObject
{
	GENERATED_BODY()

public:
	UNFactorClientAdapter();
	void CreateStack(FName StackName, UNTimelineManagerBaseDecorator* _Timeline);
	void RemoveStack(FName StackName);
	NFactorState* GetState(FName StackName);
	TArray<NFactorState*> GetStates(TArray<FName> StackNames);
	void AddFactor(FName StackName, UNFactorAdapterAbstract* Factor);
	void AddFactor(TArray<FName> StackNames, UNFactorAdapterAbstract* Factor);
	void SetDebug(const TArray<FName> StackNames, bool bDebug);

protected:
	TSharedPtr<NFactorsFactoryClient> Client;
};
