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

#include "Attribute/FactorAttribute.h"
#include "CoreMinimal.h"
#include "NansFactorsFactoryCore/Public/FactorUnitInterface.h"
#include "NansTimelineSystemUE4/Public/Event/EventDecorator.h"
#include "Operator/OperatorProviders.h"

class NEventInterface;
class NFactorOperatorInterface;
class NFactorUnit;

#include "FactorUnitAdapter.generated.h"

UCLASS(Blueprintable)
class NANSFACTORSFACTORYUE4_API UNFactorUnitAdapter : public UObject, public NFactorUnitInterface
{
	GENERATED_BODY()
public:
	UNFactorUnitAdapter() {}

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Unit")
	TSubclassOf<UNEventDecorator> EventClass = UNEventDecorator::StaticClass();

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Unit")
	TSubclassOf<UNOperatorProviderBase> OperatorProvider = UNNullOperatorProvider::StaticClass();

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Unit")
	float FactorUnitValue = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Unit")
	float Duration = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Unit")
	float Delay = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Unit")
	FName Reason = NAME_None;

	virtual void Init();
	virtual void Init(UNEventDecorator* _Event);
	virtual TSharedPtr<NFactorOperatorInterface> GetConfiguredOperator();

	UFUNCTION(BlueprintCallable, Category = "FactorsFactory|Unit")
	virtual UNEventDecorator* GetEventDecorator();

	// BEGIN NFactorUnitInterface override
	virtual TSharedPtr<NEventInterface> GetEvent() override;
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() const override;
	virtual void SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator) override;
	virtual float GetFactorUnitValue() const override;
	virtual FName GetReason() const override;
	virtual bool IsActivated() const override;
	virtual void SetFactorUnitValue(float _Value) override;
	virtual const FString GetUID() const override;
	// END NFactorUnitInterface override

	// BEGIN UObject override
	virtual void Serialize(FArchive& Ar);
	// END UObject override

protected:
	TSharedPtr<NFactorUnit> FactorUnit;

	UPROPERTY(SkipSerialization)
	UNEventDecorator* Event;
};
