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
	virtual void CreateStack(FName StackName, TSharedPtr<NTimelineInterface> Timeline) override
	{
		AddCall(FString::Format(TEXT("{0}_1"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		StubFactorsFactoryClient::CreateStack(StackName, Timeline);
	}
	virtual void CreateStack(TArray<FName> StackNames, TSharedPtr<NTimelineInterface> Timeline) override
	{
		AddCall(FString::Format(TEXT("{0}_2"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		StubFactorsFactoryClient::CreateStack(StackNames, Timeline);
	}
	virtual void AddStack(TSharedPtr<NFactorStackInterface> Stack) override
	{
		AddCall(FString::Format(TEXT("{0}"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		StubFactorsFactoryClient::AddStack(Stack);
	}
	virtual void RemoveStack(FName StackName) override
	{
		AddCall(FString::Format(TEXT("{0}"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		StubFactorsFactoryClient::RemoveStack(StackName);
	}
	virtual void GetState(FName StackName, NFactorStateInterface& State) override
	{
		AddCall(FString::Format(TEXT("{0}"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		StubFactorsFactoryClient::GetState(StackName, State);
	}
	virtual TArray<NFactorStateInterface*> GetStates(TArray<FName> StackNames, NFactorStateInterface* StateTemplate) override
	{
		AddCall(FString::Format(TEXT("{0}"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		return StubFactorsFactoryClient::GetStates(StackNames, StateTemplate);
	}
	virtual void AddFactor(FName StackName, TSharedPtr<NFactorInterface> Factor) override
	{
		AddCall(FString::Format(TEXT("{0}"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		StubFactorsFactoryClient::AddFactor(StackName, Factor);
	}
	virtual void SetDebug(const TArray<FName> StackNames, bool bDebug) override
	{
		AddCall(FString::Format(TEXT("{0}"), {ANSI_TO_TCHAR(__FUNCTION__)}));
		StubFactorsFactoryClient::SetDebug(StackNames, bDebug);
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
