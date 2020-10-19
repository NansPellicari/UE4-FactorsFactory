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
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClientInterface.h"

#include "FactorsFactoryClientAdapter.generated.h"

class NFactorUnitInterface;
class UNFactorUnitAdapter;
class NFactorStateInterface;
class NFactorInterface;
class NTimelineInterface;
class NFactorsFactoryClientInterface;
class UNFactorDecorator;

UCLASS(BlueprintType)
class NANSFACTORSFACTORYUE4_API UNFactorsFactoryClientAdapter : public UObject, public NFactorsFactoryClientInterface
{
	GENERATED_BODY()

public:
	UNFactorsFactoryClientAdapter();

	UFUNCTION(BlueprintCallable, Category = "FactorsFactory")
	virtual void Init();
	UNFactorUnitAdapter* CreateFactorUnit(const FName& FactorName, const UClass* Class);
	virtual void CreateFactor(FName FactorName, TSharedPtr<NTimelineInterface> Timeline, const UClass* FactorClass);

	// BEGIN NFactorsFactoryClientInterface override
	virtual void CreateFactor(FName FactorName, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void CreateFactor(TArray<FName> FactorNames, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) override;
	virtual void RemoveFactor(FName FactorName) override;
	virtual void GetState(FName FactorName, NFactorStateInterface& State) override;
	virtual TArray<NFactorStateInterface*> GetStates(TArray<FName> FactorNames, NFactorStateInterface* StateTemplate) override;
	virtual int32 AddFactorUnit(FName FactorName, TSharedPtr<NFactorUnitInterface> FactorUnit) override;
	virtual TSharedPtr<NFactorUnitInterface> GetFactorUnit(FName FactorName, int32 Key) override;
	virtual void SetDebug(const TArray<FName> FactorNames, bool bDebug) override;
	// END NFactorsFactoryClientInterface override

	// BEGIN UObject override
	virtual void Serialize(FArchive& Ar);
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
