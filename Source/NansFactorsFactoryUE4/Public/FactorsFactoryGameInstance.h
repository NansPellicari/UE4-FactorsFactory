#pragma once

#include "Attribute/FactorStackAttribute.h"
#include "CoreMinimal.h"
#include "FactorClientAdapter.h"
#include "UObject/ObjectMacros.h"

#include "FactorsFactoryGameInstance.generated.h"

UINTERFACE()
class UNFactorsFactoryGameInstance : public UInterface
{
	GENERATED_BODY()
};

class NANSFACTORSFACTORYUE4_API INFactorsFactoryGameInstance
{
	GENERATED_BODY()
public:
	virtual UNFactorClientAdapter* GetFactorsFactoryClient() const;
};
