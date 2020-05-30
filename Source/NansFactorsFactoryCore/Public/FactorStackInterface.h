#pragma once

#include "CoreMinimal.h"

class NFactorStackInterface;
class NFactorInterface;
class NFactorStateInterface;
class NTimelineInterface;

class NANSFACTORSFACTORYCORE_API NFactorStackInterface
{
public:
	virtual void Reset() = 0;
	virtual void SetName(FName _Name) = 0;
	virtual FName GetName() const = 0;
	virtual float GetTime() const = 0;
	virtual TSharedRef<NFactorInterface> GetFactor(uint32 Key) const = 0;
	virtual TArray<TSharedPtr<NFactorInterface>> GetFactors() const = 0;
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) = 0;
	virtual bool HasFlag(FString Flag) const = 0;
	virtual bool GetFlag(FString Flag) const = 0;
	virtual void SetFlag(FString Flag, bool Value) = 0;
	virtual void Debug(bool _bDebug) = 0;
	virtual void SupplyStateWithCurrentData(NFactorStateInterface& State) = 0;
};
