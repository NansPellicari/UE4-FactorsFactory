#include "FactorsFactoryClient.h"

#include "FactorInterface.h"
#include "FactorStack.h"
#include "FactorState.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
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
		TSharedPtr<NFactorStack> Stack = MakeShareable(new NFactorStack(StackName, _Timeline));
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

NFactorState* NFactorsFactoryClient::GetState(FName StackName)
{
	NFactorState* State = new NNullFactorState();

	if (StacksList.Contains(StackName))
	{
		TSharedPtr<NFactorStack> Stack = StacksList[StackName];
		mycheckf(Stack != nullptr, TEXT("The stack '%s' existed in the stack list but has been removed"), *StackName.ToString());
		State = Stack->GetCurrentState();
	}

	return State;
}

TArray<NFactorState*> NFactorsFactoryClient::GetStates(TArray<FName> StackNames)
{
	TArray<NFactorState*> States;
	for (FName Name : StackNames)
	{
		NFactorState* State = GetState(Name);
		if (State != nullptr)
		{
			States.Add(State);
		}
	}

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
	TSharedPtr<NFactorStack> Stack = StacksList[StackName];

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

		TSharedPtr<NFactorStack> Stack = StacksList[StackName];
		Stack->bDebug = bDebug;
	}
}
