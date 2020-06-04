#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClientInterface.h"

#include "FactorsFactoryClientAdapter.generated.h"

class NFactorInterface;
class NFactorStateInterface;
class NFactorStackInterface;
class NTimelineInterface;
class NFactorsFactoryClientInterface;
class UNFactorStackDecorator;

UCLASS(BlueprintType)
class NANSFACTORSFACTORYUE4_API UNFactorsFactoryClientAdapter : public UObject, public NFactorsFactoryClientInterface
{
	GENERATED_BODY()

public:
	UNFactorsFactoryClientAdapter();
	virtual void Init();
	// BEGIN NFactorsFactoryClientInterface override
	virtual void CreateStack(FName StackName, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void CreateStack(TArray<FName> StackNames, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void AddStack(TSharedPtr<NFactorStackInterface> Stack) override;
	virtual void RemoveStack(FName StackName) override;
	virtual void GetState(FName StackName, NFactorStateInterface& State) override;
	virtual TArray<NFactorStateInterface*> GetStates(TArray<FName> StackNames, NFactorStateInterface* StateTemplate) override;
	virtual void AddFactor(FName StackName, TSharedPtr<NFactorInterface> Factor) override;
	virtual void SetDebug(const TArray<FName> StackNames, bool bDebug) override;
	// END NFactorsFactoryClientInterface override

	// BEGIN UObject override
	virtual void Serialize(FArchive& Ar);
	// END UObject override
protected:
	TSharedPtr<NFactorsFactoryClientInterface> Client;
	UPROPERTY()
	TArray<UNFactorStackDecorator*> UEStacks;
};
