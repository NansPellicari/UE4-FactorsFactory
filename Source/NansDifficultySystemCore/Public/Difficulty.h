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
    void Initialize(int32 _DiffValue, IDifficultyOperator* _Operator, float _Duration);
    bool IsActivate();
    IDifficultyOperator* GetOperator();
    int32 GetDifficultyValue();
    void AddTime(float Time);

protected:
    int32 DifficultyValue;
    IDifficultyOperator* Operator;
    // 0 means infinite
    float Duration = 0.f;

private:
    float DurationSinceActivation = 1.f;
};
