#pragma once

#include "CoreMinimal.h"
#include "NansFactorsFactoryCore/Public/Difficulty.h"
#include "NansFactorsFactoryCore/Public/Operator/DifficultyOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"

#include "DifficultyAdapterAbstract.generated.h"

UCLASS(Abstract, Blueprintable)
class NANSFACTORSFACTORYUE4_API UNDifficultyAdapterAbstract : public UObject
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

    UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
    float DifficultyValue = 0.f;

    UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
    float Duration = 0.f;

    UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
    FName Reason = NAME_None;

    UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
    FName InStack = NAME_None;
};
