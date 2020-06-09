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
	virtual UNFactorsFactoryClientAdapter* GetFactorsFactoryClient() const;
};
