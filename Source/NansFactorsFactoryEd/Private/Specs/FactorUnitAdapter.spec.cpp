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

#include "Attribute/FactorAttribute.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "EngineGlobals.h"
#include "FactorUnit/FactorUnitView.h"
#include "FactorsFactoryBlueprintHelpers.h"
#include "Misc/AutomationTest.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/NullFactorUnit.h"
#include "NansUE4TestsHelpers/Public/Helpers/Assertions.h"
#include "Operator/OperatorProviders.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(FactorUnitAdapterSpec,
	"Nans.FactorsFactory.UE4.FactorUnitAdapter.Spec",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

END_DEFINE_SPEC(FactorUnitAdapterSpec)
void FactorUnitAdapterSpec::Define()
{
	Describe("How to use FactorUnitAdapter", [this]() {
		BeforeEach([this]() {});

		It("Should transform a provider to an operator", [this]() {
			auto FactorUnit = NewObject<UNFactorUnitView>();
			UNOperatorSimpleOperations* OpProvider = Cast<UNOperatorSimpleOperations>(
				NewObject<UNOperatorProviderBase>(FactorUnit, UNOperatorSimpleOperations::StaticClass()));

			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Null;
			TEST_EQ(TEXT("Should return a NullOperator"), FactorUnit->GetConfiguredOperator()->GetName(), FName("Null"));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Add;
			TEST_EQ(TEXT("Should return a AddOperator"), FactorUnit->GetConfiguredOperator()->GetName(), FName("Add"));
			FactorUnit->OperatorProvider = NewObject<UNOperatorProviderBase>(FactorUnit, UNResetOperatorProvider::StaticClass());
			TEST_EQ(TEXT("Should return a ResetOperator"), FactorUnit->GetConfiguredOperator()->GetName(), FName("Reset"));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Divide;
			TEST_EQ(TEXT("Should return a DividerOperator"), FactorUnit->GetConfiguredOperator()->GetName(), FName("Divider"));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Multiply;
			TEST_EQ(TEXT("Should return a MultiplyOperator"), FactorUnit->GetConfiguredOperator()->GetName(), FName("Multiply"));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Subtract;
			TEST_EQ(TEXT("Should return a SubsctractOperator"), FactorUnit->GetConfiguredOperator()->GetName(), FName("Subtract"));
		});

		It("Should transform an enum to an operator with operator property", [this]() {
			auto FactorUnit = NewObject<UNFactorUnitView>();
			UNOperatorSimpleOperations* OpProvider = Cast<UNOperatorSimpleOperations>(
				NewObject<UNOperatorProviderBase>(FactorUnit, UNOperatorSimpleOperations::StaticClass()));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Null;
			TEST_EQ(TEXT("Should return a NullOperator"), FactorUnit->GetConfiguredOperator()->GetName(), FName("Null"));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Add;
			TEST_EQ(TEXT("Should return a AddOperator"), FactorUnit->GetConfiguredOperator()->GetName(), FName("Add"));
			FactorUnit->OperatorProvider = NewObject<UNOperatorProviderBase>(FactorUnit, UNResetOperatorProvider::StaticClass());
			TEST_EQ(TEXT("Should return a ResetOperator"), FactorUnit->GetConfiguredOperator()->GetName(), FName("Reset"));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Divide;
			TEST_EQ(TEXT("Should return a DividerOperator"), FactorUnit->GetConfiguredOperator()->GetName(), FName("Divider"));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Multiply;
			TEST_EQ(TEXT("Should return a MultiplyOperator"), FactorUnit->GetConfiguredOperator()->GetName(), FName("Multiply"));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Subtract;
			TEST_EQ(TEXT("Should return a SubsctractOperator"), FactorUnit->GetConfiguredOperator()->GetName(), FName("Subtract"));
		});

		AfterEach([this]() {});
	});
}

#endif	  // WITH_DEV_AUTOMATION_TESTS
