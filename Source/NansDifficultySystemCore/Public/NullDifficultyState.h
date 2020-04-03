#pragma once

#include "CoreMinimal.h"
#include "NansDifficultySystemCore/Public/DifficultyState.h"

class INDifficultyInterface;

class NANSDIFFICULTYSYSTEMCORE_API NNullDifficultyState : public NDifficultyState
{
public:
    NNullDifficultyState();
    virtual void AddDifficulty(const INDifficultyInterface* Difficulty) override;
    virtual float Compute() override;
};
