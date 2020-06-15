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

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "EdGraphSchema_K2.h"
#include "FactorsFactoryBlueprintHelpers.h"
#include "K2Node_CallFunction.h"
#include "K2Node_DynamicCast.h"
#include "K2Node_VariableSet.h"
#include "KismetCompiler.h"

/**
 * This utility class is made to helps the UK2Node_FactorOperator::ExpandNode().
 */
struct FFactorUnitUtilities
{
public:
	UEdGraphNode* SpawnNode;
	class FKismetCompilerContext& CompilerContext;
	UEdGraph* SourceGraph;
	bool bDebug = false;
	uint32 DebugStep = 0;

	FFactorUnitUtilities(
		UEdGraphNode* _SpawnNode, class FKismetCompilerContext& _CompilerContext, UEdGraph* _SourceGraph, bool _bDebug = false)
		: SpawnNode(_SpawnNode), CompilerContext(_CompilerContext), SourceGraph(_SourceGraph), bDebug(_bDebug)
	{
	}

	UEdGraphPin* GetResultPin() const;
	bool TryConnectPin(UEdGraphPin* PinA, UEdGraphPin* PinB);
#if WITH_EDITOR
	void DebugConnectionPin(const UEdGraphPin* PinA, const UEdGraphPin* PinB, const bool bSucceeded, const TCHAR* Type);
#endif	  // WITH_EDITOR
	bool MovePinLinks(UEdGraphPin* PinA, UEdGraphPin* PinB);
	UK2Node_CallFunction* CreateUnitNode(UEdGraphPin* ClassPin, UEdGraphPin* TempFactorOutput);
	TTuple<UK2Node_CallFunction*, UK2Node_DynamicCast*> CreateOperatorNode(UEdGraphPin* OperatorPin, UClass* OperatorClassType);
	UEdGraphPin* ConnectPinsForObject(UClass* ClassType,
		UEdGraphPin* ObjectPin,
		UEdGraphPin* LastConnection,
		TArray<UEdGraphPin*> Pins,
		TArray<FName> ExcludedPinsName);
};
