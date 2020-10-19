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
#include "FactorStateInterface.h"

class NFactorOperatorInterface;
class NFactorUnitInterface;
class NNullOperator;

class NANSFACTORSFACTORYCORE_API NFactorState : public NFactorStateInterface
{
public:
	bool bDebug = false;
	virtual ~NFactorState() {}
	NFactorState() {}
	virtual int32 AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit) override;
	virtual float GetTime() const override;
	virtual void SetTime(float _Time) override;
	virtual float Compute() override;
	virtual void Clear() override;
	virtual NFactorStateInterface* Clone() override;
	virtual void Debug(bool _bDebug) override;
	virtual const TArray<FNFactorStateOperator> GetOperators() const override;

protected:
	TArray<FNFactorStateOperator> Operators;

private:
	// FactorUnit 0 means no factor
	float FactorUnitValue = 0.f;
	// This value means it has not been initiliazed
	float Time = -1.f;
};
