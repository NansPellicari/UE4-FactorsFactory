#include "DifficultyClientAdapter.h"
#include "NansDifficultySystemCore/Public/DifficultyInterface.h"
#include "NansDifficultySystemCore/Public/DifficultyState.h"
#include "NansDifficultySystemCore/Public/DifficultySystemClient.h"

UNDifficultyClientAdapter::UNDifficultyClientAdapter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    Client = MakeShareable(new NDifficultySystemClient());
}

void UNDifficultyClientAdapter::CreateStack(FName StackName)
{
    Client->CreateStack(StackName);
}

void UNDifficultyClientAdapter::RemoveStack(FName StackName)
{
    Client->RemoveStack(StackName);
}

NDifficultyState* UNDifficultyClientAdapter::GetState(FName StackName)
{
    return Client->GetState(StackName);
}

TArray<NDifficultyState*> UNDifficultyClientAdapter::GetStates(TArray<FName> StackNames)
{
    return Client->GetStates(StackNames);
}

void UNDifficultyClientAdapter::AddDifficulty(FName StackName, INDifficultyInterface* Difficulty)
{
    Client->AddDifficulty(StackName, Difficulty);
}

void UNDifficultyClientAdapter::AddTime(float Seconds)
{
    Client->AddTime(Seconds);
}

void UNDifficultyClientAdapter::SetDebug(const TArray<FName> StackNames, bool bDebug)
{
    Client->SetDebug(StackNames, bDebug);
}

void UNDifficultyClientAdapter::AddDifficulty(TArray<FName> StackNames, INDifficultyInterface* Difficulty)
{
    Client->AddDifficulty(StackNames, Difficulty);
}