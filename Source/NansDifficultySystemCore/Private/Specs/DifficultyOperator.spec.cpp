#include "DifficultyStack.h"
#include "Misc/AutomationTest.h"
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

            TestEqual("Test operator result 1 NULLOPERATOR 2 = 1", Operator->Compute(1, 2), 1);
        });

        It("should compute with add operator", [this]() {
            UNAddOperator* Operator = NewObject<UNAddOperator>();

            TestEqual("Test operator 1 + 2 = 3", Operator->Compute(1, 2), 3);
        });

        It("should compute with add operator getInverse() returned object", [this]() {
            UNAddOperator* Operator = NewObject<UNAddOperator>();
            auto Inverse = Operator->GetInverse();

            TestEqual("Test operator 1 Inverse(+) 2 = -1", Inverse->Compute(1, 2), -1);
        });

        It("should compute with subsctract operator", [this]() {
            UNSubsctractOperator* Operator = NewObject<UNSubsctractOperator>();

            TestEqual("Test operator 1 - 2 = -1", Operator->Compute(1, 2), -1);
        });
        It("should compute with subsctract operator getInverse() returned object", [this]() {
            UNSubsctractOperator* Operator = NewObject<UNSubsctractOperator>();

            TestEqual("Test operator result = 3", Operator->GetInverse()->Compute(1, 2), 3);
        });

        It("should compute with multiply operator", [this]() {
            UNMultiplyOperator* Operator = NewObject<UNMultiplyOperator>();

            TestEqual("Test operator result 1 * 2 = 2", Operator->Compute(1, 2), 2);
        });

        It("should compute with multiply operator getInverse() returned object", [this]() {
            UNMultiplyOperator* Operator = NewObject<UNMultiplyOperator>();

            TestEqual("Test operator result = 1", Operator->GetInverse()->Compute(1, 2), 1);
        });

        It("should compute with divide operator", [this]() {
            UNDividerOperator* Operator = NewObject<UNDividerOperator>();

            TestEqual("Test operator result 1 / 2 = 1", Operator->Compute(1, 2), 1);
        });

        It("should compute with divide operator getInverse() returned object", [this]() {
            UNDividerOperator* Operator = NewObject<UNDividerOperator>();

            TestEqual("Test operator result = 2", Operator->GetInverse()->Compute(1, 2), 2);
        });
    });
    // Describe("Computation With Difficulty stack", [this]() {
    //     BeforeEach([this]() { DifficultyStack = NewObject<UNDifficultyStack>(); });
    //     It("should compute when add one operator", [this]() {
    //         UNDividerOperator* Operator = NewObject<UNDividerOperator>();

    //         TestEqual("Test operator result = 2", Operator->GetInverse()->Compute(1, 2), 2);
    //     });
    //     AfterEach([this]() { DifficultyStack = nullptr });
    // });
}

#endif    // WITH_DEV_AUTOMATION_TESTS