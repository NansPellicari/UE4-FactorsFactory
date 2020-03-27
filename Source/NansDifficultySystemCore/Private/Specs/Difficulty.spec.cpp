#include "Difficulty.h"
#include "Misc/AutomationTest.h"
#include "Operator/Interfaces.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(DifficultySpec,
    "NansDifficultySystem.Core.Difficulty.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(DifficultySpec)
void DifficultySpec::Define()
{
    Describe("Test basic object", [this]() {
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

            TestEqual<uint32>("Test uniqueID", Ids.Num(), 50);

            Ids.Empty();
        });
        It("should triggered an error if try to call function before initialized correctly", [this]() {
            UNDifficulty* Difficulty = NewObject<UNDifficulty>();
            try
            {
                Difficulty->IsActivate();
                TestTrue("Should not be called", false);
            }
            catch (const TCHAR* e)
            {
                UE_LOG(LogTemp, Display, TEXT("Exception occured for: %s"), e);
                TestEqual("Error has been triggered: Operator != nullptr", e, TEXT("Operator != nullptr"));
            }
        });
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS