#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

#include "DifficultyStack.generated.h"

class UNDifficulty;
class UNDifficultyState;

UCLASS()
class NANSDIFFICULTYSYSTEMCORE_API UNDifficultyStack : public UObject
{
    GENERATED_BODY()
public:
    ~UNDifficultyStack();
    void Reset();
    UNDifficultyStack* Initialize(FName _Name);
    FName GetName() const;
    float GetTime() const;
    UNDifficulty* GetDifficulty(uint32 Key) const;
    void AddDifficulty(UNDifficulty* Difficulty);
    bool HasFlag(FString Flag) const;
    bool GetFlag(FString Flag) const;
    void SetFlag(FString Flag, bool value);
    void AddTime(float _Time);
    virtual UNDifficultyState* GetCurrentState();
    bool bDebug = false;

protected:
    TMap<FString, bool> IterationFlags;
    float Time = 0.f;
    TArray<UNDifficulty*> Difficulties;
    void AddDifficultiesToState(UNDifficultyState* State);

private:
    FName Name;
};
