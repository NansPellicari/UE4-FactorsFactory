#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

#include "DifficultyState.generated.h"

class IDifficultyOperator;
class UNDifficulty;

USTRUCT()
struct FNDifficultyStateOperator
{
    GENERATED_USTRUCT_BODY()

    FNDifficultyStateOperator() {}
    FNDifficultyStateOperator(const UNDifficulty* Difficulty);

    float Value;
    IDifficultyOperator* Operator;
    // TODO create  Serialize method which save Value + Operator class and value
};

UCLASS()
class NANSDIFFICULTYSYSTEMCORE_API UNDifficultyState : public UObject
{
    GENERATED_BODY()
public:
    UNDifficultyState* Initialize(float _Time);
    void AddDifficulty(const UNDifficulty* Difficulty);
    float GetTime() const;
    float Compute();
    bool bDebug = false;
    // TODO create a Serialize method which save Time + DifficultyValue +  Operators

protected:
    TArray<FNDifficultyStateOperator> Operators;

private:
    // Difficulty 0 means no difficulty
    float DifficultyValue = 0.f;
    // This value means it has not been initiliazed
    float Time = -1.f;
};
