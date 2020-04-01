#include "DifficultyFactory.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "EngineGlobals.h"
#include "Misc/AutomationTest.h"
#include "NansCommon/Public/Specs/NansCommonHelpers.h"
#include "NansDifficultySystemCore/Public/DifficultySystemClient.h"
#include "Specs/Mocks/MockEngineAndWorld.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(DifficultyFactorySpec,
    "Nans.DifficultySystem.UE4.DifficultyFactory.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
TSharedPtr<UWorld> World;
TSharedPtr<UMockGameInstance> GI;
TSharedPtr<UGameInstance> DGI;
// TSharedPtr<FWorldContext> WorldContext;
UMockObject* WorldContextObject;
END_DEFINE_SPEC(DifficultyFactorySpec)
void DifficultyFactorySpec::Define()
{
    GI = MakeShareable(NewObject<UMockGameInstance>());
    DGI = MakeShareable(NewObject<UGameInstance>());
    World = MakeShareable(UWorld::CreateWorld(EWorldType::Game, false));
    FWorldContext& WorldContext = GEngine->CreateNewWorldContext(EWorldType::Game);
    WorldContext.SetCurrentWorld(World.Get());

    FURL URL;
    World->InitializeActorsForPlay(URL);
    World->BeginPlay();

    WorldContextObject = NewObject<UMockObject>();
    // World = MakeShareable(GEngine->GetWorldContexts()[0].World());
    WorldContextObject->SetMyWorld(World);

    Describe("How to use DifficultyFactory", [this]() {
        BeforeEach([this]() {});

        It("should get GetDifficultyClient even after Garbage collects", [this]() {
            World->SetGameInstance(GI.Get());

            TEST_TRUE("World should still exists", World.IsValid());
            TEST_NOT_NULL("WorldContextObject should be not null", WorldContextObject);
            TEST_NOT_NULL("GEngine should still exists", GEngine);
            TEST_NOT_NULL("World should still exists", WorldContextObject->GetWorld());
            TEST_NOT_NULL(
                "UNDifficultyClientAdapter should be retrieved", UNDifficultyFactory::GetDifficultyClient(WorldContextObject));
            CollectGarbage(RF_NoFlags);
            WorldContextObject = NewObject<UMockObject>();
            WorldContextObject->SetMyWorld(World);
            TEST_TRUE("World should still exists", World.IsValid());
            TEST_NOT_NULL("World should be not null", World.Get());
            TEST_NOT_NULL("World should still exists", WorldContextObject->GetWorld());
            TEST_NOT_NULL(
                "UNDifficultyClientAdapter should be retrieved", UNDifficultyFactory::GetDifficultyClient(WorldContextObject));
            CollectGarbage(RF_NoFlags);
        });
        // It("should log and error to notify developper if the Game Instance does not implements INDifficultySystemGameInstance",
        //     [this]() {
        //         TArray<FName> Names = {FName("test1")};
        //         World->SetGameInstance(DGI.Get());
        //         WorldContextObject = NewObject<UMockObject>();
        //         WorldContextObject->SetMyWorld(World);

        //         try
        //         {
        //             UNDifficultyFactory::AddBasicDifficulty(
        //                 WorldContextObject, Names, 2.f, ENDifficultyOperator::Add, 0, FName("Reason"));
        //             TEST_TRUE("Should not be called", false);
        //         }
        //         catch (const TCHAR* e)
        //         {
        //             TEST_EQUAL("An error trigger", e, TEXT("IGI != nullptr"));
        //         }
        //     });

        // It("can add a lot of difficulty in one time", [this]() {
        //     UMockGameInstance* GI = NewObject<UMockGameInstance>();
        //     World->SetGameInstance(GI);
        //     WorldContextObject = NewObject<UMockObject>();
        //     WorldContextObject->SetMyWorld(World);

        //     TArray<FName> Names = {FName("test1")};

        //     for (uint32 I = 0; I < 200; I++)
        //     {
        //         UNDifficultyFactory::AddBasicDifficulty(
        //             WorldContextObject, Names, 2.f, ENDifficultyOperator::Add, 0, FName("Reason"));
        //     }

        //     TEST_TRUE("Yes it can without crashing", true);
        //     TMap<FName, FNDifficultyStateResult> States = UNDifficultyFactory::GetDifficultyStates(WorldContextObject, Names);
        //     TEST_TRUE("And get some results", States.Num() > 0);
        //     TEST_TRUE("And get a result for the stack 'test1'", States.Contains(Names[0]));

        //     // Just to avoid crashing the test
        //     if (States.Contains(Names[0]))
        //     {
        //         TEST_EQUAL("And get a result", States[Names[0]].Amount, 400.f);
        //     }
        // });

        // It("can add a lot of difficulty in one time AND in multiple Stacks", [this]() {
        //     UMockGameInstance* GI = NewObject<UMockGameInstance>();
        //     World->SetGameInstance(GI);
        //     WorldContextObject = NewObject<UMockObject>();
        //     WorldContextObject->SetMyWorld(World);

        //     TArray<FName> Names = {FName("test1"), FName("test2")};

        //     for (uint32 I = 0; I < 200; I++)
        //     {
        //         UNDifficultyFactory::AddBasicDifficulty(
        //             WorldContextObject, Names, 2.f, ENDifficultyOperator::Add, 0, FName("Reason"));
        //     }

        //     TEST_TRUE("Yes it can without crashing", true);
        //     TMap<FName, FNDifficultyStateResult> States = UNDifficultyFactory::GetDifficultyStates(WorldContextObject, Names);
        //     TEST_TRUE("And get some results", States.Num() == 2);
        //     TEST_TRUE("And get a result for the stack 'test1'", States.Contains(Names[0]));
        //     TEST_TRUE("And get a result for the stack 'test2'", States.Contains(Names[1]));

        //     // Just to avoid crashing the test
        //     if (States.Contains(Names[0]))
        //     {
        //         TEST_EQUAL("And get a result", States[Names[0]].Amount, 400.f);
        //         TEST_EQUAL("And get a result", States[Names[1]].Amount, 400.f);
        //     }
        // });

        It("Should continue to works after garbage collects", [this]() {
            UMockGameInstance* GI = NewObject<UMockGameInstance>();
            World->SetGameInstance(GI);
            WorldContextObject = NewObject<UMockObject>();
            WorldContextObject->SetMyWorld(World);

            TArray<FName> Names = {FName("test1"), FName("test2")};

            for (uint32 I = 0; I < 2; I++)
            {
                UNDifficultyFactory::AddBasicDifficulty(
                    WorldContextObject, Names, 2.f, ENDifficultyOperator::Add, 0, FName("Reason"));

                if (I == 1)
                {
                    CollectGarbage(RF_NoFlags);
                    WorldContextObject = NewObject<UMockObject>();
                    WorldContextObject->SetMyWorld(World);
                }

                TMap<FName, FNDifficultyStateResult> States = UNDifficultyFactory::GetDifficultyStates(WorldContextObject, Names);
                UE_LOG(LogTemp, Display, TEXT("Count %d - Stack number  %d"), I, States.Num());
            }

            TEST_TRUE("Yes it can without crashing", true);
        });

        AfterEach([this]() {
            // GEngine->DestroyWorldContext(World.Get());
            // World->DestroyWorld(false);
        });
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS