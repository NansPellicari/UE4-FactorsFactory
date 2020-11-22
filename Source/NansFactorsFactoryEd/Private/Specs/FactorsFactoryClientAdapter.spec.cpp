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
#include "Config/TimelineConfig.h"
#include "Helpers/TestWorld.h"
#include "Manager/LevelLifeTimelineManager.h"
#include "Misc/AutomationTest.h"
#include "Mock/FakeObject.h"
#include "NansUE4TestsHelpers/Public/Helpers/Assertions.h"
#include "Specs/Mocks/FakeFactorsFactoryClientAdapter.h"
#include "Specs/Mocks/MockEngineAndWorld.h"
#include "Specs/Mocks/SpyFactorsFactoryClient.h"
#include "Specs/Mocks/StubFactorState.h"
#include "Specs/Mocks/StubTimeline.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(
	FactorsFactoryClientAdapterSpec,
	"Nans.FactorsFactory.UE4.FactorsFactoryClientAdapter.Spec",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask
)
	UWorld* World;

	UFakeFactorsFactoryClientAdapter* Client;
	UFakeObject* FakeObject;
	FConfiguredTimeline TimelineConf;
	TSharedPtr<NStubTimeline> StubTimeline;
END_DEFINE_SPEC(FactorsFactoryClientAdapterSpec)

void FactorsFactoryClientAdapterSpec::Define()
{
	Describe(
		"How to use FactorsFactoryClientAdapter",
		[this]()
		{
			BeforeEach(
				[this]()
				{
					StubTimeline = MakeShareable(new NStubTimeline());
					TimelineConf.Name = StubTimeline->GetLabel();
					TimelineConf.TimelineClass = UNLevelLifeTimelineManager::StaticClass();

					UNTimelineConfig* StaticObject = GetMutableDefault<UNTimelineConfig>();
					FConfiguredTimelineConf TimelineConfDef;
					TimelineConfDef.Name = TimelineConf.Name;
					TimelineConfDef.TimelineClass = TimelineConf.TimelineClass;
					StaticObject->ConfiguredTimeline.Add(TimelineConfDef);
					World = NTestWorld::CreateAndPlay(
						EWorldType::Game,
						true,
						NAME_None,
						UFactorUnitFakeGameInstance::StaticClass()
					);
					FakeObject = NewObject<UFakeObject>(World, FName("MyFakeObject"), EObjectFlags::RF_MarkAsRootSet);
					FakeObject->SetMyWorld(World);
					Client = NewObject<UFakeFactorsFactoryClientAdapter>(FakeObject);
					Client->Init();
				}
			);

			It(
				"Should use its embeded client's methods for the most part",
				[this]()
				{
					FName FactorName("MyName");
					Client->CreateFactor(FactorName, TimelineConf);
					TEST_EQ(
						"Calls SpyFactorsFactoryClient::AddFactor once",
						Client->GetSpy()->GetCall("SpyFactorsFactoryClient::AddFactor"),
						1
					);
					TEST_EQ("Save 1 object in factors", Client->GetUEFactors().Num(), 1);
					TEST_NOT_NULL("Save an unreal object in factors", Client->GetUEFactors()[FactorName]);
					StubFactorState* State = new StubFactorState();
					Client->GetState(FactorName, *State);
					TEST_EQ(
						"Calls SpyFactorsFactoryClient::GetState once",
						Client->GetSpy()->GetCall("SpyFactorsFactoryClient::GetState"),
						1
					);
					Client->GetStates({FactorName}, State);
					TEST_EQ(
						"Calls SpyFactorsFactoryClient::GetStates once",
						Client->GetSpy()->GetCall("SpyFactorsFactoryClient::GetStates"),
						1
					);
					// Client->AddFactorUnit(FactorName, NewObject<UNNullFactorUnit>(FakeObject));
					// TEST_EQ("Calls SpyFactorsFactoryClient::AddFactorUnit once",
					// 	Client->GetSpy()->GetCall("SpyFactorsFactoryClient::AddFactorUnit"),
					// 	1);
				}
			);

			AfterEach(
				[this]()
				{
					// UE_LOG(LogTemp, Display, TEXT("-- Destroy World --"));
					// StubTimeline.Reset();
					FakeObject->ClearFlags(EObjectFlags::RF_Transient);
					FakeObject->RemoveFromRoot();
					NTestWorld::Destroy(World);
					Client->Clear();
				}
			);
		}
	);
}

#endif	  // WITH_DEV_AUTOMATION_TESTS
