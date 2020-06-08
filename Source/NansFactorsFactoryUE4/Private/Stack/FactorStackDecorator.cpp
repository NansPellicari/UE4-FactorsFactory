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

#include "Stack/FactorStackDecorator.h"

#include "NansFactorsFactoryCore/Public/FactorStack.h"
#include "NansFactorsFactoryUE4/Public/Event/FactorEventDecorator.h"
#include "NansFactorsFactoryUE4/Public/Factor/FactorAdapterAbstract.h"
#include "NansFactorsFactoryUE4/Public/Factor/UnrealFactorProxy.h"
#include "NansTimelineSystemUE4/Public/TimelineDecorator.h"
#include "NansTimelineSystemUE4/Public/UnrealTimelineProxy.h"

void FNFactorRecord::Serialize(FArchive& Ar, UNFactorStackDecorator* Stack)
{
	if (Ar.IsSaving() && Factor != nullptr)
	{
		Factor->Serialize(Ar);
	}

	if (Ar.IsLoading() && !FactorClassName.IsEmpty())
	{
		auto EventRecord = GetEventRecord(Stack);
		if (EventRecord.Event == nullptr) return;

		UClass* Class = FindObject<UClass>(ANY_PACKAGE, *FactorClassName);
		Factor = Stack->CreateFactor(Class);
		UNFactorEventDecorator* Event = Cast<UNFactorEventDecorator>(EventRecord.Event);
		mycheckf(Event != nullptr,
			TEXT("Problems occured during serialization of FNFactorRecord,"
				 "The associated event has not been found for UID %s"),
			*UId);

		Factor->Init(Event);
		Factor->Serialize(Ar);
	}
}

FNEventRecord& FNFactorRecord::GetEventRecord(UNFactorStackDecorator* Stack)
{
	auto UTimeline = Stack->GetUnrealTimeline();
	auto EventRecord = UTimeline->GetEventRecord(UId);
	mycheckf(EventRecord != nullptr,
		TEXT("Problems occured during serialization of FNFactorRecord,"
			 "The associated event record has not been found for UID %s"),
		*UId);

	return *EventRecord;
}

void UNFactorStackDecorator::Init(FName _Name, TSharedPtr<NTimelineInterface> _Timeline)
{
	Stack = MakeShareable(new NFactorStack(_Name, _Timeline));
	Stack->GetTimeline()->OnEventExpired().AddUObject(this, &UNFactorStackDecorator::OnTimelineEventExpired);
}

void UNFactorStackDecorator::OnTimelineEventExpired(TSharedPtr<NEventInterface> Event, const float& ExpiredTime, const int32& Index)
{
	const FString& UId = Event->GetUID();
	FNFactorRecord* FactorRecord = FactorStore.FindByPredicate([UId](const FNFactorRecord& Record) { return Record.UId == UId; });

	// It could be an event from an another stack or an another type
	if (FactorRecord == nullptr) return;

	FactorRecord->Factor = nullptr;
}

void UNFactorStackDecorator::Clear()
{
	FactorStore.Empty();
	Stack->Clear();
}

void UNFactorStackDecorator::SetName(FName _Name)
{
	Stack->SetName(_Name);
}

FName UNFactorStackDecorator::GetName() const
{
	return Stack->GetName();
}

TSharedPtr<NTimelineInterface> UNFactorStackDecorator::GetTimeline() const
{
	return Stack->GetTimeline();
}

float UNFactorStackDecorator::GetTime() const
{
	return Stack->GetTime();
}

UNFactorAdapterAbstract* UNFactorStackDecorator::CreateFactor(const UClass* Class)
{
	static uint32 FactorNum = 0;

	FString Name = FString::Format(TEXT("Factor_{0}_"), {Class->GetFullName()});
	Name.AppendInt(++FactorNum);

	return NewObject<UNFactorAdapterAbstract>(this, Class, FName(*Name));
}

TSharedRef<NFactorInterface> UNFactorStackDecorator::GetFactor(uint32 Key) const
{
	return Stack->GetFactor(Key);
}

TArray<TSharedPtr<NFactorInterface>> UNFactorStackDecorator::GetFactors() const
{
	return Stack->GetFactors();
}

TArray<FNFactorRecord> UNFactorStackDecorator::GetFactorStore() const
{
	return FactorStore;
}

void UNFactorStackDecorator::AddFactor(TSharedPtr<NFactorInterface> Factor)
{
	auto Proxy = dynamic_cast<NUnrealFactorProxy*>(Factor.Get());
	mycheckf(Proxy != nullptr, TEXT("You should passed NUnrealFactorProxy inherited stack only"));
	mycheckf(Proxy->GetUnrealObject() != nullptr,
		TEXT("You should instanciate your stack proxy with a UNFactorAdapterAbstract inherited stack"));

	FactorStore.Add(FNFactorRecord(Proxy->GetUnrealObject()));

	Stack->AddFactor(Factor);
}

bool UNFactorStackDecorator::HasFlag(FString Flag) const
{
	return Stack->HasFlag(Flag);
}

bool UNFactorStackDecorator::GetFlag(FString Flag) const
{
	return Stack->GetFlag(Flag);
}
void UNFactorStackDecorator::SetFlag(FString Flag, bool Value)
{
	Stack->SetFlag(Flag, Value);
}
void UNFactorStackDecorator::Debug(bool _bDebug)
{
	Stack->Debug(_bDebug);
}
void UNFactorStackDecorator::SupplyStateWithCurrentData(NFactorStateInterface& State)
{
	Stack->SupplyStateWithCurrentData(State);
}

UNTimelineDecorator* UNFactorStackDecorator::GetUnrealTimeline()
{
	auto UnrealTimeline = dynamic_cast<NUnrealTimelineProxy*>(Stack->GetTimeline().Get());
	mycheckf(UnrealTimeline != nullptr, TEXT("A factor Stack should work only with a NUnrealTimelineProxy object"));
	return UnrealTimeline->GetUnrealObject();
}

void UNFactorStackDecorator::Serialize(FArchive& Ar)
{
	// Remove actual factor to avoid cumulate old factors + new factors currenlty earned
	if (Ar.IsSaving())
	{
		SavedName = Stack->GetName();
	}

	if (Ar.IsLoading())
	{
		FactorStore.Empty();
	}

	Ar << FactorStore;
	Ar << SavedName;

	if (Ar.IsLoading())
	{
		Stack->Clear();
		Stack->SetName(SavedName);
		SavedName = NAME_None;
	}

	if (FactorStore.Num() > 0)
	{
		for (FNFactorRecord& Record : FactorStore)
		{
			Record.Serialize(Ar, this);
			if (Ar.IsLoading() && Record.Factor != nullptr)
			{
				Stack->AddFactor(MakeShareable(new NUnrealFactorProxy(Record.Factor)));
			}
		}
	}
}

void UNFactorStackDecorator::BeginDestroy()
{
	FactorStore.Empty();
	Stack.Reset();
	Super::BeginDestroy();
}
