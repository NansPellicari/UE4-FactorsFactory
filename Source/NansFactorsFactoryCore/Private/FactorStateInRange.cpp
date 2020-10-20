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

#include "FactorStateInRange.h"

#include "FactorUnit.h"
#include "Operator/FactorOperator.h"

NFactorStateInRange::NFactorStateInRange(float _Min, float _Max) : Max(_Max), Min(_Min)
{
	AddFactorUnit(MakeShareable(new NFactorUnit(Min, MakeShareable(new NMinOperator()), 0, FName(TEXT("RangeLimitation")), 0)));
	AddFactorUnit(MakeShareable(new NFactorUnit(Max, MakeShareable(new NMaxOperator()), 0, FName(TEXT("RangeLimitation")), 0)));
}

void NFactorStateInRange::Clear()
{
	NFactorState::Clear();
	AddFactorUnit(MakeShareable(new NFactorUnit(Min, MakeShareable(new NMinOperator()), 0, FName(TEXT("RangeLimitation")), 0)));
	AddFactorUnit(MakeShareable(new NFactorUnit(Max, MakeShareable(new NMaxOperator()), 0, FName(TEXT("RangeLimitation")), 0)));
}

float NFactorStateInRange::Compute()
{
	float Result = NFactorState::Compute();
	return FMath::Clamp(Result, Min, Max);
}

float NFactorStateInRange::GetDecimalPercent()
{
	float Result = Compute();
	return Result / Max;
}

float NFactorStateInRange::GetDecimalPercentInRange()
{
	float Result = Compute();
	return (Result - Min) / (Max - Min);
}
