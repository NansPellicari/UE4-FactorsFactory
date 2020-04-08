#include "DifficultySystemClient.h"

#include "DifficultyInterface.h"
#include "DifficultyStack.h"
#include "DifficultyState.h"
#include "NansCommon/Public/Misc/NansAssertionMacros.h"
#include "NullDifficultyState.h"

void NDifficultySystemClient::RemoveStack(FName StackName)
{
    if (myensureMsgf(StacksList.Contains(StackName), TEXT("The stack \"%s\" does not exists"), *StackName.ToString()))
    {
        StacksList.Remove(StackName);
    }
}

void NDifficultySystemClient::CreateStack(FName StackName)
{
    if (myensureMsgf(!StacksList.Contains(StackName), TEXT("The stack \"%s\" has been already created"), *StackName.ToString()))
    {
        NDifficultyStack* Stack = new NDifficultyStack(StackName);
        StacksList.Add(StackName, Stack);
    }
}

NDifficultyState* NDifficultySystemClient::GetState(FName StackName)
{
    NDifficultyState* State = new NNullDifficultyState();

    if (StacksList.Contains(StackName))
    {
        NDifficultyStack* Stack = StacksList[StackName];
        mycheckf(Stack != nullptr, TEXT("The stack '%s' existed in the stack list but has been removed"), *StackName.ToString());
        State = Stack->GetCurrentState();
    }

    return State;
}

TArray<NDifficultyState*> NDifficultySystemClient::GetStates(TArray<FName> StackNames)
{
    TArray<NDifficultyState*> States;
    for (FName Name : StackNames)
    {
        NDifficultyState* State = GetState(Name);
        if (State != nullptr)
        {
            States.Add(State);
        }
    }

    return States;
}

void NDifficultySystemClient::AddDifficulty(TArray<FName> StackNames, INDifficultyInterface* Difficulty)
{
    for (FName Name : StackNames)
    {
        AddDifficulty(Name, Difficulty);
    }
}

void NDifficultySystemClient::AddDifficulty(FName StackName, INDifficultyInterface* Difficulty)
{
    mycheck(StackName != NAME_None);

    if (!StacksList.Contains(StackName))
    {
        CreateStack(StackName);
    }

    NDifficultyStack* Stack = StacksList[StackName];
    if (Stack == nullptr)
    {
        return;
    }
    Stack->AddDifficulty(Difficulty);
}

void NDifficultySystemClient::AddTime(float Seconds)
{
    for (auto It : StacksList)
    {
        NDifficultyStack* Stack = It.Value;
        Stack->AddTime(Seconds);
    }
}

void NDifficultySystemClient::SetDebug(const TArray<FName> StackNames, bool bDebug)
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

        NDifficultyStack* Stack = StacksList[StackName];
        Stack->bDebug = bDebug;
    }
}
