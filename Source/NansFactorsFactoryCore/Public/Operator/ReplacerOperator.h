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
#include "Operator/ResetOperator.h"

class NFactorUnitInterface;
class NFactorInterface;

/**
 * This operator replace the value from the previous operators list
 * (It doesn't care of the Lh parameter of the method Compute).
 * For the Compute() method, it returns the value set at the Rh parameter.
 */
class NANSFACTORSFACTORYCORE_API NReplacerOperator final : public NFactorOperatorBase
{
public:
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	virtual bool IsStopper() override
	{
		return true;
	}
};
