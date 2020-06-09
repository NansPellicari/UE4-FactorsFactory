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
	virtual void AddFactorUnit(FName FactorName, TSharedPtr<NFactorUnitInterface> FactorUnit) override
	{
		AddCall(FString::Format(TEXT("{0}"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		StubFactorsFactoryClient::AddFactorUnit(FactorName, FactorUnit);
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
