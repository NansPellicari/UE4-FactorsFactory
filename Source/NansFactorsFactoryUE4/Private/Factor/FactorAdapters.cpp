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

#include "Factor/FactorAdapters.h"

#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"
#include "NansFactorsFactoryCore/Public/Operator/ResetOperator.h"

TSharedPtr<FactorOperatorInterface> UNFactorAdapterBasic::EnumToOperator(ENFactorOperator Enum)
{
	TSharedPtr<FactorOperatorInterface> Op;

	if (Enum == ENFactorOperator::Add)
	{
		Op = MakeShareable(new NAddOperator());
	}

	if (Enum == ENFactorOperator::Sub)
	{
		Op = MakeShareable(new NSubtractOperator());
	}

	if (Enum == ENFactorOperator::Mul)
	{
		Op = MakeShareable(new NMultiplyOperator());
	}

	if (Enum == ENFactorOperator::Div)
	{
		Op = MakeShareable(new NDividerOperator());
	}

	if (Enum == ENFactorOperator::ResP)
	{
		Op = MakeShareable(new NResetOperator());
	}

	if (!Op.IsValid())
	{
		Op = MakeShareable(new NNullOperator());
	}

	return Op;
}

TSharedPtr<FactorOperatorInterface> UNFactorAdapterBasic::GetConfiguredOperator() const
{
	return UNFactorAdapterBasic::EnumToOperator(Operator);
}
