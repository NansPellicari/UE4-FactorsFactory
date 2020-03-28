#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

#include "Difficulty.generated.h"

class IDifficultyOperator;

UCLASS()
class NANSDIFFICULTYSYSTEMCORE_API UNDifficulty : public UObject
{
    GENERATED_BODY()
public:
    UNDifficulty* Initialize(float _DiffValue, IDifficultyOperator* _Operator, float _Duration, FName Reason);
    bool IsActivate() const;
    IDifficultyOperator* GetOperator() const;
    float GetDifficultyValue() const;
    FName GetReason() const;
    void AddTime(float Time);

protected:
    FName Reason;
    float DifficultyValue;
    IDifficultyOperator* Operator;
    // 0 means infinite
    float Duration = 0.f;

private:
    float DurationSinceActivation = 0.f;
};
