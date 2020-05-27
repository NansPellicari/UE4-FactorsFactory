#include "Misc/AutomationTest.h"
#include "NansCommon/Public/Specs/NansCommonHelpers.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/FactorStack.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(FactorOperatorSpec,
    "Nans.FactorsFactory.Core.FactorOperator.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FactorOperatorSpec) void FactorOperatorSpec::Define()
{
    Describe("Basic computation", [this]() {
        It("should compute with a null operator", [this]() {
            NNullOperator* Operator = new NNullOperator();

            TEST_EQUAL("Test operator result 1 NULLOPERATOR 2 = 1.f", Operator->Compute(1, 2), 1.f);
        });

        It("should compute with an add operator", [this]() {
            NAddOperator* Operator = new NAddOperator();

            TEST_EQUAL("Test operator 1 + 2 = 3.f", Operator->Compute(1, 2), 3.f);
        });

        It("should compute with an add operator getInverse() returned object", [this]() {
            NAddOperator* Operator = new NAddOperator();
            CollectGarbage(RF_NoFlags);
            auto Inverse = Operator->GetInverse();

            TEST_NOT_NULL("The Operator object should be not null after CollectGarbage", Operator);
            TEST_NOT_NULL("The inverse object should be not null after CollectGarbage", Inverse);
            TEST_EQUAL("Test operator 1 Inverse(+) 2 = -1.f", Inverse->Compute(1, 2), -1.f);
        });

        It("should compute with a subsctract operator", [this]() {
            NSubsctractOperator* Operator = new NSubsctractOperator();

            TEST_EQUAL("Test operator 1 - 2 = -1.f", Operator->Compute(1, 2), -1.f);
        });

        It("should compute with a subsctract operator getInverse() returned object", [this]() {
            NSubsctractOperator* Operator = new NSubsctractOperator();

            TEST_EQUAL("Test operator result = 3.f", Operator->GetInverse()->Compute(1, 2), 3.f);
        });

        It("should compute with a multiply operator", [this]() {
            NMultiplyOperator* Operator = new NMultiplyOperator();

            TEST_EQUAL("Test operator result 1 * 2 = 2.f", Operator->Compute(1, 2), 2.f);
        });

        It("should compute with a multiply operator getInverse() returned object", [this]() {
            NMultiplyOperator* Operator = new NMultiplyOperator();

            TEST_EQUAL("Test operator result = 0.5f", Operator->GetInverse()->Compute(1, 2), 0.5f);
        });

        It("should compute with a divide operator", [this]() {
            NDividerOperator* Operator = new NDividerOperator();

            TEST_EQUAL("Test operator result 1 / 2 = 0.5f", Operator->Compute(1, 2), 0.5f);
        });

        It("should compute with a divide operator getInverse() returned object", [this]() {
            NDividerOperator* Operator = new NDividerOperator();

            TEST_EQUAL("Test operator result = 2.f", Operator->GetInverse()->Compute(1, 2), 2.f);
        });
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS
