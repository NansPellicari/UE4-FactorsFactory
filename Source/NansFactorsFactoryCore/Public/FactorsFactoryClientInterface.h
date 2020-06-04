#pragma once

#include "CoreMinimal.h"

class NFactorStackInterface;
class NFactorInterface;
class NFactorStateInterface;
class NTimelineInterface;

class NANSFACTORSFACTORYCORE_API NFactorsFactoryClientInterface
{
public:
	virtual void CreateStack(FName StackName, TSharedPtr<NTimelineInterface> Timeline) = 0;
	virtual void CreateStack(TArray<FName> StackNames, TSharedPtr<NTimelineInterface> Timeline) = 0;
	virtual void AddStack(TSharedPtr<NFactorStackInterface> Stack) = 0;
	virtual void RemoveStack(FName StackName) = 0;
	virtual void GetState(FName StackName, NFactorStateInterface& State) = 0;
	virtual TArray<NFactorStateInterface*> GetStates(TArray<FName> StackNames, NFactorStateInterface* StateTemplate) = 0;
	virtual void AddFactor(FName StackName, TSharedPtr<NFactorInterface> Factor) = 0;
	// TODO remove this !!!
	virtual void AddFactor(TArray<FName> StackNames, TSharedPtr<NFactorInterface> Factor) = 0;
	virtual void SetDebug(const TArray<FName> StackNames, bool bDebug) = 0;
};
