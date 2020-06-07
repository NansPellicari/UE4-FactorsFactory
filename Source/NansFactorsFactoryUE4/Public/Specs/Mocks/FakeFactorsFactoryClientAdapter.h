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
	TMap<FName, UNFactorStackDecorator*> GetUEStacks()
	{
		return UEStacks;
	}
	void Clear()
	{
		auto Spy = GetSpy();
		Spy->Clear();
		Client.Reset();
	}
};
