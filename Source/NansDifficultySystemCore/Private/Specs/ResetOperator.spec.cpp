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

class NMockDifficultyStack : public NDifficultyStack
{
public:
    NMockDifficultyStack(FName _Name) : NDifficultyStack(_Name) {}
    virtual NDifficultyState* GetCurrentState() override
    {
        NDifficultyState* State = new NDifficultyState(0.f);
        AddDifficultiesToState(State);
        return State;
    }
};

BEGIN_DEFINE_SPEC(ResetOperatorSpec,
    "Nans.DifficultySystem.Core.ResetOperator.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
NMockDifficultyStack* DifficultyStack;
END_DEFINE_SPEC(ResetOperatorSpec) void ResetOperatorSpec::Define()
{
    Describe("should compute with a reset operator", [this]() {
        BeforeEach([this]() {
            DifficultyStack = new NMockDifficultyStack(FName("Mocked stack"));
            // // 1 difficulty to be reset
            DifficultyStack->AddDifficulty(new NDifficulty(2, new NAddOperator(), 0, FName("reason1")));
            DifficultyStack->AddDifficulty(new NDifficulty(3, new NAddOperator(), 0, FName("reason2")));
        });
        It("should check if is an operator with stack or not", [this]() {
            // Some difficulties to be reset
            UNMockResetOperator* Operator = new UNMockResetOperator();
            TEST_FALSE("NNullOperator Is", OperatorUtils::IsOperatorWithStack(new NNullOperator()));
            TEST_TRUE("UNMockResetOperator Is", OperatorUtils::IsOperatorWithStack(Operator));
        });

        // It("should trigger an error if trying to set a key before having a stack", [this]() {
        //     // Some difficulties to be reset
        //     UNMockResetOperator* Operator = new UNMockResetOperator();
        //     try
        //     {
        //         Operator->SetKeyInStack(0);
        //         TEST_TRUE("Should not be called", false);
        //     }
        //     catch (const TCHAR* e)
        //     {
        //         TEST_EQUAL("Error has been triggered: MyStack != nullptr", e, TEXT("MyStack != nullptr"));
        //     }
        // });

        It("should reset the last difficulty set in the stack", [this]() {
            // Some difficulties to be reset
            UNMockResetOperator* Operator = new UNMockResetOperator();

            DifficultyStack->AddDifficulty(new NDifficulty(1, Operator, 0, FName("Magic potion")));
            TEST_EQUAL("Test current state result = 2.f", DifficultyStack->GetCurrentState()->Compute(), 2.f);
            TEST_TRUE("Has a stack", Operator->HasStack());
            TEST_TRUE("Has a key", Operator->GetKeyInStack() > 0);
            TEST_TRUE("Difficulty has the key of the reset difficulty",
                DifficultyStack->HasFlag(UNMockResetOperator::GetResetIdFlag(DifficultyStack->GetDifficulty(1))));
        });

        It("should reset the first difficulty set in the stack", [this]() {
            // Some difficulties to be reset
            UNMockResetOperator* Operator = new UNMockResetOperator();

            DifficultyStack->AddDifficulty(new NDifficulty(2, Operator, 0, FName("Magic potion")));

            TEST_EQUAL("Test current state result = 3.f", DifficultyStack->GetCurrentState()->Compute(), 3.f);
            TEST_TRUE("Difficulty has the key of the reset difficulty",
                DifficultyStack->HasFlag(UNMockResetOperator::GetResetIdFlag(DifficultyStack->GetDifficulty(0))));
        });

        It("should reset the first and last difficulty set in the stack", [this]() {
            // Some difficulties to be reset
            UNMockResetOperator* Operator = new UNMockResetOperator();

            DifficultyStack->AddDifficulty(new NDifficulty(1, Operator, 0, FName("Magic potion")));
            DifficultyStack->AddDifficulty(new NDifficulty(2, Operator, 0, FName("Magic potion")));

            TEST_EQUAL("Test current state result = 0.f", DifficultyStack->GetCurrentState()->Compute(), 0.f);
            TEST_TRUE("Difficulty has the key of the reset difficulty",
                DifficultyStack->HasFlag(UNMockResetOperator::GetResetIdFlag(DifficultyStack->GetDifficulty(0))));
            TEST_TRUE("Difficulty has the key of the reset difficulty",
                DifficultyStack->HasFlag(UNMockResetOperator::GetResetIdFlag(DifficultyStack->GetDifficulty(1))));
        });
        AfterEach([this]() { delete DifficultyStack; });
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS