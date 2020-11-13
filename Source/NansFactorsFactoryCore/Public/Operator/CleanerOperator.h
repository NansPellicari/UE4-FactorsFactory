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
 * This operator is raw! It removes every previous operator set in the factor's units queue.
 * For the Compute() method, it returns the value set at the Rh parameter
 * (means that the factor Unit value associated replace every previous value).
 */
class NANSFACTORSFACTORYCORE_API NCleanerOperator : public NResetOperatorBase, public NFactorOperatorWithFactorInterface
{
public:
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
	virtual bool IsShouldClean(TSharedPtr<NFactorUnitInterface> FactorUnit) const;
	virtual float Clean(TSharedPtr<NFactorUnitInterface> FactorUnit, float Lh);

	NFactorInterface* MyFactor;
	uint32 KeyInFactor;
	int32 FactorUnitsNumber = -1;
};

/**
 * This operator is raw! It removes every previous operator set in the factor's units queue.
 * It cleans only factor's unit which implies factor amount reduction.
 * The Rh parameter of the Compute() method determines the amount of FactorUnit removed (0 = all).
 * For the Compute() method it doesn't make any computation by returning the Lh parameter.
 */
class NANSFACTORSFACTORYCORE_API NReducersCleanerOperator : public NCleanerOperator
{
public:
	static const FName Name;
	virtual bool IsShouldClean(TSharedPtr<NFactorUnitInterface> FactorUnit) const override;

protected:
};

/**
 * @copydoc NReducersCleanerOperator
 * It removes also next Reducers set.
 */
class NANSFACTORSFACTORYCORE_API NReducersCleanerPersistentOperator : public NReducersCleanerOperator,
																	  public NFactorOperatorPersistentInterface
{
public:
	static const FName Name;
	virtual float PersistentCompute(float Lh, float Rh, TSharedPtr<NFactorUnitInterface> ActualUnit) override;
};

/**
 * This operator is raw! It removes every previous operator set in the factor's units queue.
 * It cleans only factor's unit which implies factor amount increase.
 * The Rh parameter of the Compute() method determines the amount of FactorUnit removed (0 = all).
 * For the Compute() method it doesn't make any computation by returning the Lh parameter.
 */
class NANSFACTORSFACTORYCORE_API NIncreasersCleanerOperator : public NCleanerOperator
{
public:
	static const FName Name;
	virtual bool IsShouldClean(TSharedPtr<NFactorUnitInterface> FactorUnit) const override;
};

/**
 * @copydoc NIncreasersCleanerOperator
 * It removes also next Increasers set.
 */
class NANSFACTORSFACTORYCORE_API NIncreasersCleanerPersistentOperator : public NIncreasersCleanerOperator,
																		public NFactorOperatorPersistentInterface
{
public:
	static const FName Name;
	virtual float PersistentCompute(float Lh, float Rh, TSharedPtr<NFactorUnitInterface> ActualUnit) override;
};
