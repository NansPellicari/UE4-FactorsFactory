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

class NFactorInterface;
class NFactorUnitInterface;

class NANSFACTORSFACTORYCORE_API NFactorOperatorInterface
{
public:
	virtual ~NFactorOperatorInterface() {}
	virtual float Compute(float Lh, float Rh) = 0;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() = 0;
	virtual const FName GetName() = 0;
	virtual float PersistentCompute(float Lh, float Rh, TSharedPtr<NFactorUnitInterface> ActualUnit) = 0;
	virtual bool IsBreaking() = 0;
	virtual bool IsStopper() = 0;
	virtual bool IsPersistent() = 0;
	virtual bool IsOperatorWithFactor() = 0;
	virtual void SetFactor(NFactorInterface* Factor) = 0;
	virtual void SetKeyInFactor(uint32 Key) = 0;
};

class NANSFACTORSFACTORYCORE_API NFactorOperatorBase : public NFactorOperatorInterface
{
public:
	virtual float Compute(float Lh, float Rh) override
	{
		return Lh;
	}
	virtual float PersistentCompute(float Lh, float Rh, TSharedPtr<NFactorUnitInterface> ActualUnit) override
	{
		return Lh;
	}
	virtual bool IsBreaking() override
	{
		return false;
	}
	virtual bool IsStopper() override
	{
		return false;
	}
	virtual bool IsPersistent() override
	{
		return false;
	}
	virtual bool IsOperatorWithFactor() override
	{
		return false;
	}
	virtual void SetFactor(NFactorInterface* Factor) override {}
	virtual void SetKeyInFactor(uint32 Key) override {}
};
