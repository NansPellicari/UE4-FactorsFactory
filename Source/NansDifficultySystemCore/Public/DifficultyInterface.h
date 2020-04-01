#pragma once

#include "CoreMinimal.h"

class IDifficultyOperator;

class INDifficultyInterface
{
public:
    virtual IDifficultyOperator* GetOperator() const = 0;
    virtual float GetDifficultyValue() const = 0;
    virtual FName GetReason() const = 0;
    virtual bool IsActivate() const = 0;
    virtual void AddTime(float Time) = 0;
    virtual uint32 GetUID() const = 0;
};