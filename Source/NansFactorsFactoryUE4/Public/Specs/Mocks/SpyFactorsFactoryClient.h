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
#include "NansFactorsFactoryCore/Public/FactorsFactoryClientInterface.h"
#include "Specs/Mocks/StubFactorsFactoryClient.h"

class SpyFactorsFactoryClient : public StubFactorsFactoryClient
{
public:
	TMap<FString, uint32> MethodCalls;

	SpyFactorsFactoryClient() {}
	virtual ~SpyFactorsFactoryClient() {}
	virtual void CreateFactor(FName FactorName, TSharedPtr<NTimelineInterface> Timeline) override
	{
		AddCall(FString::Format(TEXT("{0}_1"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		StubFactorsFactoryClient::CreateFactor(FactorName, Timeline);
	}
	virtual void CreateFactor(TArray<FName> FactorNames, TSharedPtr<NTimelineInterface> Timeline) override
	{
		AddCall(FString::Format(TEXT("{0}_2"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		StubFactorsFactoryClient::CreateFactor(FactorNames, Timeline);
	}
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) override
	{
		AddCall(FString::Format(TEXT("{0}"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		StubFactorsFactoryClient::AddFactor(Factor);
	}
	virtual void RemoveFactor(FName FactorName) override
	{
		AddCall(FString::Format(TEXT("{0}"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		StubFactorsFactoryClient::RemoveFactor(FactorName);
	}
	virtual void GetState(FName FactorName, NFactorStateInterface& State) override
	{
		AddCall(FString::Format(TEXT("{0}"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		StubFactorsFactoryClient::GetState(FactorName, State);
	}
	virtual TArray<NFactorStateInterface*> GetStates(TArray<FName> FactorNames, NFactorStateInterface* StateTemplate) override
	{
		AddCall(FString::Format(TEXT("{0}"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		return StubFactorsFactoryClient::GetStates(FactorNames, StateTemplate);
	}
	virtual int32 AddFactorUnit(FName FactorName, TSharedPtr<NFactorUnitInterface> FactorUnit) override
	{
		AddCall(FString::Format(TEXT("{0}"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		return StubFactorsFactoryClient::AddFactorUnit(FactorName, FactorUnit);
	}
	virtual TSharedPtr<NFactorUnitInterface> GetFactorUnit(FName FactorName, int32 Key) override
	{
		AddCall(FString::Format(TEXT("{0}"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		return StubFactorsFactoryClient::GetFactorUnit(FactorName, Key);
	}
	virtual void SetDebug(const TArray<FName> FactorNames, bool bDebug) override
	{
		AddCall(FString::Format(TEXT("{0}"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		StubFactorsFactoryClient::SetDebug(FactorNames, bDebug);
	}
	void Clear()
	{
		MethodCalls.Empty();
	}
	uint32 GetCall(FString FnName)
	{
		if (!MethodCalls.Contains(FnName))
		{
			return -1.f;
		}
		return MethodCalls[FnName];
	}

protected:
	void AddCall(FString FnName)
	{
		uint32& Count = MethodCalls.FindOrAdd(FnName);
		++Count;
	}
};
