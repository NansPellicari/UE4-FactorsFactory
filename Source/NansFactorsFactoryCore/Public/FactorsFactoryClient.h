#pragma once

#include "CoreMinimal.h"

class NFactorStack;
class NFactorState;
class INFactorInterface;
class NTimelineInterface;

class NANSFACTORSFACTORYCORE_API NFactorsFactoryClientInterface
{
	virtual void CreateStack(FName StackName, TSharedPtr<NTimelineInterface> Timeline) = 0;
	virtual void CreateStack(TArray<FName> StackNames, TSharedPtr<NTimelineInterface> Timeline) = 0;
	virtual void RemoveStack(FName StackName) = 0;
	virtual NFactorState* GetState(FName StackName) = 0;
	virtual TArray<NFactorState*> GetStates(TArray<FName> StackNames) = 0;
	virtual void AddFactor(FName StackName, TSharedPtr<INFactorInterface> Factor) = 0;
	virtual void AddFactor(TArray<FName> StackNames, TSharedPtr<INFactorInterface> Factor) = 0;
	virtual void SetDebug(const TArray<FName> StackNames, bool bDebug) = 0;
};

class NANSFACTORSFACTORYCORE_API NFactorsFactoryClient : public NFactorsFactoryClientInterface
{
public:
	virtual ~NFactorsFactoryClient() {}
	virtual void CreateStack(FName StackName, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void CreateStack(TArray<FName> StackNames, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void RemoveStack(FName StackName) override;
	virtual NFactorState* GetState(FName StackName) override;
	virtual TArray<NFactorState*> GetStates(TArray<FName> StackNames) override;
	virtual void AddFactor(FName StackName, TSharedPtr<INFactorInterface> Factor) override;
	virtual void AddFactor(TArray<FName> StackNames, TSharedPtr<INFactorInterface> Factor) override;
	virtual void SetDebug(const TArray<FName> StackNames, bool bDebug) override;

protected:
	TMap<FName, TSharedPtr<NFactorStack>> StacksList;

private:
};
