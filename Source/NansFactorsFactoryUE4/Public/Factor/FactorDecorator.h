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

#pragma once

#include "CoreMinimal.h"
#include "NansFactorsFactoryCore/Public/FactorInterface.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"
#include "NansFactorsFactoryUE4/Public/FactorUnit/FactorUnitAdapterAbstract.h"
#include "NansTimelineSystemUE4/Public/Event/EventRecord.h"

#include "FactorDecorator.generated.h"

class NUnrealTimelineProxy;
class UNTimelineDecorator;
class NEventInterface;

/**
 * This struct is a record object used for savegame or get user feedbacks
 */
USTRUCT()
struct NANSFACTORSFACTORYUE4_API FNFactorUnitRecord
{
	friend class UNFactorDecorator;
	GENERATED_USTRUCT_BODY()

	FNFactorUnitRecord() {}
	FNFactorUnitRecord(UNFactorUnitAdapterAbstract* _FactorUnit)
	{
		FactorUnit = _FactorUnit;
		UId = FactorUnit->GetUID();
		OperatorName = FactorUnit->GetOperator()->GetName();
		Value = FactorUnit->GetFactorUnitValue();
	}

	/** The UNFactorUnitAdapterAbstract object */
	UPROPERTY(SkipSerialization)
	UNFactorUnitAdapterAbstract* FactorUnit = nullptr;
	/** The time it as been attached to the timeline in secs (differ to UNEventDecorator::StartedAt) */
	UPROPERTY(SkipSerialization)
	FString UId = FString("");
	/** This value to keep trace of what happens, usefull for  */
	UPROPERTY(SkipSerialization)
	FName OperatorName = FName("");
	/**  */
	UPROPERTY(SkipSerialization)
	float Value = -1.f;
	/** This is used only during serialization, it allow to re-instance the object on load */
	UPROPERTY(SkipSerialization)
	FString FactorUnitClassName = FString("");

	FNEventRecord& GetEventRecord(UNFactorDecorator* Factor);

	/** It manages Event object saving and loading */
	void Serialize(FArchive& Ar, UNFactorDecorator* Factor);

	/** Just save basic data, see FNFactorUnitRecord::Serialize() to see how FactorUnit object is managed */
	friend FArchive& operator<<(FArchive& Ar, FNFactorUnitRecord& Record)
	{
		if (Ar.IsSaving())
		{
			Record.FactorUnitClassName = Record.FactorUnit != nullptr ? Record.FactorUnit->GetClass()->GetPathName() : FString("");
		}

		Ar << Record.FactorUnitClassName;
		Ar << Record.UId;
		Ar << Record.OperatorName;
		Ar << Record.Value;

		return Ar;
	};
};

UCLASS()
class NANSFACTORSFACTORYUE4_API UNFactorDecorator : public UObject, public NFactorInterface
{
	friend struct FNFactorUnitRecord;
	GENERATED_BODY()
public:
	UNFactorDecorator() {}
	void Init(FName _Name, TSharedPtr<NTimelineInterface> _Timeline);
	UNFactorUnitAdapterAbstract* CreateFactorUnit(const UClass* Class);
	void OnTimelineEventExpired(TSharedPtr<NEventInterface> Event, const float& ExpiredTime, const int32& Index);
	TArray<FNFactorUnitRecord> GetFactorUnitStore() const;

	// BEGIN NFactorInterface override
	virtual void Clear() override;
	virtual void SetName(FName _Name) override;
	virtual FName GetName() const override;
	virtual TSharedPtr<NTimelineInterface> GetTimeline() const override;
	virtual float GetTime() const override;
	virtual TSharedRef<NFactorUnitInterface> GetFactorUnit(uint32 Key) const override;
	virtual TArray<TSharedPtr<NFactorUnitInterface>> GetFactors() const override;
	virtual void AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit) override;
	virtual bool HasFlag(FString Flag) const override;
	virtual bool GetFlag(FString Flag) const override;
	virtual void SetFlag(FString Flag, bool Value) override;
	virtual void Debug(bool _bDebug) override;
	virtual void SupplyStateWithCurrentData(NFactorStateInterface& State) override;
	// END NFactorInterface override

	// BEGIN UObject override
	virtual void Serialize(FArchive& Ar);
	virtual void BeginDestroy() override;
	// END UObject override

protected:
	TSharedPtr<NFactorInterface> Factor;
	UPROPERTY()
	TArray<FNFactorUnitRecord> FactorUnitStore;

	UPROPERTY(SaveGame)
	FName SavedName;

	UNTimelineDecorator* GetUnrealTimeline();
};
