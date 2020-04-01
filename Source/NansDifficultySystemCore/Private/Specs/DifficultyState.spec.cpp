#include "Difficulty.h"
#include "DifficultyState.h"
#include "Misc/AutomationTest.h"
#include "NansCommon/Public/Specs/NansCommonHelpers.h"
#include "Operator/DifficultyOperator.h"
#include "Operator/Interfaces.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(DifficultyStateSpec,
    "Nans.DifficultySystem.Core.DifficultyState.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(DifficultyStateSpec)
void DifficultyStateSpec::Define()
{
    Describe("How to use DifficultyState", [this]() {
        // not useful now, but keep in mind how to use try catch block
        // It("should triggered an error if try to call some function before initialized correctly", [this]() {
        //     NDifficultyState* DifficultyState = new NDifficultyState(0.f);
        //     NDifficulty* Difficulty = new NDifficulty(0, new NNullOperator(), 0, FName("Oreason"));

        //     try
        //     {
        //         DifficultyState->AddDifficulty(Difficulty);
        //         TEST_TRUE("Should not be called", false);
        //     }
        //     catch (const TCHAR* e)
        //     {
        //         TEST_EQUAL("Error has been triggered: Time != -1.f", e, TEXT("Time != -1.f"));
        //     }
        // });

        It("should compute with one operator given", [this]() {
            float Time = 1;
            NDifficultyState* DifficultyState = new NDifficultyState(Time);
            INDifficultyInterface* Difficulty = new NDifficulty(2.f, new NAddOperator(), 0, FName("Exhausted"));
            Difficulty->AddTime(Time);
            DifficultyState->AddDifficulty(Difficulty);
            TEST_EQUAL("Should be equal to 2.f", DifficultyState->Compute(), 2.f);
        });

        It("should compute with a bunch of operators given", [this]() {
            float Time = 1;
            NDifficultyState* DifficultyState = new NDifficultyState(Time);
            TArray<INDifficultyInterface*> Diffs;
            Diffs.Add(new NDifficulty(2.f, new NAddOperator(), 0, FName("Exhausted")));
            Diffs.Add(new NDifficulty(2.f, new NMultiplyOperator(), 0, FName("Infinite Drunk")));

            for (auto Diff : Diffs)
            {
                Diff->AddTime(Time);
                DifficultyState->AddDifficulty(Diff);
            }
            TEST_EQUAL("Should be equal to 4.f", DifficultyState->Compute(), 4.f);
        });

        It("should compute with a bunch of operators given and considered not activated operator", [this]() {
            // Should disable the 2nd operator
            float Time = 3.f;
            NDifficultyState* DifficultyState = new NDifficultyState(Time);
            // This to get extra infos on test results
            // DifficultyState->bDebug = true;
            TArray<INDifficultyInterface*> Diffs;
            Diffs.Add(new NDifficulty(2.f, new NAddOperator(), 0, FName("Exhausted")));
            Diffs.Add(new NDifficulty(2.f, new NMultiplyOperator(), 2, FName("Drunk")));
            Diffs.Add(new NDifficulty(2.f, new NAddOperator(), 0, FName("Afraid")));

            for (auto Diff : Diffs)
            {
                Diff->AddTime(Time);
                DifficultyState->AddDifficulty(Diff);
            }
            TEST_EQUAL("Should be equal to 4.f", DifficultyState->Compute(), 4.f);
            TEST_EQUAL("Should get the same results every time it computes", DifficultyState->Compute(), 4.f);
        });
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS