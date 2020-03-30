#pragma once

#include "CoreMinimal.h"
#include "Operator/Interfaces.h"

#include "DifficultyOperator.generated.h"

class UNDifficultyStack;
class UNDifficulty;

UCLASS(Abstract)
class NANSDIFFICULTYSYSTEMCORE_API UNResetOperatorBase : public UObject, public IDifficultyOperator
{
    GENERATED_BODY()
public:
    virtual IDifficultyOperator* GetInverse() override;
    static FString GetResetIdFlag(UNDifficulty* Difficulty);
};

UCLASS() class NANSDIFFICULTYSYSTEMCORE_API UNNullOperator : public UObject, public IDifficultyOperator
{
    GENERATED_BODY()
public:
    virtual float Compute(float Lh, float Rh) override;
    virtual IDifficultyOperator* GetInverse() override;
};

UCLASS()
class NANSDIFFICULTYSYSTEMCORE_API UNAddOperator : public UObject, public IDifficultyOperator
{
    GENERATED_BODY()
public:
    virtual float Compute(float Lh, float Rh) override;
    virtual IDifficultyOperator* GetInverse() override;
};

UCLASS()
class NANSDIFFICULTYSYSTEMCORE_API UNSubsctractOperator : public UObject, public IDifficultyOperator
{
    GENERATED_BODY()
public:
    virtual float Compute(float Lh, float Rh) override;
    virtual IDifficultyOperator* GetInverse() override;
};

UCLASS()
class NANSDIFFICULTYSYSTEMCORE_API UNMultiplyOperator : public UObject, public IDifficultyOperator
{
    GENERATED_BODY()
public:
    virtual float Compute(float Lh, float Rh) override;
    virtual IDifficultyOperator* GetInverse() override;
};

UCLASS()
class NANSDIFFICULTYSYSTEMCORE_API UNDividerOperator : public UObject, public IDifficultyOperator
{
    GENERATED_BODY()
public:
    virtual float Compute(float Lh, float Rh) override;
    virtual IDifficultyOperator* GetInverse() override;
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
