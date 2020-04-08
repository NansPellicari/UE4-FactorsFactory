// Fill out your copyright notice in the Description page of Project Settings.

#include "K2Node_DifficultyOperator.h"

#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintNodeSpawner.h"
#include "Difficulty/DifficultyAdapterAbstract.h"
#include "DifficultyFactory.h"
#include "EdGraph/EdGraphSchema.h"
#include "EdGraphSchema_K2.h"
#include "EdGraphUtilities.h"
#include "EditorCategoryUtils.h"
#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "GraphEditorActions.h"
#include "K2Node_CallFunction.h"
#include "K2Node_DifficultyOperator.h"
#include "K2Node_GenericCreateObject.h"
#include "K2Node_PureAssignmentStatement.h"
#include "K2Node_TemporaryVariable.h"
#include "K2Node_VariableSet.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/CompilerResultsLog.h"
#include "KismetCompiler.h"
#include "KismetCompilerMisc.h"
#include "UObject/UnrealType.h"

#define LOCTEXT_NAMESPACE "DifficultySystemUE4"

namespace
{
    // Optional pin manager subclass.
    struct FDifficultyOperatorOptionalPinManager : public FOptionalPinManager
    {
        FDifficultyOperatorOptionalPinManager(UClass* InClass, bool bExcludeObjectContainers) : FOptionalPinManager()
        {
            SrcClass = InClass;
            bExcludeObjectArrayProperties = bExcludeObjectContainers;
            bExcludeObjectContainerProperties = bExcludeObjectContainers;
        }

        virtual void GetRecordDefaults(UProperty* TestProperty, FOptionalPinFromProperty& Record) const override
        {
            FOptionalPinManager::GetRecordDefaults(TestProperty, Record);

            // Show pin which the property is owned by the src class or UNDifficultyAdapterAbstract class.
            Record.bShowPin = TestProperty->GetOwnerClass() == SrcClass ||
                              TestProperty->GetOwnerClass() == UNDifficultyAdapterAbstract::StaticClass();
            Record.bShowPin = !TestProperty->HasAnyPropertyFlags(CPF_DisableEditOnInstance);
        }

    private:
        // Class type for which optional pins are being managed.
        UClass* SrcClass;

        // Indicates whether or not object array properties will be excluded (for backwards-compatibility).
        bool bExcludeObjectArrayProperties;

        // Indicates whether or not object container properties will be excluded (will supercede the array-specific flag when true).
        bool bExcludeObjectContainerProperties;
    };

    // Compilation handler subclass.
    class FKCHandler_DifficultyOperator : public FNodeHandlingFunctor
    {
    public:
        FKCHandler_DifficultyOperator(FKismetCompilerContext& InCompilerContext) : FNodeHandlingFunctor(InCompilerContext) {}

        //     virtual void RegisterNets(FKismetFunctionContext& Context, UEdGraphNode* Node) override
        //     {
        //         UE_LOG(LogTemp, Display, TEXT("*********** Calling %s"), ANSI_TO_TCHAR(__FUNCTION__));
        //         // Cast to the correct node type
        //         if (const UK2Node_DifficultyOperator* GetClassDefaultsNode = Cast<UK2Node_DifficultyOperator>(Node))
        //         {
        //             // Only if we have a valid class input pin
        //             if (UEdGraphPin* ClassPin = GetClassDefaultsNode->FindClassPin())
        //             {
        //                 // Redirect to a linked pin if necessary
        //                 UEdGraphPin* Net = FEdGraphUtilities::GetNetFromPin(ClassPin);
        //                 check(Net != nullptr);

        //                 // Register a literal if necessary (e.g. there are no linked pins)
        //                 if (ValidateAndRegisterNetIfLiteral(Context, Net))
        //                 {
        //                     // First check for a literal term in case one was created above
        //                     FBPTerminal** FoundTerm = Context.LiteralHackMap.Find(Net);
        //                     if (FoundTerm == nullptr)
        //                     {
        //                         // Otherwise, check for a linked term
        //                         FoundTerm = Context.NetMap.Find(Net);
        //                     }

        //                     // If we did not find an input term, make sure we create one here
        //                     FBPTerminal* ClassContextTerm = FoundTerm ? *FoundTerm : nullptr;
        //                     if (ClassContextTerm == nullptr)
        //                     {
        //                         ClassContextTerm =
        //                             Context.CreateLocalTerminalFromPinAutoChooseScope(Net,
        //                             Context.NetNameMap->MakeValidName(Net));
        //                         check(ClassContextTerm != nullptr);

        //                         Context.NetMap.Add(Net, ClassContextTerm);
        //                     }

        //                     // Flag this as a "class context" term
        //                     ClassContextTerm->SetContextTypeClass();

