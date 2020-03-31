#include "DifficultySystemClient.h"

#include "NansCommon/Public/Misc/NansAssertionMacros.h"
#include "NansDifficultySystemCore/Public/Difficulty.h"
#include "NansDifficultySystemCore/Public/DifficultyStack.h"
#include "NansDifficultySystemCore/Public/DifficultyState.h"
#include "NullDifficultyState.h"

void UNDifficultySystemClient::CreateStack(FName StackName)
{
    if (myensureMsgf(!StacksList.Contains(StackName), TEXT("The stack \"%s\" has been already created"), *StackName.ToString()))
    {
        UNDifficultyStack* Stack = NewObject<UNDifficultyStack>(this);
        Stack->Initialize(StackName);
        StacksList.Add(StackName, Stack);
    }
}

UNDifficultyState* UNDifficultySystemClient::GetState(FName StackName)
{
    UNDifficultyState* State = NewObject<UNNullDifficultyState>(this);

    if (myensureMsgf(
            StacksList.Contains(StackName), TEXT("The name \"%s\" has not been found in the stack list"), *StackName.ToString()))
    {
        UNDifficultyStack* Stack = StacksList[StackName];
        State = Stack->GetCurrentState();
    }

    return State;
}

TArray<UNDifficultyState*> UNDifficultySystemClient::GetStates(TArray<FName> StackNames)
{
    TArray<UNDifficultyState*> States;
    for (FName Name : StackNames)
    {
        UNDifficultyState* State = GetState(Name);
        if (State != nullptr)
        {
            States.Add(State);
        }
    }

    return States;
}

void UNDifficultySystemClient::AddDifficulty(TArray<FName> StackNames, UNDifficulty* Difficulty)
{
    for (FName Name : StackNames)
    {
        AddDifficulty(Name, Difficulty);
    }
}

void UNDifficultySystemClient::AddDifficulty(FName StackName, UNDifficulty* Difficulty)
{
    if (myensureMsgf(StacksList.Contains(StackName),
            TEXT("Can not add difficulty to an inexistant stack named \"%s\""),
            *StackName.ToString()))
    {
        UNDifficultyStack* Stack = StacksList[StackName];
        Stack->AddDifficulty(Difficulty);
    }
}
