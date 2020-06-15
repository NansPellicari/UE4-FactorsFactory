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

class NFactorInterface;
class NFactorUnitInterface;
class NFactorStateInterface;
class NTimelineInterface;

enum class ENFactorFlag : uint8
{
	CanNotAddNewUnit
};

class NANSFACTORSFACTORYCORE_API NFactorInterface
{
public:
	virtual void Clear() = 0;
	virtual void SetName(FName _Name) = 0;
	virtual FName GetName() const = 0;
	virtual TSharedPtr<NTimelineInterface> GetTimeline() const = 0;
	virtual float GetTime() const = 0;
	virtual TSharedPtr<NFactorUnitInterface> GetFactorUnit(uint32 Key) const = 0;
	virtual TArray<TSharedPtr<NFactorUnitInterface>> GetFactors() const = 0;
	virtual void AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit) = 0;
	virtual bool HasStateFlag(FString Flag) const = 0;
	virtual bool GetStateFlag(FString Flag) const = 0;
	virtual void SetStateFlag(FString Flag, bool Value) = 0;
	virtual void RemoveStateFlag(FString Flag) = 0;
	virtual void AddFlag(ENFactorFlag Flag) = 0;
	virtual bool HasFlag(ENFactorFlag Flag) const = 0;
	virtual void RemoveFlag(ENFactorFlag Flag) = 0;
	virtual void Debug(bool _bDebug) = 0;
	virtual void SupplyStateWithCurrentData(NFactorStateInterface& State) = 0;
};