        //                     // Infer the class type from the context term
        //                     if (const UClass* ClassType =
        //                             Cast<UClass>(ClassContextTerm->bIsLiteral ? ClassContextTerm->ObjectLiteral
        //                                                                       :
        //                                                                       ClassContextTerm->Type.PinSubCategoryObject.Get()))
        //                     {
        //                         // Create a local term for each output pin (class property)
        //                         for (int32 PinIndex = 0; PinIndex < Node->Pins.Num(); ++PinIndex)
        //                         {
        //                             UEdGraphPin* Pin = Node->Pins[PinIndex];
        //                             if (Pin != nullptr && Pin->Direction == EGPD_Input &&
        //                                 Pin->PinType.PinCategory != UEdGraphSchema_K2::PC_Exec &&
        //                                 Pin->PinName != UK2Node_DifficultyOperator::ClassPinName)
        //                             {
        //                                 UProperty* BoundProperty = FindField<UProperty>(ClassType, Pin->PinName);
        //                                 if (BoundProperty != nullptr)
        //                                 {
        //                                     FBPTerminal* OutputTerm =
        //                                         Context.CreateLocalTerminalFromPinAutoChooseScope(Pin, Pin->PinName.ToString());
        //                                     check(OutputTerm != nullptr);

        //                                     // Set as a variable within the class context
        //                                     OutputTerm->AssociatedVarProperty = BoundProperty;
        //                                     OutputTerm->Context = ClassContextTerm;

        //                                     // Flag this as a "class default" variable term
        //                                     OutputTerm->bIsConst = true;
        //                                     OutputTerm->SetVarTypeDefault();

        //                                     // Add it to the lookup table
        //                                     Context.NetMap.Add(Pin, OutputTerm);
        //                                 }
        //                                 else
        //                                 {
        //                                     CompilerContext.MessageLog.Error(
        //                                         *LOCTEXT("UnmatchedNewPinOnCompile", "Failed to find a class member to match @@")
        //                                              .ToString(),
        //                                         Pin);
        //                                 }
        //                             }
        //                         }
        //                     }
        //                     else
        //                     {
        //                         CompilerContext.MessageLog.Error(
        //                             *LOCTEXT("InvalidClassTypeOnCompile", "Missing or invalid input class type for
        //                             @@").ToString(), Node);
        //                     }
        //                 }
        //             }
        //         }
        //     }
    };
}    // namespace

FName UK2Node_DifficultyOperator::ClassPinName(TEXT("DifficultyClass"));
FName UK2Node_DifficultyOperator::OuterPinName(TEXT("Outer"));
FName UK2Node_DifficultyOperator::ObjectPinName(TEXT("DifficultyObject"));

FText UK2Node_DifficultyOperator::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    return LOCTEXT("DifficultyOperatorFactory_Title", "Create a Difficulty");
}

FText UK2Node_DifficultyOperator::GetTooltipText() const
{
    return LOCTEXT(
        "DifficultyOperatorFactory_Tooltip", "This node allow to create any difficulty and add it to a new difficulty stack");
}

FText UK2Node_DifficultyOperator::GetMenuCategory() const
{
    return LOCTEXT("DifficultyOperatorFactory_MenuCategory", "DifficultySystem|Factory");
}

void UK2Node_DifficultyOperator::PreEditChange(UProperty* PropertyThatWillChange)
{
    Super::PreEditChange(PropertyThatWillChange);

    if (PropertyThatWillChange && PropertyThatWillChange->GetFName() == GET_MEMBER_NAME_CHECKED(FOptionalPinFromProperty, bShowPin))
    {
        FOptionalPinManager::CacheShownPins(ShowPinForProperties, OldShownPins);
    }
}

UEdGraphPin* UK2Node_DifficultyOperator::GetOuterPin() const
{
    UEdGraphPin* Pin = FindPin(UK2Node_DifficultyOperator::OuterPinName);
    ensure(nullptr == Pin || Pin->Direction == EGPD_Input);
    return Pin;
}

UEdGraphPin* UK2Node_DifficultyOperator::GetResultPin() const
{
    UEdGraphPin* Pin = FindPinChecked(UEdGraphSchema_K2::PN_ReturnValue);
    check(Pin->Direction == EGPD_Output);
    return Pin;
}

UEdGraphPin* UK2Node_DifficultyOperator::GetThenPin() const
{
    UEdGraphPin* Pin = FindPinChecked(UEdGraphSchema_K2::PN_Then);
    check(Pin->Direction == EGPD_Output);
    return Pin;
}

void UK2Node_DifficultyOperator::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
    UClass* ActionKey = GetClass();
    if (ActionRegistrar.IsOpenForRegistration(ActionKey))
    {
        UBlueprintNodeSpawner* NodeSpawner = UBlueprintNodeSpawner::Create(GetClass());
        check(NodeSpawner != nullptr);

        ActionRegistrar.AddBlueprintAction(ActionKey, NodeSpawner);
    }
}

UEdGraphPin* UK2Node_DifficultyOperator::FindClassPin(const TArray<UEdGraphPin*>& FromPins) const
{
    UEdGraphPin* const* FoundPin = FromPins.FindByPredicate(
        [](const UEdGraphPin* CurPin) { return CurPin && CurPin->Direction == EGPD_Input && CurPin->PinName == ClassPinName; });

    return FoundPin ? *FoundPin : nullptr;
}

UClass* UK2Node_DifficultyOperator::GetInputClass(const UEdGraphPin* FromPin) const
{
    UClass* InputClass = nullptr;

    if (FromPin != nullptr)
    {
        check(FromPin->Direction == EGPD_Input);

        if (FromPin->DefaultObject != nullptr && FromPin->LinkedTo.Num() == 0)
        {
            InputClass = CastChecked<UClass>(FromPin->DefaultObject);
        }
        else if (FromPin->LinkedTo.Num() > 0)
        {
            if (UEdGraphPin* LinkedPin = FromPin->LinkedTo[0])
            {
                InputClass = Cast<UClass>(LinkedPin->PinType.PinSubCategoryObject.Get());
            }
        }
    }

    // Switch Blueprint Class types to use the generated skeleton class (if valid).
    if (InputClass)
    {
        if (UBlueprint* Blueprint = Cast<UBlueprint>(InputClass->ClassGeneratedBy))
        {
            // Stick with the original (serialized) class if the skeleton class is not valid for some reason (e.g. the Blueprint
            // hasn't been compiled on load yet). Note: There's not a need to force it to be preloaded here in that case,
            // because once it is loaded, we'll end up reconstructing this node again anyway.
            if (Blueprint->SkeletonGeneratedClass)
            {
                InputClass = Blueprint->SkeletonGeneratedClass;
            }
        }
    }

    return InputClass;
}

void UK2Node_DifficultyOperator::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    const FName PropertyName = (PropertyChangedEvent.Property ? PropertyChangedEvent.Property->GetFName() : NAME_None);

    if (PropertyName == GET_MEMBER_NAME_CHECKED(FOptionalPinFromProperty, bShowPin))
    {
        FOptionalPinManager::EvaluateOldShownPins(ShowPinForProperties, OldShownPins, this);
        GetSchema()->ReconstructNode(*this);
    }

    Super::PostEditChangeProperty(PropertyChangedEvent);
}

void UK2Node_DifficultyOperator::PostPlacedNewNode()
{
    // Always exclude object container properties for new nodes.
    // @TODO - Could potentially expose object reference values if/when we have support for 'const' input pins.
    bExcludeObjectContainers = true;

    if (UEdGraphPin* ClassPin = FindClassPin(Pins))
    {
        if (UClass* InputClass = GetInputClass(ClassPin))
        {
            CreateNewPins(InputClass);
        }
    }
}

void UK2Node_DifficultyOperator::PinConnectionListChanged(UEdGraphPin* ChangedPin)
{
    if (ChangedPin != nullptr && ChangedPin->PinName == ClassPinName && ChangedPin->Direction == EGPD_Input)
    {
        OnClassPinChanged();
    }
}

void UK2Node_DifficultyOperator::PinDefaultValueChanged(UEdGraphPin* ChangedPin)
{
    if (ChangedPin != nullptr && ChangedPin->PinName == ClassPinName && ChangedPin->Direction == EGPD_Input)
    {
        OnClassPinChanged();
    }
}

bool UK2Node_DifficultyOperator::HasExternalDependencies(TArray<class UStruct*>* OptionalOutput) const
{
#if WITH_EDITOR
    UE_LOG(LogTemp, Display, TEXT(">>>>>>>> %s >>>>>>>>"), ANSI_TO_TCHAR(__FUNCTION__));
#endif

    UClass* SourceClass = GetInputClass();
    UBlueprint* SourceBlueprint = GetBlueprint();
    const bool bResult = (SourceClass && (SourceClass->ClassGeneratedBy != SourceBlueprint));
    if (bResult && OptionalOutput)
    {
        OptionalOutput->AddUnique(SourceClass);
    }

    const bool bSuperResult = Super::HasExternalDependencies(OptionalOutput);
    return bSuperResult || bResult;
}

FNodeHandlingFunctor* UK2Node_DifficultyOperator::CreateNodeHandler(FKismetCompilerContext& CompilerContext) const
{
    return new FKCHandler_DifficultyOperator(CompilerContext);
}

void UK2Node_DifficultyOperator::AllocateDefaultPins()
{
    const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();

    // Execution pins
    CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Execute);
    CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Then);

    // Create the class input type selector pin
    UEdGraphPin* ClassPin =
        CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Class, UNDifficultyAdapterAbstract::StaticClass(), ClassPinName);
    K2Schema->ConstructBasicPinTooltip(*ClassPin,
        LOCTEXT("ClassPinDescription", "The class from which to access one or more default values."),
        ClassPin->PinToolTip);

    CreatePin(
        EGPD_Output, UEdGraphSchema_K2::PC_Object, UNDifficultyAdapterAbstract::StaticClass(), UEdGraphSchema_K2::PN_ReturnValue);
}

