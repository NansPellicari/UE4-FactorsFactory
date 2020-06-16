// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// https://www.s1t2.com.au/blog/virtual-reality/brief-intro-k2nodes
// Largely Inspired from [engine_path]\Engine\Source\Editor\BlueprintGraph\Private\K2Node_GetClassDefaults.cpp
#pragma once

#include "CoreMinimal.h"
#include "K2Node.h"

#include "K2Node_FactorOperator.generated.h"

class FBlueprintActionDatabaseRegistrar;

/**
 * TODO: This class needs to be cleaned, refactored and documented
 */
UCLASS()
class NANSFACTORSFACTORYUE4_API UK2Node_FactorUnit : public UK2Node
{
	GENERATED_BODY()

public:
	// Begin UObject interface
	virtual void BeginDestroy() override;
	// End UObject interface

	//~ Begin UObject Interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void PreEditChange(UProperty* PropertyAboutToChange) override;
	//~ End UObject Interface

	//~ Begin UEdGraphNode Interface
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
	virtual void AllocateDefaultPins() override;
	virtual void PostPlacedNewNode() override;
	virtual void PinDefaultValueChanged(UEdGraphPin* Pin) override;
	virtual void PinConnectionListChanged(UEdGraphPin* Pin) override;
	virtual void ValidateNodeDuringCompilation(class FCompilerResultsLog& MessageLog) const override;
	//~ End UEdGraphNode Interface

	//~ Begin UK2Node Interface
	virtual bool ShouldShowNodeProperties() const override
	{
		return true;
	}
	virtual void ReallocatePinsDuringReconstruction(TArray<UEdGraphPin*>& OldPins) override;
	virtual bool HasExternalDependencies(TArray<class UStruct*>* OptionalOutput) const override;
	virtual class FNodeHandlingFunctor* CreateNodeHandler(class FKismetCompilerContext& CompilerContext) const override;
	virtual void ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual FText GetMenuCategory() const override;
	//~ End UK2Node Interface

public:
	/** Class pin name */
	static FName ClassPinName;
	/** Factor pin name */
	static FName FactorPinName;
	/** Operator provider pin name */
	static FName OperatorPinName;
	/** Object pin name */
	static FName ObjectPinName;
	/** Outer pin name */
	static FName OuterPinName;

	/** Finds and returns the class input pin from the current set of pins. */
	UEdGraphPin* FindClassPin() const;
	UEdGraphPin* FindFactorPin() const;
	UEdGraphPin* FindOperatorPin() const;
	UEdGraphPin* GetResultPin() const;
	UEdGraphPin* GetThenPin() const;
	UEdGraphPin* GetOuterPin() const;

	/** Retrieves the current input class type. */
	UClass* GetInputClass() const;

	/** Retrieves the current input operator class type. */
	UClass* GetInputOperatorClass() const;

	void OnBlueprintClassModified(UBlueprint* TargetBlueprint);
	void ClearDelegates(FString InClassName);

protected:
#if WITH_EDITOR
	// TODO create a Pin available only in dev mode to switch this
	bool bDebug = true;
#endif

	/**
	 * Finds and returns the class input pin.
	 *
	 * @param FromPins	A list of pins to search.
	 */
	UEdGraphPin* FindClassPin(const TArray<UEdGraphPin*>& FromPins) const;

	/**
	 * Finds and returns the factor input pin.
	 *
	 * @param FromPins	A list of pins to search.
	 */
	UEdGraphPin* FindFactorPin(const TArray<UEdGraphPin*>& FromPins) const;

	/**
	 * Finds and returns the opearator provider input pin.
	 *
	 * @param FromPins	A list of pins to search.
	 */
	UEdGraphPin* FindOperatorPin(const TArray<UEdGraphPin*>& FromPins) const;

	/**
	 * Determines the input class type from the given pin.
	 *
	 * @param FromPin	Input class pin.
	 */
	UClass* GetInputClass(const UEdGraphPin* FromPin) const;

	/**
	 * Determines the input operator class type from the given pin.
	 *
	 * @param FromPin	Input class pin.
	 */
	UClass* GetInputOperatorClass(const UEdGraphPin* FromPin) const;

	/**
	 * Creates the full set of pins (properties) from the given input class.
	 *
	 * @param InClass	Input class type.
	 */
	void CreateNewPins(UClass* InClass, bool bOuputPin = true);

	/** Will be called whenever the class pin selector changes its value. */
	void OnClassPinChanged();

private:
	/**
	 * A tuple for ClassSubsciber delegates
	 * it allows to keep important details trace in memory.
	 * 0: Blueprint that we subscribed FClassSubsciberTuple<1> and FClassSubsciberTuple<2> to
	 * 1: Blueprint.OnChanged delegate handle
	 * 2: Blueprint.OnCompiled delegate handle
	 */
	using FClassSubscriberTuple = TTuple<UBlueprint*, FDelegateHandle, FDelegateHandle>;
	/** FString: Classname, FClassSubsciberTuple: delegates data */
	TMap<FString, FClassSubscriberTuple> BlueprintSubscribers;

	TArray<FOptionalPinFromProperty> ShowPinForProperties;

	TArray<FName> OldShownPins;

	/** Whether or not to exclude object container properties */
	UPROPERTY()
	bool bExcludeObjectContainers;
};
