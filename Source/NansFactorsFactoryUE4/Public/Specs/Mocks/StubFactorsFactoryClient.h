#pragma once

#include "CoreMinimal.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClientInterface.h"

class StubFactorsFactoryClient : public NFactorsFactoryClientInterface
{
public:
	TMap<FString, uint32> MethodCalls;

	StubFactorsFactoryClient() {}
	virtual ~StubFactorsFactoryClient() {}
	virtual void CreateStack(FName StackName, TSharedPtr<NTimelineInterface> Timeline) override {}
	virtual void CreateStack(TArray<FName> StackNames, TSharedPtr<NTimelineInterface> Timeline) override {}
	virtual void AddStack(TSharedPtr<NFactorStackInterface> Stack) override {}
	virtual void RemoveStack(FName StackName) override {}
	virtual void GetState(FName StackName, NFactorStateInterface& State) override {}
	virtual TArray<NFactorStateInterface*> GetStates(TArray<FName> StackNames, NFactorStateInterface* StateTemplate) override
	{
		return {};
	}
	virtual void AddFactor(FName StackName, TSharedPtr<NFactorInterface> Factor) override {}
	virtual void AddFactor(TArray<FName> StackNames, TSharedPtr<NFactorInterface> Factor) override {}
	virtual void SetDebug(const TArray<FName> StackNames, bool bDebug) override {}
};
