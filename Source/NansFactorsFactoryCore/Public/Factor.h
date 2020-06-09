#pragma once

#include "CoreMinimal.h"
#include "FactorInterface.h"

class NFactorUnitInterface;
class NFactorOperatorInterfaceWithFactor;
class NFactorState;
class NTimelineInterface;
class NEventInterface;

class NANSFACTORSFACTORYCORE_API NFactor : public NFactorInterface
{
public:
	NFactor(FName _Name, TSharedPtr<NTimelineInterface> _Timeline);
	void OnTimelineEventExpired(TSharedPtr<NEventInterface> Event, const float& ExpiredTime, const int32& Index);
	virtual ~NFactor();
	virtual void Clear() override;
	virtual void SetName(FName _Name) override;
	virtual FName GetName() const override;
	virtual TSharedPtr<NTimelineInterface> GetTimeline() const override;
	virtual float GetTime() const override;
	virtual TSharedRef<NFactorUnitInterface> GetFactorUnit(uint32 Key) const override;
	virtual void AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit) override;
	virtual bool HasFlag(FString Flag) const override;
	virtual bool GetFlag(FString Flag) const override;
	virtual void SetFlag(FString Flag, bool Value) override;
	virtual TArray<TSharedPtr<NFactorUnitInterface>> GetFactors() const override;
	virtual void SupplyStateWithCurrentData(NFactorStateInterface& State) override;
	virtual void Debug(bool _bDebug) override;

protected:
	bool bDebug = false;
	TMap<FString, bool> IterationFlags;
	TSharedPtr<NTimelineInterface> Timeline;
	TArray<TSharedPtr<NFactorUnitInterface>> Factors;
	void AddFactorsToState(NFactorStateInterface& State);
	FName Name;
};
