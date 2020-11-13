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
};

class NANSFACTORSFACTORYCORE_API NFactorOperatorWithFactorInterface
{
public:
	virtual void SetFactor(NFactorInterface* Factor) = 0;
	virtual void SetKeyInFactor(uint32 Key) = 0;
};

class NANSFACTORSFACTORYCORE_API NFactorOperatorBreakerInterface
{
public:
	virtual bool IsBreaking() = 0;
};

class NANSFACTORSFACTORYCORE_API NFactorOperatorStopperInterface
{
};

class NANSFACTORSFACTORYCORE_API NFactorOperatorPersistentInterface
{
public:
	virtual float PersistentCompute(float Lh, float Rh, TSharedPtr<NFactorUnitInterface> ActualUnit) = 0;
};

class NOperatorUtils
{
public:
	template <typename T>
	static bool IsOperatorWithFactor(T Operator)
	{
		return dynamic_cast<NFactorOperatorWithFactorInterface*>(Operator) != nullptr;
	}
};
