#include "Factor.h"

#include "Operator/FactorOperator.h"
#include "Operator/Interfaces.h"

NFactor::NFactor(float _FactorValue, IFactorOperator* _Operator, float _Duration, FName _Reason, float _Delay)
{
    FactorValue = _FactorValue;
    Operator = _Operator;
    Duration = _Duration;
    Label = _Reason;
    Delay = _Delay;
    Id = ++NFactorGUID::sNextId;
}

uint32 NFactor::GetUID() const
{
    return Id;
}

FName NFactor::GetReason() const
{
    return GetEventLabel();
}

bool NFactor::IsActivated() const
{
    return bIsActivated && !IsExpired();
}

IFactorOperator* NFactor::GetOperator() const
{
    if (!IsActivated())
    {
        return new NNullOperator();
    }
    return Operator;
}

float NFactor::GetFactorValue() const
{
    if (!IsActivated())
    {
        return 0;
    }
    return FactorValue;
}

void NFactor::AddTime(float Time)
{
    NotifyAddTime(Time);
}

void NFactor::Activate(bool _bIsActivated)
{
    bIsActivated = _bIsActivated;
}
