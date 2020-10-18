// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "Config/TimelineConfig.h"
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
	FConfiguredTimeline Timeline;
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
