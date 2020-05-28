#pragma once

#include "Attribute/FactorStackAttribute.h"
#include "CoreMinimal.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"
#include "Settings/FactorSettings.h"

#include "FactorAdapterAbstract.generated.h"

UCLASS(Abstract, Blueprintable)
class NANSFACTORSFACTORYUE4_API UNFactorAdapterAbstract : public UObject
{
	GENERATED_BODY()
public:
	TSharedPtr<NFactor> GetFactor()
	{
		if (!Factor.IsValid())
		{
			Factor = MakeShareable(new NFactor(FactorValue, GetOperator(), Duration, Reason));
		}

		return Factor;
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
	FFactorStackAttribute InStack;

protected:
	TSharedPtr<NFactor> Factor;
};
