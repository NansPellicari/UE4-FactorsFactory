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

#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryUE4/Public/FactorUnit/UnrealFactorUnitProxy.h"
#include "NansTimelineSystemUE4/Public/Event/EventDecorator.h"
#include "NansTimelineSystemUE4/Public/TimelineDecorator.h"
#include "NansTimelineSystemUE4/Public/UnrealTimelineProxy.h"

void FNFactorUnitRecord::Serialize(FArchive& Ar, UNFactorDecorator* Factor)
{
	if (Ar.IsSaving() && FactorUnit != nullptr)
	{
		FactorUnit->Serialize(Ar);
	}

	if (Ar.IsLoading() && !FactorUnitClassName.IsEmpty())
	{
		auto EventRecord = GetEventRecord(Factor);
		if (EventRecord.Event == nullptr) return;

		UClass* Class = FindObject<UClass>(ANY_PACKAGE, *FactorUnitClassName);
		FactorUnit = Factor->CreateFactorUnit(Class);
		UNEventDecorator* Event = Cast<UNEventDecorator>(EventRecord.Event);
		mycheckf(Event != nullptr,
			TEXT("Problems occured during serialization of FNFactorUnitRecord,"
				 "The associated event has not been found for UID %s"),
			*UId);
		UClass* OperatorProviderClass = FindObject<UClass>(ANY_PACKAGE, *OperatorProviderClassName);
		FactorUnit->OperatorProvider = OperatorProviderClass;

		FactorUnit->Init(Event);
		FactorUnit->Serialize(Ar);
	}
}

FNEventRecord& FNFactorUnitRecord::GetEventRecord(UNFactorDecorator* Factor)
{
	auto UTimeline = Factor->GetUnrealTimeline();
	auto EventRecord = UTimeline->GetEventRecord(UId);
	mycheckf(EventRecord != nullptr,
		TEXT("Problems occured during serialization of FNFactorUnitRecord,"
			 "The associated event record has not been found for UID %s"),
		*UId);

	return *EventRecord;
}

void UNFactorDecorator::Init(FName _Name, TSharedPtr<NTimelineInterface> _Timeline)
{
	Factor = MakeShareable(new NFactor(_Name, _Timeline));
	Factor->GetTimeline()->OnEventExpired().AddUObject(this, &UNFactorDecorator::OnTimelineEventExpired);
	OnInit();
}

void UNFactorDecorator::OnTimelineEventExpired(TSharedPtr<NEventInterface> Event, const float& ExpiredTime, const int32& Index)
{
	const FString& UId = Event->GetUID();
	FNFactorUnitRecord* FactorUnitRecord =
		FactorUnitStore.FindByPredicate([UId](const FNFactorUnitRecord& Record) { return Record.UId == UId; });

	// It could be an event from an another factor or an another type
	if (FactorUnitRecord == nullptr) return;

	OnFactorUnitExpired(FactorUnitRecord->FactorUnit);

	FactorUnitRecord->FactorUnit = nullptr;
}

void UNFactorDecorator::Clear()
{
	FactorUnitStore.Empty();
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

UNFactorUnitAdapter* UNFactorDecorator::CreateFactorUnit(const UClass* Class)
{
	static uint32 FactorUnitNum = 0;

	FString Name = FString::Format(TEXT("FactorUnit_{0}_"), {Class->GetFullName()});
	Name.AppendInt(++FactorUnitNum);

	return NewObject<UNFactorUnitAdapter>(this, Class, FName(*Name));
}

TSharedRef<NFactorUnitInterface> UNFactorDecorator::GetFactorUnit(uint32 Key) const
{
	return Factor->GetFactorUnit(Key);
}

TArray<TSharedPtr<NFactorUnitInterface>> UNFactorDecorator::GetFactors() const
{
	return Factor->GetFactors();
}

TArray<FNFactorUnitRecord> UNFactorDecorator::GetFactorUnitStore() const
{
	return FactorUnitStore;
}

void UNFactorDecorator::AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit)
{
	auto Proxy = dynamic_cast<NUnrealFactorUnitProxy*>(FactorUnit.Get());
	mycheckf(Proxy != nullptr, TEXT("You should passed NUnrealFactorUnitProxy (or derivation) only"));
	mycheckf(Proxy->GetUnrealObject() != nullptr,
		TEXT("You should instanciate your factorUnit proxy with a UNFactorUnitAdapter base class"));

	FactorUnitStore.Add(FNFactorUnitRecord(Proxy->GetUnrealObject()));

	Factor->AddFactorUnit(FactorUnit);
	OnAddFactorUnit(Proxy->GetUnrealObject());
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

UNTimelineDecorator* UNFactorDecorator::GetUnrealTimeline()
{
	auto UnrealTimeline = dynamic_cast<NUnrealTimelineProxy*>(Factor->GetTimeline().Get());
	mycheckf(UnrealTimeline != nullptr, TEXT("A factor Factor should work only with a NUnrealTimelineProxy object"));
	return UnrealTimeline->GetUnrealObject();
}

void UNFactorDecorator::Serialize(FArchive& Ar)
{
	if (Ar.IsSaving())
	{
		SavedName = Factor.IsValid() ? Factor->GetName() : SavedName;
	}

	if (Ar.IsLoading())
	{
		FactorUnitStore.Empty();
	}

	Ar << FactorUnitStore;
	Ar << SavedName;

	if (Ar.IsLoading())
	{
		// Remove actual factor to avoid cumulate old factors + new factors currenlty earned
		if (Factor.IsValid())
		{
			Factor->Clear();
			Factor->SetName(SavedName);
		}
		SavedName = NAME_None;
	}

	if (FactorUnitStore.Num() > 0)
	{
		for (FNFactorUnitRecord& Record : FactorUnitStore)
		{
			Record.Serialize(Ar, this);
			if (Ar.IsLoading() && Record.FactorUnit != nullptr)
			{
				Factor->AddFactorUnit(MakeShareable(new NUnrealFactorUnitProxy(Record.FactorUnit)));
			}
		}
	}
}

void UNFactorDecorator::BeginDestroy()
{
	FactorUnitStore.Empty();
	Factor.Reset();
	Super::BeginDestroy();
}
