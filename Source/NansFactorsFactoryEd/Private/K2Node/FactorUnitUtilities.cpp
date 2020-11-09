// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use SpawnNode file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "K2Node/FactorUnitUtilities.h"

#include "EdGraph/EdGraphNode.h"
#include "EdGraphSchema_K2.h"
#include "FactorsFactoryBlueprintHelpers.h"
#include "K2Node_CallFunction.h"
#include "K2Node_DynamicCast.h"
#include "K2Node_VariableSet.h"
#include "KismetCompiler.h"

#define LOCTEXT_NAMESPACE "FactorsFactoryEd"

UEdGraphPin* FFactorUnitUtilities::GetResultPin() const
{
	UEdGraphPin* Pin = SpawnNode->FindPinChecked(UEdGraphSchema_K2::PN_ReturnValue);
	check(Pin->Direction == EGPD_Output);
	return Pin;
}

bool FFactorUnitUtilities::TryConnectPin(UEdGraphPin* PinA, UEdGraphPin* PinB)
{
	const UEdGraphSchema_K2* Schema = CompilerContext.GetSchema();
	bool bSucceeded = true;
	FPinConnectionResponse Response = Schema->CanCreateConnection(PinA, PinB);

	if (!Response.CanSafeConnect())
	{
		bSucceeded = false;
		CompilerContext.MessageLog.Warning(
			*LOCTEXT("FactorOperator_PinConnection_Error",
				"FactorOperator error when trying to connect pins @@->@@ & @@->@@. Message: @@ in @@")
				 .ToString(),
			*PinA->GetOwningNode()->GetName(),
			*PinA->GetName(),
			*PinB->GetOwningNode()->GetName(),
			*PinB->GetName(),
			*Response.Message.ToString(),
			SpawnNode);
	}
	else
	{
		bSucceeded &= Schema->TryCreateConnection(PinA, PinB);
	}

#if WITH_EDITOR
	++DebugStep;

	DebugConnectionPin(PinA, PinB, bSucceeded, TEXT("connect"));
#endif
	return bSucceeded;
}

#if WITH_EDITOR
void FFactorUnitUtilities::DebugConnectionPin(
	const UEdGraphPin* PinA, const UEdGraphPin* PinB, const bool bSucceeded, const TCHAR* Type)
{
	if (bDebug)
	{
		UE_LOG(LogTemp,
			Display,
			TEXT("%d - %s %s->%s & %s->%s %i"),
			DebugStep,
			Type,
			*(PinA ? PinA->GetOwningNode()->GetName() : ""),
			*(PinA ? PinA->GetName() : ""),
			*(PinB ? PinB->GetOwningNode()->GetName() : ""),
			*(PinB ? PinB->GetName() : ""),
			bSucceeded);
	}
}
#endif	  // WITH_EDITOR

bool FFactorUnitUtilities::MovePinLinks(UEdGraphPin* PinA, UEdGraphPin* PinB)
{
	bool bSucceeded = PinA && PinB && CompilerContext.MovePinLinksToIntermediate(*PinA, *PinB).CanSafeConnect();

#if WITH_EDITOR
	++DebugStep;
	DebugConnectionPin(PinA, PinB, bSucceeded, TEXT("move"));
#endif

	return bSucceeded;
}

