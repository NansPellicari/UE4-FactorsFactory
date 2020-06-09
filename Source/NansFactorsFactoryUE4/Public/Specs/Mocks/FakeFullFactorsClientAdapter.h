#pragma once

#include "CoreMinimal.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"
#include "NansFactorsFactoryUE4/Public/FactorsFactoryClientAdapter.h"
#include "NansFactorsFactoryUE4/Public/Specs/Mocks/SpyFactorsFactoryClient.h"

#include "FakeFullFactorsClientAdapter.generated.h"

// Just to simplify the Init() and avoid GameInstance dependency
UCLASS(NotBlueprintable, NotPlaceable)
class UFakeFullFactorsClientAdapter : public UNFactorsFactoryClientAdapter
{
	GENERATED_BODY()
public:
	UFakeFullFactorsClientAdapter() {}
	virtual void Init() override
	{
		Client = MakeShareable(new NFactorsFactoryClient());
	}
	TMap<FName, UNFactorDecorator*> GetUEFactors()
	{
		return UEFactors;
	}
	void Clear()
	{
		Client.Reset();
	}
};
