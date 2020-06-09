#pragma once

#include "CoreMinimal.h"

class NFactorInterface;
class NFactorUnitInterface;
class NFactorStateInterface;
class NTimelineInterface;

class NANSFACTORSFACTORYCORE_API NFactorInterface
{
public:
	virtual void Clear() = 0;
	virtual void SetName(FName _Name) = 0;
	virtual FName GetName() const = 0;
	virtual TSharedPtr<NTimelineInterface> GetTimeline() const = 0;
	virtual float GetTime() const = 0;
	virtual TSharedRef<NFactorUnitInterface> GetFactorUnit(uint32 Key) const = 0;
	virtual TArray<TSharedPtr<NFactorUnitInterface>> GetFactors() const = 0;
	virtual void AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit) = 0;
	virtual bool HasFlag(FString Flag) const = 0;
	virtual bool GetFlag(FString Flag) const = 0;
	virtual void SetFlag(FString Flag, bool Value) = 0;
	virtual void Debug(bool _bDebug) = 0;
	virtual void SupplyStateWithCurrentData(NFactorStateInterface& State) = 0;
};
