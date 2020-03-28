#include "Difficulty.h"
#include "Misc/AutomationTest.h"
#include "NansCommon/Public/Specs/NansCommonHelpers.h"
#include "Operator/DifficultyOperator.h"
#include "Operator/Interfaces.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(DifficultySpec,
    "NansDifficultySystem.Core.Difficulty.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(DifficultySpec)
void DifficultySpec::Define()
{
    Describe("How to use difficulty", [this]() {
        It("should get an unique ID", [this]() {
            TArray<UNDifficulty*, TInlineAllocator<50>> Difficulties;
            TArray<uint32, TInlineAllocator<50>> Ids;
            for (int32 Index = 0; Index < 50; Index++)
            {
                UNDifficulty* Difficulty = NewObject<UNDifficulty>();
                // need to stay in life to ensure unique ID
                Difficulties.Add(Difficulty);
                Ids.AddUnique(Difficulty->GetUniqueID());
            }

            Difficulties.Empty();

            TEST_EQUAL("Test uniqueID", (uint32) Ids.Num(), (uint32) 50);

            Ids.Empty();
        });

        It("should triggered an error if try to call function before initialized correctly", [this]() {
            UNDifficulty* Difficulty = NewObject<UNDifficulty>();
            try
            {
                Difficulty->IsActivate();
                TEST_TRUE("Should not be called", false);
            }
            catch (const TCHAR* e)
            {
                TEST_EQUAL("Error has been triggered: Operator != nullptr", e, TEXT("Operator != nullptr"));
            }
        });

        It("should deactivate when his duration is exceeded", [this]() {
            UNDifficulty* Difficulty =
                NewObject<UNDifficulty>()->Initialize(2, NewObject<UNMultiplyOperator>(), 2, FName("Exhausted"));
            TEST_TRUE("Should be activate", Difficulty->IsActivate());
            Difficulty->AddTime(2.1f);
            TEST_FALSE("Should not be activate", Difficulty->IsActivate());
            TEST_NOT_NULL("Should return a NullOperator", Cast<UNNullOperator>(Difficulty->GetOperator()));
            TEST_EQUAL("Should return value of 0.f", Difficulty->GetDifficultyValue(), 0.f);
        });

        It("should works infinitely if his duration initializer is 0", [this]() {
            UNDifficulty* Difficulty =
                NewObject<UNDifficulty>()->Initialize(2, NewObject<UNMultiplyOperator>(), 0, FName("Exhausted"));
            TEST_TRUE("Should be activate", Difficulty->IsActivate());
            TEST_EQUAL("Should get a difficulty value to 2.f", Difficulty->GetDifficultyValue(), 2.f);
            Difficulty->AddTime(10000000.f);
            TEST_TRUE("Should still be activated", Difficulty->IsActivate());
            TEST_EQUAL("Should still get a difficulty value to 2.f", Difficulty->GetDifficultyValue(), 2.f);
        });
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS