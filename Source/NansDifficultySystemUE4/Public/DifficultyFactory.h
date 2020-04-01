#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "DifficultyFactory.generated.h"

class IDifficultyOperator;
class UNDifficultyClientAdapter;

UENUM(BlueprintType)
enum class ENDifficultyOperator : uint8
{
    Add UMETA(DisplayName = "Add"),
    Sub UMETA(DisplayName = "Subsctract"),
    Mul UMETA(DisplayName = "Multiply"),
    Div UMETA(DisplayName = "Divide")
};

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
    static IDifficultyOperator* EnumToOperator(ENDifficultyOperator Enum);
    static UNDifficultyClientAdapter* GetDifficultyClient(UObject* WorldContextObject);

    // clang-format off
    UFUNCTION(BlueprintCallable, Category = "DifficultySystem|Factory", meta = (WorldContext = "WorldContextObject", UnsafeDuringActorConstruction = "false", Keywords = "DifficultySystem add factory", DisplayName = "Add a basic difficulty"))
    static void AddBasicDifficulty(UObject* WorldContextObject,
        const TArray<FName> StackNames,
        float DifficultyValue,
        const ENDifficultyOperator Operator,
        float Duration,
        FName Reason);

    UFUNCTION(BlueprintPure, Category = "DifficultySystem|Factory", meta = (WorldContext = "WorldContextObject", Keywords = "DifficultySystem get states factory", DisplayName = "Get states of difficulty"))
    static TMap<FName, FNDifficultyStateResult> GetDifficultyStates(UObject* WorldContextObject, TArray<FName> StackNames);

    UFUNCTION(BlueprintCallable, Category = "DifficultySystem|Factory", meta = (DevelopmentOnly, WorldContext = "WorldContextObject", Keywords = "DifficultySystem debug", DisplayName = "Debug Difficulties"))
    static void Debug(UObject* WorldContextObject, const TArray<FName> StackNames, const bool Debug);

    //TODO create a new function to reset a stack

    // clang-format on
};
