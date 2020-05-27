#pragma once

#include "CoreMinimal.h"

class IFactorOperator;

class INFactorInterface
{
public:
    virtual IFactorOperator* GetOperator() const = 0;
    virtual float GetFactorValue() const = 0;
    virtual FName GetReason() const = 0;
    virtual bool IsActivate() const = 0;
    virtual void AddTime(float Time) = 0;
    virtual uint32 GetUID() const = 0;
};
