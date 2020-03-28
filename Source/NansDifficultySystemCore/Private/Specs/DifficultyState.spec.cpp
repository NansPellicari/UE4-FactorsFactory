#include "Difficulty.h"
#include "DifficultyState.h"
#include "Misc/AutomationTest.h"
#include "NansCommon/Public/Specs/NansCommonHelpers.h"
#include "Operator/DifficultyOperator.h"
#include "Operator/Interfaces.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(DifficultyStateSpec,
    "NansDifficultySystem.Core.DifficultyState.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(DifficultyStateSpec)
void DifficultyStateSpec::Define()
{
    Describe("How to use DifficultyState", [this]() {
        It("should triggered an error if try to call some function before initialized correctly", [this]() {
            UNDifficultyState* DifficultyState = NewObject<UNDifficultyState>();
            UNDifficulty* Difficulty = NewObject<UNDifficulty>();

            try
            {
                DifficultyState->AddDifficulty(Difficulty);
                TEST_TRUE("Should not be called", false);
            }
            catch (const TCHAR* e)
            {
                TEST_EQUAL("Error has been triggered: Time != -1.f", e, TEXT("Time != -1.f"));
            }
        });

        It("should compute with one operator given", [this]() {
            UNDifficultyState* DifficultyState = NewObject<UNDifficultyState>();
            float Time = 1;
            UNDifficulty* Difficulty =
                NewObject<UNDifficulty>()->Initialize(2.f, NewObject<UNAddOperator>(), 0, FName("Exhausted"));
            Difficulty->AddTime(Time);

            DifficultyState->Initialize(Time);
            DifficultyState->AddDifficulty(Difficulty);
            TEST_EQUAL("Should be equal to 3.f", DifficultyState->Compute(), 3.f);
        });

        It("should compute with a bunch of operators given", [this]() {
            UNDifficultyState* DifficultyState = NewObject<UNDifficultyState>();
            TArray<UNDifficulty*> Diffs;
            Diffs.Add(NewObject<UNDifficulty>()->Initialize(2.f, NewObject<UNAddOperator>(), 0, FName("Exhausted")));
            Diffs.Add(NewObject<UNDifficulty>()->Initialize(2.f, NewObject<UNMultiplyOperator>(), 0, FName("Infinite Drunk")));

            float Time = 1;
            DifficultyState->Initialize(Time);
            for (auto Diff : Diffs)
            {
                Diff->AddTime(Time);
                DifficultyState->AddDifficulty(Diff);
            }
            TEST_EQUAL("Should be equal to 6.f", DifficultyState->Compute(), 6.f);
        });

        It("should compute with a bunch of operators given and considered not activated operator", [this]() {
            UNDifficultyState* DifficultyState = NewObject<UNDifficultyState>();
            // This to get extra infos on test results
            // DifficultyState->bDebug = true;
            TArray<UNDifficulty*> Diffs;
            Diffs.Add(NewObject<UNDifficulty>()->Initialize(2.f, NewObject<UNAddOperator>(), 0, FName("Exhausted")));
            Diffs.Add(NewObject<UNDifficulty>()->Initialize(2.f, NewObject<UNMultiplyOperator>(), 2, FName("Drunk")));
            Diffs.Add(NewObject<UNDifficulty>()->Initialize(2.f, NewObject<UNAddOperator>(), 0, FName("Afraid")));

            // Should disable the 2nd operator
            float Time = 3.f;
            DifficultyState->Initialize(Time);
            for (auto Diff : Diffs)
            {
                Diff->AddTime(Time);
                DifficultyState->AddDifficulty(Diff);
            }
            TEST_EQUAL("Should be equal to 5.f", DifficultyState->Compute(), 5.f);
        });
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS