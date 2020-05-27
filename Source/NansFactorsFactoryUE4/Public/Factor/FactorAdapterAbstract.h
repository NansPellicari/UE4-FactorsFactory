#pragma once

#include "CoreMinimal.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"

#include "FactorAdapterAbstract.generated.h"

UCLASS(Abstract, Blueprintable)
class NANSFACTORSFACTORYUE4_API UNFactorAdapterAbstract : public UObject
{
    GENERATED_BODY()
public:
    NFactor* GetFactor()
    {
        return new NFactor(FactorValue, GetOperator(), Duration, Reason);
    }

    virtual IFactorOperator* GetOperator()
    {
        return new NNullOperator();
    }

    UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
    float FactorValue = 0.f;

    UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
    float Duration = 0.f;

    UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
    FName Reason = NAME_None;

    UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
    FName InStack = NAME_None;
};
