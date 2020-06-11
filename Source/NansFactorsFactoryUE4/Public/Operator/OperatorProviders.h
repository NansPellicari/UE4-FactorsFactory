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
};

UCLASS(MinimalAPI, BlueprintType, Transient)
class UNAddOperatorProvider : public UNOperatorProviderBase
{
	GENERATED_BODY()
public:
	UNAddOperatorProvider() {}
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() override
	{
		return MakeShareable(new NAddOperator());
	}
};
UCLASS(MinimalAPI, BlueprintType, Transient)
class UNSubtractOperatorProvider : public UNOperatorProviderBase
{
	GENERATED_BODY()
public:
	UNSubtractOperatorProvider() {}
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() override
	{
		return MakeShareable(new NSubtractOperator());
	}
};
UCLASS(MinimalAPI, BlueprintType, Transient)
class UNMultiplyOperatorProvider : public UNOperatorProviderBase
{
	GENERATED_BODY()
public:
	UNMultiplyOperatorProvider() {}
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() override
	{
		return MakeShareable(new NMultiplyOperator());
	}
};
UCLASS(MinimalAPI, BlueprintType, Transient)
class UNDividerOperatorProvider : public UNOperatorProviderBase
{
	GENERATED_BODY()
public:
	UNDividerOperatorProvider() {}
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() override
	{
		return MakeShareable(new NDividerOperator());
	}
};
UCLASS(MinimalAPI, BlueprintType, Transient)
class UNNullOperatorProvider : public UNOperatorProviderBase
{
	GENERATED_BODY()
public:
	UNNullOperatorProvider() {}
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() override
	{
		return MakeShareable(new NNullOperator());
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
