#include "Difficulty.h"
#include "DifficultyStack.h"
#include "DifficultyState.h"
#include "Misc/AutomationTest.h"
#include "NansCommon/Public/Specs/NansCommonHelpers.h"
#include "Operator/DifficultyOperator.h"
#include "Operator/Interfaces.h"
#include "Operator/ResetOperator.h"

#if WITH_DEV_AUTOMATION_TESTS

class UNMockResetOperator : public UNResetOperator
{
public:
    uint32 GetKeyInStack()
    {
        return KeyInStack;
    }
    bool HasStack()
    {
        return MyStack != nullptr;
    }
};

class UNMockDifficultyStack : public UNDifficultyStack
{
public:
    virtual UNDifficultyState* GetCurrentState() override
    {
        UNDifficultyState* State = NewObject<UNDifficultyState>();
        AddDifficultiesToState(State);
        return State;
    }
};

BEGIN_DEFINE_SPEC(ResetOperatorSpec,
    "NansDifficultySystem.Core.ResetOperator.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
UNMockDifficultyStack* DifficultyStack;
END_DEFINE_SPEC(ResetOperatorSpec) void ResetOperatorSpec::Define()
{
    Describe("should compute with a reset operator", [this]() {
        BeforeEach([this]() {
            DifficultyStack = NewObject<UNMockDifficultyStack>();
            DifficultyStack->Initialize(FName("Mocked stack"));
            UNDifficulty* Diff1 = NewObject<UNDifficulty>()->Initialize(2, NewObject<UNAddOperator>(), 0, FName("reason1"));
            UNDifficulty* Diff2 = NewObject<UNDifficulty>()->Initialize(3, NewObject<UNAddOperator>(), 0, FName("reason2"));
            // // 1 difficulty to be reset
            DifficultyStack->AddDifficulty(Diff1);
            DifficultyStack->AddDifficulty(Diff2);
        });

        It("should trigger an error if trying to set a key before having a stack", [this]() {
            // Some difficulties to be reset
            UNMockResetOperator* Operator = NewObject<UNMockResetOperator>();
            try
            {
                Operator->SetKeyInStack(0);
                TEST_TRUE("Should not be called", false);
            }
            catch (const TCHAR* e)
            {
                TEST_EQUAL("Error has been triggered: MyStack != nullptr", e, TEXT("MyStack != nullptr"));
            }
        });

        It("should reset the last difficulty set in the stack", [this]() {
            // Some difficulties to be reset
            UNMockResetOperator* Operator = NewObject<UNMockResetOperator>();

            DifficultyStack->AddDifficulty(NewObject<UNDifficulty>()->Initialize(1, Operator, 0, FName("Magic potion")));
            TEST_EQUAL("Test current state result = 2.f", DifficultyStack->GetCurrentState()->Compute(), 2.f);
            TEST_TRUE("Has a stack", Operator->HasStack());
            TEST_TRUE("Has a key", Operator->GetKeyInStack() > 0);
            TEST_TRUE("Difficulty has the key of the reset difficulty",
                DifficultyStack->HasFlag(UNMockResetOperator::GetResetIdFlag(DifficultyStack->GetDifficulty(1))));
            DifficultyStack->Reset();
        });

        It("should reset the first difficulty set in the stack", [this]() {
            // Some difficulties to be reset
            UNMockResetOperator* Operator = NewObject<UNMockResetOperator>();

            DifficultyStack->AddDifficulty(NewObject<UNDifficulty>()->Initialize(2, Operator, 0, FName("Magic potion")));

            TEST_EQUAL("Test current state result = 3.f", DifficultyStack->GetCurrentState()->Compute(), 3.f);
            TEST_TRUE("Difficulty has the key of the reset difficulty",
                DifficultyStack->HasFlag(UNMockResetOperator::GetResetIdFlag(DifficultyStack->GetDifficulty(0))));
            DifficultyStack->Reset();
        });

        It("should reset the first and last difficulty set in the stack", [this]() {
            // Some difficulties to be reset
            UNMockResetOperator* Operator = NewObject<UNMockResetOperator>();

            DifficultyStack->AddDifficulty(NewObject<UNDifficulty>()->Initialize(1, Operator, 0, FName("Magic potion")));
            DifficultyStack->AddDifficulty(NewObject<UNDifficulty>()->Initialize(2, Operator, 0, FName("Magic potion")));

            TEST_EQUAL("Test current state result = 0.f", DifficultyStack->GetCurrentState()->Compute(), 0.f);
            TEST_TRUE("Difficulty has the key of the reset difficulty",
                DifficultyStack->HasFlag(UNMockResetOperator::GetResetIdFlag(DifficultyStack->GetDifficulty(0))));
            TEST_TRUE("Difficulty has the key of the reset difficulty",
                DifficultyStack->HasFlag(UNMockResetOperator::GetResetIdFlag(DifficultyStack->GetDifficulty(1))));
            DifficultyStack->Reset();
        });
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS