#include "Attribute/FactorAttribute.h"
#include "FactorUnit/FactorUnitAdapters.h"
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
#include "Factor/FactorDecorator.h"

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

		It("Should failed when add the wrong stack", [this]() {
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

		It("Should failed when add the wrong stack's proxy", [this]() {
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
			TEST_EQ(
				"Calls SpyFactorsFactoryClient::AddFactor once", Client->GetSpy()->GetCall("SpyFactorsFactoryClient::AddFactor"), 1);
			TEST_EQ("Save 1 object in stacks", Client->GetUEFactors().Num(), 1);
			TEST_NOT_NULL("Save an unreal object in stacks", Client->GetUEFactors()[FactorName]);
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
