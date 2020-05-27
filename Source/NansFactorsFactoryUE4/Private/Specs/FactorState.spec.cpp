#include "Misc/AutomationTest.h"
#include "NansCommon/Public/Specs/NansCommonHelpers.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(FactorStateSpec,
    "Nans.FactorsFactory.Core.FactorState.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FactorStateSpec)
void FactorStateSpec::Define()
{
    Describe("How to use FactorState", [this]() {
        // not useful now, but keep in mind how to use try catch block
        // It("should triggered an error if try to call some function before initialized correctly", [this]() {
        //     NFactorState* FactorState = new NFactorState(0.f);
        //     NFactor* Factor = new NFactor(0, new NNullOperator(), 0, FName("Oreason"));

        //     try
        //     {
        //         FactorState->AddFactor(Factor);
        //         TEST_TRUE("Should not be called", false);
        //     }
        //     catch (const TCHAR* e)
        //     {
        //         TEST_EQUAL("Error has been triggered: Time != -1.f", e, TEXT("Time != -1.f"));
        //     }
        // });

        It("should compute with one operator given", [this]() {
            float Time = 1;
            NFactorState* FactorState = new NFactorState(Time);
            INFactorInterface* Factor = new NFactor(2.f, new NAddOperator(), 0, FName("Exhausted"));
            Factor->AddTime(Time);
            FactorState->AddFactor(Factor);
            TEST_EQUAL("Should be equal to 2.f", FactorState->Compute(), 2.f);
        });

        It("should compute with a bunch of operators given", [this]() {
            float Time = 1;
            NFactorState* FactorState = new NFactorState(Time);
            TArray<INFactorInterface*> Factors;
            Factors.Add(new NFactor(2.f, new NAddOperator(), 0, FName("Exhausted")));
            Factors.Add(new NFactor(2.f, new NMultiplyOperator(), 0, FName("Infinite Drunk")));

            for (auto Factor : Factors)
            {
                Factor->AddTime(Time);
                FactorState->AddFactor(Factor);
            }
            TEST_EQUAL("Should be equal to 4.f", FactorState->Compute(), 4.f);
        });

        It("should compute with a bunch of operators given and considered not activated operator", [this]() {
            // Should disable the 2nd operator
            float Time = 3.f;
            NFactorState* FactorState = new NFactorState(Time);
            // This to get extra infos on test results
            // FactorState->bDebug = true;
            TArray<INFactorInterface*> Factors;
            Factors.Add(new NFactor(2.f, new NAddOperator(), 0, FName("Exhausted")));
            Factors.Add(new NFactor(2.f, new NMultiplyOperator(), 2, FName("Drunk")));
            Factors.Add(new NFactor(2.f, new NAddOperator(), 0, FName("Afraid")));

            for (auto Factor : Factors)
            {
                Factor->AddTime(Time);
                FactorState->AddFactor(Factor);
            }
            TEST_EQUAL("Should be equal to 4.f", FactorState->Compute(), 4.f);
            TEST_EQUAL("Should get the same results every time it computes", FactorState->Compute(), 4.f);
        });
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS
