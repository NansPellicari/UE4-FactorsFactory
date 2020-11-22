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

#include "FactorUnit/FactorUnitView.h"

#include "Attribute/FactorAttribute.h"
#include "FactorUnit/UnrealFactorUnitProxy.h"
#include "NansFactorsFactoryCore/Public/FactorUnit.h"
#include "NansFactorsFactoryCore/Public/FactorUnitInterface.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"
#include "NansFactorsFactoryUE4/Public/Operator/OperatorProviders.h"
#include "NansTimelineSystemUE4/Public/Event/EventView.h"
#include "Settings/FactorSettings.h"

void UNFactorUnitView::Init(TSharedPtr<NEventInterface> Event)
{
	FactorUnit = MakeShareable(new NFactorUnit(FactorUnitValue, GetConfiguredOperator(), Event));
}

TSharedPtr<NEventInterface> UNFactorUnitView::GetEvent()
{
	return FactorUnit->GetEvent();
}

void UNFactorUnitView::SetOperatorProvider(UNOperatorProviderBase* _OperatorProvider)
{
	OperatorProvider = _OperatorProvider;
}

TSharedPtr<NFactorOperatorInterface> UNFactorUnitView::GetConfiguredOperator()
{
	check(IsValid(OperatorProvider));
	return OperatorProvider->GetOperator();
}

TSharedPtr<NFactorOperatorInterface> UNFactorUnitView::GetOperator()
{
	return FactorUnit->GetOperator();
}

void UNFactorUnitView::SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator)
{
	FactorUnit->SetOperator(_Operator);
}

float UNFactorUnitView::GetFactorUnitValue() const
{
	return FactorUnit->GetFactorUnitValue();
}

FName UNFactorUnitView::GetReason() const
{
	return FactorUnit->GetReason();
}

void UNFactorUnitView::SetFactorUnitValue(float _Value)
{
	FactorUnit->SetFactorUnitValue(_Value);
}

bool UNFactorUnitView::IsActivated() const
{
	return FactorUnit->IsActivated();
}

const FString UNFactorUnitView::GetUID() const
{
	return FactorUnit->GetUID();
}

void UNFactorUnitView::Activate(bool _bIsActivated)
{
	return FactorUnit->Activate(_bIsActivated);
}

void UNFactorUnitView::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	if (Ar.IsSaving() && FactorUnit.IsValid())
	{
		FactorUnitValue = FactorUnit->GetFactorUnitValue();
	}

	Ar << FactorUnitValue;

	if (FactorUnit.IsValid())
	{
		FactorUnit->Archive(Ar);
	}

	if (Ar.IsLoading() && FactorUnit.IsValid())
	{
		SetFactorUnitValue(FactorUnitValue);
		SetOperator(GetConfiguredOperator());
	}
}
