#include "FactorsFactoryClient.h"

#include "FactorInterface.h"
#include "FactorStack.h"
#include "FactorStackInterface.h"
#include "FactorState.h"
#include "FactorStateInterface.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "NansTimelineSystemCore/Public/TimelineInterface.h"
#include "NullFactorState.h"

void NFactorsFactoryClient::RemoveStack(FName StackName)
{
	if (myensureMsgf(StacksList.Contains(StackName), TEXT("The stack \"%s\" does not exists"), *StackName.ToString()))
	{
		StacksList.Remove(StackName);
	}
}

void NFactorsFactoryClient::CreateStack(FName StackName, TSharedPtr<NTimelineInterface> _Timeline)
{
	if (myensureMsgf(!StacksList.Contains(StackName), TEXT("The stack \"%s\" has been already created"), *StackName.ToString()))
	{
		TSharedPtr<NFactorStackInterface> Stack = MakeShareable(new NFactorStack(StackName, _Timeline));
		StacksList.Add(StackName, Stack);
	}
}

void NFactorsFactoryClient::CreateStack(TArray<FName> StackNames, TSharedPtr<NTimelineInterface> Timeline)
{
	for (FName Name : StackNames)
	{
		CreateStack(Name, Timeline);
	}
}

void NFactorsFactoryClient::AddStack(TSharedPtr<NFactorStackInterface> Stack)
{
	if (myensureMsgf(
			!StacksList.Contains(Stack->GetName()), TEXT("The stack \"%s\" has been already added"), *Stack->GetName().ToString()))
	{
		StacksList.Add(Stack->GetName(), Stack);
	}
}

void NFactorsFactoryClient::GetState(FName StackName, NFactorStateInterface& State)
{
	if (StacksList.Contains(StackName))
	{
		TSharedPtr<NFactorStackInterface> Stack = StacksList[StackName];
		mycheckf(Stack.IsValid(), TEXT("The stack '%s' existed in the stack list but has been removed"), *StackName.ToString());
		Stack->SupplyStateWithCurrentData(State);
	}
	else
	{
		State = *(new NNullFactorState());
	}
}

TArray<NFactorStateInterface*> NFactorsFactoryClient::GetStates(TArray<FName> StackNames, NFactorStateInterface* StateTemplate)
{
	TArray<NFactorStateInterface*> States;
	for (FName Name : StackNames)
	{
		NFactorStateInterface* State = StateTemplate->Clone();
		GetState(Name, *State);
		if (State != nullptr)
		{
			States.Add(State);
		}
	}
	StateTemplate = nullptr;
	return States;
}

void NFactorsFactoryClient::AddFactor(TArray<FName> StackNames, TSharedPtr<NFactorInterface> Factor)
{
	for (FName Name : StackNames)
	{
		AddFactor(Name, Factor);
	}
}

void NFactorsFactoryClient::AddFactor(FName StackName, TSharedPtr<NFactorInterface> Factor)
{
	mycheck(StackName != NAME_None);
	mycheckf(StacksList.Contains(StackName), TEXT("Stack %s does not exists"), *StackName.ToString());
	TSharedPtr<NFactorStackInterface> Stack = StacksList[StackName];

	if (!Stack.IsValid() || !Factor.IsValid())
	{
		return;
	}
	Stack->AddFactor(Factor);
}

void NFactorsFactoryClient::SetDebug(const TArray<FName> StackNames, bool bDebug)
{
	for (FName StackName : StackNames)
	{
		mycheckf(StacksList.Contains(StackName), TEXT("Stack %s does not exists"), *StackName.ToString());

		if (!ensureMsgf(
				StacksList.Contains(StackName), TEXT("Can not debug an inexistant stack named \"%s\""), *StackName.ToString()))
			return;

		TSharedPtr<NFactorStackInterface> Stack = StacksList[StackName];
		Stack->Debug(bDebug);
	}
}
