#include "Attribute/FactorAttribute.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "EngineGlobals.h"
#include "FactorUnit/FactorUnitAdapters.h"
#include "Misc/AutomationTest.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/NullFactorUnit.h"
#include "NansUE4TestsHelpers/Public/Helpers/Assertions.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(FactorUnitAdapterSpec,
	"Nans.FactorsFactory.UE4.FactorUnitAdapter.Spec",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

END_DEFINE_SPEC(FactorUnitAdapterSpec)
void FactorUnitAdapterSpec::Define()
{
	Describe("How to use FactorUnitAdapter", [this]() {
		BeforeEach([this]() {});

		It("Should transform an enum to an operator with static class", [this]() {
			auto Operator = UNFactorUnitAdapterBasic::EnumToOperator(ENFactorOperator::Null);
			TEST_NOT_NULL(TEXT("Should return a NullOperator"), dynamic_cast<NNullOperator*>(Operator.Get()));
			Operator = UNFactorUnitAdapterBasic::EnumToOperator(ENFactorOperator::Add);
			TEST_NOT_NULL(TEXT("Should return a AddOperator"), dynamic_cast<NAddOperator*>(Operator.Get()));
			Operator = UNFactorUnitAdapterBasic::EnumToOperator(ENFactorOperator::ResP);
			TEST_NOT_NULL(TEXT("Should return a ResetOperator"), dynamic_cast<NResetOperator*>(Operator.Get()));
			Operator = UNFactorUnitAdapterBasic::EnumToOperator(ENFactorOperator::Div);
			TEST_NOT_NULL(TEXT("Should return a DividerOperator"), dynamic_cast<NDividerOperator*>(Operator.Get()));
			Operator = UNFactorUnitAdapterBasic::EnumToOperator(ENFactorOperator::Mul);
			TEST_NOT_NULL(TEXT("Should return a MultiplyOperator"), dynamic_cast<NMultiplyOperator*>(Operator.Get()));
			Operator = UNFactorUnitAdapterBasic::EnumToOperator(ENFactorOperator::Sub);
			TEST_NOT_NULL(TEXT("Should return a SubsctractOperator"), dynamic_cast<NSubtractOperator*>(Operator.Get()));
		});

		It("Should transform an enum to an operator with operator property", [this]() {
			auto FactorUnit = NewObject<UNFactorUnitAdapterBasic>();
			FactorUnit->Operator = ENFactorOperator::Null;
			TEST_NOT_NULL(
				TEXT("Should return a NullOperator"), dynamic_cast<NNullOperator*>(FactorUnit->GetConfiguredOperator().Get()));
			FactorUnit->Operator = ENFactorOperator::Add;
			TEST_NOT_NULL(TEXT("Should return a AddOperator"), dynamic_cast<NAddOperator*>(FactorUnit->GetConfiguredOperator().Get()));
			FactorUnit->Operator = ENFactorOperator::ResP;
			TEST_NOT_NULL(
				TEXT("Should return a ResetOperator"), dynamic_cast<NResetOperator*>(FactorUnit->GetConfiguredOperator().Get()));
			FactorUnit->Operator = ENFactorOperator::Div;
			TEST_NOT_NULL(
				TEXT("Should return a DividerOperator"), dynamic_cast<NDividerOperator*>(FactorUnit->GetConfiguredOperator().Get()));
			FactorUnit->Operator = ENFactorOperator::Mul;
			TEST_NOT_NULL(
				TEXT("Should return a MultiplyOperator"), dynamic_cast<NMultiplyOperator*>(FactorUnit->GetConfiguredOperator().Get()));
			FactorUnit->Operator = ENFactorOperator::Sub;
			TEST_NOT_NULL(TEXT("Should return a SubsctractOperator"),
				dynamic_cast<NSubtractOperator*>(FactorUnit->GetConfiguredOperator().Get()));
		});

		AfterEach([this]() {});
	});
}

#endif	  // WITH_DEV_AUTOMATION_TESTS
