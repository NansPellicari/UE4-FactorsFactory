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

#include "K2Node/K2Node_FactorOperator.h"

#include "BlueprintActionDatabaseRegistrar.h"
#include "BlueprintNodeSpawner.h"
#include "EdGraph/EdGraphSchema.h"
#include "EdGraphSchema_K2.h"
#include "EdGraphUtilities.h"
#include "EditorCategoryUtils.h"
#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "FactorUnit/FactorUnitAdapter.h"
#include "FactorsFactoryBlueprintHelpers.h"
#include "GraphEditorActions.h"
#include "K2Node/FactorUnitUtilities.h"
#include "K2Node_AssignmentStatement.h"
#include "K2Node_CallFunction.h"
#include "K2Node_DynamicCast.h"
#include "K2Node_GenericCreateObject.h"
#include "K2Node_TemporaryVariable.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/CompilerResultsLog.h"
#include "KismetCompiler.h"
#include "KismetCompilerMisc.h"
#include "Operator/OperatorProviders.h"
#include "UObject/UnrealType.h"

#define LOCTEXT_NAMESPACE "FactorsFactoryEd"

namespace
{
	// Optional pin manager subclass.
	struct FFactorOperatorOptionalPinManager : public FOptionalPinManager
	{
		FFactorOperatorOptionalPinManager(UClass* InClass, bool bExcludeObjectContainers) : FOptionalPinManager()
		{
			SrcClass = InClass;
			bExcludeObjectArrayProperties = bExcludeObjectContainers;
			bExcludeObjectContainerProperties = bExcludeObjectContainers;
		}

		virtual void GetRecordDefaults(UProperty* TestProperty, FOptionalPinFromProperty& Record) const override
		{
			FOptionalPinManager::GetRecordDefaults(TestProperty, Record);

			// Show pin which the property is owned by the src class or UNFactorUnitAdapter class.
			Record.bShowPin = TestProperty->GetOwnerClass() == SrcClass;
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
	class FKCHandler_FactorOperator : public FNodeHandlingFunctor
	{
	public:
		FKCHandler_FactorOperator(FKismetCompilerContext& InCompilerContext) : FNodeHandlingFunctor(InCompilerContext) {}

		// virtual void RegisterNets(FKismetFunctionContext& Context, UEdGraphNode* Node) override
		// {
		// 	UE_LOG(LogTemp, Warning, TEXT("*********** Calling %s"), ANSI_TO_TCHAR(__FUNCTION__));
		//         // Cast to the correct node type
		//         if (const UK2Node_FactorUnit* GetClassDefaultsNode = Cast<UK2Node_FactorUnit>(Node))
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
		//                                 Pin->PinName != UK2Node_FactorUnit::ClassPinName)
		//                             {
		//                                 UProperty* BoundProperty = FindField<UProperty>(ClassType, Pin->PinName);
		//                                 if (BoundProperty != nullptr)
		//                                 {
		//                                     FBPTerminal* OutputTerm =
		//                                         Context.CreateLocalTerminalFromPinAutoChooseScope(Pin,
		//                                         Pin->PinName.ToString());
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
		//                                         *LOCTEXT("UnmatchedNewPinOnCompile", "Failed to find a class member to match
		//                                         @@")
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
		// }
	};
}	 // namespace

FName UK2Node_FactorUnit::ClassPinName(TEXT("FactorUnitClass"));
FName UK2Node_FactorUnit::FactorPinName(TEXT("Factor"));
FName UK2Node_FactorUnit::OperatorPinName(TEXT("Operator"));
FName UK2Node_FactorUnit::OuterPinName(TEXT("Outer"));
FName UK2Node_FactorUnit::ObjectPinName(TEXT("FactorUnitObject"));

FText UK2Node_FactorUnit::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("FactorOperatorFactory_Title", "Create a Factor Unit");
}

FText UK2Node_FactorUnit::GetTooltipText() const
{
	return LOCTEXT("FactorOperatorFactory_Tooltip", "This node allow to create any factorUnit and add it to a factor");
}

FText UK2Node_FactorUnit::GetMenuCategory() const
{
	return LOCTEXT("FactorOperatorFactory_MenuCategory", "FactorsFactory|Factory");
}

void UK2Node_FactorUnit::PreEditChange(UProperty* PropertyThatWillChange)
{
	Super::PreEditChange(PropertyThatWillChange);

	if (PropertyThatWillChange && PropertyThatWillChange->GetFName() == GET_MEMBER_NAME_CHECKED(FOptionalPinFromProperty, bShowPin))
	{
		FOptionalPinManager::CacheShownPins(ShowPinForProperties, OldShownPins);
	}
}

UEdGraphPin* UK2Node_FactorUnit::GetOuterPin() const
{
	UEdGraphPin* Pin = FindPin(UK2Node_FactorUnit::OuterPinName);
	ensure(nullptr == Pin || Pin->Direction == EGPD_Input);
	return Pin;
}

UEdGraphPin* UK2Node_FactorUnit::GetResultPin() const
{
	UEdGraphPin* Pin = FindPinChecked(UEdGraphSchema_K2::PN_ReturnValue);
	check(Pin->Direction == EGPD_Output);
	return Pin;
}

UEdGraphPin* UK2Node_FactorUnit::GetThenPin() const
{
	UEdGraphPin* Pin = FindPinChecked(UEdGraphSchema_K2::PN_Then);
	check(Pin->Direction == EGPD_Output);
	return Pin;
}

void UK2Node_FactorUnit::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
	Super::GetMenuActions(ActionRegistrar);

