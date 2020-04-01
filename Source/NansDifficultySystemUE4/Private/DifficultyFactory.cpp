#include "DifficultyFactory.h"

#include "DifficultyClientAdapter.h"
#include "DifficultySystemGameInstance.h"
#include "Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "NansCommon/Public/Misc/NansAssertionMacros.h"
#include "NansDifficultySystemCore/Public/Difficulty.h"
#include "NansDifficultySystemCore/Public/DifficultyInterface.h"
#include "NansDifficultySystemCore/Public/DifficultyState.h"
#include "NansDifficultySystemCore/Public/Operator/DifficultyOperator.h"
#include "NansDifficultySystemCore/Public/Operator/Interfaces.h"

void UNDifficultyFactory::AddBasicDifficulty(UObject* WorldContextObject,
    TArray<FName> StackNames,
    float DifficultyValue,
    ENDifficultyOperator Operator,
    float Duration,
    FName Reason)
{
    UNDifficultyClientAdapter* Client = GetDifficultyClient(WorldContextObject);

    if (Client == nullptr) return;

    IDifficultyOperator* OperatorObject = EnumToOperator(Operator);
    Client->AddDifficulty(StackNames, new NDifficulty(DifficultyValue, OperatorObject, Duration, Reason));
}

UNDifficultyClientAdapter* UNDifficultyFactory::GetDifficultyClient(UObject* WorldContextObject)
{
    UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
    if (!World) return nullptr;

    UGameInstance* GI = World->GetGameInstance();
    INDifficultySystemGameInstance* IGI = Cast<INDifficultySystemGameInstance>(GI);

    if (myensureMsgf(IGI != nullptr, TEXT("The game instance should implements INDifficultySystemGameInstance to works")))
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

TMap<FName, FNDifficultyStateResult> UNDifficultyFactory::GetDifficultyStates(UObject* WorldContextObject, TArray<FName> StackNames)
{
    TMap<FName, FNDifficultyStateResult> Results;
    UNDifficultyClientAdapter* Client = GetDifficultyClient(WorldContextObject);

    if (Client == nullptr) return Results;

    for (FName StackName : StackNames)
    {
        NDifficultyState* State = Client->GetState(StackName);
        if (State == nullptr) continue;

        TArray<FName> Reasons;
        const TArray<FNDifficultyStateOperator> Operators = State->GetOperators();
        for (FNDifficultyStateOperator Op : Operators)
        {
            // TODO Should be great to get the number of time the same reason has been added
            Reasons.AddUnique(Op.Reason);
        }

        Results.Add(StackName, FNDifficultyStateResult(State->Compute(), Reasons, State->GetTime()));
    }
    return Results;
}

IDifficultyOperator* UNDifficultyFactory::EnumToOperator(ENDifficultyOperator Enum)
{
    if (Enum == ENDifficultyOperator::Add)
    {
        return new NAddOperator();
    }

    if (Enum == ENDifficultyOperator::Sub)
    {
        return new NSubsctractOperator();
    }

    if (Enum == ENDifficultyOperator::Mul)
    {
        return new NMultiplyOperator();
    }

    if (Enum == ENDifficultyOperator::Div)
    {
        return new NDividerOperator();
    }

    return new NNullOperator();
}