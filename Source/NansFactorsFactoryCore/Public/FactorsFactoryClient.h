#pragma once

#include "CoreMinimal.h"
#include "FactorsFactoryClientInterface.h"

class NFactorInterface;
class NFactorUnitInterface;
class NFactorStateInterface;
class NTimelineInterface;

class NANSFACTORSFACTORYCORE_API NFactorsFactoryClient : public NFactorsFactoryClientInterface
{
public:
	virtual ~NFactorsFactoryClient() {}
	virtual void CreateFactor(FName FactorName, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void CreateFactor(TArray<FName> FactorNames, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) override;
	virtual void RemoveFactor(FName FactorName) override;
	virtual void GetState(FName FactorName, NFactorStateInterface& State) override;
	virtual TArray<NFactorStateInterface*> GetStates(TArray<FName> FactorNames, NFactorStateInterface* StateTemplate) override;
	virtual void AddFactorUnit(FName FactorName, TSharedPtr<NFactorUnitInterface> FactorUnit) override;
	virtual void SetDebug(const TArray<FName> FactorNames, bool bDebug) override;

protected:
	TMap<FName, TSharedPtr<NFactorInterface>> FactorsList;

private:
};
