#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"

#include "FactorClientAdapter.generated.h"

class INFactorInterface;
class NFactorState;
class NTimelineInterface;

UCLASS(BlueprintType)
class NANSFACTORSFACTORYUE4_API UNFactorClientAdapter : public UObject, public NFactorsFactoryClientInterface
{
	GENERATED_BODY()

public:
	UNFactorClientAdapter();
	void Init();
	virtual void CreateStack(FName StackName, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void CreateStack(TArray<FName> StackNames, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void RemoveStack(FName StackName) override;
	virtual NFactorState* GetState(FName StackName) override;
	virtual TArray<NFactorState*> GetStates(TArray<FName> StackNames) override;
	virtual void AddFactor(FName StackName, TSharedPtr<INFactorInterface> Factor) override;
	virtual void AddFactor(TArray<FName> StackNames, TSharedPtr<INFactorInterface> Factor) override;
	virtual void SetDebug(const TArray<FName> StackNames, bool bDebug) override;

protected:
	TSharedPtr<NFactorsFactoryClient> Client;
};
