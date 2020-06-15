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

#include "Operator/ReplacerOperator.h"

#include "Factor.h"
#include "FactorUnit.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "Operator/FactorOperator.h"
#include "Operator/ResetOperator.h"

const FName NReplacerOperator::Name(TEXT("Replacer"));

float NReplacerOperator::Compute(float Lh, float Rh)
{
	return Rh;
}

TSharedPtr<NFactorOperatorInterface> NReplacerOperator::GetInverse()
{
	static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NNullOperator());
	return Operator;
}
