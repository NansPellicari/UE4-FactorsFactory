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

#include "Operator/FactorOperator.h"

const FName NNullOperator::Name(TEXT("Null"));
const FName NAddOperator::Name(TEXT("Add"));
const FName NSubtractOperator::Name(TEXT("Subsctract"));
const FName NMultiplyOperator::Name(TEXT("Multiply"));
const FName NDividerOperator::Name(TEXT("Divider"));
const FName NMaxOperator::Name(TEXT("Max"));
const FName NMinOperator::Name(TEXT("Min"));

float NNullOperator::Compute(float Lh, float Rh)
{
	return Lh;
}

TSharedPtr<NFactorOperatorInterface> NNullOperator::GetInverse()
{
	static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NNullOperator());
	return Operator;
}

float NAddOperator::Compute(float Lh, float Rh)
{
	return Lh + Rh;
}

TSharedPtr<NFactorOperatorInterface> NAddOperator::GetInverse()
{
	static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NSubtractOperator());
	return Operator;
}

float NSubtractOperator::Compute(float Lh, float Rh)
{
	return Lh - Rh;
}

TSharedPtr<NFactorOperatorInterface> NSubtractOperator::GetInverse()
{
	static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NAddOperator());
	return Operator;
}

float NMultiplyOperator::Compute(float Lh, float Rh)
{
	return Lh * Rh;
}

TSharedPtr<NFactorOperatorInterface> NMultiplyOperator::GetInverse()
{
	static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NDividerOperator());
	return Operator;
}

float NDividerOperator::Compute(float Lh, float Rh)
{
	return Lh / Rh;
}

TSharedPtr<NFactorOperatorInterface> NDividerOperator::GetInverse()
{
	static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NMultiplyOperator());
	return Operator;
}

TSharedPtr<NFactorOperatorInterface> NMaxOperator::GetInverse()
{
	static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NNullOperator());
	return Operator;
}

bool NMaxOperator::IsBreaking()
{
	return bBreak;
}

float NMaxOperator::Compute(float Lh, float Rh, TSharedPtr<NFactorUnitInterface> ActualUnit)
{
	if (Lh >= Rh)
	{
		bBreak = true;
		return Rh;
	}
	return Lh;
}

float NMaxOperator::Compute(float Lh, float Rh)
{
	if (Lh >= Rh)
	{
		bBreak = true;
		return Rh;
	}
	return Lh;
}

TSharedPtr<NFactorOperatorInterface> NMinOperator::GetInverse()
{
	static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NNullOperator());
	return Operator;
}

bool NMinOperator::IsBreaking()
{
	return bBreak;
}

float NMinOperator::Compute(float Lh, float Rh)
{
	if (Lh <= Rh)
	{
		bBreak = true;
		return Rh;
	}
	return Lh;
}

float NMinOperator::Compute(float Lh, float Rh, TSharedPtr<NFactorUnitInterface> ActualUnit)
{
	if (Lh <= Rh)
	{
		bBreak = true;
		return Rh;
	}
	return Lh;
}
