#pragma once

#include "CoreMinimal.h"
#include "Operator/Interfaces.h"

class NANSDIFFICULTYSYSTEMCORE_API NNullOperator : public IDifficultyOperator
{
public:
    virtual float Compute(float Lh, float Rh) override;
    virtual IDifficultyOperator* GetInverse() override;
    static const FName Name;
    virtual const FName GetName() override
    {
        return Name;
    }
};

class NANSDIFFICULTYSYSTEMCORE_API NAddOperator : public IDifficultyOperator
{
public:
    virtual float Compute(float Lh, float Rh) override;
    virtual IDifficultyOperator* GetInverse() override;
    static const FName Name;
    virtual const FName GetName() override
    {
        return Name;
    }
};

class NANSDIFFICULTYSYSTEMCORE_API NSubsctractOperator : public IDifficultyOperator
{
public:
    virtual float Compute(float Lh, float Rh) override;
    virtual IDifficultyOperator* GetInverse() override;
    static const FName Name;
    virtual const FName GetName() override
    {
        return Name;
    }
};

class NANSDIFFICULTYSYSTEMCORE_API NMultiplyOperator : public IDifficultyOperator
{
public:
    virtual float Compute(float Lh, float Rh) override;
    virtual IDifficultyOperator* GetInverse() override;
    static const FName Name;
    virtual const FName GetName() override
    {
        return Name;
    }
};

class NANSDIFFICULTYSYSTEMCORE_API NDividerOperator : public IDifficultyOperator
{
public:
    virtual float Compute(float Lh, float Rh) override;
    virtual IDifficultyOperator* GetInverse() override;
    static const FName Name;
    virtual const FName GetName() override
    {
        return Name;
    }
};
