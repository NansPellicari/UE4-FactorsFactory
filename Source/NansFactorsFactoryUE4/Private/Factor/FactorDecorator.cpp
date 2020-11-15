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

#include "Factor/FactorDecorator.h"

#include "FactorUnit/FactorUnitView.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryUE4/Public/FactorUnit/UnrealFactorUnitProxy.h"
#include "NansTimelineSystemUE4/Public/Config/TimelineConfig.h"
#include "NansTimelineSystemUE4/Public/Event/EventView.h"
#include "NansTimelineSystemUE4/Public/TimelineBlueprintHelpers.h"

void UNFactorDecorator::Init(FName _Name, TSharedPtr<NTimelineInterface> _Timeline)
{
	Factor = MakeShareable(new NFactor(_Name, _Timeline));
	OnInit();
}

void UNFactorDecorator::Clear()
{
	Factor->Clear();
}

void UNFactorDecorator::SetName(FName _Name)
{
	Factor->SetName(_Name);
}

FName UNFactorDecorator::GetName() const
{
	return Factor->GetName();
}

TSharedPtr<NTimelineInterface> UNFactorDecorator::GetTimeline() const
{
	return Factor->GetTimeline();
}

float UNFactorDecorator::GetTime() const
{
	return Factor->GetTime();
}

UNFactorUnitView* UNFactorDecorator::CreateFactorUnit(const UClass* Class)
{
	static uint32 FactorUnitNum = 0;

	FString Name = FString::Format(TEXT("FactorUnit_{0}_"), {Class->GetFullName()});
	Name.AppendInt(++FactorUnitNum);

	return NewObject<UNFactorUnitView>(this, Class, FName(*Name));
}

UNOperatorProviderBase* UNFactorDecorator::CreateOperatorProvider(const UClass* Class)
{
	static uint32 OperatorNum = 0;

	FString Name = FString::Format(TEXT("OperatorProvider_{0}_"), {Class->GetFullName()});
	Name.AppendInt(++OperatorNum);

	return NewObject<UNOperatorProviderBase>(this, Class, FName(*Name));
}

TSharedPtr<NFactorUnitInterface> UNFactorDecorator::GetFactorUnit(uint32 Key) const
{
	return Factor->GetFactorUnit(Key);
}

TArray<TSharedPtr<NFactorUnitInterface>> UNFactorDecorator::GetFactors() const
{
	return Factor->GetFactors();
}

UNFactorUnitView* UNFactorDecorator::GetGCFactorUnit(int32 Index)
{
	if (GCAdapters.IsValidIndex(Index))
	{
		return GCAdapters[Index];
	}
	return nullptr;
}

int32 UNFactorDecorator::AddFactorUnit(UNFactorUnitView* FactorUnit)
{
	FConfiguredTimeline ConfiguredTimeline;
	ConfiguredTimeline.Name = GetTimeline()->GetLabel();
	TSharedPtr<NEventInterface> Event =
		UNTimelineBlueprintHelpers::GetTimeline(this, ConfiguredTimeline)
		->CreateNewEvent(FactorUnit->Reason, FactorUnit->Duration, FactorUnit->Delay);
	FactorUnit->Init(Event);
	// TODO refacto: remove this when OnEventExpired trigger.
	GCAdapters.Add(FactorUnit);

	return Factor->AddFactorUnit(MakeShareable(new NUnrealFactorUnitProxy(FactorUnit)));
}

int32 UNFactorDecorator::AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit)
{
	return Factor->AddFactorUnit(FactorUnit);
}

bool UNFactorDecorator::HasStateFlag(FString Flag) const
{
	return Factor->HasStateFlag(Flag);
}

bool UNFactorDecorator::GetStateFlag(FString Flag) const
{
	return Factor->GetStateFlag(Flag);
}

void UNFactorDecorator::SetStateFlag(FString Flag, bool Value)
{
	Factor->SetStateFlag(Flag, Value);
}

void UNFactorDecorator::RemoveStateFlag(FString Flag)
{
	Factor->RemoveStateFlag(Flag);
}

void UNFactorDecorator::AddFlag(ENFactorFlag Flag)
{
	Factor->AddFlag(Flag);
}

bool UNFactorDecorator::HasFlag(ENFactorFlag Flag) const
{
	return Factor->HasFlag(Flag);
}

void UNFactorDecorator::RemoveFlag(ENFactorFlag Flag)
{
	Factor->RemoveFlag(Flag);
}

void UNFactorDecorator::Debug(bool _bDebug)
{
	Factor->Debug(_bDebug);
}

void UNFactorDecorator::SupplyStateWithCurrentData(NFactorStateInterface& State)
{
	Factor->SupplyStateWithCurrentData(State);
}

void UNFactorDecorator::Serialize(FArchive& Ar)
{
	if (Ar.IsSaving())
	{
		FactorUnitStoreCount = Factor->GetFactors().Num();
	}

	Ar << FactorUnitStoreCount;

	if (Ar.IsLoading())
	{
		GCAdapters.Empty();
		Factor->Clear();
	}

	Factor->Archive(Ar);

	if (FactorUnitStoreCount > 0)
	{
		for (int32 Idx = 0; Idx < FactorUnitStoreCount; ++Idx)
		{
			TSharedPtr<NFactorUnitInterface> FactorUnit;

			if (Ar.IsLoading())
			{
				TSharedPtr<NUnrealFactorUnitProxy> Proxy = MakeShareable(new NUnrealFactorUnitProxy());
				Proxy->ArchiveWithFactor(Ar, this);
				FactorUnit = Proxy;
			}

			if (Ar.IsSaving()) FactorUnit = Factor->GetFactors()[Idx];

			FactorUnit->Archive(Ar);

			if (Ar.IsLoading())
			{
				Factor->AddFactorUnit(FactorUnit);
			}
		}
	}
}

void UNFactorDecorator::BeginDestroy()
{
	GCAdapters.Empty();
	Factor.Reset();
	Super::BeginDestroy();
}
