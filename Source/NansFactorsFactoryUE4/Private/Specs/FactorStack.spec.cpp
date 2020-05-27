#include "Factor.h"
#include "FactorStack.h"
#include "FactorState.h"
#include "Misc/AutomationTest.h"
#include "NansCommon/Public/Specs/NansCommonHelpers.h"
#include "Operator/FactorOperator.h"
#include "Operator/Interfaces.h"

#if WITH_DEV_AUTOMATION_TESTS
BEGIN_DEFINE_SPEC(FactorStackSpec,
    "Nans.FactorsFactory.Core.FactorStack.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
NFactorStack* FactorStack;
END_DEFINE_SPEC(FactorStackSpec)
void FactorStackSpec::Define()
{
    FactorStack = new NFactorStack(FName("Test iteration flag"));

    Describe("How to use FactorStack", [this]() {
        // It("should triggered error if any method is called before the name has been set", [this]() {
        //     TMap<FString, TBaseDelegate<void>> Delegates;
        //     Delegates.Add(TEXT("GetName"), TBaseDelegate<void>::CreateLambda([this]() { this->FactorStack->GetName(); }));
        //     Delegates.Add(TEXT("GetTime"), TBaseDelegate<void>::CreateLambda([this]() { this->FactorStack->GetTime(); }));
        //     Delegates.Add(
        //         TEXT("GetFactor"), TBaseDelegate<void>::CreateLambda([this]() { this->FactorStack->GetFactor(0); }));
        //     Delegates.Add(
        //         TEXT("GetCurrentState"), TBaseDelegate<void>::CreateLambda([this]() { this->FactorStack->GetCurrentState();
        //         }));
        //     Delegates.Add(
        //         TEXT("GetFlag"), TBaseDelegate<void>::CreateLambda([this]() { this->FactorStack->GetFlag(TEXT("Flag")); }));
        //     Delegates.Add(TEXT("SetFlag"),
        //         TBaseDelegate<void>::CreateLambda([this]() { this->FactorStack->SetFlag(TEXT("Flag"), true); }));
        //     Delegates.Add(TEXT("AddTime"), TBaseDelegate<void>::CreateLambda([this]() { this->FactorStack->AddTime(1.f); }));
        //     Delegates.Add(TEXT("AddFactor"), TBaseDelegate<void>::CreateLambda([this]() {
        //         FactorStack->AddFactor(new NFactor(0, new NNullOperator(), 0, FName("Oreason")));
        //     }));
        //     for (auto Del : Delegates)
        //     {
        //         try
        //         {
        //             Del.Value.Execute();
        //             FString Message = FString::Format(TEXT("Method {0} should not be called"), {Del.Key});
        //             TEST_TRUE(Message, false);
        //         }
        //         catch (const TCHAR* e)
        //         {
        //             FString Message =
        //                 FString::Format(TEXT("Error has been triggered calling the method {0}: Name != NAME_None"), {Del.Key});
        //             TEST_EQUAL(Message, e, TEXT("Name != NAME_None"));
        //         }
        //     }
        //     Delegates.Empty();
        // });

        It("should removes every set Flags after getting the current state", [this]() {
            FactorStack->SetName(FName("Test iteration flag"));
            FactorStack->SetFlag("Flag", true);
            FactorStack->GetCurrentState();
            try
            {
                FactorStack->GetFlag("Flag");
            }
            catch (const TCHAR* e)
            {
                TEST_EQUAL("Error has been triggered: IterationFlags.Contains(Flag)", e, TEXT("IterationFlags.Contains(Flag)"));
            }
            FactorStack->Reset();
        });

        Describe("FactorStack should get valid state and compute correctly when", [this]() {
            BeforeEach([this]() {
                FactorStack->SetName(FName("Dialog"));

                FactorStack->AddFactor(new NFactor(2.f, new NAddOperator(), 0, FName("Exhausted")));
                FactorStack->AddFactor(new NFactor(1.5f, new NMultiplyOperator(), 2, FName("Drunk")));
                FactorStack->AddFactor(new NFactor(2.f, new NAddOperator(), 10, FName("Psychologicaly attacked")));
            });

            It("1 second have passed ", [this]() {
                // To get debug infos in output
                // FactorStack->bDebug = true;
                FactorStack->AddTime(1.f);
                auto State = FactorStack->GetCurrentState();
                TEST_EQUAL("Total time: 1.f", State->GetTime(), 1.f);
                TEST_EQUAL("5.f", State->Compute(), 5.f);
            });

            It("3 secs have passed", [this]() {
                FactorStack->AddTime(3.f);
                auto State = FactorStack->GetCurrentState();
                TEST_EQUAL("Total time: 3.f", State->GetTime(), 3.f);
                TEST_EQUAL("4.f", State->Compute(), 4.f);
            });

            It("10.1 secs have passed", [this]() {
                FactorStack->AddTime(10.1f);
                auto State = FactorStack->GetCurrentState();
                TEST_EQUAL("Total time: 10.1f", State->GetTime(), 10.1f);
                TEST_EQUAL("2.f", State->Compute(), 2.f);
            });

            Describe("4 secs have passed and new factor is added", [this]() {
                BeforeEach([this]() {
                    FactorStack->AddTime(4.f);
                    FactorStack->AddFactor(new NFactor(4.f, new NAddOperator(), 1.f, FName("Exhausted")));
                });

                It("should add new factor in computation", [this]() {
                    auto State = FactorStack->GetCurrentState();
                    TEST_EQUAL("Total time: 4.f", State->GetTime(), 4.f);
                    TEST_EQUAL("8.f", State->Compute(), 8.f);
                });

                It("+1,1secs should not added the last new factor in computation", [this]() {
                    FactorStack->AddTime(1.1f);
                    auto State = FactorStack->GetCurrentState();
                    TEST_EQUAL("Total time: 5.1f", State->GetTime(), 5.1f);
                    TEST_EQUAL("4.f", State->Compute(), 4.f);
                });
            });

            AfterEach([this]() { FactorStack->Reset(); });
        });
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS
