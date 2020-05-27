#pragma once

#include "CoreMinimal.h"
#include "FactorClientAdapter.h"
#include "UObject/ObjectMacros.h"

#include "FactorsFactoryGameInstance.generated.h"

UINTERFACE()
class NANSFACTORSFACTORYUE4_API UNFactorsFactoryGameInstance : public UInterface
{
    GENERATED_BODY()
};

class NANSFACTORSFACTORYUE4_API INFactorsFactoryGameInstance
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "FactorsFactory")
    UNFactorClientAdapter* GetFactorsFactoryClient() const;
};
