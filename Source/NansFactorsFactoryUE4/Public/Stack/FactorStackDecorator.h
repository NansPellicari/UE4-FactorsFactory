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
#include "NansFactorsFactoryCore/Public/FactorStackInterface.h"

#include "FactorStackDecorator.generated.h"

UCLASS()
class NANSFACTORSFACTORYUE4_API UNFactorStackDecorator : public UObject, public NFactorStackInterface
{
	GENERATED_BODY()
public:
	UNFactorStackDecorator() {}
	void Init(FName _Name, TSharedPtr<NTimelineInterface> _Timeline);
	virtual void Reset() override;
	virtual void SetName(FName _Name) override;
	virtual FName GetName() const override;
	virtual float GetTime() const override;
	virtual TSharedRef<NFactorInterface> GetFactor(uint32 Key) const override;
	virtual TArray<TSharedPtr<NFactorInterface>> GetFactors() const override;
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) override;
	virtual bool HasFlag(FString Flag) const override;
	virtual bool GetFlag(FString Flag) const override;
	virtual void SetFlag(FString Flag, bool Value) override;
	virtual void Debug(bool _bDebug) override;
	virtual void SupplyStateWithCurrentData(NFactorStateInterface& State) override;

protected:
	TSharedPtr<NFactorStackInterface> Stack;
	UPROPERTY()
	TArray<UNFactorAdapterAbstract*> UEFactors;
};
