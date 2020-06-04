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
#include "FactorStackInterface.h"

class UNFactorStackDecorator;

class NANSFACTORSFACTORYUE4_API NUnrealFactorStackProxy : public NFactorStackInterface
{
public:
	UNFactorStackDecorator& Stack;
	NUnrealFactorStackProxy(UNFactorStackDecorator& _Stack) : Stack(_Stack) {}
	virtual void Reset();
	virtual void SetName(FName _Name);
	virtual FName GetName() const;
	virtual float GetTime() const;
	virtual TSharedRef<NFactorInterface> GetFactor(uint32 Key) const;
	virtual TArray<TSharedPtr<NFactorInterface>> GetFactors() const;
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor);
	virtual bool HasFlag(FString Flag) const;
	virtual bool GetFlag(FString Flag) const;
	virtual void SetFlag(FString Flag, bool Value);
	virtual void Debug(bool _bDebug);
	virtual void SupplyStateWithCurrentData(NFactorStateInterface& State);
	virtual UNFactorStackDecorator* GetUnrealObject() const;
};
