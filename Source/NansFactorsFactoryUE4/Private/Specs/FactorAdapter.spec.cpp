#include "Attribute/FactorStackAttribute.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "EngineGlobals.h"
#include "Factor/FactorAdapters.h"
#include "Misc/AutomationTest.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/NullFactor.h"
#include "NansUE4TestsHelpers/Public/Helpers/Assertions.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(FactorAdapterSpec,
	"Nans.FactorsFactory.UE4.FactorAdapter.Spec",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

END_DEFINE_SPEC(FactorAdapterSpec)
void FactorAdapterSpec::Define()
{
	Describe("How to use FactorAdapter", [this]() {
		BeforeEach([this]() {});

		It("Should transform an enum to an operator with static class", [this]() {
			auto Operator = UNFactorAdapterBasic::EnumToOperator(ENFactorOperator::Null);
			TEST_NOT_NULL(TEXT("Should return a NullOperator"), dynamic_cast<NNullOperator*>(Operator.Get()));
			Operator = UNFactorAdapterBasic::EnumToOperator(ENFactorOperator::Add);
			TEST_NOT_NULL(TEXT("Should return a AddOperator"), dynamic_cast<NAddOperator*>(Operator.Get()));
			Operator = UNFactorAdapterBasic::EnumToOperator(ENFactorOperator::ResP);
			TEST_NOT_NULL(TEXT("Should return a ResetOperator"), dynamic_cast<NResetOperator*>(Operator.Get()));
			Operator = UNFactorAdapterBasic::EnumToOperator(ENFactorOperator::Div);
			TEST_NOT_NULL(TEXT("Should return a DividerOperator"), dynamic_cast<NDividerOperator*>(Operator.Get()));
			Operator = UNFactorAdapterBasic::EnumToOperator(ENFactorOperator::Mul);
			TEST_NOT_NULL(TEXT("Should return a MultiplyOperator"), dynamic_cast<NMultiplyOperator*>(Operator.Get()));
			Operator = UNFactorAdapterBasic::EnumToOperator(ENFactorOperator::Sub);
			TEST_NOT_NULL(TEXT("Should return a SubsctractOperator"), dynamic_cast<NSubsctractOperator*>(Operator.Get()));
		});

		It("Should transform an enum to an operator with operator property", [this]() {
			auto Factor = NewObject<UNFactorAdapterBasic>();
			Factor->Operator = ENFactorOperator::Null;
			TEST_NOT_NULL(
				TEXT("Should return a NullOperator"), dynamic_cast<NNullOperator*>(Factor->GetConfiguredOperator().Get()));
			Factor->Operator = ENFactorOperator::Add;
			TEST_NOT_NULL(TEXT("Should return a AddOperator"), dynamic_cast<NAddOperator*>(Factor->GetConfiguredOperator().Get()));
			Factor->Operator = ENFactorOperator::ResP;
			TEST_NOT_NULL(
				TEXT("Should return a ResetOperator"), dynamic_cast<NResetOperator*>(Factor->GetConfiguredOperator().Get()));
			Factor->Operator = ENFactorOperator::Div;
			TEST_NOT_NULL(
				TEXT("Should return a DividerOperator"), dynamic_cast<NDividerOperator*>(Factor->GetConfiguredOperator().Get()));
			Factor->Operator = ENFactorOperator::Mul;
			TEST_NOT_NULL(
				TEXT("Should return a MultiplyOperator"), dynamic_cast<NMultiplyOperator*>(Factor->GetConfiguredOperator().Get()));
			Factor->Operator = ENFactorOperator::Sub;
			TEST_NOT_NULL(TEXT("Should return a SubsctractOperator"),
				dynamic_cast<NSubsctractOperator*>(Factor->GetConfiguredOperator().Get()));
		});

		AfterEach([this]() {});
	});
}

#endif	  // WITH_DEV_AUTOMATION_TESTS
