#pragma once

#include "Attribute/FactorAttribute.h"
#include "CoreMinimal.h"
#include "FactorUnit/FactorUnitAdapters.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NansFactorsFactoryCore/Public/FactorUnit.h"
#include "Settings/FactorSettings.h"

#include "FactorsFactoryBlueprintHelpers.generated.h"

class NFactorOperatorInterface;
class UNFactorsFactoryClientAdapter;
class UOperatorTest;
class FactorUnit;
class UNFactorUnitAdapterAbstract;

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

UCLASS(meta = (ScriptName = "FactorUnitLibrary"))
class NANSFACTORSFACTORYUE4_API UNFactorsFactoryBlueprintHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	static UNFactorsFactoryClientAdapter* GetFactorUnitClient(UObject* WorldContextObject);
	static FNFactorStateResult GetFactorState(FFactorAttribute FactorName, UNFactorsFactoryClientAdapter* Client);

	// clang-format off
	/**
	 * My design decision here is to always retrieve a result (0 is a result),
	 * even if the desired FactorName does not (still) exists.
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
	UFUNCTION(BlueprintPure, Category = "FactorsFactory|Factory", meta = (WorldContext = "WorldContextObject", Keywords = "FactorsFactory get states factory", DisplayName = "Get states of the factors list"))
	static TMap<FName, FNFactorStateResult> GetFactorStates(UObject* WorldContextObject, TArray<FFactorAttribute> FactorNames);
	
	UFUNCTION(BlueprintPure, Category = "FactorsFactory|Factory", meta = (WorldContext = "WorldContextObject", Keywords = "FactorsFactory get state factory", DisplayName = "Get state of a factor"))
	static FNFactorStateResult GetFactorState(UObject* WorldContextObject, FFactorAttribute FactorName);

	UFUNCTION(BlueprintCallable, Category = "FactorsFactory|Factory", meta = (WorldContext = "WorldContextObject", Keywords = "FactorsFactory remove factor", DisplayName = "Remove a factor"))
	static void Clear(UObject* WorldContextObject, TArray<FFactorAttribute> FactorNames);

	UFUNCTION(BlueprintCallable, Category = "FactorsFactory|Factory", meta = (DevelopmentOnly, WorldContext = "WorldContextObject", Keywords = "FactorsFactory debug", DisplayName = "Debug a factor"))
	static void Debug(UObject* WorldContextObject, const TArray<FFactorAttribute> FactorNames, const bool Debug);
	
	UFUNCTION(meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), BlueprintCallable, Category = "FactorsFactory|Factory")
	static UNFactorUnitAdapterAbstract* CreateFactorUnit(UObject* WorldContextObject, UClass* Class, FFactorAttribute Factor);

	UFUNCTION(meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject"), BlueprintCallable, Category = "FactorsFactory|Factory")
	static UNFactorUnitAdapterAbstract* AddFactorUnit(UObject* WorldContextObject, UNFactorUnitAdapterAbstract* FactorUnit, FFactorAttribute Factor);
	// clang-format on
};
