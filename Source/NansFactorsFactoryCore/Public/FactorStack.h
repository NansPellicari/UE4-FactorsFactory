#pragma once

#include "CoreMinimal.h"

class NFactorInterface;
class IFactorOperatorWithStack;
class NFactorState;
class NTimelineInterface;

class NANSFACTORSFACTORYCORE_API NFactorStack
{
public:
	NFactorStack(FName _Name, TSharedPtr<NTimelineInterface> _Timeline);
	virtual ~NFactorStack();
	void Reset();
	void SetName(FName _Name);
	FName GetName() const;
	float GetTime() const;
	TSharedRef<NFactorInterface> GetFactor(uint32 Key) const;
	void AddFactor(TSharedPtr<NFactorInterface> Factor);
	bool HasFlag(FString Flag) const;
	bool GetFlag(FString Flag) const;
	void SetFlag(FString Flag, bool value);
	virtual NFactorState* GetCurrentState();
	bool bDebug = false;

protected:
	TMap<FString, bool> IterationFlags;
	TSharedPtr<NTimelineInterface> Timeline;
	TArray<TSharedPtr<NFactorInterface>> Factors;
	void AddFactorsToState(NFactorState* State);
	FName Name;
};
