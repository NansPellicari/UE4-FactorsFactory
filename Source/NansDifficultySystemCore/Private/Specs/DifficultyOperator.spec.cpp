#include "DifficultyStack.h"
#include "Misc/AutomationTest.h"
#include "NansCommon/Public/Specs/NansCommonHelpers.h"
#include "Operator/DifficultyOperator.h"
#include "Operator/Interfaces.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(DifficultyOperatorSpec,
    "NansDifficultySystem.Core.DifficultyOperator.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
// UNDifficultyStack DifficultyStack;
END_DEFINE_SPEC(DifficultyOperatorSpec)
void DifficultyOperatorSpec::Define()
{
    Describe("Basic computation", [this]() {
        It("should compute with null operator", [this]() {
            UNNullOperator* Operator = NewObject<UNNullOperator>();

            TEST_EQUAL("Test operator result 1 NULLOPERATOR 2 = 1.f", Operator->Compute(1, 2), 1.f);
        });

        It("should compute with add operator", [this]() {
            UNAddOperator* Operator = NewObject<UNAddOperator>();

            TEST_EQUAL("Test operator 1 + 2 = 3.f", Operator->Compute(1, 2), 3.f);
        });

        It("should compute with add operator getInverse() returned object", [this]() {
            UNAddOperator* Operator = NewObject<UNAddOperator>();
            auto Inverse = Operator->GetInverse();

            TEST_EQUAL("Test operator 1 Inverse(+) 2 = -1.f", Inverse->Compute(1, 2), -1.f);
        });

        It("should compute with subsctract operator", [this]() {
            UNSubsctractOperator* Operator = NewObject<UNSubsctractOperator>();

            TEST_EQUAL("Test operator 1 - 2 = -1.f", Operator->Compute(1, 2), -1.f);
        });
        It("should compute with subsctract operator getInverse() returned object", [this]() {
            UNSubsctractOperator* Operator = NewObject<UNSubsctractOperator>();

            TEST_EQUAL("Test operator result = 3.f", Operator->GetInverse()->Compute(1, 2), 3.f);
        });

        It("should compute with multiply operator", [this]() {
            UNMultiplyOperator* Operator = NewObject<UNMultiplyOperator>();

            TEST_EQUAL("Test operator result 1 * 2 = 2.f", Operator->Compute(1, 2), 2.f);
        });

        It("should compute with multiply operator getInverse() returned object", [this]() {
            UNMultiplyOperator* Operator = NewObject<UNMultiplyOperator>();

            TEST_EQUAL("Test operator result = 0.5f", Operator->GetInverse()->Compute(1, 2), 0.5f);
        });

        It("should compute with divide operator", [this]() {
            UNDividerOperator* Operator = NewObject<UNDividerOperator>();

            TEST_EQUAL("Test operator result 1 / 2 = 0.5f", Operator->Compute(1, 2), 0.5f);
        });

        It("should compute with divide operator getInverse() returned object", [this]() {
            UNDividerOperator* Operator = NewObject<UNDividerOperator>();

            TEST_EQUAL("Test operator result = 2.f", Operator->GetInverse()->Compute(1, 2), 2.f);
        });
    });
    // Describe("Computation With Difficulty stack", [this]() {
    //     BeforeEach([this]() { DifficultyStack = NewObject<UNDifficultyStack>(); });
    //     It("should compute when add one operator", [this]() {
    //         UNDividerOperator* Operator = NewObject<UNDividerOperator>();

    //         TEST_EQUAL("Test operator result = 2", Operator->GetInverse()->Compute(1, 2), 2);
    //     });
    //     AfterEach([this]() { DifficultyStack = nullptr });
    // });
}

#endif    // WITH_DEV_AUTOMATION_TESTS