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
#include "Factor/FactorDecorator.h"
#include "FactorUnit/FactorUnitAdapter.h"
#include "Misc/AutomationTest.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/FactorInterface.h"
#include "NansFactorsFactoryCore/Public/NullFactorUnit.h"
#include "NansFactorsFactoryUE4/Public/Specs/Mocks/SpyFactorsFactoryClient.h"
#include "NansUE4TestsHelpers/Public/Helpers/Assertions.h"
#include "Specs/Mocks/FakeFactorsFactoryClientAdapter.h"
#include "Specs/Mocks/StubFactorNotWorking.h"
#include "Specs/Mocks/StubFactorState.h"
#include "Specs/Mocks/StubNullUnrealFactorProxy.h"
#include "Specs/Mocks/StubTimeline.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(FactorsFactoryClientAdapterSpec,
	"Nans.FactorsFactory.UE4.FactorsFactoryClientAdapter.Spec",
	EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

UFakeFactorsFactoryClientAdapter* Client;
END_DEFINE_SPEC(FactorsFactoryClientAdapterSpec)
void FactorsFactoryClientAdapterSpec::Define()
{
	Describe("How to use FactorsFactoryClientAdapter", [this]() {
		BeforeEach([this]() {
			NFactorUnitInterface* NullObj = new NNullFactorUnit();
			Client = NewObject<UFakeFactorsFactoryClientAdapter>();
			Client->Init();
		});

		It("Should failed when add the wrong factor", [this]() {
			TSharedPtr<NFactorInterface> Factor = MakeShareable(new StubFactorNotWorking());
			try
			{
				Client->AddFactor(Factor);
				TEST_FALSE(TEXT("Should not be called"), true);
			}
			catch (const TCHAR* e)
			{
				TEST_EQ("An error trigger", e, TEXT("Proxy != nullptr"));
			}
		});

		It("Should failed when add the wrong factor's proxy", [this]() {
			UNFactorDecorator* Factor = NewObject<UNFactorDecorator>();
			TSharedPtr<NFactorInterface> Proxy = MakeShareable(new StubNullUnrealFactorProxy(*Factor));

			try
			{
				Client->AddFactor(Proxy);
				TEST_FALSE(TEXT("Should not be called"), true);
			}
			catch (const TCHAR* e)
			{
				TEST_EQ("An error trigger", e, TEXT("Proxy->GetUnrealObject() != nullptr"));
			}
		});

		It("Should use its embeded client's methods for the most part", [this]() {
			FName FactorName("MyName");
			TSharedPtr<NStubTimeline> StubTimeline = MakeShareable(new NStubTimeline());
			Client->CreateFactor(FactorName, StubTimeline);
			TEST_EQ("Calls SpyFactorsFactoryClient::AddFactor once",
				Client->GetSpy()->GetCall("SpyFactorsFactoryClient::AddFactor"),
				1);
			TEST_EQ("Save 1 object in factors", Client->GetUEFactors().Num(), 1);
			TEST_NOT_NULL("Save an unreal object in factors", Client->GetUEFactors()[FactorName]);
			StubFactorState* State = new StubFactorState();
			Client->GetState(FactorName, *State);
			TEST_EQ(
				"Calls SpyFactorsFactoryClient::GetState once", Client->GetSpy()->GetCall("SpyFactorsFactoryClient::GetState"), 1);
			Client->GetStates({FactorName}, State);
			TEST_EQ("Calls SpyFactorsFactoryClient::GetStates once",
				Client->GetSpy()->GetCall("SpyFactorsFactoryClient::GetStates"),
				1);
			auto FactorUnit = MakeShareable(new NNullFactorUnit());
			Client->AddFactorUnit(FactorName, FactorUnit);
			TEST_EQ("Calls SpyFactorsFactoryClient::AddFactorUnit once",
				Client->GetSpy()->GetCall("SpyFactorsFactoryClient::AddFactorUnit"),
				1);
		});

		AfterEach([this]() { Client->Clear(); });
	});
}

#endif	  // WITH_DEV_AUTOMATION_TESTS
