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
#include "Operator/Interfaces.h"

class NANSFACTORSFACTORYCORE_API NNullOperator final : public NFactorOperatorBase
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

class NANSFACTORSFACTORYCORE_API NAddOperator final : public NFactorOperatorBase
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

class NANSFACTORSFACTORYCORE_API NSubtractOperator final : public NFactorOperatorBase
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

class NANSFACTORSFACTORYCORE_API NMultiplyOperator final : public NFactorOperatorBase
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

class NANSFACTORSFACTORYCORE_API NDividerOperator final : public NFactorOperatorBase
{
public:
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
};

/**
 * It limits the computation with a max value.
 */
class NANSFACTORSFACTORYCORE_API NMaxOperator final : public NFactorOperatorBase
{
public:
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
	bool bBreak;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	virtual float PersistentCompute(float Lh, float Rh, TSharedPtr<NFactorUnitInterface> ActualUnit) override;
	virtual float Compute(float Lh, float Rh) override;
	virtual bool IsBreaking() override;
	virtual bool IsPersistent() override
	{
		return true;
	}
};
class NANSFACTORSFACTORYCORE_API NMinOperator final : public NFactorOperatorBase
{
public:
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
	bool bBreak;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	virtual float PersistentCompute(float Lh, float Rh, TSharedPtr<NFactorUnitInterface> ActualUnit) override;
	virtual float Compute(float Lh, float Rh) override;
	virtual bool IsBreaking() override;
	virtual bool IsPersistent() override
	{
		return true;
	}
};
