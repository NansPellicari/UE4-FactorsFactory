#pragma once

#include "CoreMinimal.h"

class NFactorStack;
class NFactorState;
class INFactorInterface;
class NTimeline;

class NANSFACTORSFACTORYCORE_API NFactorsFactoryClient
{
public:
	void CreateStack(FName StackName, TSharedPtr<NTimeline> Timeline);
	void CreateStack(TArray<FName> StackNames, TSharedPtr<NTimeline> Timeline);
	void RemoveStack(FName StackName);
	NFactorState* GetState(FName StackName);
	TArray<NFactorState*> GetStates(TArray<FName> StackNames);
	void AddFactor(FName StackName, TSharedPtr<INFactorInterface> Factor);
	void AddFactor(TArray<FName> StackNames, TSharedPtr<INFactorInterface> Factor);
	void SetDebug(const TArray<FName> StackNames, bool bDebug);

protected:
	TMap<FName, TSharedPtr<NFactorStack>> StacksList;

private:
};