#if WITH_EDITOR
void UK2Node_DifficultyOperator::DebugConnectionPin(
    uint32 Step, const UEdGraphPin* PinA, const UEdGraphPin* PinB, const bool bSucceeded) const
{
    if (bDebug)
    {
        UE_LOG(LogTemp,
            Display,
            TEXT("%d - Connect %s->%s & %s->%s %i"),
            Step,
            *(PinA ? PinA->GetOwningNode()->GetName() : ""),
            *(PinA ? PinA->GetName() : ""),
            *(PinB ? PinB->GetOwningNode()->GetName() : ""),
            *(PinB ? PinB->GetName() : ""),
            bSucceeded);
    }
}
#endif    // WITH_EDITOR

void UK2Node_DifficultyOperator::ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
    Super::ExpandNode(CompilerContext, SourceGraph);

    const UEdGraphSchema_K2* Schema = CompilerContext.GetSchema();

    UClass* ClassType = GetInputClass();

    UK2Node_DifficultyOperator* Node = this;
    UEdGraphPin* ClassPin = FindClassPin();

#if WITH_EDITOR
    if (bDebug) UE_LOG(LogTemp, Display, TEXT(">>>>>>>>>> BEGIN: %s >>>>>>>>>>"), ANSI_TO_TCHAR(__FUNCTION__));
