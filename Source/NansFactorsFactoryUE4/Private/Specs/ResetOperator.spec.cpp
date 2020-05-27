#include "Misc/AutomationTest.h"
#include "NansCommon/Public/Specs/NansCommonHelpers.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/FactorStack.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"
#include "NansFactorsFactoryCore/Public/Operator/ResetOperator.h"

#if WITH_DEV_AUTOMATION_TESTS

class UNMockResetOperator : public NResetOperator
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

class NMockFactorStack : public NFactorStack
{
public:
    NMockFactorStack(FName _Name) : NFactorStack(_Name) {}
    virtual NFactorState* GetCurrentState() override
    {
        NFactorState* State = new NFactorState(0.f);
        AddFactorsToState(State);
        return State;
    }
};

BEGIN_DEFINE_SPEC(ResetOperatorSpec,
    "Nans.FactorsFactory.Core.ResetOperator.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
NMockFactorStack* FactorStack;
END_DEFINE_SPEC(ResetOperatorSpec) void ResetOperatorSpec::Define()
{
    Describe("should compute with a reset operator", [this]() {
        BeforeEach([this]() {
            FactorStack = new NMockFactorStack(FName("Mocked stack"));
            // // 1 factor to be reset
            FactorStack->AddFactor(new NFactor(2, new NAddOperator(), 0, FName("reason1")));
            FactorStack->AddFactor(new NFactor(3, new NAddOperator(), 0, FName("reason2")));
        });
        It("should check if is an operator with stack or not", [this]() {
            // Some factors to be reset
            UNMockResetOperator* Operator = new UNMockResetOperator();
            TEST_FALSE("NNullOperator Is", OperatorUtils::IsOperatorWithStack(new NNullOperator()));
            TEST_TRUE("UNMockResetOperator Is", OperatorUtils::IsOperatorWithStack(Operator));
        });

        // It("should trigger an error if trying to set a key before having a stack", [this]() {
        //     // Some factors to be reset
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

        It("should reset the last factor set in the stack", [this]() {
            // Some factors to be reset
            UNMockResetOperator* Operator = new UNMockResetOperator();

            FactorStack->AddFactor(new NFactor(1, Operator, 0, FName("Magic potion")));
            TEST_EQUAL("Test current state result = 2.f", FactorStack->GetCurrentState()->Compute(), 2.f);
            TEST_TRUE("Has a stack", Operator->HasStack());
            TEST_TRUE("Has a key", Operator->GetKeyInStack() > 0);
            TEST_TRUE("Factor has the key of the reset factor",
                FactorStack->HasFlag(UNMockResetOperator::GetResetIdFlag(FactorStack->GetFactor(1))));
        });

        It("should reset the first factor set in the stack", [this]() {
            // Some factors to be reset
            UNMockResetOperator* Operator = new UNMockResetOperator();

            FactorStack->AddFactor(new NFactor(2, Operator, 0, FName("Magic potion")));

            TEST_EQUAL("Test current state result = 3.f", FactorStack->GetCurrentState()->Compute(), 3.f);
            TEST_TRUE("Factor has the key of the reset factor",
                FactorStack->HasFlag(UNMockResetOperator::GetResetIdFlag(FactorStack->GetFactor(0))));
        });

        It("should reset the first and last factor set in the stack", [this]() {
            // Some factors to be reset
            UNMockResetOperator* Operator = new UNMockResetOperator();

            FactorStack->AddFactor(new NFactor(1, Operator, 0, FName("Magic potion")));
            FactorStack->AddFactor(new NFactor(2, Operator, 0, FName("Magic potion")));

            TEST_EQUAL("Test current state result = 0.f", FactorStack->GetCurrentState()->Compute(), 0.f);
            TEST_TRUE("Factor has the key of the reset factor",
                FactorStack->HasFlag(UNMockResetOperator::GetResetIdFlag(FactorStack->GetFactor(0))));
            TEST_TRUE("Factor has the key of the reset factor",
                FactorStack->HasFlag(UNMockResetOperator::GetResetIdFlag(FactorStack->GetFactor(1))));
        });
        AfterEach([this]() { delete FactorStack; });
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS
