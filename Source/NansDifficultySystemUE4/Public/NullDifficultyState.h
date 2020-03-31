#pragma once

#include "CoreMinimal.h"
#include "NansDifficultySystemCore/Public/DifficultyState.h"
#include "UObject/ObjectMacros.h"

#include "NullDifficultyState.generated.h"

UCLASS()
class NANSDIFFICULTYSYSTEMUE4_API UNNullDifficultyState : public UNDifficultyState
{
    GENERATED_BODY()
public:
    virtual float Compute() override;
};
