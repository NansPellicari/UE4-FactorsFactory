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

class NFactorUnitInterface;
class NFactorInterface;

class NANSFACTORSFACTORYCORE_API NResetOperatorBase : public NFactorOperatorInterface
{
public:
	virtual ~NResetOperatorBase() {}
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	static FString GetResetIdFlag(TSharedPtr<NFactorUnitInterface> FactorUnit);
};

// TODO create ResetByReasonOperator ResetWithRangeOperator
/**
 * This class find a previous FactorUnit and try to reset it.
 * The Rh parameter of the Compute() method determines the previous position
 * (The Index of the FactorUnit which embeds this Operator - Rh)
 * of the FactorUnit you want to reset.
 */
class NANSFACTORSFACTORYCORE_API NResetOperator : public NResetOperatorBase, public NFactorOperatorWithFactorInterface
{
public:
	virtual ~NResetOperator();
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
	virtual float Compute(float Lh, float Rh) override;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override;
	virtual void SetFactor(NFactorInterface* Factor) override;
	virtual void SetKeyInFactor(uint32 Key) override;

protected:
	NFactorInterface* MyFactor;
	uint32 KeyInFactor;
};
