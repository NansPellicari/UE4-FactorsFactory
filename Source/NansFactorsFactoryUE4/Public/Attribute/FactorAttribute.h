#pragma once

#include "CoreMinimal.h"

#include "FactorAttribute.generated.h"

USTRUCT(BlueprintType)
struct FFactorAttribute
{
	GENERATED_BODY()

public:
	FFactorAttribute() {}
	FFactorAttribute(FName _Name) : Name(_Name) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FactorsFactory")
	FName Name;
};
