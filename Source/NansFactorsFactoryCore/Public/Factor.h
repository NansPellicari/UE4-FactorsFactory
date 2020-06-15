#pragma once

#include "CoreMinimal.h"
#include "FactorInterface.h"

class NFactorUnitInterface;
class NFactorOperatorWithFactorInterface;
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
	virtual TSharedPtr<NFactorUnitInterface> GetFactorUnit(uint32 Key) const override;
	virtual void AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit) override;
	virtual bool HasStateFlag(FString Flag) const override;
	virtual bool GetStateFlag(FString Flag) const override;
	virtual void SetStateFlag(FString Flag, bool Value) override;
	virtual void RemoveStateFlag(FString Flag) override;
	virtual TArray<TSharedPtr<NFactorUnitInterface>> GetFactors() const override;
	virtual void SupplyStateWithCurrentData(NFactorStateInterface& State) override;
	virtual void Debug(bool _bDebug) override;
	virtual void AddFlag(ENFactorFlag Flag) override;
	virtual bool HasFlag(ENFactorFlag Flag) const override;
	virtual void RemoveFlag(ENFactorFlag Flag) override;

protected:
	bool bDebug = false;
	TMap<FString, bool> IterationFlags;
	TArray<ENFactorFlag> OwnFlags;
	TSharedPtr<NTimelineInterface> Timeline;
	TArray<TSharedPtr<NFactorUnitInterface>> Factors;
	void AddFactorsToState(NFactorStateInterface& State);

	/**
	 * This is use as a delegate attached to a NEventInterface::OnStart of the FactorUnit's event
	 * when its FactorOperator is an implementation of NFactorOperatorStopperInterface.
	 */
	void OnStopperStart(NEventInterface* Event, const float& StartTime);

	FName Name;
};
