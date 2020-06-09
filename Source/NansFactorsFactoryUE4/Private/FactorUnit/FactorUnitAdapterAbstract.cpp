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

#include "FactorUnit/FactorUnitAdapterAbstract.h"

#include "Attribute/FactorAttribute.h"
#include "Event/EventDecorator.h"
#include "Event/FactorEventDecorator.h"
#include "NansFactorsFactoryCore/Public/FactorUnit.h"
#include "NansFactorsFactoryCore/Public/FactorUnitInterface.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"
#include "NansTimelineSystemUE4/Public/Event/UnrealEventProxy.h"
#include "Settings/FactorSettings.h"

void UNFactorUnitAdapterAbstract::Init()
{
	Event = UNEventDecoratorFactory::CreateObject<UNFactorEventDecorator>(this, UNFactorEventDecorator::StaticClass(), Reason);
	TSharedPtr<NEventInterface> EventProxy = MakeShareable(new NUnrealEventProxy(*Event));
	FactorUnit = MakeShareable(new NFactorUnit(FactorUnitValue, GetConfiguredOperator(), Duration, Reason, Delay, EventProxy));
}

void UNFactorUnitAdapterAbstract::Init(UNFactorEventDecorator* _Event)
{
	Event = _Event;
	TSharedPtr<NEventInterface> EventProxy = MakeShareable(new NUnrealEventProxy(*Event));
	FactorUnit = MakeShareable(new NFactorUnit(FactorUnitValue, GetConfiguredOperator(), EventProxy));
}

TSharedPtr<NEventInterface> UNFactorUnitAdapterAbstract::GetEvent()
{
	return FactorUnit->GetEvent();
}

TSharedPtr<NFactorOperatorInterface> UNFactorUnitAdapterAbstract::GetConfiguredOperator() const
{
	return MakeShareable(new NNullOperator());
}

TSharedPtr<NFactorOperatorInterface> UNFactorUnitAdapterAbstract::GetOperator() const
{
	return FactorUnit->GetOperator();
}

void UNFactorUnitAdapterAbstract::SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator)
{
	FactorUnit->SetOperator(_Operator);
}

float UNFactorUnitAdapterAbstract::GetFactorUnitValue() const
{
	return FactorUnit->GetFactorUnitValue();
}

FName UNFactorUnitAdapterAbstract::GetReason() const
{
	return FactorUnit->GetReason();
}

void UNFactorUnitAdapterAbstract::SetFactorUnitValue(float _Value)
{
	FactorUnit->SetFactorUnitValue(_Value);
}

bool UNFactorUnitAdapterAbstract::IsActivated() const
{
	return FactorUnit->IsActivated();
}

const FString UNFactorUnitAdapterAbstract::GetUID() const
{
	return FactorUnit->GetUID();
}

void UNFactorUnitAdapterAbstract::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	if (Ar.IsSaving() && FactorUnit.IsValid())
	{
		FactorUnitValue = FactorUnit->GetFactorUnitValue();
	}

	Ar << FactorUnitValue;

	if (Ar.IsLoading() && FactorUnit.IsValid())
	{
		SetFactorUnitValue(FactorUnitValue);
	}
}
