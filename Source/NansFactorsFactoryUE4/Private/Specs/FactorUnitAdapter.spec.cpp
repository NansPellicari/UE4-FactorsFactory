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
#include "FactorUnit/FactorUnitAdapter.h"
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
			auto FactorUnit = NewObject<UNFactorUnitAdapter>();
			UNOperatorSimpleOperations* OpProvider = Cast<UNOperatorSimpleOperations>(
				UNFactorsFactoryBlueprintHelpers::CreateOperatorProvider(FactorUnit, UNOperatorSimpleOperations::StaticClass()));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Null;
			TEST_NOT_NULL(
				TEXT("Should return a NullOperator"), dynamic_cast<NNullOperator*>(FactorUnit->GetConfiguredOperator().Get()));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Add;
			TEST_NOT_NULL(
				TEXT("Should return a AddOperator"), dynamic_cast<NAddOperator*>(FactorUnit->GetConfiguredOperator().Get()));
			FactorUnit->OperatorProvider =
				UNFactorsFactoryBlueprintHelpers::CreateOperatorProvider(FactorUnit, UNResetOperatorProvider::StaticClass());
			TEST_NOT_NULL(
				TEXT("Should return a ResetOperator"), dynamic_cast<NResetOperator*>(FactorUnit->GetConfiguredOperator().Get()));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Divide;
			TEST_NOT_NULL(TEXT("Should return a DividerOperator"),
				dynamic_cast<NDividerOperator*>(FactorUnit->GetConfiguredOperator().Get()));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Multiply;
			TEST_NOT_NULL(TEXT("Should return a MultiplyOperator"),
				dynamic_cast<NMultiplyOperator*>(FactorUnit->GetConfiguredOperator().Get()));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Subtract;
			TEST_NOT_NULL(TEXT("Should return a SubsctractOperator"),
				dynamic_cast<NSubtractOperator*>(FactorUnit->GetConfiguredOperator().Get()));
		});

		It("Should transform an enum to an operator with operator property", [this]() {
			auto FactorUnit = NewObject<UNFactorUnitAdapter>();
			UNOperatorSimpleOperations* OpProvider = Cast<UNOperatorSimpleOperations>(
				UNFactorsFactoryBlueprintHelpers::CreateOperatorProvider(FactorUnit, UNOperatorSimpleOperations::StaticClass()));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Null;
			TEST_NOT_NULL(
				TEXT("Should return a NullOperator"), dynamic_cast<NNullOperator*>(FactorUnit->GetConfiguredOperator().Get()));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Add;
			TEST_NOT_NULL(
				TEXT("Should return a AddOperator"), dynamic_cast<NAddOperator*>(FactorUnit->GetConfiguredOperator().Get()));
			FactorUnit->OperatorProvider =
				UNFactorsFactoryBlueprintHelpers::CreateOperatorProvider(FactorUnit, UNResetOperatorProvider::StaticClass());
			TEST_NOT_NULL(
				TEXT("Should return a ResetOperator"), dynamic_cast<NResetOperator*>(FactorUnit->GetConfiguredOperator().Get()));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Divide;
			TEST_NOT_NULL(TEXT("Should return a DividerOperator"),
				dynamic_cast<NDividerOperator*>(FactorUnit->GetConfiguredOperator().Get()));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Multiply;
			TEST_NOT_NULL(TEXT("Should return a MultiplyOperator"),
				dynamic_cast<NMultiplyOperator*>(FactorUnit->GetConfiguredOperator().Get()));
			FactorUnit->OperatorProvider = OpProvider;
			OpProvider->Type = ENFactorSimpleOperation::Subtract;
			TEST_NOT_NULL(TEXT("Should return a SubsctractOperator"),
				dynamic_cast<NSubtractOperator*>(FactorUnit->GetConfiguredOperator().Get()));
		});

		AfterEach([this]() {});
	});
}

#endif	  // WITH_DEV_AUTOMATION_TESTS
