#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "EngineGlobals.h"
#include "Factor/FactorAdapters.h"
#include "FactorFactory.h"
#include "Misc/AutomationTest.h"
#include "NansCommon/Public/Specs/NansCommonHelpers.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"
#include "Specs/Mocks/MockEngineAndWorld.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(FactorFactorySpec,
    "Nans.FactorsFactory.UE4.FactorFactory.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
TSharedPtr<UWorld> World;
TSharedPtr<UMockGameInstance> GI;
TSharedPtr<UGameInstance> DGI;
// TSharedPtr<FWorldContext> WorldContext;
UMockObject* WorldContextObject;
END_DEFINE_SPEC(FactorFactorySpec)
void FactorFactorySpec::Define()
{
    World = MakeShareable(UWorld::CreateWorld(EWorldType::Game, false));
    GI = MakeShareable(NewObject<UMockGameInstance>(World.Get()));
    DGI = MakeShareable(NewObject<UGameInstance>(World.Get()));
    FWorldContext& WorldContext = GEngine->CreateNewWorldContext(EWorldType::Game);
    WorldContext.SetCurrentWorld(World.Get());

    FURL URL;
    World->InitializeActorsForPlay(URL);
    World->BeginPlay();

    WorldContextObject = NewObject<UMockObject>();
    // World = MakeShareable(GEngine->GetWorldContexts()[0].World());
    WorldContextObject->SetMyWorld(World);

    Describe("How to use FactorFactory", [this]() {
        BeforeEach([this]() {});

        It("should get GetFactorClient even after Garbage collects", [this]() {
            World->SetGameInstance(GI.Get());

            TEST_TRUE("World should still exists", World.IsValid());
            TEST_NOT_NULL("WorldContextObject should be not null", WorldContextObject);
            TEST_NOT_NULL("GEngine should still exists", GEngine);
            TEST_NOT_NULL("World should still exists", WorldContextObject->GetWorld());
            TEST_NOT_NULL("UNFactorClientAdapter should be retrieved", UNFactorFactory::GetFactorClient(WorldContextObject));
            CollectGarbage(RF_NoFlags);
            WorldContextObject = NewObject<UMockObject>();
            WorldContextObject->SetMyWorld(World);
            TEST_TRUE("World should still exists", World.IsValid());
            TEST_NOT_NULL("World should be not null", World.Get());
            TEST_NOT_NULL("World should still exists", WorldContextObject->GetWorld());
            TEST_NOT_NULL("UNFactorClientAdapter should be retrieved", UNFactorFactory::GetFactorClient(WorldContextObject));
            CollectGarbage(RF_NoFlags);
        });

        It("should instanciate a UNFactorAdapterBasic", [this]() {
            World->SetGameInstance(GI.Get());
            WorldContextObject = NewObject<UMockObject>();
            WorldContextObject->SetMyWorld(World);
            UNFactorAdapterAbstract* MyObject =
                UNFactorFactory::CreateFactor(WorldContextObject, UNFactorAdapterBasic::StaticClass());
            TEST_NOT_NULL("Should not be null", MyObject);
        });

        It("should log and error to notify developper if the Game Instance does not implements INFactorsFactoryGameInstance",
            [this]() {
                World->SetGameInstance(DGI.Get());
                WorldContextObject = NewObject<UMockObject>();
                WorldContextObject->SetMyWorld(World);

                try
                {
                    UNFactorFactory::CreateFactor(WorldContextObject, UNFactorAdapterBasic::StaticClass());
                    TEST_TRUE("Should not be called", false);
                }
                catch (const TCHAR* e)
                {
                    TEST_EQUAL("An error trigger", e, TEXT("bIsImplementedFactorGI"));
                }
            });

        It("should Create and add a new Factor", [this]() {
            World->SetGameInstance(GI.Get());
            WorldContextObject = NewObject<UMockObject>();
            WorldContextObject->SetMyWorld(World);
            UNFactorAdapterBasic* MyObject =
                Cast<UNFactorAdapterBasic>(UNFactorFactory::CreateFactor(WorldContextObject, UNFactorAdapterBasic::StaticClass()));
            TEST_NOT_NULL("Should not be null", MyObject);
            MyObject->FactorValue = 2.f;
            MyObject->Duration = 0;
            MyObject->Reason = FName("Reason");
            MyObject->Operator = ENFactorOperator::Add;
            MyObject->InStack = FName("test1");

            UNFactorAdapterBasic* ObjectAdded =
                Cast<UNFactorAdapterBasic>(UNFactorFactory::AddFactor(WorldContextObject, MyObject));
            TEST_EQUAL("Should be add and equals as itself...", ObjectAdded, MyObject);
        });

        It("should get a results even if the asked stack not exists", [this]() {
            World->SetGameInstance(GI.Get());
            WorldContextObject = NewObject<UMockObject>();
            WorldContextObject->SetMyWorld(World);
            TArray<FName> Names = {FName("Im not existing")};
            TMap<FName, FNFactorStateResult> States;

            // An error is thrown by the "myensureMsgf" function only in test env
            // This global var is used to avoid this behavior.
            GNAssertThrowError = false;
            States = UNFactorFactory::GetFactorStates(WorldContextObject, Names);
            GNAssertThrowError = true;

            TEST_TRUE("And get some results", States.Num() > 0);
            TEST_TRUE("with an amount", States[Names[0]].Amount == 0);
        });

        It("can add a lot of factor in one time", [this]() {
            World->SetGameInstance(GI.Get());
            WorldContextObject = NewObject<UMockObject>();
            WorldContextObject->SetMyWorld(World);

            TArray<FName> Names = {FName("test1")};

            for (uint32 I = 0; I < 200; I++)
            {
                UNFactorAdapterBasic* MyObject = Cast<UNFactorAdapterBasic>(
                    UNFactorFactory::CreateFactor(WorldContextObject, UNFactorAdapterBasic::StaticClass()));
                MyObject->FactorValue = 2.f;
                MyObject->Duration = 0;
                MyObject->Reason = FName("Reason");
                MyObject->Operator = ENFactorOperator::Add;
                MyObject->InStack = Names[0];

                UNFactorFactory::AddFactor(WorldContextObject, MyObject);
            }

            TEST_TRUE("Yes it can without crashing", true);
            TMap<FName, FNFactorStateResult> States = UNFactorFactory::GetFactorStates(WorldContextObject, Names);
            TEST_TRUE("And get some results", States.Num() > 0);
            TEST_TRUE("And get a result for the stack 'test1'", States.Contains(Names[0]));

            // Just to avoid crashing the test
            if (States.Contains(Names[0]))
            {
                TEST_EQUAL("And get a result", States[Names[0]].Amount, 400.f);
            }
            UNFactorFactory::Clear(WorldContextObject, Names);
        });

        // It("can add a lot of factor in one time AND in multiple Stacks", [this]() {
        //     World->SetGameInstance(GI.Get());
        //     WorldContextObject = NewObject<UMockObject>();
        //     WorldContextObject->SetMyWorld(World);

        //     TArray<FName> Names = {FName("test1"), FName("test2")};

        //     for (uint32 I = 0; I < 200; I++)
        //     {
        //         UNFactorAdapterBasic* MyObject = Cast<UNFactorAdapterBasic>(
        //             UNFactorFactory::CreateFactor(WorldContextObject, UNFactorAdapterBasic::StaticClass()));
        //         MyObject->FactorValue = 2.f;
        //         MyObject->Duration = 0;
        //         MyObject->Reason = FName("Reason");
        //         MyObject->Operator = ENFactorOperator::Add;
        //         MyObject->InStack = Names[0];

        //         UNFactorFactory::AddFactor(WorldContextObject, MyObject);
        //     }

        //     TEST_TRUE("Yes it can create and add 200 diff without crashing", true);
        //     TMap<FName, FNFactorStateResult> States = UNFactorFactory::GetFactorStates(WorldContextObject, Names);
        //     TEST_TRUE("And get some results", States.Num() == 2);
        //     TEST_TRUE("And get a result for the stack 'test1'", States.Contains(Names[0]));
        //     TEST_TRUE("And get a result for the stack 'test2'", States.Contains(Names[1]));

        //     // Just to avoid crashing the test
        //     if (States.Contains(Names[0]))
        //     {
        //         TEST_EQUAL("And get a result", States[Names[0]].Amount, 400.f);
        //         TEST_EQUAL("And get a result", States[Names[1]].Amount, 400.f);
        //     }
        //     UNFactorFactory::Clear(WorldContextObject, Names);
        // });

        // It("Should continue to works after garbage collects", [this]() {
        //     World->SetGameInstance(GI.Get());
        //     WorldContextObject = NewObject<UMockObject>();
        //     WorldContextObject->SetMyWorld(World);

        //     TArray<FName> Names = {FName("test1"), FName("test2")};

        //     for (uint32 I = 0; I < 2; I++)
        //     {
        //         UNFactorFactory::AddBasicFactor(
        //             WorldContextObject, Names, 2.f, ENFactorOperator::Add, 0, FName("Reason"));

        //         if (I == 1)
        //         {
        //             CollectGarbage(RF_NoFlags);
        //             WorldContextObject = NewObject<UMockObject>();
        //             WorldContextObject->SetMyWorld(World);
        //         }

        //         TMap<FName, FNFactorStateResult> States = UNFactorFactory::GetFactorStates(WorldContextObject,
        //         Names); UE_LOG(LogTemp, Display, TEXT("Count %d - Stack number  %d"), I, States.Num());
        //     }

        //     TEST_TRUE("Yes it can without crashing", true);
        //     UNFactorFactory::Clear(WorldContextObject, Names);
        // });

        AfterEach([this]() {});
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS
