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
#include "Factor/UnrealFactorProxy.h"
#include "FactorInterface.h"
#include "NansFactorsFactoryCore/Public/NullFactorUnit.h"

class StubNullUnrealFactorProxy : public NUnrealFactorProxy
{
public:
	StubNullUnrealFactorProxy(UNFactorDecorator& _Factor) : NUnrealFactorProxy(_Factor) {}

	virtual void Clear() override {}
	virtual void SetName(FName _Name) override {}
	virtual FName GetName() const override
	{
		return NAME_None;
	}
	virtual TSharedPtr<NTimelineInterface> GetTimeline() const override
	{
		return nullptr;
	}

	virtual float GetTime() const override
	{
		return 0.f;
	}
	virtual TSharedPtr<NFactorUnitInterface> GetFactorUnit(uint32 Key) const override
	{
		static NFactorUnitInterface* NullObj = new NNullFactorUnit();
		return MakeShareable(NullObj);
	}
	virtual TArray<TSharedPtr<NFactorUnitInterface>> GetFactors() const override
	{
		return {};
	}
	virtual void AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit) override {}
	virtual bool HasStateFlag(FString Flag) const override
	{
		return false;
	}
	virtual bool GetStateFlag(FString Flag) const override
	{
		return false;
	}
	virtual void SetStateFlag(FString Flag, bool Value) override {}
	virtual void Debug(bool _bDebug) override {}
	virtual void SupplyStateWithCurrentData(NFactorStateInterface& State) override {}
	virtual UNFactorDecorator* GetUnrealObject() const
	{
		return nullptr;
	}
};
