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
#include "Stack/FactorStackDecorator.h"

class NANSFACTORSFACTORYUE4_API UNUnrealFactorStackProxy : public NFactorStackInterface
{
public:
	UNFactorStackDecorator& Stack;
	UNUnrealFactorStackProxy(UNFactorStackDecorator& _Stack) : Stack(_Stack) {}
	virtual void Reset() override
	{
		Stack.Reset();
	}
	virtual void SetName(FName _Name) override
	{
		Stack.SetName(_Name);
	}
	virtual FName GetName() const override
	{
		return Stack.GetName();
	}
	virtual float GetTime() const override
	{
		return Stack.GetTime();
	}
	virtual TSharedRef<NFactorInterface> GetFactor(uint32 Key) const override
	{
		return Stack.GetFactor(Key);
	}
	virtual TArray<TSharedPtr<NFactorInterface>> GetFactors() const override
	{
		return Stack.GetFactors();
	}
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) override
	{
		Stack.AddFactor(Factor);
	}
	virtual bool HasFlag(FString Flag) const override
	{
		return Stack.HasFlag(Flag);
	}
	virtual bool GetFlag(FString Flag) const override
	{
		return Stack.GetFlag(Flag);
	}
	virtual void SetFlag(FString Flag, bool Value) override
	{
		Stack.SetFlag(Flag, Value);
	}
	virtual void Debug(bool _bDebug) override
	{
		Stack.Debug(_bDebug);
	}
	virtual NFactorStateInterface* GetCurrentState() override
	{
		return Stack.GetCurrentState();
	}
};
