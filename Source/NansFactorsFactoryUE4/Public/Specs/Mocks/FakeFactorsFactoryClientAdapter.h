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
#include "NansFactorsFactoryUE4/Public/FactorsFactoryClientAdapter.h"
#include "NansFactorsFactoryUE4/Public/Specs/Mocks/SpyFactorsFactoryClient.h"

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
