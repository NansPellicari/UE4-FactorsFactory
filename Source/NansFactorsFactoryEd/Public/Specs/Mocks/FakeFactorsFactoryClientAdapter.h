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
#include "NansFactorsFactoryCore/Public/NullFactorUnit.h"
#include "NansFactorsFactoryUE4/Public/FactorUnit/FactorUnitView.h"
#include "NansFactorsFactoryUE4/Public/FactorsFactoryClientAdapter.h"
#include "NansTimelineSystemUE4/Public/Event/EventView.h"
#include "Specs/Mocks/SpyFactorsFactoryClient.h"

#include "FakeFactorsFactoryClientAdapter.generated.h"

// Just to simplify the Init() and avoid GameInstance dependency
UCLASS(NotBlueprintable, NotPlaceable)
class UFakeFactorsFactoryClientAdapter : public UNFactorsFactoryClientAdapter
{
	GENERATED_BODY()
public:
	UFakeFactorsFactoryClientAdapter() {}
	virtual void Init() override
	{
		Client = MakeShareable(new SpyFactorsFactoryClient());
	}
	SpyFactorsFactoryClient* GetSpy()
	{
		return dynamic_cast<SpyFactorsFactoryClient*>(Client.Get());
	}
	TMap<FName, UNFactorDecorator*> GetUEFactors()
	{
		return UEFactors;
	}
	void Clear()
	{
		auto Spy = GetSpy();
		Spy->Clear();
		Client.Reset();
	}
};

UCLASS(NotBlueprintable, NotPlaceable)
class UNNullFactorUnit : public UNFactorUnitView
{
	GENERATED_BODY()
public:
	UNNullFactorUnit() {}

	virtual void Init(UNEventView* _Event) {}
	virtual void Init(TSharedPtr<NEventInterface> _Event) {}

	virtual bool IsActivated() const override
	{
		return false;
	}
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() override
	{
		return nullptr;
	}
	virtual void SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator) override {}
	virtual float GetFactorUnitValue() const override
	{
		return 0.f;
	}
	virtual void SetFactorUnitValue(float _Value) override {}
	virtual FName GetReason() const override
	{
		return NAME_None;
	}
	virtual const FString GetUID() const override
	{
		static const FString ID = "";
		return ID;
	}
	virtual TSharedPtr<NEventInterface> GetEvent() override
	{
		return nullptr;
	}
	virtual void Activate(bool _bIsActivated) override {}

	virtual void PreDelete() override {}

	virtual void Archive(FArchive& Ar) override {}
};
