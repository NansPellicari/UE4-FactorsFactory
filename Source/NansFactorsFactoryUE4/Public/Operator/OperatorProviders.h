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
#include "NansFactorsFactoryCore/Public/Operator/CleanerOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"
#include "NansFactorsFactoryCore/Public/Operator/ResetOperator.h"

#include "OperatorProviders.generated.h"

UCLASS(Abstract, BlueprintType, Transient, NotPlaceable)
class NANSFACTORSFACTORYUE4_API UNOperatorProviderBase : public UObject
{
	GENERATED_BODY()
public:
	UNOperatorProviderBase() {}
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() PURE_VIRTUAL(UNOperatorProviderBase::GetOperator, return nullptr;);
	virtual void Serialize(FArchive& Ar) override
	{
		Super::Serialize(Ar);
	}
};

UENUM()
enum class ENFactorSimpleOperation : uint8
{
	Add,
	Subtract,
	Multiply,
	Divide,
	Null
};

UCLASS(MinimalAPI, BlueprintType, Transient)
class UNOperatorSimpleOperations : public UNOperatorProviderBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operator", meta = (DisplayName = "Computation Type"))
	ENFactorSimpleOperation Type;

	UNOperatorSimpleOperations() {}
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() override
	{
		if (Type == ENFactorSimpleOperation::Add)
		{
			return MakeShareable(new NAddOperator());
		}
		if (Type == ENFactorSimpleOperation::Subtract)
		{
			return MakeShareable(new NSubtractOperator());
		}
		if (Type == ENFactorSimpleOperation::Multiply)
		{
			return MakeShareable(new NMultiplyOperator());
		}
		if (Type == ENFactorSimpleOperation::Divide)
		{
			return MakeShareable(new NDividerOperator());
		}

		return MakeShareable(new NNullOperator());
	}

	virtual void Serialize(FArchive& Ar) override
	{
		Super::Serialize(Ar);
		Ar << Type;
	}
};

UCLASS(MinimalAPI, BlueprintType, Transient)
class UNResetOperatorProvider : public UNOperatorProviderBase
{
	GENERATED_BODY()
public:
	UNResetOperatorProvider() {}
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() override
	{
		return MakeShareable(new NResetOperator());
	}
};

UENUM()
enum class ENFactorCleaner : uint8
{
	Cleaner,
	ReducersCleaner,
	IncreasersCleaner,
	ReducersPersistentCleaner,
	IncreasersPersistentCleaner
};

UCLASS(MinimalAPI, BlueprintType, Transient)
class UNOperatorCleaners : public UNOperatorProviderBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operator", meta = (DisplayName = "Cleaner Type"))
	ENFactorCleaner Type;

	UNOperatorCleaners() {}
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() override
	{
		if (Type == ENFactorCleaner::IncreasersCleaner)
		{
			return MakeShareable(new NIncreasersCleanerOperator());
		}
		if (Type == ENFactorCleaner::ReducersCleaner)
		{
			return MakeShareable(new NReducersCleanerOperator());
		}
		if (Type == ENFactorCleaner::ReducersPersistentCleaner)
		{
			return MakeShareable(new NReducersCleanerPersistentOperator());
		}
		if (Type == ENFactorCleaner::IncreasersPersistentCleaner)
		{
			return MakeShareable(new NIncreasersCleanerPersistentOperator());
		}

		return MakeShareable(new NCleanerOperator());
	}

	virtual void Serialize(FArchive& Ar) override
	{
		Super::Serialize(Ar);
		Ar << Type;
	}
};
