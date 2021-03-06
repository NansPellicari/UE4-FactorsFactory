// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Attribute/FactorAttribute.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "EngineGlobals.h"
#include "FactorUnit/FactorUnitView.h"
#include "FactorsFactoryBlueprintHelpers.h"
#include "Misc/AutomationTest.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"
#include "NansTimelineSystemUE4/Public/Config/TimelineConfig.h"
#include "NansTimelineSystemUE4/Public/Manager/LevelLifeTimelineManager.h"
#include "NansTimelineSystemUE4/Public/Manager/TimelineManagerDecorator.h"
#include "NansUE4TestsHelpers/Public/Helpers/Assertions.h"
#include "NansUE4TestsHelpers/Public/Helpers/TestWorld.h"
#include "NansUE4TestsHelpers/Public/Mock/FakeObject.h"
#include "Specs/Mocks/MockEngineAndWorld.h"
#include "Specs/Mocks/StubTimeline.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(FactorsFactoryBlueprintHelpersSpec,
	"Nans.FactorsFactory.UE4.FactorsFactoryBlueprintHelpers.Spec",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
UWorld* World;
// It is used has a worldContext object
UFakeObject* FakeObject;
TSharedPtr<NStubTimeline> StubTimeline;
FConfiguredTimeline TimelineConf;
END_DEFINE_SPEC(FactorsFactoryBlueprintHelpersSpec)
void FactorsFactoryBlueprintHelpersSpec::Define()
{
	Describe("How to use FactorsFactoryBlueprintHelpers", [this]() {
		BeforeEach([this]() {
			UE_LOG(LogTemp, Display, TEXT("-- Create World --"));
			StubTimeline = MakeShareable(new NStubTimeline());
			TimelineConf.Name = StubTimeline->GetLabel();
			TimelineConf.TimelineClass = UNLevelLifeTimelineManager::StaticClass();

			UNTimelineConfig* StaticObject = GetMutableDefault<UNTimelineConfig>();
			FConfiguredTimelineConf TimelineConfDef;
			TimelineConfDef.Name = TimelineConf.Name;
			TimelineConfDef.TimelineClass = TimelineConf.TimelineClass;
			StaticObject->ConfiguredTimeline.Add(TimelineConfDef);
			World = NTestWorld::CreateAndPlay(EWorldType::Game, true, NAME_None, UFactorUnitFakeGameInstance::StaticClass());
			FakeObject = NewObject<UFakeObject>(World, FName("MyFakeObject"), EObjectFlags::RF_MarkAsRootSet);
			FakeObject->SetMyWorld(World);
		});

		It("Should get GetFactorUnitClient even after Garbage collects", [this]() {
			TEST_TRUE("World should still exists", World != nullptr);
			TEST_NOT_NULL("FakeObject should be not null", FakeObject);
			TEST_NOT_NULL("GEngine should still exists", GEngine);
			TEST_NOT_NULL("World should still exists", FakeObject->GetWorld());
			TEST_NOT_NULL("UNFactorsFactoryClientAdapter should be retrieved",
				UNFactorsFactoryBlueprintHelpers::GetFactorUnitClient(FakeObject));
			CollectGarbage(RF_NoFlags);
			TEST_NOT_NULL("World should be not null", World);
			TEST_NOT_NULL("World should still exists", FakeObject->GetWorld());
			TEST_NOT_NULL("UNFactorsFactoryClientAdapter should be retrieved",
				UNFactorsFactoryBlueprintHelpers::GetFactorUnitClient(FakeObject));
			CollectGarbage(RF_NoFlags);
		});

		It("Should instanciate a UNFactorUnitView", [this]() {
			auto Client = UNFactorsFactoryBlueprintHelpers::GetFactorUnitClient(FakeObject);
			Client->CreateFactor(FName("test1"), TimelineConf);
			UNFactorUnitView* MyObject = UNFactorsFactoryBlueprintHelpers::CreateFactorUnit(
				FakeObject, UNFactorUnitView::StaticClass(), FFactorAttribute(FName("test1")));
			TEST_NOT_NULL("Should not be null", MyObject);
		});

		It("Should log an error to notify developper if the Game Instance does not implements INFactorsFactoryGameInstance",
			[this]() {
				World = NTestWorld::CreateAndPlay(EWorldType::Game, true);
				FakeObject->SetMyWorld(World);

				try
				{
					UNFactorsFactoryBlueprintHelpers::CreateFactorUnit(
						FakeObject, UNFactorUnitView::StaticClass(), FFactorAttribute());
					TEST_TRUE("Should not be called", false);
				}
				catch (const TCHAR* e)
				{
					TEST_EQ("An error trigger",
						e,
						TEXT("GI->GetClass()->ImplementsInterface(UNFactorsFactoryGameInstance::StaticClass())"));
				}
			});

		It("Should Create and add a new FactorUnit", [this]() {
			auto Client = UNFactorsFactoryBlueprintHelpers::GetFactorUnitClient(FakeObject);
			Client->CreateFactor(FName("test1"), TimelineConf);
			FFactorAttribute FactorConf = FFactorAttribute(FName("test1"));

			UNFactorUnitView* MyObject = Cast<UNFactorUnitView>(
				UNFactorsFactoryBlueprintHelpers::CreateFactorUnit(FakeObject, UNFactorUnitView::StaticClass(), FactorConf));

			TEST_NOT_NULL("Should not be null", MyObject);
			MyObject->FactorUnitValue = 2.f;
			MyObject->Duration = 0;
			MyObject->Reason = FName("Reason");
			MyObject->OperatorProvider = UNFactorsFactoryBlueprintHelpers::CreateOperatorProvider(
				FakeObject, UNOperatorSimpleOperations::StaticClass(), FactorConf);
			Cast<UNOperatorSimpleOperations>(MyObject->OperatorProvider)->Type = ENFactorSimpleOperation::Add;

			UNFactorUnitView* ObjectAdded =
				Cast<UNFactorUnitView>(UNFactorsFactoryBlueprintHelpers::AddFactorUnit(FakeObject, MyObject, FactorConf));
			TEST_EQ("Should be add and equals as itself...", ObjectAdded, MyObject);
		});

		It("Should get a results even if the asked factor does not exists", [this]() {
			TArray<FFactorAttribute> Names = {FFactorAttribute(FName("Im not existing"))};
			TMap<FName, FNFactorStateResult> States;

			// An exception is thrown by the "myensureMsgf" function only in test env
			// This global var is used to avoid this blocking behavior.
			GNAssertThrowError = false;
			States = UNFactorsFactoryBlueprintHelpers::GetFactorStates(FakeObject, Names);
			GNAssertThrowError = true;

			TEST_TRUE("And get some results", States.Num() > 0);
			TEST_TRUE("with an amount", States[Names[0].Name].Amount == 0);
		});

		It("Can clear factors", [this]() {
			TArray<FFactorAttribute> Names = {FFactorAttribute(FName("test1"))};
			auto Client = UNFactorsFactoryBlueprintHelpers::GetFactorUnitClient(FakeObject);
			Client->CreateFactor(Names[0].Name, TimelineConf);

			FName Reason = FName("A temp object");
			UNFactorUnitView* MyObject = Cast<UNFactorUnitView>(
				UNFactorsFactoryBlueprintHelpers::CreateFactorUnit(FakeObject, UNFactorUnitView::StaticClass(), Names[0]));
			MyObject->FactorUnitValue = 2.f;
			MyObject->Duration = 0;
			MyObject->Reason = Reason;
			MyObject->OperatorProvider = UNFactorsFactoryBlueprintHelpers::CreateOperatorProvider(
				FakeObject, UNOperatorSimpleOperations::StaticClass(), Names[0]);
			Cast<UNOperatorSimpleOperations>(MyObject->OperatorProvider)->Type = ENFactorSimpleOperation::Add;
			UNFactorsFactoryBlueprintHelpers::AddFactorUnit(FakeObject, MyObject, Names[0]);

			FNFactorStateResult State = UNFactorsFactoryBlueprintHelpers::GetFactorState(FakeObject, Names[0]);
			TEST_GT("First has a state with an amount of 2", State.Amount, 0);
			TEST_TRUE("First has a state with a reason", State.Reasons.Contains(Reason));

			UNFactorsFactoryBlueprintHelpers::Clear(FakeObject, Names);

			State = UNFactorsFactoryBlueprintHelpers::GetFactorState(FakeObject, Names[0]);
			TEST_EQ("Then has a null state with an amount of 0", State.Amount, 0.f);
			TEST_EQ("Then has a null state first with a time of -1", State.Time, -1.f);
			TEST_EQ("Then has a state with no reason", State.Reasons.Num(), 0);
		});

		It("Can add a lot of factor in one time", [this]() {
			TArray<FFactorAttribute> Names = {FFactorAttribute(FName("test1"))};
			auto Client = UNFactorsFactoryBlueprintHelpers::GetFactorUnitClient(FakeObject);
			Client->CreateFactor(Names[0].Name, TimelineConf);

			for (uint32 I = 0; I < 200; I++)
			{
				UNFactorUnitView* MyObject = Cast<UNFactorUnitView>(
					UNFactorsFactoryBlueprintHelpers::CreateFactorUnit(FakeObject, UNFactorUnitView::StaticClass(), Names[0]));
				MyObject->FactorUnitValue = 2.f;
				MyObject->Duration = 0;
				MyObject->Reason = FName("Reason");
				MyObject->OperatorProvider = UNFactorsFactoryBlueprintHelpers::CreateOperatorProvider(
					FakeObject, UNOperatorSimpleOperations::StaticClass(), Names[0]);
				Cast<UNOperatorSimpleOperations>(MyObject->OperatorProvider)->Type = ENFactorSimpleOperation::Add;

				UNFactorsFactoryBlueprintHelpers::AddFactorUnit(FakeObject, MyObject, Names[0]);
			}

			TEST_TRUE("Yes it can without crashing", true);
			TMap<FName, FNFactorStateResult> States = UNFactorsFactoryBlueprintHelpers::GetFactorStates(FakeObject, Names);
			TEST_TRUE("And get some results", States.Num() > 0);
			TEST_TRUE("And get a result for the factor 'test1'", States.Contains(Names[0].Name));

			// Just to avoid crashing the test
			if (States.Contains(Names[0].Name))
			{
				TEST_EQ("And get a result", States[Names[0].Name].Amount, 400.f);
			}
			UNFactorsFactoryBlueprintHelpers::Clear(FakeObject, Names);
		});

		It("Can add a lot of factor in one time AND in multiple Factors", [this]() {
			TArray<FFactorAttribute> Names = {FFactorAttribute(FName("test1")), FFactorAttribute(FName("test2"))};
			auto Client = UNFactorsFactoryBlueprintHelpers::GetFactorUnitClient(FakeObject);
			Client->CreateFactor({Names[0].Name, Names[1].Name}, TimelineConf);

			for (uint32 I = 0; I < 200; I++)
			{
				UNFactorUnitView* MyObject = Cast<UNFactorUnitView>(
					UNFactorsFactoryBlueprintHelpers::CreateFactorUnit(FakeObject, UNFactorUnitView::StaticClass(), Names[0]));
				MyObject->FactorUnitValue = 2.f;
				MyObject->Duration = 0;
				MyObject->Reason = FName("Reason");
				MyObject->OperatorProvider = UNFactorsFactoryBlueprintHelpers::CreateOperatorProvider(
					FakeObject, UNOperatorSimpleOperations::StaticClass(), Names[0]);
				Cast<UNOperatorSimpleOperations>(MyObject->OperatorProvider)->Type = ENFactorSimpleOperation::Add;

				UNFactorsFactoryBlueprintHelpers::AddFactorUnit(FakeObject, MyObject, I % 2 ? Names[0] : Names[1]);
			}

			TEST_TRUE("Yes it can create and add 200 diff without crashing", true);
			TMap<FName, FNFactorStateResult> States = UNFactorsFactoryBlueprintHelpers::GetFactorStates(FakeObject, Names);
			TEST_TRUE("And get some results", States.Num() == 2);
			TEST_TRUE("And get a result for the factor 'test1'", States.Contains(Names[0].Name));
			TEST_TRUE("And get a result for the factor 'test2'", States.Contains(Names[1].Name));

			// Just to avoid crashing the test in case of a problem occured earlyer
			if (States.Contains(Names[0].Name))
			{
				TEST_EQ("And get a result", States[Names[0].Name].Amount, 200.f);
				TEST_EQ("And get a result", States[Names[1].Name].Amount, 200.f);
			}
			UNFactorsFactoryBlueprintHelpers::Clear(FakeObject, Names);
		});

		It("Should continue to works after garbage collects", [this]() {
			TArray<FFactorAttribute> Names = {FFactorAttribute(FName("test1")), FFactorAttribute(FName("test2"))};
			auto Client = UNFactorsFactoryBlueprintHelpers::GetFactorUnitClient(FakeObject);
			Client->CreateFactor({Names[0].Name, Names[1].Name}, TimelineConf);

			for (uint32 I = 0; I < 100; I++)
			{
				UNFactorUnitView* MyObject = Cast<UNFactorUnitView>(
					UNFactorsFactoryBlueprintHelpers::CreateFactorUnit(FakeObject, UNFactorUnitView::StaticClass(), Names[0]));
				MyObject->FactorUnitValue = 2.f;
				MyObject->Duration = 0;
				MyObject->Reason = FName("Reason");
				MyObject->OperatorProvider = UNFactorsFactoryBlueprintHelpers::CreateOperatorProvider(
					FakeObject, UNOperatorSimpleOperations::StaticClass(), Names[0]);
				Cast<UNOperatorSimpleOperations>(MyObject->OperatorProvider)->Type = ENFactorSimpleOperation::Add;
				UNFactorsFactoryBlueprintHelpers::AddFactorUnit(FakeObject, MyObject, I % 2 ? Names[0] : Names[1]);

				// Launch GC at each 10th's iteration
				if (I > 0 && I % 10 == 0)
				{
					CollectGarbage(RF_NoFlags);
				}

				TMap<FName, FNFactorStateResult> States = UNFactorsFactoryBlueprintHelpers::GetFactorStates(FakeObject, Names);
			}

			TEST_TRUE("Yes it can without crashing", true);
			UNFactorsFactoryBlueprintHelpers::Clear(FakeObject, Names);
		});

		AfterEach([this]() {
			UE_LOG(LogTemp, Display, TEXT("-- Destroy World --"));
			StubTimeline.Reset();
			FakeObject->ClearFlags(EObjectFlags::RF_Transient);
			FakeObject->RemoveFromRoot();
			NTestWorld::Destroy(World);
		});
	});
}

#endif	  // WITH_DEV_AUTOMATION_TESTS
