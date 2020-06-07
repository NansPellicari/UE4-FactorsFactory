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
#include "NansFactorsFactoryCore/Public/FactorStackInterface.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"
#include "NansTimelineSystemUE4/Public/Event/EventRecord.h"

#include "FactorStackDecorator.generated.h"

class UNFactorAdapterAbstract;
class NUnrealTimelineProxy;
class UNTimelineDecorator;

/**
 * This struct is a record object used for savegame or get user feedbacks
 */
USTRUCT()
struct NANSFACTORSFACTORYUE4_API FNFactorRecord
{
	friend class UNFactorStackDecorator;
	GENERATED_USTRUCT_BODY()

	FNFactorRecord() {}
	FNFactorRecord(UNFactorAdapterAbstract* _Factor)
	{
		Factor = _Factor;
		UId = Factor->GetUID();
		OperatorName = Factor->GetOperator()->GetName();
		// TODO create a NFactor::GetValueForComputation() to allow having the initial value with GetFactorValue
		Value = Factor->GetFactorValue();
	}

	/** The UNFactorAdapterAbstract object */
	UPROPERTY(SkipSerialization)
	UNFactorAdapterAbstract* Factor = nullptr;
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
	FString FactorClassName = FString("");

	FNEventRecord& GetEventRecord(UNFactorStackDecorator* Stack);

	/** It manages Event object saving and loading */
	void Serialize(FArchive& Ar, UNFactorStackDecorator* Stack);

	/** Just save basic data, see FNFactorRecord::Serialize() to see how Factor object is managed */
	friend FArchive& operator<<(FArchive& Ar, FNFactorRecord& Record)
	{
		if (Ar.IsSaving())
		{
			Record.FactorClassName = Record.Factor != nullptr ? Record.Factor->GetClass()->GetPathName() : FString("");
		}

		Ar << Record.FactorClassName;
		Ar << Record.UId;
		Ar << Record.OperatorName;
		Ar << Record.Value;

		return Ar;
	};
};

UCLASS()
class NANSFACTORSFACTORYUE4_API UNFactorStackDecorator : public UObject, public NFactorStackInterface
{
	friend struct FNFactorRecord;
	GENERATED_BODY()
public:
	UNFactorStackDecorator() {}
	void Init(FName _Name, TSharedPtr<NTimelineInterface> _Timeline);
	UNFactorAdapterAbstract* CreateFactor(const UClass* Class);

	// BEGIN NFactorStackInterface override
	virtual void Reset() override;
	virtual void SetName(FName _Name) override;
	virtual FName GetName() const override;
	virtual TSharedPtr<NTimelineInterface> GetTimeline() const override;
	virtual float GetTime() const override;
	virtual TSharedRef<NFactorInterface> GetFactor(uint32 Key) const override;
	virtual TArray<TSharedPtr<NFactorInterface>> GetFactors() const override;
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) override;
	virtual bool HasFlag(FString Flag) const override;
	virtual bool GetFlag(FString Flag) const override;
	virtual void SetFlag(FString Flag, bool Value) override;
	virtual void Debug(bool _bDebug) override;
	virtual void SupplyStateWithCurrentData(NFactorStateInterface& State) override;
	// END NFactorStackInterface override

	// BEGIN UObject override
	virtual void Serialize(FArchive& Ar);
	// END UObject override

protected:
	TSharedPtr<NFactorStackInterface> Stack;
	UPROPERTY()
	TArray<FNFactorRecord> FactorStore;

	UPROPERTY(SaveGame)
	FName SavedName;

	UNTimelineDecorator* GetUnrealTimeline();
};