	UClass* ActionKey = GetClass();
	if (ActionRegistrar.IsOpenForRegistration(ActionKey))
	{
		UBlueprintNodeSpawner* NodeSpawner = UBlueprintNodeSpawner::Create(GetClass());
		check(NodeSpawner != nullptr);

		ActionRegistrar.AddBlueprintAction(ActionKey, NodeSpawner);
	}
}

UClass* UK2Node_FactorUnit::GetInputClass() const
{
	return GetInputClass(FindClassPin());
}

UClass* UK2Node_FactorUnit::GetInputOperatorClass() const
{
	return GetInputClass(FindOperatorPin());
}

UEdGraphPin* UK2Node_FactorUnit::FindClassPin() const
{
	UEdGraphPin* Pin = FindPinChecked(UK2Node_FactorUnit::ClassPinName);
	check(Pin->Direction == EGPD_Input);
	return Pin;
}

UEdGraphPin* UK2Node_FactorUnit::FindClassPin(const TArray<UEdGraphPin*>& FromPins) const
{
	UEdGraphPin* const* FoundPin = FromPins.FindByPredicate(
		[](const UEdGraphPin* CurPin) { return CurPin && CurPin->Direction == EGPD_Input && CurPin->PinName == ClassPinName; });

	return FoundPin ? *FoundPin : nullptr;
}

UEdGraphPin* UK2Node_FactorUnit::FindFactorPin() const
{
	UEdGraphPin* Pin = FindPinChecked(UK2Node_FactorUnit::FactorPinName);
	check(Pin->Direction == EGPD_Input);
	return Pin;
}

UEdGraphPin* UK2Node_FactorUnit::FindFactorPin(const TArray<UEdGraphPin*>& FromPins) const
{
	UEdGraphPin* const* FoundPin = FromPins.FindByPredicate(
		[](const UEdGraphPin* CurPin) { return CurPin && CurPin->Direction == EGPD_Input && CurPin->PinName == FactorPinName; });

	return FoundPin ? *FoundPin : nullptr;
}

UEdGraphPin* UK2Node_FactorUnit::FindOperatorPin() const
{
	UEdGraphPin* Pin = FindPinChecked(UK2Node_FactorUnit::OperatorPinName);
	check(Pin->Direction == EGPD_Input);
	return Pin;
}

UEdGraphPin* UK2Node_FactorUnit::FindOperatorPin(const TArray<UEdGraphPin*>& FromPins) const
{
	UEdGraphPin* const* FoundPin = FromPins.FindByPredicate(
		[](const UEdGraphPin* CurPin) { return CurPin && CurPin->Direction == EGPD_Input && CurPin->PinName == OperatorPinName; });

	return FoundPin ? *FoundPin : nullptr;
}

UClass* UK2Node_FactorUnit::GetInputClass(const UEdGraphPin* FromPin) const
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

