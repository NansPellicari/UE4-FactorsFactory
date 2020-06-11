#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClientInterface.h"

#include "FactorsFactoryClientAdapter.generated.h"

class NFactorUnitInterface;
class UNFactorUnitAdapter;
class NFactorStateInterface;
class NFactorInterface;
class NTimelineInterface;
class NFactorsFactoryClientInterface;
class UNFactorDecorator;

UCLASS(BlueprintType)
class NANSFACTORSFACTORYUE4_API UNFactorsFactoryClientAdapter : public UObject, public NFactorsFactoryClientInterface
{
	GENERATED_BODY()

public:
	UNFactorsFactoryClientAdapter();
	virtual void Init();
	UNFactorUnitAdapter* CreateFactorUnit(const FName& FactorName, const UClass* Class);
	virtual void CreateFactor(FName FactorName, TSharedPtr<NTimelineInterface> Timeline, const UClass* FactorClass);

	// BEGIN NFactorsFactoryClientInterface override
	virtual void CreateFactor(FName FactorName, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void CreateFactor(TArray<FName> FactorNames, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) override;
	virtual void RemoveFactor(FName FactorName) override;
	virtual void GetState(FName FactorName, NFactorStateInterface& State) override;
	virtual TArray<NFactorStateInterface*> GetStates(TArray<FName> FactorNames, NFactorStateInterface* StateTemplate) override;
	virtual void AddFactorUnit(FName FactorName, TSharedPtr<NFactorUnitInterface> FactorUnit) override;
	virtual void SetDebug(const TArray<FName> FactorNames, bool bDebug) override;
	// END NFactorsFactoryClientInterface override

	// BEGIN UObject override
	virtual void Serialize(FArchive& Ar);
	// END UObject override
protected:
	TSharedPtr<NFactorsFactoryClientInterface> Client;
	UPROPERTY(SkipSerialization)
	TMap<FName, UNFactorDecorator*> UEFactors;

	/**
	 * This parameter is usefull only for serialization,
	 * it allows to keep the same factor list order
	 * for save & load to maintain data serialization's order consistency.
	 */
	UPROPERTY(SaveGame)
	TArray<FName> UEFactorsNames;
};
