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

#include "CoreMinimal.h"
#include "Factor/FactorDecorator.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "FactorsFactoryClientAdapter.generated.h"

class NFactorUnitInterface;
class UNFactorUnitView;
class NFactorStateInterface;
class NFactorInterface;
class NTimelineInterface;
class NFactorsFactoryClientInterface;
class UNOperatorProviderBase;
struct FConfiguredTimeline;

// TODO refacto: this class is really usefull?
// TODO This class shoud be removed like all Adapters
UCLASS(BlueprintType)
class NANSFACTORSFACTORYUE4_API UNFactorsFactoryClientAdapter : public UObject
{
	GENERATED_BODY()
public:
	UNFactorsFactoryClientAdapter();

	UFUNCTION(BlueprintCallable, Category = "FactorsFactory")
	virtual void Init();
	UNFactorUnitView* CreateFactorUnit(const FName& FactorName, const UClass* Class);
	int32 AddFactorUnit(FName FactorName, UNFactorUnitView* FactorUnit);
	UNOperatorProviderBase* CreateOperatorProvider(const FName& FactorName, const UClass* Class);
	void CreateFactor(const TArray<FName> FactorNames,
		FConfiguredTimeline Timeline,
		const UClass* FactorClass = UNFactorDecorator::StaticClass());
	void CreateFactor(
		const FName& FactorName, FConfiguredTimeline Timeline, const UClass* FactorClass = UNFactorDecorator::StaticClass());

	UNFactorUnitView* GetFactorUnit(FName FactorName, int32 FactorIndex);

	bool HasFactor(const FName& FactorName) const;
	void RemoveFactor(const FName& FactorName);
	void GetState(FName FactorName, NFactorStateInterface& State);
	TArray<NFactorStateInterface*> GetStates(TArray<FName> FactorNames, NFactorStateInterface* StateTemplate);
	void SetDebug(const TArray<FName> FactorNames, bool bDebug);

	// BEGIN UObject override
	virtual void Serialize(FArchive& Ar) override;
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
