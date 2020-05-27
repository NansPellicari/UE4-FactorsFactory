#include "Factor.h"

#include "Operator/FactorOperator.h"
#include "Operator/Interfaces.h"

NFactor::NFactor(float _FactorValue, IFactorOperator* _Operator, float _Duration, FName _Reason)
{
    FactorValue = _FactorValue;
    Operator = _Operator;
    Duration = _Duration;
    Reason = _Reason;
    Id = ++NFactorGUID::sNextId;
}

uint32 NFactor::GetUID() const
{
    return Id;
}

FName NFactor::GetReason() const
{
    return Reason;
}

bool NFactor::IsActivate() const
{
    return Duration == 0 || DurationSinceActivation <= Duration;
}

IFactorOperator* NFactor::GetOperator() const
{
    if (!IsActivate())
    {
        return new NNullOperator();
    }
    return Operator;
}

float NFactor::GetFactorValue() const
{
    if (!IsActivate())
    {
        return 0;
    }
    return FactorValue;
}

void NFactor::AddTime(float Time)
{
    DurationSinceActivation += Time;
}
