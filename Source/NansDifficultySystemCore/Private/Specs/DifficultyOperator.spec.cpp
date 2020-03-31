#include "Difficulty.h"
#include "DifficultyStack.h"
#include "DifficultyState.h"
#include "Misc/AutomationTest.h"
#include "NansCommon/Public/Specs/NansCommonHelpers.h"
#include "Operator/DifficultyOperator.h"
#include "Operator/Interfaces.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(DifficultyOperatorSpec,
    "NansDifficultySystem.Core.DifficultyOperator.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(DifficultyOperatorSpec) void DifficultyOperatorSpec::Define()
{
    Describe("Basic computation", [this]() {
        It("should compute with a null operator", [this]() {
            UNNullOperator* Operator = NewObject<UNNullOperator>();

            TEST_EQUAL("Test operator result 1 NULLOPERATOR 2 = 1.f", Operator->Compute(1, 2), 1.f);
        });

        It("should compute with an add operator", [this]() {
            UNAddOperator* Operator = NewObject<UNAddOperator>();

            TEST_EQUAL("Test operator 1 + 2 = 3.f", Operator->Compute(1, 2), 3.f);
        });

        It("should compute with an add operator getInverse() returned object", [this]() {
            UNAddOperator* Operator = NewObject<UNAddOperator>();
            auto Inverse = Operator->GetInverse();

            TEST_EQUAL("Test operator 1 Inverse(+) 2 = -1.f", Inverse->Compute(1, 2), -1.f);
        });

        It("should compute with a subsctract operator", [this]() {
            UNSubsctractOperator* Operator = NewObject<UNSubsctractOperator>();

            TEST_EQUAL("Test operator 1 - 2 = -1.f", Operator->Compute(1, 2), -1.f);
        });

        It("should compute with a subsctract operator getInverse() returned object", [this]() {
            UNSubsctractOperator* Operator = NewObject<UNSubsctractOperator>();

            TEST_EQUAL("Test operator result = 3.f", Operator->GetInverse()->Compute(1, 2), 3.f);
        });

        It("should compute with a multiply operator", [this]() {
            UNMultiplyOperator* Operator = NewObject<UNMultiplyOperator>();

            TEST_EQUAL("Test operator result 1 * 2 = 2.f", Operator->Compute(1, 2), 2.f);
        });

        It("should compute with a multiply operator getInverse() returned object", [this]() {
            UNMultiplyOperator* Operator = NewObject<UNMultiplyOperator>();

            TEST_EQUAL("Test operator result = 0.5f", Operator->GetInverse()->Compute(1, 2), 0.5f);
        });

        It("should compute with a divide operator", [this]() {
            UNDividerOperator* Operator = NewObject<UNDividerOperator>();

            TEST_EQUAL("Test operator result 1 / 2 = 0.5f", Operator->Compute(1, 2), 0.5f);
        });

        It("should compute with a divide operator getInverse() returned object", [this]() {
            UNDividerOperator* Operator = NewObject<UNDividerOperator>();

            TEST_EQUAL("Test operator result = 2.f", Operator->GetInverse()->Compute(1, 2), 2.f);
        });
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS