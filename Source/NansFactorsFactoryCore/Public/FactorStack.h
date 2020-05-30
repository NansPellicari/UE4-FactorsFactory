#pragma once

#include "CoreMinimal.h"
#include "FactorStackInterface.h"

class NFactorInterface;
class FactorOperatorInterfaceWithStack;
class NFactorState;
class NTimelineInterface;

class NANSFACTORSFACTORYCORE_API NFactorStack : public NFactorStackInterface
{
public:
	NFactorStack(FName _Name, TSharedPtr<NTimelineInterface> _Timeline);
	virtual ~NFactorStack();
	virtual void Reset() override;
	virtual void SetName(FName _Name) override;
	virtual FName GetName() const override;
	virtual float GetTime() const override;
	virtual TSharedRef<NFactorInterface> GetFactor(uint32 Key) const override;
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) override;
	virtual bool HasFlag(FString Flag) const override;
	virtual bool GetFlag(FString Flag) const override;
	virtual void SetFlag(FString Flag, bool Value) override;
	virtual TArray<TSharedPtr<NFactorInterface>> GetFactors() const override;
	virtual NFactorStateInterface* GetCurrentState() override;
	virtual void Debug(bool _bDebug) override;

protected:
	bool bDebug = false;
	TMap<FString, bool> IterationFlags;
	TSharedPtr<NTimelineInterface> Timeline;
	TArray<TSharedPtr<NFactorInterface>> Factors;
	void AddFactorsToState(NFactorStateInterface* State);
	FName Name;
};
