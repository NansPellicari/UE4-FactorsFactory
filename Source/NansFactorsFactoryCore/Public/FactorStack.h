#pragma once

#include "CoreMinimal.h"

class INFactorInterface;
class IFactorOperatorWithStack;
class NFactorState;

class NANSFACTORSFACTORYCORE_API NFactorStack
{
public:
    NFactorStack(FName _Name);
    virtual ~NFactorStack();
    void Reset();
    void SetName(FName _Name);
    FName GetName() const;
    float GetTime() const;
    INFactorInterface* GetFactor(uint32 Key) const;
    void AddFactor(INFactorInterface* Factor);
    bool HasFlag(FString Flag) const;
    bool GetFlag(FString Flag) const;
    void SetFlag(FString Flag, bool value);
    void AddTime(float _Time);
    virtual NFactorState* GetCurrentState();
    bool bDebug = false;

protected:
    TMap<FString, bool> IterationFlags;
    float Time = 0.f;
    TArray<INFactorInterface*> Factors;
    void AddFactorsToState(NFactorState* State);
    FName Name;
};