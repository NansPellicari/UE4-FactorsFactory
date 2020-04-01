#pragma once

#include "CoreMinimal.h"
#include "DifficultyClientAdapter.h"
#include "UObject/ObjectMacros.h"

#include "DifficultySystemGameInstance.generated.h"

UINTERFACE()
class NANSDIFFICULTYSYSTEMUE4_API UNDifficultySystemGameInstance : public UInterface
{
    GENERATED_BODY()
};

class NANSDIFFICULTYSYSTEMUE4_API INDifficultySystemGameInstance
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "DifficultySystem")
    UNDifficultyClientAdapter* GetDifficultySystemClient() const;
};