UK2Node_CallFunction* FFactorUnitUtilities::CreateUnitNode(UEdGraphPin* ClassPin, UEdGraphPin* TempFactorOutput)
{
#if WITH_EDITOR
	if (bDebug) UE_LOG(LogTemp, Display, TEXT("> CreateFactorUnitNode "));
#endif
	bool bSucceeded = true;
	UK2Node_CallFunction* CallCreateUnitNode = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(SpawnNode, SourceGraph);
	CallCreateUnitNode->FunctionReference.SetExternalMember(
		GET_FUNCTION_NAME_CHECKED(UNFactorsFactoryBlueprintHelpers, CreateFactorUnit),
		UNFactorsFactoryBlueprintHelpers::StaticClass());
	CallCreateUnitNode->AllocateDefaultPins();
	CompilerContext.MessageLog.NotifyIntermediateObjectCreation(CallCreateUnitNode, SpawnNode);

	UEdGraphPin* CallExecPin = CallCreateUnitNode->GetExecPin();

	// connect class
	UEdGraphPin* CallClassPin = CallCreateUnitNode->FindPin(FName("Class"), EGPD_Input);
	UEdGraphPin* CallFactorPin = CallCreateUnitNode->FindPin(FName("Factor"), EGPD_Input);

	bSucceeded &= MovePinLinks(ClassPin, CallClassPin);

#if WITH_EDITOR
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

	bSucceeded &= TryConnectPin(TempFactorOutput, CallFactorPin);

	UEdGraphPin* CallResultPin = nullptr;
	// connect result
	UEdGraphPin* SpawnResultPin = GetResultPin();
	CallResultPin = CallCreateUnitNode->GetReturnValuePin();

	// cast HACK. It should be safe. The only problem is native code generation.
	if (SpawnResultPin && CallResultPin)
	{
		CallResultPin->PinType = SpawnResultPin->PinType;
	}

	bSucceeded &= MovePinLinks(SpawnResultPin, CallResultPin);

#if WITH_EDITOR
	if (bDebug)
	{
		UE_LOG(LogTemp,
			Display,
			TEXT("3A - classname retrieve from %s>>pin->PinType is %s"),
			*(CallCreateUnitNode ? CallCreateUnitNode->GetName() : ""),
			*(CallResultPin ? CallResultPin->PinType.PinSubCategoryObject.Get()->GetName() : ""));
	}
#endif

	return CallCreateUnitNode;
}

TTuple<UK2Node_CallFunction*, UK2Node_DynamicCast*> FFactorUnitUtilities::CreateOperatorNode(
	UEdGraphPin* OperatorPin, UClass* OperatorClassType, UEdGraphPin* TempFactorOutput)
{
#if WITH_EDITOR
	if (bDebug) UE_LOG(LogTemp, Display, TEXT("> CreateOperatorNode "));
#endif
	bool bSucceeded = true;
	UK2Node_CallFunction* CallCreateOperatorNode =
		CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(SpawnNode, SourceGraph);
	CallCreateOperatorNode->FunctionReference.SetExternalMember(
		GET_FUNCTION_NAME_CHECKED(UNFactorsFactoryBlueprintHelpers, CreateOperatorProvider),
		UNFactorsFactoryBlueprintHelpers::StaticClass());
	CallCreateOperatorNode->AllocateDefaultPins();

	CompilerContext.MessageLog.NotifyIntermediateObjectCreation(CallCreateOperatorNode, SpawnNode);

	// connect class
	UEdGraphPin* CallClassPin = CallCreateOperatorNode->FindPin(FName("OperatorProviderClass"), EGPD_Input);
	UEdGraphPin* CallFactorPin = CallCreateOperatorNode->FindPin(FName("Factor"), EGPD_Input);

	bSucceeded &= MovePinLinks(OperatorPin, CallClassPin);

#if WITH_EDITOR
	if (bDebug)
	{
		UE_LOG(LogTemp,
			Display,
			TEXT("2A - classname retrieve from Node>>pin->PinType is %s"),
			*(OperatorPin ? OperatorPin->PinType.PinSubCategoryObject.Get()->GetName() : ""));
		UE_LOG(LogTemp,
			Display,
			TEXT("2B - classname from Node>>pin->defaultObject is %s"),
			*(OperatorPin ? OperatorPin->DefaultObject->GetName() : ""));
	}
#endif

	bSucceeded &= TryConnectPin(TempFactorOutput, CallFactorPin);

	UEdGraphPin* TmpOperatorCreatedPin = CallCreateOperatorNode->GetReturnValuePin();

	// Create Cast Node
	UK2Node_DynamicCast* CastNode = CompilerContext.SpawnIntermediateNode<UK2Node_DynamicCast>(SpawnNode, SourceGraph);
	CastNode->SetPurity(true);
	CastNode->TargetType = OperatorClassType;
	CastNode->AllocateDefaultPins();

	// Connect Object/Class to Cast
	UEdGraphPin* CastInput = CastNode->GetCastSourcePin();
	bool bIsErrorFree = TryConnectPin(TmpOperatorCreatedPin, CastInput);

	if (!bIsErrorFree)
	{
		CompilerContext.MessageLog.Error(
			*LOCTEXT("FactorOperator_objectCast_Error", "FactorOperator error when trying to cast to type @@").ToString(),
			*OperatorClassType->GetName(),
			SpawnNode);
	}

	return TTuple<UK2Node_CallFunction*, UK2Node_DynamicCast*>(CallCreateOperatorNode, CastNode);
}

