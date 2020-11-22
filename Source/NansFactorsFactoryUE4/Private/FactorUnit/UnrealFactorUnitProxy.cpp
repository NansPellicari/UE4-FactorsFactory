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


#include "TimelineInterface.h"
#include "Factor/FactorDecorator.h"
#include "FactorUnit/FactorUnitView.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "UObject/Package.h"

NUnrealFactorUnitProxy::NUnrealFactorUnitProxy(UNFactorUnitView* _FactorUnit) : FactorUnit(_FactorUnit) {}

TSharedPtr<NFactorOperatorInterface> NUnrealFactorUnitProxy::GetOperator()
{
	check(IsValid(FactorUnit));
	return FactorUnit->GetOperator();
}

void NUnrealFactorUnitProxy::SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator)
{
	check(IsValid(FactorUnit));
	return FactorUnit->SetOperator(_Operator);
}

float NUnrealFactorUnitProxy::GetFactorUnitValue() const
{
	check(IsValid(FactorUnit));
	return FactorUnit->GetFactorUnitValue();
}

void NUnrealFactorUnitProxy::SetFactorUnitValue(float _Value)
{
	check(IsValid(FactorUnit));
	return FactorUnit->SetFactorUnitValue(_Value);
}

FName NUnrealFactorUnitProxy::GetReason() const
{
	check(IsValid(FactorUnit));
	return FactorUnit->GetReason();
}

bool NUnrealFactorUnitProxy::IsActivated() const
{
	check(IsValid(FactorUnit));
	return FactorUnit->IsActivated();
}

const FString NUnrealFactorUnitProxy::GetUID() const
{
	check(IsValid(FactorUnit));
	return FactorUnit->GetUID();
}

void NUnrealFactorUnitProxy::Activate(bool _bIsActivated)
{
	check(IsValid(FactorUnit));
	return FactorUnit->Activate(_bIsActivated);
}

TSharedPtr<NEventInterface> NUnrealFactorUnitProxy::GetEvent()
{
	check(IsValid(FactorUnit));
	return FactorUnit->GetEvent();
}

void NUnrealFactorUnitProxy::PreDelete() {}

void NUnrealFactorUnitProxy::ArchiveWithFactor(FArchive& Ar, UNFactorDecorator* Factor)
{
	if (Ar.IsLoading())
	{
		Ar << FactorUnitClassName;
		Ar << UID;
		Ar << OperatorProviderClassName;

		TSharedPtr<NEventInterface> Event = Factor->GetTimeline()->GetEvent(UID);

		UClass* Class = FindObject<UClass>(ANY_PACKAGE, *FactorUnitClassName);
		FactorUnit = Factor->CreateFactorUnit(Class);
		mycheckf(
			Event.IsValid(),
			TEXT("Problems occured during serialization of FNFactorUnitRecord,"
				"The associated event has not been found for UID %s"),
			*UID
		);
		UClass* OperatorProviderClass = FindObject<UClass>(ANY_PACKAGE, *OperatorProviderClassName);
		FactorUnit->OperatorProvider = NewObject<UNOperatorProviderBase>(FactorUnit, OperatorProviderClass, NAME_None);
		FactorUnit->Init(Event);
	}
}

void NUnrealFactorUnitProxy::Archive(FArchive& Ar)
{
	if (Ar.IsSaving())
	{
		UID = FactorUnit->GetUID();
		FactorUnitClassName = FactorUnit->GetClass()->GetPathName();
		OperatorProviderClassName = FactorUnit->OperatorProvider->GetClass()->GetPathName();
		Ar << FactorUnitClassName;
		Ar << UID;
		Ar << OperatorProviderClassName;
	}

	if (IsValid(FactorUnit))
	{
		FactorUnit->OperatorProvider->Serialize(Ar);
		FactorUnit->Serialize(Ar);
	}
}
