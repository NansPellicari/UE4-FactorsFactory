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

#include "FactorUnit/UnrealFactorUnitProxy.h"

#include "FactorUnit/FactorUnitAdapter.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/FactorUnitInterface.h"

TSharedPtr<NFactorOperatorInterface> NUnrealFactorUnitProxy::GetOperator() const
{
	mycheck(FactorUnit != nullptr);
	return FactorUnit->GetOperator();
}
void NUnrealFactorUnitProxy::SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator)
{
	mycheck(FactorUnit != nullptr);
	return FactorUnit->SetOperator(_Operator);
}

float NUnrealFactorUnitProxy::GetFactorUnitValue() const
{
	mycheck(FactorUnit != nullptr);
	return FactorUnit->GetFactorUnitValue();
}

void NUnrealFactorUnitProxy::SetFactorUnitValue(float _Value)
{
	mycheck(FactorUnit != nullptr);
	return FactorUnit->SetFactorUnitValue(_Value);
}

FName NUnrealFactorUnitProxy::GetReason() const
{
	mycheck(FactorUnit != nullptr);
	return FactorUnit->GetReason();
}

bool NUnrealFactorUnitProxy::IsActivated() const
{
	mycheck(FactorUnit != nullptr);
	return FactorUnit->IsActivated();
}

const FString NUnrealFactorUnitProxy::GetUID() const
{
	mycheck(FactorUnit != nullptr);
	return FactorUnit->GetUID();
}

void NUnrealFactorUnitProxy::Activate(bool _bIsActivated)
{
	mycheck(FactorUnit != nullptr);
	return FactorUnit->Activate(_bIsActivated);
}

TSharedPtr<NEventInterface> NUnrealFactorUnitProxy::GetEvent()
{
	mycheck(FactorUnit != nullptr);
	return FactorUnit->GetEvent();
}

UNFactorUnitAdapter* NUnrealFactorUnitProxy::GetUnrealObject()
{
	return FactorUnit;
}
