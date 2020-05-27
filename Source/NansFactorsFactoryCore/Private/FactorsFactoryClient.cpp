#include "FactorsFactoryClient.h"

#include "FactorInterface.h"
#include "FactorStack.h"
#include "FactorState.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NullFactorState.h"

void NFactorsFactoryClient::RemoveStack(FName StackName)
{
    if (myensureMsgf(StacksList.Contains(StackName), TEXT("The stack \"%s\" does not exists"), *StackName.ToString()))
    {
        StacksList.Remove(StackName);
    }
}

void NFactorsFactoryClient::CreateStack(FName StackName)
{
    if (myensureMsgf(!StacksList.Contains(StackName), TEXT("The stack \"%s\" has been already created"), *StackName.ToString()))
    {
        NFactorStack* Stack = new NFactorStack(StackName);
        StacksList.Add(StackName, Stack);
    }
}

NFactorState* NFactorsFactoryClient::GetState(FName StackName)
{
    NFactorState* State = new NNullFactorState();

    if (StacksList.Contains(StackName))
    {
        NFactorStack* Stack = StacksList[StackName];
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

void NFactorsFactoryClient::AddFactor(TArray<FName> StackNames, INFactorInterface* Factor)
{
    for (FName Name : StackNames)
    {
        AddFactor(Name, Factor);
    }
}

void NFactorsFactoryClient::AddFactor(FName StackName, INFactorInterface* Factor)
{
    mycheck(StackName != NAME_None);

    if (!StacksList.Contains(StackName))
    {
        CreateStack(StackName);
    }

    NFactorStack* Stack = StacksList[StackName];
    if (Stack == nullptr)
    {
        return;
    }
    Stack->AddFactor(Factor);
}

void NFactorsFactoryClient::AddTime(float Seconds)
{
    for (auto It : StacksList)
    {
        NFactorStack* Stack = It.Value;
        Stack->AddTime(Seconds);
    }
}

void NFactorsFactoryClient::SetDebug(const TArray<FName> StackNames, bool bDebug)
{
    for (FName StackName : StackNames)
    {
        if (!StacksList.Contains(StackName))
        {
            CreateStack(StackName);
        }

        if (!ensureMsgf(
                StacksList.Contains(StackName), TEXT("Can not debug an inexistant stack named \"%s\""), *StackName.ToString()))
            return;

        NFactorStack* Stack = StacksList[StackName];
        Stack->bDebug = bDebug;
    }
}
