#include "Attribute/FactorStackAttribute.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "EngineGlobals.h"
#include "Factor/FactorAdapters.h"
#include "FactorsFactoryBlueprintHelpers.h"
#include "Misc/AutomationTest.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"
#include "NansUE4TestsHelpers/Public/Helpers/Assertions.h"
#include "NansUE4TestsHelpers/Public/Helpers/TestWorld.h"
#include "NansUE4TestsHelpers/Public/Mock/FakeObject.h"
#include "Specs/Mocks/MockEngineAndWorld.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(FactorsFactoryBlueprintHelpersSpec,
	"Nans.FactorsFactory.UE4.FactorsFactoryBlueprintHelpers.Spec",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
UWorld* World;
UFakeObject* FakeObject;
END_DEFINE_SPEC(FactorsFactoryBlueprintHelpersSpec)
void FactorsFactoryBlueprintHelpersSpec::Define()
{
	Describe("How to use FactorsFactoryBlueprintHelpers", [this]() {
		BeforeEach([this]() {
			World = NTestWorld::CreateAndPlay(EWorldType::Game, true, NAME_None, UFactorFakeGameInstance::StaticClass());
			FakeObject = NewObject<UFakeObject>(World, FName("MyFakeObject"), EObjectFlags::RF_MarkAsRootSet);
			FakeObject->SetMyWorld(World);
		});

		It("should get GetFactorClient even after Garbage collects", [this]() {
			TEST_TRUE("World should still exists", World != nullptr);
			TEST_NOT_NULL("FakeObject should be not null", FakeObject);
			TEST_NOT_NULL("GEngine should still exists", GEngine);
			TEST_NOT_NULL("World should still exists", FakeObject->GetWorld());
			TEST_NOT_NULL("UNFactorsFactoryClientAdapter should be retrieved", UNFactorsFactoryBlueprintHelpers::GetFactorClient(FakeObject));
			CollectGarbage(RF_NoFlags);
			TEST_NOT_NULL("World should be not null", World);
			TEST_NOT_NULL("World should still exists", FakeObject->GetWorld());
			TEST_NOT_NULL("UNFactorsFactoryClientAdapter should be retrieved", UNFactorsFactoryBlueprintHelpers::GetFactorClient(FakeObject));
			CollectGarbage(RF_NoFlags);
		});

		It("should instanciate a UNFactorAdapterBasic", [this]() {
			UNFactorAdapterAbstract* MyObject = UNFactorsFactoryBlueprintHelpers::CreateFactor(FakeObject, UNFactorAdapterBasic::StaticClass());
			TEST_NOT_NULL("Should not be null", MyObject);
		});

		It("should log and error to notify developper if the Game Instance does not implements INFactorsFactoryGameInstance",
			[this]() {
				World = NTestWorld::CreateAndPlay(EWorldType::Game, true);
				FakeObject->SetMyWorld(World);

				try
				{
					UNFactorsFactoryBlueprintHelpers::CreateFactor(FakeObject, UNFactorAdapterBasic::StaticClass());
					TEST_TRUE("Should not be called", false);
				}
				catch (const TCHAR* e)
				{
					TEST_EQ("An error trigger", e, TEXT("bIsImplementedFactorGI"));
				}
			});

		// It("should Create and add a new Factor", [this]() {
		// 	UNFactorAdapterBasic* MyObject =
		// 		Cast<UNFactorAdapterBasic>(UNFactorsFactoryBlueprintHelpers::CreateFactor(FakeObject, UNFactorAdapterBasic::StaticClass()));
		// 	TEST_NOT_NULL("Should not be null", MyObject);
		// 	MyObject->FactorValue = 2.f;
		// 	MyObject->Duration = 0;
		// 	MyObject->Reason = FName("Reason");
		// 	MyObject->Operator = ENFactorOperator::Add;
		// 	MyObject->InStack = FName("test1");

		// 	UNFactorAdapterBasic* ObjectAdded = Cast<UNFactorAdapterBasic>(UNFactorsFactoryBlueprintHelpers::AddFactor(FakeObject, MyObject));
		// 	TEST_EQ("Should be add and equals as itself...", ObjectAdded, MyObject);
		// });

		It("should get a results even if the asked stack not exists", [this]() {
			TArray<FFactorStackAttribute> Names = {FFactorStackAttribute(FName("Im not existing"))};
			TMap<FName, FNFactorStateResult> States;

			// An error is thrown by the "myensureMsgf" function only in test env
			// This global var is used to avoid this behavior.
			GNAssertThrowError = false;
			States = UNFactorsFactoryBlueprintHelpers::GetFactorStates(FakeObject, Names);
			GNAssertThrowError = true;

			TEST_TRUE("And get some results", States.Num() > 0);
			TEST_TRUE("with an amount", States[Names[0].Name].Amount == 0);
		});

		// It("can add a lot of factor in one time", [this]() {
		// 	TArray<FName> Names = {FName("test1")};

		// 	for (uint32 I = 0; I < 200; I++)
		// 	{
		// 		UNFactorAdapterBasic* MyObject =
		// 			Cast<UNFactorAdapterBasic>(UNFactorsFactoryBlueprintHelpers::CreateFactor(FakeObject, UNFactorAdapterBasic::StaticClass()));
		// 		MyObject->FactorValue = 2.f;
		// 		MyObject->Duration = 0;
		// 		MyObject->Reason = FName("Reason");
		// 		MyObject->Operator = ENFactorOperator::Add;
		// 		MyObject->InStack = Names[0];

		// 		UNFactorsFactoryBlueprintHelpers::AddFactor(FakeObject, MyObject);
		// 	}

		// 	TEST_TRUE("Yes it can without crashing", true);
		// 	TMap<FName, FNFactorStateResult> States = UNFactorsFactoryBlueprintHelpers::GetFactorStates(FakeObject, Names);
		// 	TEST_TRUE("And get some results", States.Num() > 0);
		// 	TEST_TRUE("And get a result for the stack 'test1'", States.Contains(Names[0]));

		// 	// Just to avoid crashing the test
		// 	if (States.Contains(Names[0]))
		// 	{
		// 		TEST_EQ("And get a result", States[Names[0]].Amount, 400.f);
		// 	}
		// 	UNFactorsFactoryBlueprintHelpers::Clear(FakeObject, Names);
		// });

		// It("can add a lot of factor in one time AND in multiple Stacks", [this]() {
		// 	TArray<FName> Names = {FName("test1"), FName("test2")};

		// 	for (uint32 I = 0; I < 200; I++)
		// 	{
		// 		UNFactorAdapterBasic* MyObject =
		// 			Cast<UNFactorAdapterBasic>(UNFactorsFactoryBlueprintHelpers::CreateFactor(FakeObject, UNFactorAdapterBasic::StaticClass()));
		// 		MyObject->FactorValue = 2.f;
		// 		MyObject->Duration = 0;
		// 		MyObject->Reason = FName("Reason");
		// 		MyObject->Operator = ENFactorOperator::Add;
		// 		MyObject->InStack = Names[0];

		// 		UNFactorsFactoryBlueprintHelpers::AddFactor(FakeObject, MyObject);
		// 	}

		// 	TEST_TRUE("Yes it can create and add 200 diff without crashing", true);
		// 	TMap<FName, FNFactorStateResult> States = UNFactorsFactoryBlueprintHelpers::GetFactorStates(FakeObject, Names);
		// 	TEST_TRUE("And get some results", States.Num() == 2);
		// 	TEST_TRUE("And get a result for the stack 'test1'", States.Contains(Names[0]));
		// 	TEST_TRUE("And get a result for the stack 'test2'", States.Contains(Names[1]));

		// 	// Just to avoid crashing the test
		// 	if (States.Contains(Names[0]))
		// 	{
		// 		TEST_EQ("And get a result", States[Names[0]].Amount, 400.f);
		// 		TEST_EQ("And get a result", States[Names[1]].Amount, 400.f);
		// 	}
		// 	UNFactorsFactoryBlueprintHelpers::Clear(FakeObject, Names);
		// });

		// It("Should continue to works after garbage collects", [this]() {
		// 	TArray<FName> Names = {FName("test1"), FName("test2")};

		// 	for (uint32 I = 0; I < 2; I++)
		// 	{
		// 		UNFactorsFactoryBlueprintHelpers::AddBasicFactor(FakeObject, Names, 2.f, ENFactorOperator::Add, 0, FName("Reason"));

		// 		if (I == 1)
		// 		{
		// 			CollectGarbage(RF_NoFlags);
		// 		}

		// 		TMap<FName, FNFactorStateResult> States = UNFactorsFactoryBlueprintHelpers::GetFactorStates(FakeObject, Names);
		// 		UE_LOG(LogTemp, Display, TEXT("Count %d - Stack number  %d"), I, States.Num());
		// 	}

		// 	TEST_TRUE("Yes it can without crashing", true);
		// 	UNFactorsFactoryBlueprintHelpers::Clear(FakeObject, Names);
		// });

		AfterEach([this]() {
			FakeObject->ClearFlags(EObjectFlags::RF_Transient);
			FakeObject->RemoveFromRoot();
			NTestWorld::Destroy(World);
		});
	});
}

#endif	  // WITH_DEV_AUTOMATION_TESTS
