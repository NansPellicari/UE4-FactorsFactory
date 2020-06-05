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

#include "Attribute/FactorStackAttribute.h"
#include "CoreMinimal.h"
#include "NansFactorsFactoryCore/Public/FactorInterface.h"

class NEventInterface;
class FactorOperatorInterface;
class UNFactorEventDecorator;
class NFactor;

#include "FactorAdapterAbstract.generated.h"

UCLASS(Abstract, Blueprintable)
class NANSFACTORSFACTORYUE4_API UNFactorAdapterAbstract : public UObject, public NFactorInterface
{
	GENERATED_BODY()
public:
	UNFactorAdapterAbstract() {}

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
	float FactorValue = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
	float Duration = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
	float Delay = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
	FName Reason = NAME_None;

	virtual void Init();

	virtual TSharedPtr<NEventInterface> GetEvent() override;
	virtual TSharedPtr<FactorOperatorInterface> GetConfiguredOperator() const;
	virtual TSharedPtr<FactorOperatorInterface> GetOperator() const override;
	virtual float GetFactorValue() const override;
	virtual FName GetReason() const override;
	virtual bool IsActivated() const override;
	virtual uint32 GetUID() const override;

protected:
	TSharedPtr<NFactor> Factor;

	UPROPERTY()
	UNFactorEventDecorator* Event;
};
