#pragma once

#include "Attribute/FactorAttribute.h"
#include "CoreMinimal.h"
#include "FactorsFactoryClientAdapter.h"
#include "UObject/ObjectMacros.h"

#include "FactorsFactoryGameInstance.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UNFactorsFactoryGameInstance : public UInterface
{
	GENERATED_BODY()
};

class NANSFACTORSFACTORYUE4_API INFactorsFactoryGameInstance
{
	GENERATED_BODY()
public:
	/**
	 * A blueprint overridable fn to get the Actual UNFactorsFactoryClientAdapter
	 */
	UFUNCTION(
		BlueprintCallable, BlueprintNativeEvent, meta = (DisplayName = "Get the FactorsFactory client"), Category = "NansTimeline")
	UNFactorsFactoryClientAdapter* GetFactorsFactoryClient() const;
};
