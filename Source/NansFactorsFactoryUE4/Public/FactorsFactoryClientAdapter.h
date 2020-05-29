#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClientInterface.h"

#include "FactorsFactoryClientAdapter.generated.h"

class NFactorInterface;
class NFactorState;
class NTimelineInterface;
class NFactorsFactoryClient;

UCLASS(BlueprintType)
class NANSFACTORSFACTORYUE4_API UNFactorsFactoryClientAdapter : public UObject, public NFactorsFactoryClientInterface
{
	GENERATED_BODY()

public:
	UNFactorsFactoryClientAdapter();
	void Init();
	virtual void CreateStack(FName StackName, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void CreateStack(TArray<FName> StackNames, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void RemoveStack(FName StackName) override;
	virtual NFactorState* GetState(FName StackName) override;
	virtual TArray<NFactorState*> GetStates(TArray<FName> StackNames) override;
	virtual void AddFactor(FName StackName, TSharedPtr<NFactorInterface> Factor) override;
	virtual void AddFactor(TArray<FName> StackNames, TSharedPtr<NFactorInterface> Factor) override;
	virtual void SetDebug(const TArray<FName> StackNames, bool bDebug) override;

protected:
	TSharedPtr<NFactorsFactoryClient> Client;
};
