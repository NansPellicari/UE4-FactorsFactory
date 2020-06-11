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

#include "FactorUnit/FactorUnitAdapter.h"

#include "Attribute/FactorAttribute.h"
#include "NansFactorsFactoryCore/Public/FactorUnit.h"
#include "NansFactorsFactoryCore/Public/FactorUnitInterface.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"
#include "NansFactorsFactoryUE4/Public/Operator/OperatorProviders.h"
#include "NansTimelineSystemUE4/Public/Event/EventDecorator.h"
#include "NansTimelineSystemUE4/Public/Event/UnrealEventProxy.h"
#include "Settings/FactorSettings.h"

void UNFactorUnitAdapter::Init()
{
	UClass* TheEventClass = EventClass;
	if (!TheEventClass->IsChildOf(UNEventDecorator::StaticClass()))
	{
		UE_LOG(LogTemp,
			Error,
			TEXT("%s - The event class should be a subclass of UNEventDecorator!"
				 "To avoid crashing the game, it has been replaced by UNEventDecorator."),
			ANSI_TO_TCHAR(__FUNCTION__));
		TheEventClass = UNEventDecorator::StaticClass();
	}

	Event = UNEventDecoratorFactory::CreateObject<UNEventDecorator>(this, TheEventClass, Reason);
	TSharedPtr<NEventInterface> EventProxy = MakeShareable(new NUnrealEventProxy(*Event));
	FactorUnit = MakeShareable(new NFactorUnit(FactorUnitValue, GetConfiguredOperator(), Duration, Reason, Delay, EventProxy));
}

void UNFactorUnitAdapter::Init(UNEventDecorator* _Event)
{
	Event = _Event;
	TSharedPtr<NEventInterface> EventProxy = MakeShareable(new NUnrealEventProxy(*Event));
	FactorUnit = MakeShareable(new NFactorUnit(FactorUnitValue, GetConfiguredOperator(), EventProxy));
}

TSharedPtr<NEventInterface> UNFactorUnitAdapter::GetEvent()
{
	return FactorUnit->GetEvent();
}

TSharedPtr<NFactorOperatorInterface> UNFactorUnitAdapter::GetConfiguredOperator()
{
	UClass* OperatorProviderClass = OperatorProvider;
	UNOperatorProviderBase* Provider = NewObject<UNOperatorProviderBase>(this, OperatorProviderClass, NAME_None, RF_Transient);
	return Provider->GetOperator();
}

TSharedPtr<NFactorOperatorInterface> UNFactorUnitAdapter::GetOperator() const
{
	return FactorUnit->GetOperator();
}

void UNFactorUnitAdapter::SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator)
{
	FactorUnit->SetOperator(_Operator);
}

float UNFactorUnitAdapter::GetFactorUnitValue() const
{
	return FactorUnit->GetFactorUnitValue();
}

UNEventDecorator* UNFactorUnitAdapter::GetEventDecorator()
{
	return Event;
}

FName UNFactorUnitAdapter::GetReason() const
{
	return FactorUnit->GetReason();
}

void UNFactorUnitAdapter::SetFactorUnitValue(float _Value)
{
	FactorUnit->SetFactorUnitValue(_Value);
}

bool UNFactorUnitAdapter::IsActivated() const
{
	return FactorUnit->IsActivated();
}

const FString UNFactorUnitAdapter::GetUID() const
{
	return FactorUnit->GetUID();
}

void UNFactorUnitAdapter::Serialize(FArchive& Ar)
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
		SetOperator(GetConfiguredOperator());
	}
}
