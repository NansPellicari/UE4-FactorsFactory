// Fill out your copyright notice in the Description page of Project Settings.
// https://www.s1t2.com.au/blog/virtual-reality/brief-intro-k2nodes
// Largely Inspired from [engine_path]\Engine\Source\Editor\BlueprintGraph\Private\K2Node_GetClassDefaults.cpp
#pragma once

#include "CoreMinimal.h"
#include "K2Node.h"

#include "K2Node_DifficultyOperator.generated.h"

class FBlueprintActionDatabaseRegistrar;

/**
 *
 */
UCLASS()
class NANSFACTORSFACTORYUE4_API UK2Node_DifficultyOperator : public UK2Node
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
    virtual bool IsNodePure() const override
    {
        return true;
    }
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
    /** Object pin name */
    static FName ObjectPinName;
    /** Outer pin name */
    static FName OuterPinName;

    bool TryConnectPin(FKismetCompilerContext& CompilerContext, UEdGraphPin* PinA, UEdGraphPin* PinB) const;

    /** Finds and returns the class input pin from the current set of pins. */
    UEdGraphPin* FindClassPin() const
    {
        UEdGraphPin* Pin = FindPinChecked(UK2Node_DifficultyOperator::ClassPinName);
        check(Pin->Direction == EGPD_Input);
        return Pin;
    }
    UEdGraphPin* GetResultPin() const;
    UEdGraphPin* GetThenPin() const;
    UEdGraphPin* GetOuterPin() const;

    /** Retrieves the current input class type. */
    UClass* GetInputClass() const
    {
        return GetInputClass(FindClassPin());
    }

    void OnBlueprintClassModified(UBlueprint* TargetBlueprint);
    void ClearDelegates();

protected:
#if WITH_EDITOR
    // TODO create a Pin available only in dev mode to switch this
    bool bDebug = true;
    void DebugConnectionPin(uint32 Step, const UEdGraphPin* PinA, const UEdGraphPin* PinB, const bool bSucceeded) const;
#endif
    /**
     * Finds and returns the class input pin.
     *
     * @param FromPins	A list of pins to search.
     */
    UEdGraphPin* FindClassPin(const TArray<UEdGraphPin*>& FromPins) const;

    /**
     * Determines the input class type from the given pin.
     *
     * @param FromPin	Input class pin.
     */
    UClass* GetInputClass(const UEdGraphPin* FromPin) const;

    /**
     * Creates the full set of pins (properties) from the given input class.
     *
     * @param InClass	Input class type.
     */
    void CreateNewPins(UClass* InClass);

    /** Will be called whenever the class pin selector changes its value. */
    void OnClassPinChanged();

private:
    /** Blueprint that we subscribed OnBlueprintChangedDelegate and OnBlueprintCompiledDelegate to */
    UPROPERTY()
    UBlueprint* BlueprintSubscribedTo;

    /** Blueprint.OnChanged delegate handle */
    FDelegateHandle OnBlueprintChangedDelegate;

    /** Blueprint.OnCompiled delegate handle */
    FDelegateHandle OnBlueprintCompiledDelegate;
    TArray<FOptionalPinFromProperty> ShowPinForProperties;

    TArray<FName> OldShownPins;

    /** Whether or not to exclude object container properties */
    UPROPERTY()
    bool bExcludeObjectContainers;
};
