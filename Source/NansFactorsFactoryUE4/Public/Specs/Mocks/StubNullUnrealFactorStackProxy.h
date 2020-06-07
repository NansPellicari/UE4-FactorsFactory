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
#include "FactorStackInterface.h"
#include "NansFactorsFactoryCore/Public/NullFactor.h"
#include "Stack/FactorStackDecorator.h"
#include "Stack/UnrealFactorStackProxy.h"

class StubNullUnrealFactorStackProxy : public NUnrealFactorStackProxy
{
public:
	StubNullUnrealFactorStackProxy(UNFactorStackDecorator& _Stack) : NUnrealFactorStackProxy(_Stack) {}

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
	virtual TSharedRef<NFactorInterface> GetFactor(uint32 Key) const override
	{
		static NFactorInterface* NullObj = new NNullFactor();
		return MakeShareable(NullObj);
	}
	virtual TArray<TSharedPtr<NFactorInterface>> GetFactors() const override
	{
		return {};
	}
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) override {}
	virtual bool HasFlag(FString Flag) const override
	{
		return false;
	}
	virtual bool GetFlag(FString Flag) const override
	{
		return false;
	}
	virtual void SetFlag(FString Flag, bool Value) override {}
	virtual void Debug(bool _bDebug) override {}
	virtual void SupplyStateWithCurrentData(NFactorStateInterface& State) override {}
	virtual UNFactorStackDecorator* GetUnrealObject() const
	{
		return nullptr;
	}
};
