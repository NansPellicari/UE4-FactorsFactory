#pragma once

#include "CoreMinimal.h"
#include "FactorsFactoryClientInterface.h"

class NFactorStack;
class NFactorState;
class NFactorInterface;
class NTimelineInterface;

class NANSFACTORSFACTORYCORE_API NFactorsFactoryClient : public NFactorsFactoryClientInterface
{
public:
	virtual ~NFactorsFactoryClient() {}
	virtual void CreateStack(FName StackName, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void CreateStack(TArray<FName> StackNames, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void RemoveStack(FName StackName) override;
	virtual NFactorState* GetState(FName StackName) override;
	virtual TArray<NFactorState*> GetStates(TArray<FName> StackNames) override;
	virtual void AddFactor(FName StackName, TSharedPtr<NFactorInterface> Factor) override;
	virtual void AddFactor(TArray<FName> StackNames, TSharedPtr<NFactorInterface> Factor) override;
	virtual void SetDebug(const TArray<FName> StackNames, bool bDebug) override;

protected:
	TMap<FName, TSharedPtr<NFactorStack>> StacksList;

private:
};
