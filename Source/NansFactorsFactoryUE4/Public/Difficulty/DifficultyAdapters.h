#pragma once

#include "CoreMinimal.h"
#include "DifficultyAdapterAbstract.h"
#include "NansFactorsFactoryCore/Public/Operator/DifficultyOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"
#include "NansFactorsFactoryCore/Public/Operator/ResetOperator.h"

#include "DifficultyAdapters.generated.h"

UENUM(BlueprintType)
enum class ENDifficultyOperator : uint8
{
    Null UMETA(DisplayName = "Null"),
    Add UMETA(DisplayName = "Add"),
    Sub UMETA(DisplayName = "Subsctract"),
    Mul UMETA(DisplayName = "Multiply"),
    Div UMETA(DisplayName = "Divide"),
    ResP UMETA(DisplayName = "Reset by Position")
};

UCLASS(BlueprintType)
class NANSFACTORSFACTORYUE4_API UNDifficultyAdapterBasic : public UNDifficultyAdapterAbstract
{
    GENERATED_BODY()
public:
    // TODO Move This when Factory doesn't require anymore
    static IDifficultyOperator* EnumToOperator(ENDifficultyOperator Enum)
    {
        IDifficultyOperator* Op = new NNullOperator();

        if (Enum == ENDifficultyOperator::Add)
        {
            Op = new NAddOperator();
        }

        if (Enum == ENDifficultyOperator::Sub)
        {
            Op = new NSubsctractOperator();
        }

        if (Enum == ENDifficultyOperator::Mul)
        {
            Op = new NMultiplyOperator();
        }

        if (Enum == ENDifficultyOperator::Div)
        {
            Op = new NDividerOperator();
        }

        if (Enum == ENDifficultyOperator::ResP)
        {
            Op = new NResetOperator();
        }

        return Op;
    }

    UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
    ENDifficultyOperator Operator = ENDifficultyOperator::Null;

    virtual IDifficultyOperator* GetOperator()
    {
        return UNDifficultyAdapterBasic::EnumToOperator(Operator);
    }
};

// TODO Create an ENUM to choose behaviors (all, last, number)
UCLASS(BlueprintType)
class NANSFACTORSFACTORYUE4_API UNDifficultyAdapterResetFromReason : public UNDifficultyAdapterAbstract
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
    FName ReasonToReset = NAME_None;
};
