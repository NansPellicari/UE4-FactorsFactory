#include "Difficulty.h"
#include "DifficultyStack.h"
#include "DifficultyState.h"
#include "Misc/AutomationTest.h"
#include "NansCommon/Public/Specs/NansCommonHelpers.h"
#include "Operator/DifficultyOperator.h"
#include "Operator/Interfaces.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(DifficultyStackSpec,
    "NansDifficultySystem.Core.DifficultyStack.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
UNDifficultyStack* DifficultyStack = NewObject<UNDifficultyStack>();
END_DEFINE_SPEC(DifficultyStackSpec)
void DifficultyStackSpec::Define()
{
    Describe("How to use DifficultyStack", [this]() {
        It("should triggered error if any method is called before the name has been set", [this]() {
            TMap<FString, TBaseDelegate<void>> Delegates;
            Delegates.Add(TEXT("GetName"), TBaseDelegate<void>::CreateLambda([this]() { this->DifficultyStack->GetName(); }));
            Delegates.Add(TEXT("GetTime"), TBaseDelegate<void>::CreateLambda([this]() { this->DifficultyStack->GetTime(); }));
            Delegates.Add(
                TEXT("GetDifficulty"), TBaseDelegate<void>::CreateLambda([this]() { this->DifficultyStack->GetDifficulty(0); }));
            Delegates.Add(
                TEXT("GetCurrentState"), TBaseDelegate<void>::CreateLambda([this]() { this->DifficultyStack->GetCurrentState(); }));
            Delegates.Add(
                TEXT("GetFlag"), TBaseDelegate<void>::CreateLambda([this]() { this->DifficultyStack->GetFlag(TEXT("Flag")); }));
            Delegates.Add(TEXT("SetFlag"),
                TBaseDelegate<void>::CreateLambda([this]() { this->DifficultyStack->SetFlag(TEXT("Flag"), true); }));
            Delegates.Add(TEXT("AddTime"), TBaseDelegate<void>::CreateLambda([this]() { this->DifficultyStack->AddTime(1.f); }));
            Delegates.Add(TEXT("AddDifficulty"),
                TBaseDelegate<void>::CreateLambda([this]() { DifficultyStack->AddDifficulty(NewObject<UNDifficulty>()); }));
            for (auto Del : Delegates)
            {
                try
                {
                    Del.Value.Execute();
                    FString Message = FString::Format(TEXT("Method {0} should not be called"), {Del.Key});
                    TEST_TRUE(Message, false);
                }
                catch (const TCHAR* e)
                {
                    FString Message =
                        FString::Format(TEXT("Error has been triggered calling the method {0}: Name != NAME_None"), {Del.Key});
                    TEST_EQUAL(Message, e, TEXT("Name != NAME_None"));
                }
            }
            Delegates.Empty();
        });

        Describe("DifficultyStack should get valid state and compute correctly when", [this]() {
            BeforeEach([this]() {
                DifficultyStack->Initialize(FName("Dialog"));
                UNDifficulty* Difficulty = NewObject<UNDifficulty>();

                DifficultyStack->AddDifficulty(
                    NewObject<UNDifficulty>()->Initialize(2.f, NewObject<UNAddOperator>(), 0, FName("Exhausted")));
                DifficultyStack->AddDifficulty(
                    NewObject<UNDifficulty>()->Initialize(1.5f, NewObject<UNMultiplyOperator>(), 2, FName("Drunk")));
                DifficultyStack->AddDifficulty(
                    NewObject<UNDifficulty>()->Initialize(2.f, NewObject<UNAddOperator>(), 10, FName("Psychologicaly attacked")));
            });
            It("1 second have passed ", [this]() {
                // To get debug infos in output
                // DifficultyStack->bDebug = true;
                DifficultyStack->AddTime(1.f);
                auto State = DifficultyStack->GetCurrentState();
                TEST_EQUAL("Total time: 1.f", State->GetTime(), 1.f);
                TEST_EQUAL("6.5f", State->Compute(), 6.5f);
            });
            It("3 secs have passed", [this]() {
                DifficultyStack->AddTime(3.f);
                auto State = DifficultyStack->GetCurrentState();
                TEST_EQUAL("Total time: 3.f", State->GetTime(), 3.f);
                TEST_EQUAL("5.f", State->Compute(), 5.f);
            });
            It("10 secs have passed", [this]() {
                DifficultyStack->AddTime(10.1f);
                auto State = DifficultyStack->GetCurrentState();
                TEST_EQUAL("Total time: 10.1f", State->GetTime(), 10.1f);
                TEST_EQUAL("3.f", State->Compute(), 3.f);
            });
            Describe("4 secs have passed and new difficulty is added", [this]() {
                BeforeEach([this]() {
                    DifficultyStack->AddTime(4.f);
                    DifficultyStack->AddDifficulty(
                        NewObject<UNDifficulty>()->Initialize(4.f, NewObject<UNAddOperator>(), 1.f, FName("Exhausted")));
                });
                It("should add new difficulty in computation", [this]() {
                    auto State = DifficultyStack->GetCurrentState();
                    TEST_EQUAL("Total time: 4.f", State->GetTime(), 4.f);
                    TEST_EQUAL("9.f", State->Compute(), 9.f);
                });
                It("+1,1secs should not add new difficulty in computation", [this]() {
                    DifficultyStack->AddTime(1.1f);
                    auto State = DifficultyStack->GetCurrentState();
                    TEST_EQUAL("Total time: 5.1f", State->GetTime(), 5.1f);
                    TEST_EQUAL("5.f", State->Compute(), 5.f);
                });
            });
            AfterEach([this]() { DifficultyStack->Reset(); });
        });
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS