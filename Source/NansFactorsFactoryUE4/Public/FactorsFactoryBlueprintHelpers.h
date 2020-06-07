#pragma once

#include "Attribute/FactorStackAttribute.h"
#include "CoreMinimal.h"
#include "Factor/FactorAdapters.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "Settings/FactorSettings.h"

#include "FactorsFactoryBlueprintHelpers.generated.h"

class NFactorOperatorInterface;
class UNFactorsFactoryClientAdapter;
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
	float Amount = -1.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FactorsFactory")
	TArray<FName> Reasons;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FactorsFactory")
	float Time = -1.f;
};

UCLASS(meta = (ScriptName = "FactorLibrary"))
class NANSFACTORSFACTORYUE4_API UNFactorsFactoryBlueprintHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	static UNFactorsFactoryClientAdapter* GetFactorClient(UObject* WorldContextObject);
	static FNFactorStateResult GetFactorState(FFactorStackAttribute StackName, UNFactorsFactoryClientAdapter* Client);

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
	UFUNCTION(BlueprintPure, Category = "FactorsFactory|Factory", meta = (WorldContext = "WorldContextObject", Keywords = "FactorsFactory get states factory", DisplayName = "Get states of FactorsFactory stacks list"))
	static TMap<FName, FNFactorStateResult> GetFactorStates(UObject* WorldContextObject, TArray<FFactorStackAttribute> StackNames);
	
	UFUNCTION(BlueprintPure, Category = "FactorsFactory|Factory", meta = (WorldContext = "WorldContextObject", Keywords = "FactorsFactory get state factory", DisplayName = "Get state of a FactorsFactory stack"))
	static FNFactorStateResult GetFactorState(UObject* WorldContextObject, FFactorStackAttribute StackName);

	UFUNCTION(BlueprintCallable, Category = "FactorsFactory|Factory", meta = (WorldContext = "WorldContextObject", Keywords = "FactorsFactory remove stack", DisplayName = "Remove a FactorsFactory stack"))
	static void Clear(UObject* WorldContextObject, TArray<FFactorStackAttribute> StackNames);

	UFUNCTION(BlueprintCallable, Category = "FactorsFactory|Factory", meta = (DevelopmentOnly, WorldContext = "WorldContextObject", Keywords = "FactorsFactory debug", DisplayName = "Debug FactorsFactory stack"))
	static void Debug(UObject* WorldContextObject, const TArray<FFactorStackAttribute> StackNames, const bool Debug);
	
	UFUNCTION(meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), BlueprintCallable, Category = "FactorsFactory|Factory")
	static UNFactorAdapterAbstract* CreateFactor(UObject* WorldContextObject, UClass* Class, FFactorStackAttribute Stack);

	UFUNCTION(meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), BlueprintCallable, Category = "FactorsFactory|Factory")
	static UNFactorAdapterAbstract* AddFactor(UObject* WorldContextObject, UNFactorAdapterAbstract* Factor, FFactorStackAttribute Stack);
	// clang-format on
};
