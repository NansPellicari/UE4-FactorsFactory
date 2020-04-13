
#include "NullDifficultyState.h"

#include "DifficultyInterface.h"

NNullDifficultyState::NNullDifficultyState()
{
    NDifficultyState(0.f);
    Operators.Add(FNDifficultyStateOperator());
}

float NNullDifficultyState::Compute()
{
    return 0.f;
}

void NNullDifficultyState::AddDifficulty(const INDifficultyInterface* Difficulty)
{
    return;
}