void UK2Node_FactorUnit::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	const FName PropertyName = (PropertyChangedEvent.Property ? PropertyChangedEvent.Property->GetFName() : NAME_None);

	if (PropertyName == GET_MEMBER_NAME_CHECKED(FOptionalPinFromProperty, bShowPin))
	{
		FOptionalPinManager::EvaluateOldShownPins(ShowPinForProperties, OldShownPins, this);
		GetSchema()->ReconstructNode(*this);
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void UK2Node_FactorUnit::PostPlacedNewNode()
{
	// Always exclude object container properties for new nodes.
	// @TODO - Could potentially expose object reference values if/when we have support for 'const' input pins.
	bExcludeObjectContainers = true;

	if (UEdGraphPin* OpClassPin = FindOperatorPin(Pins))
	{
		if (UClass* OpInputClass = GetInputClass(OpClassPin))
		{
			CreateNewPins(OpInputClass, false);
		}
	}

	if (UEdGraphPin* ClassPin = FindClassPin(Pins))
	{
		if (UClass* InputClass = GetInputClass(ClassPin))
		{
			CreateNewPins(InputClass);
		}
	}
}

void UK2Node_FactorUnit::PinConnectionListChanged(UEdGraphPin* ChangedPin)
{
	if (ChangedPin != nullptr && (ChangedPin->PinName == ClassPinName || ChangedPin->PinName == OperatorPinName) &&
		ChangedPin->Direction == EGPD_Input)
	{
		OnClassPinChanged();
	}
}

void UK2Node_FactorUnit::PinDefaultValueChanged(UEdGraphPin* ChangedPin)
{
	if (ChangedPin != nullptr && (ChangedPin->PinName == ClassPinName || ChangedPin->PinName == OperatorPinName) &&
		ChangedPin->Direction == EGPD_Input)
	{
		OnClassPinChanged();
	}
}

bool UK2Node_FactorUnit::HasExternalDependencies(TArray<class UStruct*>* OptionalOutput) const
{
#if WITH_EDITOR
	if (bDebug) UE_LOG(LogTemp, Display, TEXT(">>>>>>>> %s >>>>>>>>"), ANSI_TO_TCHAR(__FUNCTION__));
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

FNodeHandlingFunctor* UK2Node_FactorUnit::CreateNodeHandler(FKismetCompilerContext& CompilerContext) const
{
	return new FKCHandler_FactorOperator(CompilerContext);
}

void UK2Node_FactorUnit::AllocateDefaultPins()
{
	const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();

	// Execution pins
	CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Execute);
	CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Then);

	// Create the class input type selector pin
	UEdGraphPin* ClassPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Class, UNFactorUnitAdapter::StaticClass(), ClassPinName);
	K2Schema->ConstructBasicPinTooltip(*ClassPin,
		LOCTEXT("ClassPinDescription", "The class from which to access one or more default values."),
		ClassPin->PinToolTip);

	UEdGraphPin* FactorPin = CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Struct, FFactorAttribute::StaticStruct(), FactorPinName);
	K2Schema->ConstructBasicPinTooltip(*FactorPin,
		LOCTEXT("ClassPinDescription", "The factor from which the factorUnit will be attached to."),
		FactorPin->PinToolTip);

	UEdGraphPin* OperatorClassPin =
		CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Class, UNOperatorProviderBase::StaticClass(), OperatorPinName);
	K2Schema->ConstructBasicPinTooltip(*ClassPin,
		LOCTEXT("ClassPinDescription", "The class from which to access one or more default values."),
		ClassPin->PinToolTip);

	CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Object, UNFactorUnitAdapter::StaticClass(), UEdGraphSchema_K2::PN_ReturnValue);
}

void UK2Node_FactorUnit::ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
	Super::ExpandNode(CompilerContext, SourceGraph);

	const UEdGraphSchema_K2* Schema = CompilerContext.GetSchema();

	FFactorUnitUtilities* Utils = new FFactorUnitUtilities(this, CompilerContext, SourceGraph, bDebug);

	UClass* ClassType = GetInputClass();
	UClass* OperatorClassType = GetInputOperatorClass();
#if WITH_EDITOR
	uint32 DebugStep = 0;
