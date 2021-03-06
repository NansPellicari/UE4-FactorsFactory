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
#include "FactorInterface.h"

class UNFactorDecorator;

class NANSFACTORSFACTORYUE4_API NUnrealFactorProxy : public NFactorInterface
{
public:
	UNFactorDecorator& Factor;
	NUnrealFactorProxy(UNFactorDecorator& _Factor) : Factor(_Factor) {}
	virtual void Clear() override;
	virtual void SetName(FName _Name) override;
	virtual FName GetName() const override;
	virtual TSharedPtr<NTimelineInterface> GetTimeline() const override;
	virtual float GetTime() const override;
	virtual TSharedPtr<NFactorUnitInterface> GetFactorUnit(uint32 Key) const override;
	virtual TArray<TSharedPtr<NFactorUnitInterface>> GetFactors() const override;
	virtual int32 AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit) override;
	virtual bool HasStateFlag(FString Flag) const override;
	virtual bool GetStateFlag(FString Flag) const override;
	virtual void SetStateFlag(FString Flag, bool Value) override;
	virtual void RemoveStateFlag(FString Flag) override;
	virtual void AddFlag(ENFactorFlag Flag) override;
	virtual bool HasFlag(ENFactorFlag Flag) const override;
	virtual void RemoveFlag(ENFactorFlag Flag) override;
	virtual void Debug(bool _bDebug) override;
	virtual void SupplyStateWithCurrentData(NFactorStateInterface& State) override;
	virtual void PreDelete() override;
	virtual void Archive(FArchive& Ar) override;
};
