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

class NFactorOperatorInterface;
class NFactorUnitInterface;
class NNullOperator;

struct FNFactorStateOperator
{
	FNFactorStateOperator();
	FNFactorStateOperator(TSharedPtr<NFactorUnitInterface> _FactorUnit);

	TSharedPtr<NFactorUnitInterface> FactorUnit;
	float Value = 0.f;
	FName Reason = FName("");
	bool Activate = true;
	TSharedPtr<NFactorOperatorInterface> Operator;
};

class NANSFACTORSFACTORYCORE_API NFactorStateInterface
{
public:
	virtual int32 AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit) = 0;
	virtual void SetTime(float _Time) = 0;
	virtual float GetTime() const = 0;
	virtual float Compute() = 0;
	virtual void Clear() = 0;
	virtual NFactorStateInterface* Clone() = 0;
	virtual void Debug(bool _bDebug) = 0;
	virtual const TArray<FNFactorStateOperator> GetOperators() const = 0;
};
