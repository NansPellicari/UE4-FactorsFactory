
#include "NullFactorState.h"

#include "FactorInterface.h"

NNullFactorState::NNullFactorState()
{
    NFactorState(0.f);
    Operators.Add(FNFactorStateOperator());
}

float NNullFactorState::Compute()
{
    return 0.f;
}

void NNullFactorState::AddFactor(TSharedPtr<INFactorInterface> Factor)
{
    return;
}
