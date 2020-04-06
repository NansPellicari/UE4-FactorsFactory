#include "DifficultyFactory.h"

#include "Difficulty/DifficultyAdapters.h"
#include "DifficultyClientAdapter.h"
#include "DifficultySystemGameInstance.h"
#include "Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "NansCommon/Public/Misc/NansAssertionMacros.h"
#include "NansDifficultySystemCore/Public/Difficulty.h"
#include "NansDifficultySystemCore/Public/DifficultyInterface.h"
#include "NansDifficultySystemCore/Public/DifficultyState.h"
#include "NansDifficultySystemCore/Public/NullDifficultyState.h"
#include "NansDifficultySystemCore/Public/Operator/DifficultyOperator.h"
#include "NansDifficultySystemCore/Public/Operator/Interfaces.h"
#include "NansDifficultySystemCore/Public/Operator/ResetOperator.h"

void UNDifficultyFactory::AddBasicDifficulty(UObject* WorldContextObject,
    TArray<FName> StackNames,
    float DifficultyValue,
    ENDifficultyOperator Operator,
    float Duration,
    FName Reason)
{
    UNDifficultyClientAdapter* Client = GetDifficultyClient(WorldContextObject);

    if (Client == nullptr) return;

    IDifficultyOperator* OperatorObject = UNDifficultyAdapterBasic::EnumToOperator(Operator);
    Client->AddDifficulty(StackNames, new NDifficulty(DifficultyValue, OperatorObject, Duration, Reason));
}

UNDifficultyClientAdapter* UNDifficultyFactory::GetDifficultyClient(UObject* WorldContextObject)
{
    UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
    if (!World) return nullptr;

    UGameInstance* GI = World->GetGameInstance();
    if (!myensureMsgf(GI, TEXT("Should have a game instance to works"))) return nullptr;

    bool bIsImplementedDifficultyGI = GI->Implements<UNDifficultySystemGameInstance>();
    if (myensureMsgf(
            bIsImplementedDifficultyGI, TEXT("The game instance should implements INDifficultySystemGameInstance to works")))
    {
        UNDifficultyClientAdapter* Client = INDifficultySystemGameInstance::Execute_GetDifficultySystemClient(GI);
        return Client;
    }
    return nullptr;
}

void UNDifficultyFactory::Debug(UObject* WorldContextObject, const TArray<FName> StackNames, const bool Debug)
{
    UNDifficultyClientAdapter* Client = GetDifficultyClient(WorldContextObject);
    if (Client == nullptr) return;

    Client->SetDebug(StackNames, Debug);
}

FNDifficultyStateResult UNDifficultyFactory::GetDifficultyState(FName StackName, UNDifficultyClientAdapter* Client)
{
    NDifficultyState* State = Client->GetState(StackName);
    TArray<FName> Reasons;
    if (State == nullptr)
    {
        State = new NNullDifficultyState();
    }

    const TArray<FNDifficultyStateOperator> Operators = State->GetOperators();
    for (FNDifficultyStateOperator Op : Operators)
    {
        // TODO Should be great to get the number of time the same reason has been added
        Reasons.AddUnique(Op.Reason);
    }

    return FNDifficultyStateResult(State->Compute(), Reasons, State->GetTime());
}
FNDifficultyStateResult UNDifficultyFactory::GetDifficultyState(UObject* WorldContextObject, FName StackName)
{
    UNDifficultyClientAdapter* Client = GetDifficultyClient(WorldContextObject);
    if (Client == nullptr) return FNDifficultyStateResult();

    return UNDifficultyFactory::GetDifficultyState(StackName, Client);
}

TMap<FName, FNDifficultyStateResult> UNDifficultyFactory::GetDifficultyStates(UObject* WorldContextObject, TArray<FName> StackNames)
{
    TMap<FName, FNDifficultyStateResult> Results;
    UNDifficultyClientAdapter* Client = GetDifficultyClient(WorldContextObject);

    if (Client == nullptr) return Results;

    for (FName StackName : StackNames)
    {
        Results.Add(StackName, UNDifficultyFactory::GetDifficultyState(StackName, Client));
    }
    return Results;
}

void UNDifficultyFactory::Clear(UObject* WorldContextObject, TArray<FName> StackNames)
{
    UNDifficultyClientAdapter* Client = GetDifficultyClient(WorldContextObject);

    if (Client == nullptr) return;

    for (FName StackName : StackNames)
    {
        Client->RemoveStack(StackName);
    }
}

UNDifficultyAdapterAbstract* UNDifficultyFactory::AddDifficulty(UNDifficultyAdapterAbstract* Difficulty)
{
    UE_LOG(LogTemp, Warning, TEXT("Call me baby!!"));
    return Difficulty;
}