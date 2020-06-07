// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "CoreMinimal.h"
#include "FactorAdapterAbstract.h"

#include "FactorAdapters.generated.h"

class NFactorOperatorInterface;

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
	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
	ENFactorOperator Operator = ENFactorOperator::Null;

	static TSharedPtr<NFactorOperatorInterface> EnumToOperator(ENFactorOperator Enum);

	// BEGIN UNFactorAdapterAbstract override
	virtual TSharedPtr<NFactorOperatorInterface> GetConfiguredOperator() const override;
	// END UNFactorAdapterAbstract override

	// BEGIN UObject override
	virtual void Serialize(FArchive& Ar);
	// END UObject override
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
