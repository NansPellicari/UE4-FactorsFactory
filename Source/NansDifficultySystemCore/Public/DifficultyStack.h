#pragma once

#include "CoreMinimal.h"

class INDifficultyInterface;
class IDifficultyOperatorWithStack;
class NDifficultyState;

class NANSDIFFICULTYSYSTEMCORE_API NDifficultyStack
{
public:
    NDifficultyStack(FName _Name);
    virtual ~NDifficultyStack();
    void Reset();
    void SetName(FName _Name);
    FName GetName() const;
    float GetTime() const;
    INDifficultyInterface* GetDifficulty(uint32 Key) const;
    void AddDifficulty(INDifficultyInterface* Difficulty);
    bool HasFlag(FString Flag) const;
    bool GetFlag(FString Flag) const;
    void SetFlag(FString Flag, bool value);
    void AddTime(float _Time);
    virtual NDifficultyState* GetCurrentState();
    bool bDebug = false;

protected:
    TMap<FString, bool> IterationFlags;
    float Time = 0.f;
    TArray<INDifficultyInterface*> Difficulties;
    void AddDifficultiesToState(NDifficultyState* State);
    FName Name;
};
