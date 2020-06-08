#pragma once

#include "CoreMinimal.h"
#include "FactorStackInterface.h"

class NFactorInterface;
class NFactorOperatorInterfaceWithStack;
class NFactorState;
class NTimelineInterface;

class NANSFACTORSFACTORYCORE_API NFactorStack : public NFactorStackInterface
{
public:
	NFactorStack(FName _Name, TSharedPtr<NTimelineInterface> _Timeline);
	void OnTimelineEventExpired(TSharedPtr<NEventInterface> Event, const float& ExpiredTime, const int32& Index);
	virtual ~NFactorStack();
	virtual void Clear() override;
	virtual void SetName(FName _Name) override;
	virtual FName GetName() const override;
	virtual TSharedPtr<NTimelineInterface> GetTimeline() const override;
	virtual float GetTime() const override;
	virtual TSharedRef<NFactorInterface> GetFactor(uint32 Key) const override;
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) override;
	virtual bool HasFlag(FString Flag) const override;
	virtual bool GetFlag(FString Flag) const override;
	virtual void SetFlag(FString Flag, bool Value) override;
	virtual TArray<TSharedPtr<NFactorInterface>> GetFactors() const override;
	virtual void SupplyStateWithCurrentData(NFactorStateInterface& State) override;
	virtual void Debug(bool _bDebug) override;

protected:
	bool bDebug = false;
	TMap<FString, bool> IterationFlags;
	TSharedPtr<NTimelineInterface> Timeline;
	TArray<TSharedPtr<NFactorInterface>> Factors;
	void AddFactorsToState(NFactorStateInterface& State);
	FName Name;
};
