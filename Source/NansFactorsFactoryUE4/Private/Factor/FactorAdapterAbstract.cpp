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

#include "Factor/FactorAdapterAbstract.h"

#include "Attribute/FactorStackAttribute.h"
#include "Event/EventDecorator.h"
#include "Event/FactorEventDecorator.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/FactorInterface.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"
#include "NansTimelineSystemUE4/Public/Event/UnrealEventProxy.h"
#include "Settings/FactorSettings.h"

void UNFactorAdapterAbstract::Init()
{
	Event = UNEventDecoratorFactory::CreateObject<UNFactorEventDecorator>(this, UNFactorEventDecorator::StaticClass(), Reason);
	TSharedPtr<NEventInterface> EventProxy = MakeShareable(new NUnrealEventProxy(*Event));
	Factor = MakeShareable(new NFactor(FactorValue, GetConfiguredOperator(), Duration, Reason, Delay, EventProxy));
}

TSharedPtr<NEventInterface> UNFactorAdapterAbstract::GetEvent()
{
	return Factor->GetEvent();
}

TSharedPtr<FactorOperatorInterface> UNFactorAdapterAbstract::GetConfiguredOperator() const
{
	return MakeShareable(new NNullOperator());
}

TSharedPtr<FactorOperatorInterface> UNFactorAdapterAbstract::GetOperator() const
{
	return Factor->GetOperator();
}

float UNFactorAdapterAbstract::GetFactorValue() const
{
	return Factor->GetFactorValue();
}

FName UNFactorAdapterAbstract::GetReason() const
{
	return Factor->GetReason();
}

bool UNFactorAdapterAbstract::IsActivated() const
{
	return Factor->IsActivated();
}

uint32 UNFactorAdapterAbstract::GetUID() const
{
	return Factor->GetUID();
}
