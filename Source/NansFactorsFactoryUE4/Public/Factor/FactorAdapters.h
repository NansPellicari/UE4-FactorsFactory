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
	static TSharedPtr<FactorOperatorInterface> EnumToOperator(ENFactorOperator Enum)
	{
		TSharedPtr<FactorOperatorInterface> Op;

		if (Enum == ENFactorOperator::Add)
		{
			Op = MakeShareable(new NAddOperator());
		}

		if (Enum == ENFactorOperator::Sub)
		{
			Op = MakeShareable(new NSubsctractOperator());
		}

		if (Enum == ENFactorOperator::Mul)
		{
			Op = MakeShareable(new NMultiplyOperator());
		}

		if (Enum == ENFactorOperator::Div)
		{
			Op = MakeShareable(new NDividerOperator());
		}

		if (Enum == ENFactorOperator::ResP)
		{
			Op = MakeShareable(new NResetOperator());
		}

		if (!Op.IsValid())
		{
			Op = MakeShareable(new NNullOperator());
		}

		return Op;
	}

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
	ENFactorOperator Operator = ENFactorOperator::Null;

	virtual TSharedPtr<FactorOperatorInterface> GetConfiguredOperator() const override
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