#endif

    if (!(ClassType || ClassPin->LinkedTo.Num() > 0) || ClassType->HasAnyClassFlags(EClassFlags::CLASS_Abstract))
    {
        CompilerContext.MessageLog.Error(
            *LOCTEXT("DifficultyOperator_Error", "DifficultyOperator node @@ must have a @@ specified in @@").ToString(),
            *Node->GetName(),
            *ClassPin->GetName(),
            this);
        // we break exec links so this is the only error we get, don't want the SpawnActor node being considered and giving
        // 'unexpected node' type warnings
        Node->BreakAllNodeLinks();
        return;
    }

    UK2Node_CallFunction* CallCreateNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
    CallCreateNode->FunctionReference.SetExternalMember(
        GET_FUNCTION_NAME_CHECKED(UNDifficultyFactory, CreateDifficulty), UNDifficultyFactory::StaticClass());
    CallCreateNode->AllocateDefaultPins();

    CompilerContext.MessageLog.NotifyIntermediateObjectCreation(CallCreateNode, this);

    UEdGraphPin* CallExecPin = nullptr;
    bool bSucceeded = true;
    // connect exe
    {
        UEdGraphPin* SpawnExecPin = GetExecPin();
        CallExecPin = CallCreateNode->GetExecPin();
        bSucceeded &=
            SpawnExecPin && CallExecPin && CompilerContext.MovePinLinksToIntermediate(*SpawnExecPin, *CallExecPin).CanSafeConnect();

#if WITH_EDITOR
        DebugConnectionPin(1, SpawnExecPin, CallExecPin, bSucceeded);
#endif
    }

    // connect class
    {
        UEdGraphPin* CallClassPin = CallCreateNode->FindPin(FName("Class"), EGPD_Input);
        bSucceeded &=
            ClassPin && CallClassPin && CompilerContext.MovePinLinksToIntermediate(*ClassPin, *CallClassPin).CanSafeConnect();

#if WITH_EDITOR
        DebugConnectionPin(2, ClassPin, CallClassPin, bSucceeded);
        if (bDebug)
        {
            UE_LOG(LogTemp,
                Display,
                TEXT("2A - classname retrieve from Node>>pin->PinType is %s"),
                *(ClassPin ? ClassPin->PinType.PinSubCategoryObject.Get()->GetName() : ""));
            UE_LOG(LogTemp,
                Display,
                TEXT("2B - classname from Node>>pin->defaultObject is %s"),
                *(ClassPin ? ClassPin->DefaultObject->GetName() : ""));
        }
#endif
    }

    UEdGraphPin* CallResultPin = nullptr;
    UEdGraphPin* LastThen = nullptr;
    // connect result
    {
        UEdGraphPin* SpawnResultPin = GetResultPin();
        CallResultPin = CallCreateNode->GetReturnValuePin();

        // cast HACK. It should be safe. The only problem is native code generation.
        if (SpawnResultPin && CallResultPin)
        {
            CallResultPin->PinType = SpawnResultPin->PinType;
        }
        bSucceeded &= SpawnResultPin && CallResultPin &&
                      CompilerContext.MovePinLinksToIntermediate(*SpawnResultPin, *CallResultPin).CanSafeConnect();

#if WITH_EDITOR
        DebugConnectionPin(3, SpawnResultPin, CallResultPin, bSucceeded);

        if (bDebug)
        {
            UE_LOG(LogTemp,
                Display,
                TEXT("3A - classname retrieve from %s>>pin->PinType is %s"),
                *(CallCreateNode ? CallCreateNode->GetName() : ""),
                *(ClassPin ? CallResultPin->PinType.PinSubCategoryObject.Get()->GetName() : ""));
        }
#endif
    }

    // assign exposed values and connect then
    {
        LastThen = CallCreateNode->GetThenPin();
        UEdGraphPin* SpawnNodeThen = GetThenPin();
        bSucceeded &=
            SpawnNodeThen && LastThen && CompilerContext.MovePinLinksToIntermediate(*SpawnNodeThen, *LastThen).CanSafeConnect();

#if WITH_EDITOR
        DebugConnectionPin(4, SpawnNodeThen, LastThen, bSucceeded);
#endif
    }

    // For container properties,
    // return a local copy of the container so that the original cannot be modified.
    for (UEdGraphPin* Pin : Pins)
    {
        if (Pin == nullptr || Pin->Direction != EGPD_Input || Pin->PinName == ClassPinName || Pin->PinName == OuterPinName ||
            Pin->PinName == ClassPinName)
            continue;

        UProperty* BoundProperty = FindField<UProperty>(ClassType, Pin->PinName);

        if (BoundProperty == nullptr) continue;
        if (BoundProperty->HasAnyPropertyFlags(CPF_DisableEditOnInstance)) continue;

        bool bSucceeded2 = true;
        bool bSucceeded3 = true;
        FPinConnectionResponse Response;

#if WITH_EDITOR
        if (bDebug) UE_LOG(LogTemp, Display, TEXT("  > Try to set var from pin: %s"), *Pin->GetName());
#endif

        UK2Node_VariableSet* VarToSetNode = CompilerContext.SpawnIntermediateNode<UK2Node_VariableSet>(this, SourceGraph);
        VarToSetNode->SetFromProperty(BoundProperty, false, ClassType);
        Schema->ConfigureVarNode(VarToSetNode, BoundProperty->GetFName(), ClassType, CompilerContext.Blueprint);
        VarToSetNode->AllocateDefaultPins();
        CompilerContext.MessageLog.NotifyIntermediateObjectCreation(VarToSetNode, this);

        UEdGraphPin* ObjectVarToSetPin = VarToSetNode->FindPin(UEdGraphSchema_K2::PN_Self);
        UEdGraphPin* VariableVarToSetPin = VarToSetNode->FindPinChecked(BoundProperty->GetFName(), EGPD_Input);
        UEdGraphPin* ThenVarToSetPin = VarToSetNode->FindPinChecked(UEdGraphSchema_K2::PN_Then);
        UEdGraphPin* ExecVarToSetPin = VarToSetNode->GetExecPin();

#if WITH_EDITOR
        if (bDebug)
        {
            // clang-format off
            UE_LOG(LogTemp, Display, TEXT("    @Pin Variable Name: %s"), *VariableVarToSetPin->GetName());
            UE_LOG(LogTemp, Display, TEXT("    @Pin Object Name: %s"), *ObjectVarToSetPin->GetName());
            UE_LOG(LogTemp, Display, TEXT("    @GetMemberParentClass : %s"), *VarToSetNode->VariableReference.GetMemberParentClass()->GetName());
            UE_LOG(LogTemp, Display, TEXT("    @GetMemberName : %s"), *VarToSetNode->VariableReference.GetMemberName().ToString());
            UE_LOG(LogTemp, Display, TEXT("    @GetScope : %s"), *VarToSetNode->VariableReference.GetScope()->GetName());
            UE_LOG(LogTemp, Display, TEXT("    @GetVariableSourceClass : %s"), *VarToSetNode->GetVariableSourceClass()->GetName());
            // clang-format on
        }
#endif
        bSucceeded2 = CompilerContext.MovePinLinksToIntermediate(*Pin, *VariableVarToSetPin).CanSafeConnect();
        bSucceeded3 &= bSucceeded2;
#if WITH_EDITOR
        if (bDebug) UE_LOG(LogTemp, Display, TEXT("    1 - Connecting %s: %i "), *VariableVarToSetPin->GetName(), bSucceeded2);
#endif
        bSucceeded2 = TryConnectPin(CompilerContext, CallResultPin, ObjectVarToSetPin);
        bSucceeded3 &= bSucceeded2;
#if WITH_EDITOR
        if (bDebug) UE_LOG(LogTemp, Display, TEXT("    2 - Connecting %s: %i"), *ObjectVarToSetPin->GetName(), bSucceeded2);
#endif

        if (bSucceeded3)
        {
            bSucceeded2 = CompilerContext.MovePinLinksToIntermediate(*LastThen, *ThenVarToSetPin).CanSafeConnect();
            bSucceeded2 = TryConnectPin(CompilerContext, LastThen, ExecVarToSetPin);
            bSucceeded3 = bSucceeded2;
            if (bSucceeded2)
            {
                LastThen = ThenVarToSetPin;
            }

#if WITH_EDITOR
            if (bDebug) UE_LOG(LogTemp, Display, TEXT("    3B - Connecting last execution to the new node: %i"), bSucceeded2);
#endif
        }

        if (!bSucceeded3)
        {
            CallResultPin->BreakLinkTo(ObjectVarToSetPin);
            Pin->BreakLinkTo(VariableVarToSetPin);
#if WITH_EDITOR
            if (bDebug) UE_LOG(LogTemp, Display, TEXT("    3A - break previous connection"));
#endif
            continue;
        }
    }