#endif

	UK2Node_FactorUnit* Node = this;
	UEdGraphPin* ClassPin = FindClassPin();
	UEdGraphPin* OperatorPin = FindOperatorPin();
	UEdGraphPin* FactorPin = FindFactorPin();
	UEdGraphPin* SpawnExecPin = GetExecPin();
	UEdGraphPin* SpawnThenPin = GetThenPin();
	bool bSucceeded = true;
	UEdGraphPin* LastThen = nullptr;

#if WITH_EDITOR
	if (bDebug) UE_LOG(LogTemp, Display, TEXT(">>>>>>>>>> BEGIN: %s >>>>>>>>>>"), ANSI_TO_TCHAR(__FUNCTION__));
#endif

	if (!(ClassType || ClassPin->LinkedTo.Num() > 0) || ClassType->HasAnyClassFlags(EClassFlags::CLASS_Abstract))
	{
		CompilerContext.MessageLog.Error(
			*LOCTEXT("FactorOperator_Error", "FactorOperator node @@ must have a @@ specified in @@").ToString(),
			*Node->GetName(),
			*ClassPin->GetName(),
			this);
		// we break exec links so this is the only error we get, don't want the SpawnActor node being considered and giving
		// 'unexpected node' type warnings
		Node->BreakAllNodeLinks();
		return;
	}

	if (!(OperatorClassType || OperatorPin->LinkedTo.Num() > 0) || OperatorClassType->HasAnyClassFlags(EClassFlags::CLASS_Abstract))
	{
		CompilerContext.MessageLog.Error(
			*LOCTEXT("FactorOperator_Error", "FactorOperator node @@ must have a @@ specified in @@").ToString(),
			*Node->GetName(),
			*OperatorPin->GetName(),
			this);
		// we break exec links so this is the only error we get, don't want the SpawnActor node being considered and giving
		// 'unexpected node' type warnings
		Node->BreakAllNodeLinks();
		return;
	}

	// Create temp variable for factor field which allows to connect it to blueprint helpers functions
	UK2Node_TemporaryVariable* TempFactorNode = CompilerContext.SpawnIntermediateNode<UK2Node_TemporaryVariable>(this, SourceGraph);
	TempFactorNode->VariableType = FactorPin->PinType;
	TempFactorNode->AllocateDefaultPins();
	CompilerContext.MessageLog.NotifyIntermediateObjectCreation(TempFactorNode, this);
	// Get the output pin
	UEdGraphPin* TempFactorOutput = TempFactorNode->GetVariablePin();
	// Create an assignement for the temp variable
	UK2Node_AssignmentStatement* AssignmentNode = SourceGraph->CreateIntermediateNode<UK2Node_AssignmentStatement>();
	AssignmentNode->AllocateDefaultPins();
	CompilerContext.MessageLog.NotifyIntermediateObjectCreation(AssignmentNode, this);
	AssignmentNode->GetVariablePin()->PinType = TempFactorNode->GetVariablePin()->PinType;
	AssignmentNode->GetVariablePin()->MakeLinkTo(TempFactorNode->GetVariablePin());
	AssignmentNode->GetValuePin()->PinType = TempFactorNode->GetVariablePin()->PinType;

	bSucceeded &= Utils->MovePinLinks(SpawnExecPin, AssignmentNode->GetExecPin());
	bSucceeded &= Utils->MovePinLinks(SpawnThenPin, AssignmentNode->GetThenPin());
	bSucceeded &= Utils->MovePinLinks(FactorPin, AssignmentNode->GetValuePin());

	if (bSucceeded)
	{
		LastThen = AssignmentNode->GetThenPin();
	}

	// BEGIN Create & populate FactorUnit
	UK2Node_CallFunction* CallCreateUnitNode = Utils->CreateUnitNode(ClassPin, TempFactorOutput);
	bSucceeded &= Utils->MovePinLinks(LastThen, CallCreateUnitNode->GetThenPin());
	bSucceeded &= Utils->TryConnectPin(LastThen, CallCreateUnitNode->GetExecPin());

	if (bSucceeded)
	{
		LastThen = CallCreateUnitNode->GetThenPin();
	}

	UEdGraphPin* UnitCreatedPin = CallCreateUnitNode->GetReturnValuePin();

	LastThen = Utils->ConnectPinsForObject(
		ClassType, UnitCreatedPin, LastThen, Pins, {ClassPinName, FactorPinName, OperatorPinName, OuterPinName});
	// END Create & populate FactorUnit

	// BEGIN Create & populate OperatorProvider
	TTuple<UK2Node_CallFunction*, UK2Node_DynamicCast*> lastNodes = Utils->CreateOperatorNode(OperatorPin, OperatorClassType);
	bSucceeded &= Utils->MovePinLinks(LastThen, lastNodes.Get<0>()->GetThenPin());
	bSucceeded &= Utils->TryConnectPin(LastThen, lastNodes.Get<0>()->GetExecPin());

	if (bSucceeded)
	{
		LastThen = lastNodes.Get<0>()->GetThenPin();
	}

	// Connect output to cast
	UEdGraphPin* OperatorCreatedPin = lastNodes.Get<1>()->GetCastResultPin();

	LastThen = Utils->ConnectPinsForObject(
		OperatorClassType, OperatorCreatedPin, LastThen, Pins, {ClassPinName, FactorPinName, OperatorPinName, OuterPinName});
	// END Create & populate OperatorProvider

