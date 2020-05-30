
#include "NullFactorState.h"

#include "FactorInterface.h"

NNullFactorState::NNullFactorState()
{
	Operators.Add(FNFactorStateOperator());
	SetTime(0.f);
}

float NNullFactorState::Compute()
{
	return 0.f;
}

void NNullFactorState::AddFactor(TSharedPtr<NFactorInterface> Factor)
{
	return;
}
