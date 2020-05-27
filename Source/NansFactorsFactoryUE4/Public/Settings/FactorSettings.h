// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"

#include "FactorSettings.generated.h"

USTRUCT(BlueprintType)
struct FNFactorSettings
{
    GENERATED_USTRUCT_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FactorCategory)
    FName Name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FactorCategory)
    TArray<FName> CollectionsNames;
};

/**
 * This allow to
 * Thanks to: https://forums.unrealengine.com/development-discussion/c-gameplay-programming/1503868-adding-a-custom-ini-file
 */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Factor Category"))
class NANSFACTORSFACTORYUE4_API UFactorSettings : public UDeveloperSettings
{
    GENERATED_BODY()
public:
    UPROPERTY(config, EditAnywhere)
    TArray<FNFactorSettings> CategoryNames;

    static void GetNames(TArray<TSharedPtr<FName>>& ShareableNames)
    {
        static const UFactorSettings* StaticObject = GetDefault<UFactorSettings>();
        for (FNFactorSettings Settings : StaticObject->CategoryNames)
        {
            ShareableNames.Add(MakeShareable(new FName(Settings.Name)));
        }
    };
};
