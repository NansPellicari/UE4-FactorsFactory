#include "Attribute/FactorStackAttribute.h"
#include "Factor/FactorAdapters.h"
#include "Misc/AutomationTest.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/FactorStackInterface.h"
#include "NansFactorsFactoryCore/Public/NullFactor.h"
#include "NansFactorsFactoryUE4/Public/Specs/Mocks/SpyFactorsFactoryClient.h"
#include "NansUE4TestsHelpers/Public/Helpers/Assertions.h"
#include "Specs/Mocks/FakeFactorsFactoryClientAdapter.h"
#include "Specs/Mocks/StubFactorStackNotWorking.h"
#include "Specs/Mocks/StubFactorState.h"
#include "Specs/Mocks/StubNullUnrealFactorStackProxy.h"
#include "Specs/Mocks/StubTimeline.h"
#include "Stack/FactorStackDecorator.h"

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
			NFactorInterface* NullObj = new NNullFactor();
			Client = NewObject<UFakeFactorsFactoryClientAdapter>();
			Client->Init();
		});

		It("Should failed when add the wrong stack", [this]() {
			TSharedPtr<NFactorStackInterface> Stack = MakeShareable(new StubFactorStackNotWorking());
			try
			{
				Client->AddStack(Stack);
				TEST_FALSE(TEXT("Should not be called"), true);
			}
			catch (const TCHAR* e)
			{
				TEST_EQ("An error trigger", e, TEXT("Proxy != nullptr"));
			}
		});

		It("Should failed when add the wrong stack's proxy", [this]() {
			UNFactorStackDecorator* Stack = NewObject<UNFactorStackDecorator>();
			TSharedPtr<NFactorStackInterface> Proxy = MakeShareable(new StubNullUnrealFactorStackProxy(*Stack));

			try
			{
				Client->AddStack(Proxy);
				TEST_FALSE(TEXT("Should not be called"), true);
			}
			catch (const TCHAR* e)
			{
				TEST_EQ("An error trigger", e, TEXT("Proxy->GetUnrealObject() != nullptr"));
			}
		});

		It("Should use its embeded client's methods for the most part", [this]() {
			FName StackName("MyName");
			TSharedPtr<NStubTimeline> StubTimeline = MakeShareable(new NStubTimeline());
			Client->CreateStack(StackName, StubTimeline);
			TEST_EQ(
				"Calls SpyFactorsFactoryClient::AddStack once", Client->GetSpy()->GetCall("SpyFactorsFactoryClient::AddStack"), 1);
			TEST_EQ("Save 1 object in stacks", Client->GetUEStacks().Num(), 1);
			TEST_NOT_NULL("Save an unreal object in stacks", Client->GetUEStacks()[StackName]);
			StubFactorState* State = new StubFactorState();
			Client->GetState(StackName, *State);
			TEST_EQ(
				"Calls SpyFactorsFactoryClient::GetState once", Client->GetSpy()->GetCall("SpyFactorsFactoryClient::GetState"), 1);
			Client->GetStates({StackName}, State);
			TEST_EQ("Calls SpyFactorsFactoryClient::GetStates once",
				Client->GetSpy()->GetCall("SpyFactorsFactoryClient::GetStates"),
				1);
			auto Factor = MakeShareable(new NNullFactor());
			Client->AddFactor(StackName, Factor);
			TEST_EQ("Calls SpyFactorsFactoryClient::AddFactor once",
				Client->GetSpy()->GetCall("SpyFactorsFactoryClient::AddFactor"),
				1);
		});

		AfterEach([this]() { Client->Clear(); });
	});
}

#endif	  // WITH_DEV_AUTOMATION_TESTS
