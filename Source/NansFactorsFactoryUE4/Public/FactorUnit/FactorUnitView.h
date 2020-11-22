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
#include "NansTimelineSystemUE4/Public/Event/EventView.h"
#include "Operator/OperatorProviders.h"

class NEventInterface;
class NFactorOperatorInterface;
class NFactorUnit;
class NUnrealFactorUnitProxy;

#include "FactorUnitView.generated.h"

// TODO Create a PostEditProperty listener to change embed factor data
UCLASS(Blueprintable)
class NANSFACTORSFACTORYUE4_API UNFactorUnitView : public UObject, public NFactorUnitInterface
{
	GENERATED_BODY()
public:
	friend class NUnrealFactorUnitProxy;

	UNFactorUnitView() {}

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Unit")
	float FactorUnitValue = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Unit")
	float Duration = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Unit")
	float Delay = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Unit")
	FName Reason = NAME_None;

	// @formatter:off
	UFUNCTION(meta = (BlueprintInternalUseOnly = "true"), BlueprintCallable, Category = "FactorsFactory|Unit")
	virtual void SetOperatorProvider(UNOperatorProviderBase* _OperatorProvider);
	// @formatter:on

	UPROPERTY()
	UNOperatorProviderBase* OperatorProvider;

	/** This is used as a constructor */
	virtual void Init(TSharedPtr<NEventInterface> Event);

	virtual TSharedPtr<NFactorOperatorInterface> GetConfiguredOperator();

	// BEGIN NFactorUnitInterface override
	virtual TSharedPtr<NEventInterface> GetEvent() override;
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() override;
	virtual void SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator) override;
	virtual float GetFactorUnitValue() const override;
	virtual FName GetReason() const override;
	virtual bool IsActivated() const override;
	virtual void SetFactorUnitValue(float _Value) override;
	virtual const FString GetUID() const override;
	virtual void Activate(bool _bIsActivated) override;
	virtual void PreDelete() override {}
	virtual void Archive(FArchive& Ar) override {}
	// END NFactorUnitInterface override

	// BEGIN UObject override
	virtual void Serialize(FArchive& Ar) override;
	// END UObject override

protected:

	TSharedPtr<NFactorUnit> FactorUnit;
};
