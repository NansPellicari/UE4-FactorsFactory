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
#include "NansFactorsFactoryUE4/Public/FactorUnit/FactorUnitAdapter.h"
#include "NansTimelineSystemUE4/Public/Event/EventRecord.h"

#include "FactorDecorator.generated.h"

class NUnrealTimelineProxy;
class UNTimelineDecorator;
class NEventInterface;
class NUnrealFactorUnitProxy;

/**
 * This struct is a record object used for savegame or get user feedbacks
 */
USTRUCT()
struct NANSFACTORSFACTORYUE4_API FNFactorUnitRecord
{
	friend class UNFactorDecorator;
	GENERATED_USTRUCT_BODY()

	FNFactorUnitRecord() {}
	FNFactorUnitRecord(UNFactorUnitAdapter* _FactorUnit)
	{
		FactorUnit = _FactorUnit;
		UId = FactorUnit->GetUID();
		OperatorName = FactorUnit->GetOperator()->GetName();
		Value = FactorUnit->GetFactorUnitValue();
		OperatorProviderClassName = FactorUnit->OperatorProvider->GetClass()->GetPathName();
	}

	/** The UNFactorUnitAdapter object */
	UPROPERTY(SkipSerialization)
	UNFactorUnitAdapter* FactorUnit = nullptr;
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

	UPROPERTY(SkipSerialization)
	FString OperatorProviderClassName = FString("");

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
		Ar << Record.OperatorProviderClassName;
		Ar << Record.UId;
		Ar << Record.OperatorName;
		Ar << Record.Value;

		return Ar;
	};
};

UCLASS(Blueprintable)
class NANSFACTORSFACTORYUE4_API UNFactorDecorator : public UObject, public NFactorInterface
{
	friend struct FNFactorUnitRecord;
	GENERATED_BODY()
public:
	UNFactorDecorator() {}

	void Init(FName _Name, TSharedPtr<NTimelineInterface> _Timeline);
	UNFactorUnitAdapter* CreateFactorUnit(const UClass* Class);
	TArray<FNFactorUnitRecord> GetFactorUnitStore() const;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "FactorsFactory")
	void OnInit();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "FactorsFactory")
	void OnAddFactorUnit(UNFactorUnitAdapter* FactorUnit, int32 key);

	/**
	 * @warning The FactorUnit pointer is immediatly removed after this method is called.
	 *
	 * @param FactorUnit - A pointer to a factorUnit which end its lifetime.
	 */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "FactorsFactory")
	void OnFactorUnitExpired(UNFactorUnitAdapter* FactorUnit);

	UFUNCTION(BlueprintCallable, Category = "FactorsFactory")
	virtual FName GetName() const override;

	UFUNCTION(BlueprintCallable, Category = "FactorsFactory")
	virtual float GetTime() const override;

	UFUNCTION(BlueprintCallable, Category = "FactorsFactory")
	virtual bool HasStateFlag(FString Flag) const override;

	UFUNCTION(BlueprintCallable, Category = "FactorsFactory")
	virtual bool GetStateFlag(FString Flag) const override;

	UFUNCTION(BlueprintCallable, Category = "FactorsFactory")
	virtual void Debug(bool _bDebug) override;

	UFUNCTION(BlueprintCallable, Category = "FactorsFactory")
	virtual void SetStateFlag(FString Flag, bool Value) override;

	UFUNCTION(BlueprintCallable, Category = "FactorsFactory")
	virtual void RemoveStateFlag(FString Flag) override;

	// BEGIN NFactorInterface override
	virtual void Clear() override;
	virtual void SetName(FName _Name) override;
	virtual void AddFlag(ENFactorFlag Flag) override;
	virtual bool HasFlag(ENFactorFlag Flag) const override;
	virtual void RemoveFlag(ENFactorFlag Flag) override;
	virtual TSharedPtr<NTimelineInterface> GetTimeline() const override;
	virtual TSharedPtr<NFactorUnitInterface> GetFactorUnit(uint32 Key) const override;
	virtual TArray<TSharedPtr<NFactorUnitInterface>> GetFactors() const override;
	virtual int32 AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit) override;
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

	virtual bool PreAddUnit(NUnrealFactorUnitProxy* Unit);
	virtual void PostAddUnit(NUnrealFactorUnitProxy* Unit, int32 Key);

	UNTimelineDecorator* GetUnrealTimeline();
	void OnTimelineEventExpired(TSharedPtr<NEventInterface> Event, const float& ExpiredTime, const int32& Index);
};
