#include "Attribute/FactorStackAttribute.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "EngineGlobals.h"
#include "Factor/FactorAdapters.h"
#include "Factor/UnrealFactorProxy.h"
#include "FactorsFactoryBlueprintHelpers.h"
#include "Misc/AutomationTest.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"
#include "NansFactorsFactoryUE4/Public/FactorsFactoryClientAdapter.h"
#include "NansTimelineSystemUE4/Public/Manager/LevelLifeTimelineManager.h"
#include "NansTimelineSystemUE4/Public/Manager/TimelineManagerDecorator.h"
#include "NansUE4TestsHelpers/Public/Helpers/Assertions.h"
#include "NansUE4TestsHelpers/Public/Helpers/TestWorld.h"
#include "NansUE4TestsHelpers/Public/Mock/FakeObject.h"
#include "Specs/Mocks/FakeFullFactorsClientAdapter.h"
#include "Specs/Mocks/MockEngineAndWorld.h"
#include "Specs/Mocks/StubTimeline.h"
#include "Stack/FactorStackDecorator.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(FactorsFactorySerializationSpec,
	"Nans.FactorsFactory.UE4.FactorsFactorySerialization.Spec",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
UWorld* World;
// It is used has a worldContext object
UFakeObject* FakeObject;
UFakeFullFactorsClientAdapter* Client;
END_DEFINE_SPEC(FactorsFactorySerializationSpec)
void FactorsFactorySerializationSpec::Define()
{
	Describe("How to use Serialization on FactorsFactory", [this]() {
		BeforeEach([this]() {
			UE_LOG(LogTemp, Display, TEXT("-- Create World --"));
			World = NTestWorld::CreateAndPlay(EWorldType::Game, true, NAME_None, UFactorFakeGameInstance::StaticClass());
			FakeObject = NewObject<UFakeObject>(World, FName("MyFakeObject"), EObjectFlags::RF_MarkAsRootSet);
			FakeObject->SetMyWorld(World);
			Client = NewObject<UFakeFullFactorsClientAdapter>();
			Client->Init();
		});

		It("Should serialize", [this]() {
			TArray<FFactorStackAttribute> Names = {FFactorStackAttribute(FName("test1"))};
			UNLevelLifeTimelineManager* TimelineManager =
				UNTimelineManagerDecoratorFactory::CreateObject<UNLevelLifeTimelineManager>(
					FakeObject, 1.f, FName("TestTimeline"), EObjectFlags::RF_MarkAsRootSet);

			Client->CreateStack({Names[0].Name}, TimelineManager->GetTimeline());
			UNFactorStackDecorator* Stack = Client->GetUEStacks()[Names[0].Name];

			TimelineManager->Play();

			NTestWorld::Tick(World, KINDA_SMALL_NUMBER);

			UNFactorAdapterBasic* MyObject =
				Cast<UNFactorAdapterBasic>(Client->CreateFactor(Names[0].Name, UNFactorAdapterBasic::StaticClass()));
			MyObject->FactorValue = 2.f;
			MyObject->Duration = 0;
			MyObject->Reason = FName("Reason 1");
			MyObject->Operator = ENFactorOperator::Add;
			MyObject->Init();

			Client->AddFactor(Names[0].Name, MakeShareable(new NUnrealFactorProxy(MyObject)));
			MyObject = Cast<UNFactorAdapterBasic>(Client->CreateFactor(Names[0].Name, UNFactorAdapterBasic::StaticClass()));
			MyObject->FactorValue = 1.f;
			MyObject->Duration = 2.f;
			MyObject->Reason = FName("Reason 2");
			MyObject->Operator = ENFactorOperator::ResP;
			MyObject->Init();
			Client->AddFactor(Names[0].Name, MakeShareable(new NUnrealFactorProxy(MyObject)));

			FNFactorStateResult State = UNFactorsFactoryBlueprintHelpers::GetFactorState(Names[0].Name, Client);
			TEST_EQ("And get a result", State.Amount, 0.f);

			NTestWorld::Tick(World, KINDA_SMALL_NUMBER);
			NTestWorld::Tick(World);
			NTestWorld::Tick(World);

			State = UNFactorsFactoryBlueprintHelpers::GetFactorState(Names[0].Name, Client);
			TEST_EQ("Timeline manager has been called 2", TimelineManager->GetCurrentTime(), 2.f);
			TEST_EQ("And get a result", State.Amount, 2.f);

			// Save in memory
			FBufferArchive ToBinary;
			TimelineManager->Serialize(ToBinary);
			Stack->Serialize(ToBinary);

			// Add a factor to ensure it will be deleted when the previous data are loaded
			{
				MyObject = Cast<UNFactorAdapterBasic>(Client->CreateFactor(Names[0].Name, UNFactorAdapterBasic::StaticClass()));
				MyObject->FactorValue = 2.f;
				MyObject->Duration = 0;
				MyObject->Reason = FName("Reason 3");
				MyObject->Operator = ENFactorOperator::Add;
				MyObject->Init();
				Client->AddFactor(Names[0].Name, MakeShareable(new NUnrealFactorProxy(MyObject)));
			}

			NTestWorld::Tick(World, KINDA_SMALL_NUMBER);
			NTestWorld::Tick(World);

			State = UNFactorsFactoryBlueprintHelpers::GetFactorState(Names[0].Name, Client);
			TEST_EQ("Timeline manager has been called 3", TimelineManager->GetCurrentTime(), 3.f);
			TEST_EQ("And get a result", State.Amount, 4.f);
			TEST_EQ("There is 3 Events in Timeline collection", TimelineManager->GetEvents().Num(), 3);
			TEST_EQ("There is 3 Factors in store", Stack->GetFactorStore().Num(), 3);
			TEST_EQ("There is 2 Factors in stack", Stack->GetFactors().Num(), 2);

			// load from memory
			FMemoryReader FromBinary = FMemoryReader(ToBinary, true);
			FromBinary.Seek(0);
			TimelineManager->Serialize(FromBinary);
			Stack->Serialize(FromBinary);

			State = UNFactorsFactoryBlueprintHelpers::GetFactorState(Names[0].Name, Client);
			TEST_EQ("Timeline manager has been called 2", TimelineManager->GetCurrentTime(), 2.f);
			TEST_EQ("And get a result", State.Amount, 2.f);
			TEST_EQ("There is 2 Events in Timeline collection", TimelineManager->GetEvents().Num(), 2);
			TEST_EQ("There is 2 Factors in store", Stack->GetFactorStore().Num(), 2);
			TEST_EQ("There is 1 Factor in stack", Stack->GetFactors().Num(), 1);

			Client->Clear();
		});

		AfterEach([this]() {
			UE_LOG(LogTemp, Display, TEXT("-- Destroy World --"));
			Client->Clear();
			FakeObject->ClearFlags(EObjectFlags::RF_Transient);
			FakeObject->RemoveFromRoot();
			NTestWorld::Destroy(World);
		});
	});
}

#endif	  // WITH_DEV_AUTOMATION_TESTS
