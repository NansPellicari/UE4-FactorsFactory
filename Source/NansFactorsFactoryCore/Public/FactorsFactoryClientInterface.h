#pragma once

#include "CoreMinimal.h"
#include "FactorInterface.h"
#include "FactorStack.h"	// TODO Should be replaced by interface
#include "FactorState.h"	// TODO Should be replaced by interface
#include "NansTimelineSystemCore/Public/TimelineInterface.h"

class NANSFACTORSFACTORYCORE_API NFactorsFactoryClientInterface
{
public:
	virtual void CreateStack(FName StackName, TSharedPtr<NTimelineInterface> Timeline) = 0;
	virtual void CreateStack(TArray<FName> StackNames, TSharedPtr<NTimelineInterface> Timeline) = 0;
	virtual void RemoveStack(FName StackName) = 0;
	virtual NFactorState* GetState(FName StackName) = 0;
	virtual TArray<NFactorState*> GetStates(TArray<FName> StackNames) = 0;
	virtual void AddFactor(FName StackName, TSharedPtr<NFactorInterface> Factor) = 0;
	virtual void AddFactor(TArray<FName> StackNames, TSharedPtr<NFactorInterface> Factor) = 0;
	virtual void SetDebug(const TArray<FName> StackNames, bool bDebug) = 0;
};
