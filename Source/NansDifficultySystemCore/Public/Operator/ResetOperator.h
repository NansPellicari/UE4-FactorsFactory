#pragma once

#include "CoreMinimal.h"
#include "Operator/Interfaces.h"

#include "ResetOperator.generated.h"

class UNDifficulty;
class UNDifficultyStack;

UCLASS(Abstract)
class NANSDIFFICULTYSYSTEMCORE_API UNResetOperatorBase : public UObject, public IDifficultyOperator
{
    GENERATED_BODY()
public:
    virtual IDifficultyOperator* GetInverse() override;
    static FString GetResetIdFlag(UNDifficulty* Difficulty);
};

// TODO create ResetByReasonOperator ResetWithRangeOperator ResetAllOperator
UCLASS()
class NANSDIFFICULTYSYSTEMCORE_API UNResetOperator : public UNResetOperatorBase, public IDifficultyOperatorWithStack
{
    GENERATED_BODY()
public:
    virtual float Compute(float Lh, float Rh) override;
    virtual IDifficultyOperator* GetInverse() override;
    virtual void SetStack(UNDifficultyStack* Stack) override;
    virtual void SetKeyInStack(uint32 Key) override;

protected:
    UNDifficultyStack* MyStack;
    uint32 KeyInStack;
};
