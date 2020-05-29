#pragma once

#include "CoreMinimal.h"

#include "FactorStackAttribute.generated.h"

USTRUCT(BlueprintType)
struct FFactorStackAttribute
{
	GENERATED_BODY()

public:
	FFactorStackAttribute() {}
	FFactorStackAttribute(FName _Name) : Name(_Name) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FactorsFactory")
	FName Name;
};
