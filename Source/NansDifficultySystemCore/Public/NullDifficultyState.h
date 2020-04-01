#pragma once

#include "CoreMinimal.h"
#include "NansDifficultySystemCore/Public/DifficultyState.h"

class NANSDIFFICULTYSYSTEMCORE_API UNNullDifficultyState : public NDifficultyState
{
    using NDifficultyState::NDifficultyState;

public:
    virtual float Compute() override;
};
