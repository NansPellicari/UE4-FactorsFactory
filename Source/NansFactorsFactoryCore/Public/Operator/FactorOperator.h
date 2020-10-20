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

class NANSFACTORSFACTORYCORE_API NNullOperator : public NFactorOperatorInterface
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

class NANSFACTORSFACTORYCORE_API NAddOperator : public NFactorOperatorInterface
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

class NANSFACTORSFACTORYCORE_API NSubtractOperator : public NFactorOperatorInterface
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

class NANSFACTORSFACTORYCORE_API NMultiplyOperator : public NFactorOperatorInterface
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

class NANSFACTORSFACTORYCORE_API NDividerOperator : public NFactorOperatorInterface
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
class NANSFACTORSFACTORYCORE_API NMaxOperator : public NFactorOperatorBreakerInterface,
												public NFactorOperatorPersistentInterface,
												public NFactorOperatorInterface
{
public:
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
	float bBreak;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	virtual float Compute(float Lh, float Rh, TSharedPtr<NFactorUnitInterface> ActualUnit) override;
	virtual float Compute(float Lh, float Rh) override;
	virtual bool IsBreaking() override;
};
class NANSFACTORSFACTORYCORE_API NMinOperator : public NFactorOperatorBreakerInterface,
												public NFactorOperatorPersistentInterface,
												public NFactorOperatorInterface
{
public:
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
	float bBreak;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	virtual float Compute(float Lh, float Rh, TSharedPtr<NFactorUnitInterface> ActualUnit) override;
	virtual float Compute(float Lh, float Rh) override;
	virtual bool IsBreaking() override;
};
