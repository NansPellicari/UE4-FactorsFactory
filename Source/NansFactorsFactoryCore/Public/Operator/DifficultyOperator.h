#pragma once

#include "CoreMinimal.h"
#include "Operator/Interfaces.h"

class NANSFACTORSFACTORYCORE_API NNullOperator : public IDifficultyOperator
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

class NANSFACTORSFACTORYCORE_API NAddOperator : public IDifficultyOperator
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

class NANSFACTORSFACTORYCORE_API NSubsctractOperator : public IDifficultyOperator
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

class NANSFACTORSFACTORYCORE_API NMultiplyOperator : public IDifficultyOperator
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

class NANSFACTORSFACTORYCORE_API NDividerOperator : public IDifficultyOperator
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
