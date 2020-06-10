// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Factor/FactorDecorator.h"

#include "FactorSettings.generated.h"

USTRUCT(BlueprintType)
struct FNFactorSettings
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FactorsFactors")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FactorsFactors")
	TSubclassOf<UNFactorDecorator> FactorClass = UNFactorDecorator::StaticClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FactorsFactors")
	FName TimelineName;
};

/**
 * This allow to
 *
 * Thanks to: https://forums.unrealengine.com/development-discussion/c-gameplay-programming/1503868-adding-a-custom-ini-file
 *
 * @see https://github.com/NansPellicari/UE4-HowTo-CustomPin to get more examples.
 */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Factors Factors"))
class NANSFACTORSFACTORYUE4_API UFactorSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(config, EditAnywhere)
	TArray<FNFactorSettings> CategoryNames;

	static void GetConfigs(TArray<FNFactorSettings>& ShareableNames)
	{
		static const UFactorSettings* StaticObject = GetDefault<UFactorSettings>();
		for (FNFactorSettings Settings : StaticObject->CategoryNames)
		{
			ShareableNames.Add(Settings);
		}
	};
};
