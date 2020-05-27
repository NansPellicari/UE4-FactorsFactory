#pragma once

#include "CoreMinimal.h"
#include "Factor/FactorAdapters.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "Settings/FactorSettings.h"

#include "FactorFactory.generated.h"

class IFactorOperator;
class UNFactorClientAdapter;
class UOperatorTest;
class Factor;
class UNFactorAdapterAbstract;

USTRUCT(BlueprintType)
struct FNFactorStateResult
{
	GENERATED_USTRUCT_BODY()

	FNFactorStateResult() {}
	FNFactorStateResult(float _Amount, TArray<FName> _Reasons, float _Time) : Amount(_Amount), Reasons(_Reasons), Time(_Time) {}

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FactorsFactory")
	float Amount;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FactorsFactory")
	TArray<FName> Reasons;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FactorsFactory")
	float Time;
};

UCLASS(meta = (ScriptName = "FactorLibrary"))
class NANSFACTORSFACTORYUE4_API UNFactorFactory : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	static UNFactorClientAdapter* GetFactorClient(UObject* WorldContextObject);
	static FNFactorStateResult GetFactorState(FName StackName, UNFactorClientAdapter* Client);

	// clang-format off
    /**
     * My design decision here is to always retrieve a result (0 is a result),
     * even if the desired StackName does not (still) exists.
     * 
     * When you think about it, this method aimed to be called to get 
     * a result, no matter WHEN it's called, and don't have to bother
     * the client with differents way to manage the results.
     * Intent of the client should be:
     * -    "Ok code, give me the factor level for 'AIMING',
     *      I'll use it as a helper factor for the player"
     * But not:
     * -    "Ok code, give me the factor level for 'AIMING but can be null',
     *      and if there is a results I can use it as a helpers factor,
     *      and if not I can ... do ... things?"
     */
    UFUNCTION(BlueprintPure, Category = "FactorsFactory|Factory", meta = (WorldContext = "WorldContextObject", Keywords = "FactorsFactory get states factory", DisplayName = "Get states of factor"))
    static TMap<FName, FNFactorStateResult> GetFactorStates(UObject* WorldContextObject, TArray<FName> StackNames);
    
    UFUNCTION(BlueprintPure, Category = "FactorsFactory|Factory", meta = (WorldContext = "WorldContextObject", Keywords = "FactorsFactory get state factory", DisplayName = "Get a state of a factor"))
    static FNFactorStateResult GetFactorState(UObject* WorldContextObject, FName StackName);

    UFUNCTION(BlueprintCallable, Category = "FactorsFactory|Factory", meta = (WorldContext = "WorldContextObject", Keywords = "FactorsFactory reset states factory", DisplayName = "Clear factors"))
    static void Clear(UObject* WorldContextObject, TArray<FName> StackNames);
    
    UFUNCTION(BlueprintCallable, Category = "FactorsFactory|Factory", meta = (Keywords = "FactorsFactory reset states factory", DisplayName = "Testouilles"))
    static void Testouille(FNFactorSettings Settings) {
        UE_LOG(LogTemp, Warning, TEXT("%s: attr: "), ANSI_TO_TCHAR(__FUNCTION__), *Settings.Name.ToString());
    }

    UFUNCTION(BlueprintCallable, Category = "FactorsFactory|Factory", meta = (DevelopmentOnly, WorldContext = "WorldContextObject", Keywords = "FactorsFactory debug", DisplayName = "Debug Factors"))
    static void Debug(UObject* WorldContextObject, const TArray<FName> StackNames, const bool Debug);

    UFUNCTION(meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), BlueprintCallable, Category = "FactorsFactory|Factory")
    static UNFactorAdapterAbstract* CreateFactor(UObject* WorldContextObject, UClass* Class);

    UFUNCTION(meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), BlueprintCallable, Category = "FactorsFactory|Factory")
    static UNFactorAdapterAbstract* AddFactor(UObject* WorldContextObject, UNFactorAdapterAbstract* Factor);

	// clang-format on
};