UEdGraphPin* FFactorUnitUtilities::ConnectPinsForObject(UClass* ClassType,
	UEdGraphPin* ObjectPin,
	UEdGraphPin* LastConnection,
	TArray<UEdGraphPin*> Pins,
	TArray<FName> ExcludedPinsName)
{
	const UEdGraphSchema_K2* Schema = CompilerContext.GetSchema();
	UEdGraphPin* LastThen = LastConnection;

	// For container properties,
	// return a local copy of the container so that the original cannot be modified.
	for (UEdGraphPin* Pin : Pins)
	{
		if (Pin == nullptr || Pin->Direction != EGPD_Input || ExcludedPinsName.Contains(Pin->PinName)) continue;

		FProperty* BoundProperty = FindFProperty<FProperty>(ClassType, Pin->PinName);

		if (BoundProperty == nullptr) continue;
		if (BoundProperty->HasAnyPropertyFlags(CPF_DisableEditOnInstance)) continue;

		bool bSucceeded2 = true;
		bool bSucceeded3 = true;
		FPinConnectionResponse Response;

#if WITH_EDITOR
		if (bDebug) UE_LOG(LogTemp, Display, TEXT("  > Try to set var from pin: %s"), *Pin->GetName());
#endif

		UK2Node_VariableSet* VarToSetNode = CompilerContext.SpawnIntermediateNode<UK2Node_VariableSet>(SpawnNode, SourceGraph);
		VarToSetNode->SetFromProperty(BoundProperty, false, ClassType);
		Schema->ConfigureVarNode(VarToSetNode, BoundProperty->GetFName(), ClassType, CompilerContext.Blueprint);
		VarToSetNode->AllocateDefaultPins();
		CompilerContext.MessageLog.NotifyIntermediateObjectCreation(VarToSetNode, SpawnNode);

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
	            UE_LOG(LogTemp, Display, TEXT("    @GetMemberParentClass : %s"),
	            *VarToSetNode->VariableReference.GetMemberParentClass()->GetName());
                UE_LOG(LogTemp, Display, TEXT("@GetMemberName : %s"), *VarToSetNode->VariableReference.GetMemberName().ToString()); UE_LOG(LogTemp, Display,
	            TEXT("    @GetScope : %s"), *VarToSetNode->VariableReference.GetScope()->GetName()); UE_LOG(LogTemp, Display,
	            TEXT("    @GetVariableSourceClass : %s"), *VarToSetNode->GetVariableSourceClass()->GetName());
			// clang-format on
		}
#endif
		bSucceeded2 &= MovePinLinks(Pin, VariableVarToSetPin);
		bSucceeded3 &= bSucceeded2;
#if WITH_EDITOR
		if (bDebug) UE_LOG(LogTemp, Display, TEXT("    1 - Connecting %s: %i "), *VariableVarToSetPin->GetName(), bSucceeded2);
#endif
		bSucceeded2 &= TryConnectPin(ObjectPin, ObjectVarToSetPin);
		bSucceeded3 &= bSucceeded2;
#if WITH_EDITOR
		if (bDebug) UE_LOG(LogTemp, Display, TEXT("    2 - Connecting %s: %i"), *ObjectVarToSetPin->GetName(), bSucceeded2);
#endif

		if (bSucceeded3)
		{
			bSucceeded2 &= MovePinLinks(LastThen, ThenVarToSetPin);
			bSucceeded2 &= TryConnectPin(LastThen, ExecVarToSetPin);
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
			ObjectPin->BreakLinkTo(ObjectVarToSetPin);
			Pin->BreakLinkTo(VariableVarToSetPin);
#if WITH_EDITOR
			if (bDebug) UE_LOG(LogTemp, Display, TEXT("    3A - break previous connection"));
#endif
			continue;
		}
	}

	return LastThen;
}

#undef LOCTEXT_NAMESPACE