#if WITH_EDITOR
	if (bDebug) UE_LOG(LogTemp, Display, TEXT("> Call SetOperatorProvider"));
#endif
	UFunction* SetFunction = ClassType->FindFunctionByName(TEXT("SetOperatorProvider"));
	check(SetFunction);

	UK2Node_CallFunction* CallFuncOperatorSetterNode =
		CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
	CallFuncOperatorSetterNode->SetFromFunction(SetFunction);
	CallFuncOperatorSetterNode->AllocateDefaultPins();
	CompilerContext.MessageLog.NotifyIntermediateObjectCreation(CallFuncOperatorSetterNode, this);

	bSucceeded &= Utils->TryConnectPin(UnitCreatedPin, Schema->FindSelfPin(*CallFuncOperatorSetterNode, EGPD_Input));
	bSucceeded &= Utils->TryConnectPin(OperatorCreatedPin, CallFuncOperatorSetterNode->FindPin(TEXT("_OperatorProvider")));
	bSucceeded &= Utils->MovePinLinks(LastThen, CallFuncOperatorSetterNode->GetThenPin());
	bSucceeded &= Utils->TryConnectPin(LastThen, CallFuncOperatorSetterNode->GetExecPin());

	if (bSucceeded)
	{
		LastThen = CallFuncOperatorSetterNode->GetThenPin();
	}

#if WITH_EDITOR
	if (bDebug) UE_LOG(LogTemp, Display, TEXT("> AddFactorUnitNode "));
#endif
	UK2Node_CallFunction* CallAddFactorUnitNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
	CallAddFactorUnitNode->FunctionReference.SetExternalMember(
		GET_FUNCTION_NAME_CHECKED(UNFactorsFactoryBlueprintHelpers, AddFactorUnit),
		UNFactorsFactoryBlueprintHelpers::StaticClass());
	CallAddFactorUnitNode->AllocateDefaultPins();
	CompilerContext.MessageLog.NotifyIntermediateObjectCreation(CallAddFactorUnitNode, this);

	// Move pin values from this node to the function library
	UEdGraphPin* CallAddFactorUnitPin = CallAddFactorUnitNode->FindPin(TEXT("FactorUnit"));
	UEdGraphPin* CallAddFactorPin = CallAddFactorUnitNode->FindPin(TEXT("Factor"));

	bSucceeded &= Utils->TryConnectPin(UnitCreatedPin, CallAddFactorUnitPin);
	bSucceeded &= Utils->TryConnectPin(TempFactorOutput, CallAddFactorPin);
	bSucceeded &= Utils->MovePinLinks(LastThen, CallAddFactorUnitNode->GetThenPin());
	bSucceeded &= Utils->TryConnectPin(LastThen, CallAddFactorUnitNode->GetExecPin());
	bSucceeded &= CompilerContext.GetSchema()->TryCreateConnection(LastThen, CallAddFactorUnitNode->GetExecPin());
	BreakAllNodeLinks();

	if (!bSucceeded)
	{
		CompilerContext.MessageLog.Error(*LOCTEXT("FactorOperator_Error", "FactorOperator error @@").ToString(), this);
	}
#if WITH_EDITOR
	if (bDebug) UE_LOG(LogTemp, Display, TEXT("<<<<<<<< END: %s <<<<<<<<"), ANSI_TO_TCHAR(__FUNCTION__));
#endif
}

void UK2Node_FactorUnit::OnBlueprintClassModified(UBlueprint* TargetBlueprint)
{
	check(TargetBlueprint);
	UBlueprint* OwnerBlueprint =
		FBlueprintEditorUtils::FindBlueprintForNode(this);	  // GetBlueprint() will crash, when the node is transient, etc
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

void UK2Node_FactorUnit::ReallocatePinsDuringReconstruction(TArray<UEdGraphPin*>& OldPins)
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

	// Recreate output pins based on the previous input class
	UEdGraphPin* OldOperatorClassPin = FindOperatorPin(OldPins);
	if (UClass* InputOperatorClass = GetInputClass(OldOperatorClassPin))
	{
		CreateNewPins(InputOperatorClass, false);
	}

	// Recreate output pins based on the previous input class
	UEdGraphPin* OldClassPin = FindClassPin(OldPins);
	if (UClass* InputClass = GetInputClass(OldClassPin))
	{
		CreateNewPins(InputClass);
	}

	RestoreSplitPins(OldPins);
}

void UK2Node_FactorUnit::CreateNewPins(UClass* InClass, bool bOuputPin)
{
	// Create the set of output pins through the optional pin manager
	FFactorOperatorOptionalPinManager OptionalPinManager(InClass, bExcludeObjectContainers);
	OptionalPinManager.RebuildPropertyList(ShowPinForProperties, InClass);
	OptionalPinManager.CreateVisiblePins(ShowPinForProperties, InClass, EGPD_Input, this);

	if (bOuputPin)
	{
		CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Object, InClass, UEdGraphSchema_K2::PN_ReturnValue);
	}

	// Unbind OnChanged() delegate from a previous Blueprint, if valid.
	// If the class was generated for a Blueprint, bind delegates to handle any OnChanged() & OnCompiled() events.
	bool bShouldClearDelegate = true;
	if (InClass)
	{
		if (UBlueprint* Blueprint = Cast<UBlueprint>(InClass->ClassGeneratedBy))
		{
			// only clear the delegate if the pin has changed:
			bShouldClearDelegate = !BlueprintSubscribers.Contains(InClass->GetPathName()) ||
								   BlueprintSubscribers[InClass->GetPathName()].Get<0>() != Blueprint;
		}
	}

	if (bShouldClearDelegate)
	{
		ClearDelegates(InClass->GetPathName());
	}

	if (InClass && bShouldClearDelegate)
	{
		if (UBlueprint* Blueprint = Cast<UBlueprint>(InClass->ClassGeneratedBy))
		{
			BlueprintSubscribers[InClass->GetPathName()].Get<0>() = Blueprint;
			BlueprintSubscribers[InClass->GetPathName()].Get<1>() =
				Blueprint->OnChanged().AddUObject(this, &ThisClass::OnBlueprintClassModified);
			;
			BlueprintSubscribers[InClass->GetPathName()].Get<2>() =
				Blueprint->OnCompiled().AddUObject(this, &ThisClass::OnBlueprintClassModified);
		}
	}
}

void UK2Node_FactorUnit::OnClassPinChanged()
{
	UClass* InputClass = GetInputClass();
	UClass* InputOpClass = GetInputOperatorClass();

#if WITH_EDITOR
	if (!InputClass->IsChildOf(UNFactorUnitAdapter::StaticClass()) || InputClass->HasAnyClassFlags(EClassFlags::CLASS_Abstract))
	{
		UE_LOG(LogTemp,
			Error,
			TEXT("%s has a wrong class selected, you have to set a subclass of %s"),
			*this->GetName(),
			*UNFactorUnitAdapter::StaticClass()->GetName());
	}
	if (!InputOpClass->IsChildOf(UNOperatorProviderBase::StaticClass()) ||
		InputOpClass->HasAnyClassFlags(EClassFlags::CLASS_Abstract))
	{
		UE_LOG(LogTemp,
			Error,
			TEXT("%s has a wrong operator class selected, you have to set a subclass of %s"),
			*this->GetName(),
			*UNOperatorProviderBase::StaticClass()->GetName());
	}
#endif

	Modify();

	TArray<UEdGraphPin*> OldPins = MoveTemp(Pins);

	// Gather all current output pins
	bool bHasToBeSaved = false;
#if WITH_EDITOR
	if (bDebug) UE_LOG(LogTemp, Display, TEXT(">>>>>> %s >>>>>>"), ANSI_TO_TCHAR(__FUNCTION__));
	if (bDebug) UE_LOG(LogTemp, Display, TEXT("OldPins %d"), OldPins.Num());
#endif
	for (int32 PinIndex = 0; PinIndex < OldPins.Num(); ++PinIndex)
	{
		UEdGraphPin* OldPin = OldPins[PinIndex];
		if (OldPin->PinType.PinCategory == UEdGraphSchema_K2::PC_Exec ||
			(OldPin->Direction == EGPD_Input && OldPin->PinName == ClassPinName) ||
			(OldPin->Direction == EGPD_Input && OldPin->PinName == FactorPinName) ||
			(OldPin->Direction == EGPD_Input && OldPin->PinName == OperatorPinName) ||
			(OldPin->Direction == EGPD_Input && OldPin->PinName == OuterPinName))
		{
#if WITH_EDITOR
			if (bDebug) UE_LOG(LogTemp, Display, TEXT("  Pin: %s"), *OldPin->GetName());
#endif
			OldPins.RemoveAt(PinIndex--, 1, false);
			Pins.Add(OldPin);
		}
	}
#if WITH_EDITOR
	if (bDebug) UE_LOG(LogTemp, Display, TEXT("NewPins %d"), Pins.Num());
#endif

	// Clear the current output pin settings (so they don't carry over to the new set)
	ShowPinForProperties.Reset();

	// Create output pins for the new class type

	CreateNewPins(InputOpClass, false);
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

void UK2Node_FactorUnit::ValidateNodeDuringCompilation(class FCompilerResultsLog& MessageLog) const
{
	Super::ValidateNodeDuringCompilation(MessageLog);

#if WITH_EDITOR
	if (bDebug) UE_LOG(LogTemp, Display, TEXT("%s"), ANSI_TO_TCHAR(__FUNCTION__));
#endif

	TMap<const UClass*, const UClass*> Classes;

	if (const UClass* SourceOpClass = GetInputOperatorClass())
	{
		Classes.Add(SourceOpClass, UNOperatorProviderBase::StaticClass());
	}

	if (const UClass* Class = GetInputClass())
	{
		Classes.Add(Class, UNFactorUnitAdapter::StaticClass());
	}

	for (auto& It : Classes)
	{
		const UClass* SourceClass = It.Key;
		const UClass* ExpectedClass = It.Value;
		if (!SourceClass->IsChildOf(ExpectedClass) || SourceClass->HasAnyClassFlags(EClassFlags::CLASS_Abstract))
		{
			bool bEmitWarning = true;
			MessageLog.Warning(
				*LOCTEXT("NotInstanciableObjectWarning", "@@ has a wrong class selected, you have to set a subclass of @@")
					 .ToString(),
				this,
				ExpectedClass);
			return;
		}

		// return;

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

void UK2Node_FactorUnit::ClearDelegates(FString InClassName)
{
	if (!BlueprintSubscribers.Contains(InClassName))
	{
		return;
	}

	auto& Tuple = BlueprintSubscribers[InClassName];
	if (Tuple.Get<1>().IsValid())
	{
		if (Tuple.Get<0>())
		{
			Tuple.Get<0>()->OnChanged().Remove(Tuple.Get<1>());
		}
		Tuple.Get<1>().Reset();
	}

	if (Tuple.Get<2>().IsValid())
	{
		if (Tuple.Get<0>())
		{
			Tuple.Get<0>()->OnCompiled().Remove(Tuple.Get<2>());
		}
		Tuple.Get<2>().Reset();
	}
	BlueprintSubscribers.Remove(InClassName);
}

void UK2Node_FactorUnit::BeginDestroy()
{
	for (auto& It : BlueprintSubscribers)
	{
		ClearDelegates(It.Key);
	}
	Super::BeginDestroy();
}

#undef LOCTEXT_NAMESPACE