#if WITH_EDITOR
    if (bDebug) UE_LOG(LogTemp, Display, TEXT("> AddDifficultyNode "));
#endif

    UK2Node_CallFunction* CallAddDifficultyNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
    CallAddDifficultyNode->FunctionReference.SetExternalMember(
        GET_FUNCTION_NAME_CHECKED(UNDifficultyFactory, AddDifficulty), UNDifficultyFactory::StaticClass());
    CallAddDifficultyNode->AllocateDefaultPins();
    CompilerContext.MessageLog.NotifyIntermediateObjectCreation(CallAddDifficultyNode, this);

    // Move pin values from this node to the function library
    UEdGraphPin* CallAddDifficultyPin = CallAddDifficultyNode->FindPin(TEXT("Difficulty"));
    bSucceeded &= CompilerContext.GetSchema()->TryCreateConnection(CallResultPin, CallAddDifficultyPin);

#if WITH_EDITOR
    DebugConnectionPin(1, CallResultPin, CallAddDifficultyPin, bSucceeded);
#endif

    bSucceeded &= CallAddDifficultyNode->GetThenPin() && LastThen &&
                  CompilerContext.MovePinLinksToIntermediate(*LastThen, *CallAddDifficultyNode->GetThenPin()).CanSafeConnect();

#if WITH_EDITOR
    DebugConnectionPin(2, LastThen, CallAddDifficultyNode->GetThenPin(), bSucceeded);
#endif

    bSucceeded &= CompilerContext.GetSchema()->TryCreateConnection(LastThen, CallAddDifficultyNode->GetExecPin());

#if WITH_EDITOR
    DebugConnectionPin(2, LastThen, CallAddDifficultyNode->GetExecPin(), bSucceeded);
#endif

    BreakAllNodeLinks();

    if (!bSucceeded)
    {
        CompilerContext.MessageLog.Error(*LOCTEXT("DifficultyOperator_Error", "DifficultyOperator error @@").ToString(), this);
    }
#if WITH_EDITOR
    if (bDebug) UE_LOG(LogTemp, Display, TEXT("<<<<<<<< END: %s <<<<<<<<"), ANSI_TO_TCHAR(__FUNCTION__));
#endif
}

bool UK2Node_DifficultyOperator::TryConnectPin(FKismetCompilerContext& CompilerContext, UEdGraphPin* PinA, UEdGraphPin* PinB) const
{
    const UEdGraphSchema_K2* Schema = CompilerContext.GetSchema();
    bool bSucceeded = true;
    FPinConnectionResponse Response = Schema->CanCreateConnection(PinA, PinB);

    if (!Response.CanSafeConnect())
    {
        bSucceeded = false;
        CompilerContext.MessageLog.Warning(
            *LOCTEXT("DifficultyOperator_PinConnection_Error",
                "DifficultyOperator error when trying to connect pins @@->@@ & @@->@@. Message: @@ in @@")
                 .ToString(),
            *PinA->GetOwningNode()->GetName(),
            *PinA->GetName(),
            *PinB->GetOwningNode()->GetName(),
            *PinB->GetName(),
            *Response.Message.ToString(),
            this);
    }
    else
    {
        bSucceeded &= Schema->TryCreateConnection(PinA, PinB);
    }
    return bSucceeded;
}

void UK2Node_DifficultyOperator::OnBlueprintClassModified(UBlueprint* TargetBlueprint)
{
    check(TargetBlueprint);
    UBlueprint* OwnerBlueprint =
        FBlueprintEditorUtils::FindBlueprintForNode(this);    // GetBlueprint() will crash, when the node is transient, etc
    if (OwnerBlueprint)
    {
        // The Blueprint that contains this node may have finished
        // regenerating (see bHasBeenRegenerated), but we still may be
        // in the midst of unwinding a cyclic load (dependent Blueprints);
        // this lambda could be triggered during the targeted
        // Blueprint's regeneration - meaning we really haven't completed
        // the load process. In this situation, we cannot "reset loaders"
        // because it is not likely that all of the package's objects
        // have been post-loaded (meaning an assert will most likely
        // fire from ReconstructNode). To guard against this, we flip this
        // Blueprint's bIsRegeneratingOnLoad (like in
        // UBlueprintGeneratedClass::ConditionalRecompileClass), which
        // we use throughout Blueprints to keep us from reseting loaders
        // on object Rename()
        const bool bOldIsRegeneratingVal = OwnerBlueprint->bIsRegeneratingOnLoad;
        OwnerBlueprint->bIsRegeneratingOnLoad = bOldIsRegeneratingVal || TargetBlueprint->bIsRegeneratingOnLoad;

        ReconstructNode();

        OwnerBlueprint->bIsRegeneratingOnLoad = bOldIsRegeneratingVal;
    }
}

