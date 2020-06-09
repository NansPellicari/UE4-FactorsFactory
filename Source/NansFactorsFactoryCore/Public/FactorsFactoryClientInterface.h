#pragma once

#include "CoreMinimal.h"

class NFactorInterface;
class NFactorUnitInterface;
class NFactorStateInterface;
class NTimelineInterface;

class NANSFACTORSFACTORYCORE_API NFactorsFactoryClientInterface
{
public:
	virtual void CreateFactor(FName FactorName, TSharedPtr<NTimelineInterface> Timeline) = 0;
	virtual void CreateFactor(TArray<FName> FactorNames, TSharedPtr<NTimelineInterface> Timeline) = 0;
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) = 0;
	virtual void RemoveFactor(FName FactorName) = 0;
	virtual void GetState(FName FactorName, NFactorStateInterface& State) = 0;
	virtual TArray<NFactorStateInterface*> GetStates(TArray<FName> FactorNames, NFactorStateInterface* StateTemplate) = 0;
	virtual void AddFactorUnit(FName FactorName, TSharedPtr<NFactorUnitInterface> FactorUnit) = 0;
	virtual void SetDebug(const TArray<FName> FactorNames, bool bDebug) = 0;
};
