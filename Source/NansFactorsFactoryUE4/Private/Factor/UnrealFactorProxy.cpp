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

#include "Factor/UnrealFactorProxy.h"

#include "Factor/FactorAdapterAbstract.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/FactorInterface.h"

TSharedPtr<FactorOperatorInterface> NUnrealFactorProxy::GetOperator() const
{
	mycheck(Factor != nullptr);
	return Factor->GetOperator();
}

float NUnrealFactorProxy::GetFactorValue() const
{
	mycheck(Factor != nullptr);
	return Factor->GetFactorValue();
}

FName NUnrealFactorProxy::GetReason() const
{
	mycheck(Factor != nullptr);
	return Factor->GetReason();
}

bool NUnrealFactorProxy::IsActivated() const
{
	mycheck(Factor != nullptr);
	return Factor->IsActivated();
}

uint32 NUnrealFactorProxy::GetUID() const
{
	mycheck(Factor != nullptr);
	return Factor->GetUID();
}

TSharedPtr<NEventInterface> NUnrealFactorProxy::GetEvent()
{
	mycheck(Factor != nullptr);
	return Factor->GetEvent();
}

UNFactorAdapterAbstract* NUnrealFactorProxy::GetUnrealObject()
{
	return Factor;
}
