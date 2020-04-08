#pragma once

#include "CoreMinimal.h"
// TODO Remove this when no more dependencies !!
#include "Difficulty/DifficultyAdapters.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NansDifficultySystemCore/Public/Difficulty.h"

#include "DifficultyFactory.generated.h"

class IDifficultyOperator;
class UNDifficultyClientAdapter;
class UOperatorTest;
class Difficulty;
class UNDifficultyAdapterAbstract;

USTRUCT(BlueprintType)
struct FNDifficultyStateResult
{
    GENERATED_USTRUCT_BODY()

    FNDifficultyStateResult() {}
    FNDifficultyStateResult(float _Amount, TArray<FName> _Reasons, float _Time) : Amount(_Amount), Reasons(_Reasons), Time(_Time) {}

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DifficultySystem")
    float Amount;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DifficultySystem")
    TArray<FName> Reasons;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DifficultySystem")
    float Time;
};

UCLASS(meta = (ScriptName = "DifficultyLibrary"))
class NANSDIFFICULTYSYSTEMUE4_API UNDifficultyFactory : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    static UNDifficultyClientAdapter* GetDifficultyClient(UObject* WorldContextObject);
    static FNDifficultyStateResult GetDifficultyState(FName StackName, UNDifficultyClientAdapter* Client);

    // clang-format off
    /**
     * My design decision here is to always retrieve a result (0 is a result),
     * even if the desired StackName does not (still) exists.
     * 
     * When you think about it, this method aimed to be called to get 
     * a result, no matter WHEN it's called, and don't have to bother
     * the client with differents way to manage the results.
     * Intent of the client should be:
     * -    "Ok code, give me the difficulty level for 'AIMING',
     *      I'll use it as a helper factor for the player"
     * But not:
     * -    "Ok code, give me the difficulty level for 'AIMING but can be null',
     *      and if there is a results I can use it as a helpers factor,
     *      and if not I can ... do ... things?"
     */
    UFUNCTION(BlueprintPure, Category = "DifficultySystem|Factory", meta = (WorldContext = "WorldContextObject", Keywords = "DifficultySystem get states factory", DisplayName = "Get states of difficulty"))
    static TMap<FName, FNDifficultyStateResult> GetDifficultyStates(UObject* WorldContextObject, TArray<FName> StackNames);
    
    UFUNCTION(BlueprintPure, Category = "DifficultySystem|Factory", meta = (WorldContext = "WorldContextObject", Keywords = "DifficultySystem get state factory", DisplayName = "Get a state of a difficulty"))
    static FNDifficultyStateResult GetDifficultyState(UObject* WorldContextObject, FName StackName);

    UFUNCTION(BlueprintCallable, Category = "DifficultySystem|Factory", meta = (WorldContext = "WorldContextObject", Keywords = "DifficultySystem reset states factory", DisplayName = "Clear difficulties"))
    static void Clear(UObject* WorldContextObject, TArray<FName> StackNames);

    UFUNCTION(BlueprintCallable, Category = "DifficultySystem|Factory", meta = (DevelopmentOnly, WorldContext = "WorldContextObject", Keywords = "DifficultySystem debug", DisplayName = "Debug Difficulties"))
    static void Debug(UObject* WorldContextObject, const TArray<FName> StackNames, const bool Debug);

    UFUNCTION(meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), BlueprintCallable, Category = "DifficultySystem|Factory")
    static UNDifficultyAdapterAbstract* CreateDifficulty(UObject* WorldContextObject, UClass* Class);

    UFUNCTION(meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), BlueprintCallable, Category = "DifficultySystem|Factory")
    static UNDifficultyAdapterAbstract* AddDifficulty(UObject* WorldContextObject, UNDifficultyAdapterAbstract* Difficulty);
    // clang-format on
};