void UK2Node_DifficultyOperator::ReallocatePinsDuringReconstruction(TArray<UEdGraphPin*>& OldPins)
{
#if WITH_EDITOR
    if (bDebug) UE_LOG(LogTemp, Display, TEXT(">>>>>>>> %s >>>>>>>>"), ANSI_TO_TCHAR(__FUNCTION__));
    if (bDebug) UE_LOG(LogTemp, Display, TEXT("Oldpins: %d"), OldPins.Num());
#endif

    AllocateDefaultPins();

    // This pin is rebuild in CreateNewPins() using InputClass
    bool bRemoveSuccess = RemovePin(FindPin(UEdGraphSchema_K2::PN_ReturnValue, EGPD_Output));

#if WITH_EDITOR
    if (bDebug) UE_LOG(LogTemp, Display, TEXT("Remove default success: %i"), bRemoveSuccess);
#endif

    // // Recreate output pins based on the previous input class
    UEdGraphPin* OldClassPin = FindClassPin(OldPins);
    if (UClass* InputClass = GetInputClass(OldClassPin))
    {
        CreateNewPins(InputClass);
    }

    RestoreSplitPins(OldPins);
}

void UK2Node_DifficultyOperator::CreateNewPins(UClass* InClass)
{
    // Create the set of output pins through the optional pin manager
    FDifficultyOperatorOptionalPinManager OptionalPinManager(InClass, bExcludeObjectContainers);
    OptionalPinManager.RebuildPropertyList(ShowPinForProperties, InClass);
    OptionalPinManager.CreateVisiblePins(ShowPinForProperties, InClass, EGPD_Input, this);

    CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Object, InClass, UEdGraphSchema_K2::PN_ReturnValue);

    // Unbind OnChanged() delegate from a previous Blueprint, if valid.
    // If the class was generated for a Blueprint, bind delegates to handle any OnChanged() & OnCompiled() events.
    bool bShouldClearDelegate = true;
    if (InClass)
    {
        if (UBlueprint* Blueprint = Cast<UBlueprint>(InClass->ClassGeneratedBy))
        {
            // only clear the delegate if the pin has changed:
            bShouldClearDelegate = BlueprintSubscribedTo != Blueprint;
        }
    }

    if (bShouldClearDelegate)
    {
        ClearDelegates();
    }

    if (InClass && bShouldClearDelegate)
    {
        if (UBlueprint* Blueprint = Cast<UBlueprint>(InClass->ClassGeneratedBy))
        {
            BlueprintSubscribedTo = Blueprint;
            OnBlueprintChangedDelegate = Blueprint->OnChanged().AddUObject(this, &ThisClass::OnBlueprintClassModified);
            OnBlueprintCompiledDelegate = Blueprint->OnCompiled().AddUObject(this, &ThisClass::OnBlueprintClassModified);
        }
    }
}

void UK2Node_DifficultyOperator::OnClassPinChanged()
{
    UClass* InputClass = GetInputClass();

#if WITH_EDITOR
    if (!InputClass->IsChildOf(UNDifficultyAdapterAbstract::StaticClass()) ||
        InputClass->HasAnyClassFlags(EClassFlags::CLASS_Abstract))
    {
        UE_LOG(LogTemp,
            Error,
            TEXT("%s has a wrong class selected, you have to set a subclass of %s"),
            *this->GetName(),
            *UNDifficultyAdapterAbstract::StaticClass()->GetName());
    }
#endif

    Modify();

    TArray<UEdGraphPin*> OldPins = MoveTemp(Pins);

    // Gather all current output pins
    bool bHasToBeSaved = false;
#if WITH_EDITOR
    UE_LOG(LogTemp, Display, TEXT(">>>>>> %s >>>>>>"), ANSI_TO_TCHAR(__FUNCTION__));
    UE_LOG(LogTemp, Display, TEXT("OldPins %d"), OldPins.Num());
#endif
    for (int32 PinIndex = 0; PinIndex < OldPins.Num(); ++PinIndex)
    {
        UEdGraphPin* OldPin = OldPins[PinIndex];
        if (OldPin->PinType.PinCategory == UEdGraphSchema_K2::PC_Exec ||
            (OldPin->Direction == EGPD_Input && OldPin->PinName == ClassPinName) ||
            (OldPin->Direction == EGPD_Input && OldPin->PinName == OuterPinName))
        {
#if WITH_EDITOR
            UE_LOG(LogTemp, Display, TEXT("  Pin: %s"), *OldPin->GetName());
#endif
            OldPins.RemoveAt(PinIndex--, 1, false);
            Pins.Add(OldPin);
        }
    }
#if WITH_EDITOR
    UE_LOG(LogTemp, Display, TEXT("NewPins %d"), Pins.Num());
#endif

    // Clear the current output pin settings (so they don't carry over to the new set)
    ShowPinForProperties.Reset();

    // Create output pins for the new class type

    CreateNewPins(InputClass);

    // Only try to rewire pins from porperties existing in both old and new class
    for (int32 PinIndex = 0; PinIndex < OldPins.Num(); ++PinIndex)
    {
        UEdGraphPin* OldPin = OldPins[PinIndex];
        bool bInNewPins = false;
        for (FOptionalPinFromProperty& NewPin : ShowPinForProperties)
        {
            bInNewPins = NewPin.PropertyName == OldPin->PinName ? true : bInNewPins;
        }
        if (!bInNewPins)
        {
            OldPins.RemoveAt(PinIndex--, 1, false);
        }
    }

    // Restore the split pins and reconnect input pins to previously linked inputs
    RestoreSplitPins(OldPins);
    RewireOldPinsToNewPins(OldPins, Pins, nullptr);

    // Notify the graph that the node has been changed
    if (UEdGraph* Graph = GetGraph())
    {
        Graph->NotifyGraphChanged();
    }
}

