#pragma once

#include "CoreMinimal.h"
#include "FactorAdapterAbstract.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"
#include "NansFactorsFactoryCore/Public/Operator/ResetOperator.h"

#include "FactorAdapters.generated.h"

UENUM(BlueprintType)
enum class ENFactorOperator : uint8
{
    Null UMETA(DisplayName = "Null"),
    Add UMETA(DisplayName = "Add"),
    Sub UMETA(DisplayName = "Subsctract"),
    Mul UMETA(DisplayName = "Multiply"),
    Div UMETA(DisplayName = "Divide"),
    ResP UMETA(DisplayName = "Reset by Position")
};

UCLASS(BlueprintType)
class NANSFACTORSFACTORYUE4_API UNFactorAdapterBasic : public UNFactorAdapterAbstract
{
    GENERATED_BODY()
public:
    // TODO Move This when Factory doesn't require anymore
    static IFactorOperator* EnumToOperator(ENFactorOperator Enum)
    {
        IFactorOperator* Op = new NNullOperator();

        if (Enum == ENFactorOperator::Add)
        {
            Op = new NAddOperator();
        }

        if (Enum == ENFactorOperator::Sub)
        {
            Op = new NSubsctractOperator();
        }

        if (Enum == ENFactorOperator::Mul)
        {
            Op = new NMultiplyOperator();
        }

        if (Enum == ENFactorOperator::Div)
        {
            Op = new NDividerOperator();
        }

        if (Enum == ENFactorOperator::ResP)
        {
            Op = new NResetOperator();
        }

        return Op;
    }

    UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
    ENFactorOperator Operator = ENFactorOperator::Null;

    virtual IFactorOperator* GetOperator()
    {
        return UNFactorAdapterBasic::EnumToOperator(Operator);
    }
};

// TODO Create an ENUM to choose behaviors (all, last, number)
UCLASS(BlueprintType)
class NANSFACTORSFACTORYUE4_API UNFactorAdapterResetFromReason : public UNFactorAdapterAbstract
{
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
    FName ReasonToReset = NAME_None;
};
