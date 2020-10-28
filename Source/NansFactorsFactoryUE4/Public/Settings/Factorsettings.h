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

	~FNFactorSettings()
	{
		Name = NAME_None;
		FactorClass = nullptr;
		bIsReadOnly = false;
		ReadOnlyReason = FText::GetEmpty();
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FactorsFactors")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FactorsFactors")
	TSubclassOf<UNFactorDecorator> FactorClass = UNFactorDecorator::StaticClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FactorsFactors")
	FConfiguredTimeline Timeline;

	/**
	 * TODO implement this
	 * This if you want this factor only updatable in c++ code
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FactorsFactors|Access")
	bool bIsReadOnly = false;

	/**
	 * TODO implements this
	 * Give a reason why, this to inform designer in log when they tried
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FactorsFactors|Access", Meta = (EditCondition = "bIsReadOnly"))
	FText ReadOnlyReason;
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

	static void GetConfigs(TArray<TSharedPtr<FNFactorSettings>>& ShareableNames)
	{
		const UFactorSettings* StaticObject = GetDefault<UFactorSettings>();
		for (FNFactorSettings Settings : StaticObject->CategoryNames)
		{
			ShareableNames.Add(MakeShareable(new FNFactorSettings(Settings)));
		}
	};
	static void GetFactorNames(TArray<TSharedPtr<FName>>& ShareableNames)
	{
		const UFactorSettings* StaticObject = GetDefault<UFactorSettings>();
		for (const FNFactorSettings& Settings : StaticObject->CategoryNames)
		{
			ShareableNames.Add(MakeShareable(new FName(Settings.Name)));
		}
	};
};
