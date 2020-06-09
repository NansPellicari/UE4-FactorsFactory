#pragma once

#include "CoreMinimal.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClientInterface.h"

class StubFactorsFactoryClient : public NFactorsFactoryClientInterface
{
public:
	TMap<FString, uint32> MethodCalls;

	StubFactorsFactoryClient() {}
	virtual ~StubFactorsFactoryClient() {}
	virtual void CreateFactor(FName FactorName, TSharedPtr<NTimelineInterface> Timeline) override {}
	virtual void CreateFactor(TArray<FName> FactorNames, TSharedPtr<NTimelineInterface> Timeline) override {}
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) override {}
	virtual void RemoveFactor(FName FactorName) override {}
	virtual void GetState(FName FactorName, NFactorStateInterface& State) override {}
	virtual TArray<NFactorStateInterface*> GetStates(TArray<FName> FactorNames, NFactorStateInterface* StateTemplate) override
	{
		return {};
	}
	virtual void AddFactorUnit(FName FactorName, TSharedPtr<NFactorUnitInterface> FactorUnit) override {}
	virtual void SetDebug(const TArray<FName> FactorNames, bool bDebug) override {}
};
