#pragma once

#include "CoreMinimal.h"
#include "Operator/Interfaces.h"

#include "DifficultyOperator.generated.h"

UCLASS()
class NANSDIFFICULTYSYSTEMCORE_API UNNullOperator : public UObject, public IDifficultyOperator
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
