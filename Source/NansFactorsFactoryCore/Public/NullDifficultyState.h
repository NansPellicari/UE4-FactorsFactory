#pragma once

#include "CoreMinimal.h"
#include "NansFactorsFactoryCore/Public/DifficultyState.h"

class INDifficultyInterface;

class NANSFACTORSFACTORYCORE_API NNullDifficultyState : public NDifficultyState
{
public:
    NNullDifficultyState();
    virtual void AddDifficulty(const INDifficultyInterface* Difficulty) override;
    virtual float Compute() override;
};