void UK2Node_DifficultyOperator::ValidateNodeDuringCompilation(class FCompilerResultsLog& MessageLog) const
{
    Super::ValidateNodeDuringCompilation(MessageLog);

#if WITH_EDITOR
    UE_LOG(LogTemp, Display, TEXT("%s"), ANSI_TO_TCHAR(__FUNCTION__));
#endif

    if (const UClass* SourceClass = GetInputClass())
    {
        if (!SourceClass->IsChildOf(UNDifficultyAdapterAbstract::StaticClass()) ||
            SourceClass->HasAnyClassFlags(EClassFlags::CLASS_Abstract))
        {
            bool bEmitWarning = true;
            MessageLog.Warning(
                *LOCTEXT("NotInstanciableObjectWarning", "@@ has a wrong class selected, you have to set a subclass of @@")
                     .ToString(),
                this,
                UNDifficultyAdapterAbstract::StaticClass());
            return;
        }

        return;

        for (const UEdGraphPin* Pin : Pins)
        {
            // Emit a warning for existing connections to potentially unsafe array property defaults. We do this rather than
            // just implicitly breaking the connection (for compatibility).
            if (Pin && Pin->Direction == EGPD_Input && Pin->LinkedTo.Num() > 0)
            {
                // Even though container property defaults are copied, the copy could still contain a reference to a non-class
                // object that belongs to the CDO, which would potentially be unsafe to modify.
                bool bEmitWarning = false;
                const UProperty* TestProperty = SourceClass->FindPropertyByName(Pin->PinName);
                if (const UArrayProperty* ArrayProperty = Cast<UArrayProperty>(TestProperty))
                {
                    bEmitWarning = ArrayProperty->Inner && ArrayProperty->Inner->IsA<UObjectProperty>() &&
                                   !ArrayProperty->Inner->IsA<UClassProperty>();
                }
                else if (const USetProperty* SetProperty = Cast<USetProperty>(TestProperty))
                {
                    bEmitWarning = SetProperty->ElementProp && SetProperty->ElementProp->IsA<UObjectProperty>() &&
                                   !SetProperty->ElementProp->IsA<UClassProperty>();
                }
                else if (const UMapProperty* MapProperty = Cast<UMapProperty>(TestProperty))
                {
                    bEmitWarning = (MapProperty->KeyProp && MapProperty->KeyProp->IsA<UObjectProperty>() &&
                                       !MapProperty->KeyProp->IsA<UClassProperty>()) ||
                                   (MapProperty->ValueProp && MapProperty->ValueProp->IsA<UObjectProperty>() &&
                                       !MapProperty->ValueProp->IsA<UClassProperty>());
                }

                if (bEmitWarning)
                {
                    MessageLog.Warning(*LOCTEXT("UnsafeConnectionWarning",
                                           "@@ has an unsafe connection to the @@ output pin that is not fully supported at "
                                           "this time. It should "
                                           "be disconnected to avoid potentially corrupting class defaults at runtime. If you "
                                           "need to keep this "
                                           "connection, make sure you're not changing the state of any elements in the "
                                           "container. Also note that "
                                           "if you recreate this node, it will not include this output pin.")
                                            .ToString(),
                        this,
                        Pin);
                }
            }
        }
    }
}

void UK2Node_DifficultyOperator::ClearDelegates()
{
    if (OnBlueprintChangedDelegate.IsValid())
    {
        if (BlueprintSubscribedTo)
        {
            BlueprintSubscribedTo->OnChanged().Remove(OnBlueprintChangedDelegate);
        }
        OnBlueprintChangedDelegate.Reset();
    }

    if (OnBlueprintCompiledDelegate.IsValid())
    {
        if (BlueprintSubscribedTo)
        {
            BlueprintSubscribedTo->OnCompiled().Remove(OnBlueprintCompiledDelegate);
        }
        OnBlueprintCompiledDelegate.Reset();
    }
    BlueprintSubscribedTo = nullptr;
}

void UK2Node_DifficultyOperator::BeginDestroy()
{
    ClearDelegates();
    Super::BeginDestroy();
}

#undef LOCTEXT_NAMESPACE