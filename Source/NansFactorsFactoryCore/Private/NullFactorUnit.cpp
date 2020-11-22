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

#include "NullFactorUnit.h"

#include "NansTimelineSystemCore/public/EventInterface.h"
#include "Operator/Interfaces.h"

NNullFactorUnit::NNullFactorUnit() {}
NNullFactorUnit::~NNullFactorUnit() {}
bool NNullFactorUnit::IsActivated() const
{
	return false;
}
TSharedPtr<NFactorOperatorInterface> NNullFactorUnit::GetOperator()
{
	return nullptr;
}
void NNullFactorUnit::SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator) {}
float NNullFactorUnit::GetFactorUnitValue() const
{
	return 0.f;
}
void NNullFactorUnit::SetFactorUnitValue(float _Value) {}
FName NNullFactorUnit::GetReason() const
{
	return NAME_None;
}
const FString NNullFactorUnit::GetUID() const
{
	static const FString ID = "";
	return ID;
}
TSharedPtr<NEventInterface> NNullFactorUnit::GetEvent()
{
	return nullptr;
}
void NNullFactorUnit::Activate(bool _bIsActivated) {}

void NNullFactorUnit::PreDelete() {}

void NNullFactorUnit::Archive(FArchive& Ar) {}
