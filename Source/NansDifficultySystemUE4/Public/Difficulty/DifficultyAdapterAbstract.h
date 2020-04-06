#pragma once

#include "CoreMinimal.h"
#include "NansDifficultySystemCore/Public/Difficulty.h"
#include "NansDifficultySystemCore/Public/Operator/DifficultyOperator.h"
#include "NansDifficultySystemCore/Public/Operator/Interfaces.h"

#include "DifficultyAdapterAbstract.generated.h"

UCLASS(Abstract, Blueprintable)
class NANSDIFFICULTYSYSTEMUE4_API UNDifficultyAdapterAbstract : public UObject
{
    GENERATED_BODY()
public:
    NDifficulty* GetDifficulty()
    {
        return new NDifficulty(DifficultyValue, GetOperator(), Duration, Reason);
    }

    virtual IDifficultyOperator* GetOperator()
    {
        return new NNullOperator();
    }

    UPROPERTY(BlueprintReadWrite, Category = "DifficultySystem|Operation")
    float DifficultyValue = 0.f;

    UPROPERTY(BlueprintReadWrite, Category = "DifficultySystem|Operation")
    float Duration = 0.f;

    UPROPERTY(BlueprintReadWrite, Category = "DifficultySystem|Operation")
    FName Reason = NAME_None;

    UPROPERTY(BlueprintReadWrite, Category = "DifficultySystem|Operation")
    FName InStack = NAME_None;
};
