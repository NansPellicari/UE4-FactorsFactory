#include "Misc/AutomationTest.h"
#include "NansCommon/Public/Specs/NansCommonHelpers.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/FactorStack.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NullFactorState.h"

#if WITH_DEV_AUTOMATION_TESTS

class UNMockFactorsFactoryClient : public NFactorsFactoryClient
{
public:
    TMap<FName, NFactorStack*> GetStack()
    {
        return StacksList;
    };

    void Reset()
    {
        StacksList.Empty();
    }
};

BEGIN_DEFINE_SPEC(FactorsFactoryClientSpec,
    "Nans.FactorsFactory.Core.FactorsFactoryClient.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
UNMockFactorsFactoryClient* Client;
END_DEFINE_SPEC(FactorsFactoryClientSpec)
void FactorsFactoryClientSpec::Define()
{
    Client = new UNMockFactorsFactoryClient();
    Describe("Client manipulations", [this]() {
        BeforeEach([this]() { Client->Reset(); });
        It("should create a new stack", [this]() {
            FName Name = FName("test");
            TEST_FALSE("Should have a stack", Client->GetStack().Num() > 0);
            Client->CreateStack(Name);
            TEST_TRUE("Should have a stack", Client->GetStack().Num() > 0);
            TEST_TRUE("Should have a stack named 'test'", Client->GetStack().Contains(Name));
        });

        It("should not create the same stack", [this]() {
            FName Name = FName("test");
            Client->CreateStack(Name);
            try
            {
                Client->CreateStack(Name);
                TEST_TRUE("Should not be called", false);
            }
            catch (const TCHAR* e)
            {
                TEST_EQUAL("Error has been triggered", e, TEXT("!StacksList.Contains(StackName)"));
            }
        });

        It("should add a factor to a stack", [this]() {
            FName Name = FName("test");
            Client->CreateStack(Name);
            Client->AddFactor(Name, new NFactor(1, new NAddOperator(), 0, FName("reason1")));
            TEST_EQUAL("The new stack should have the new factor recently added",
                Client->GetStack()[Name]->GetFactor(0)->GetReason(),
                FName("reason1"))
        });

        It("should add a new factor to 2 stacks", [this]() {
            TArray<FName> Names = {FName("test1"), FName("test2")};
            Client->CreateStack(Names[0]);
            Client->CreateStack(Names[1]);
            Client->AddFactor(Names, new NFactor(1, new NAddOperator(), 0, FName("reason1")));
            TEST_EQUAL("The 1st and the second stack should have the same new factor recently added",
                Client->GetStack()[Names[0]]->GetFactor(0),
                Client->GetStack()[Names[1]]->GetFactor(0));
        });

        It("should get a stack's state after adding factor", [this]() {
            FName Name = FName("test");
            Client->CreateStack(Name);
            Client->AddFactor(Name, new NFactor(1, new NAddOperator(), 0, FName("reason1")));
            TEST_NOT_NULL("Should get a state", Client->GetState(Name));
        });

        It("should get stack's states after adding factors", [this]() {
            TArray<FName> Names = {FName("test1"), FName("test2")};
            Client->CreateStack(Names[0]);
            Client->CreateStack(Names[1]);
            Client->AddFactor(Names, new NFactor(1, new NAddOperator(), 0, FName("reason1")));
            TEST_EQUAL("Should get 2 states", Client->GetStates(Names).Num(), 2);
            TEST_EQUAL("State 1 should get the right amount of factor", Client->GetState(Names[0])->Compute(), 1.f);
            TEST_EQUAL("State 2 should get the right amount of factor", Client->GetState(Names[1])->Compute(), 1.f);
        });

        It("can add a lot of factor in one time", [this]() {
            TArray<FName> Names = {FName("test1")};

            for (uint32 I = 0; I < 200; I++)
            {
                NFactor* Factor = new NFactor(2.f, new NAddOperator(), 0, FName("Reason"));
                Client->AddFactor(Names, Factor);
            }

            TEST_TRUE("Yes it can without crashing", true);
            TEST_EQUAL("And get a result", Client->GetState(Names[0])->Compute(), 400.f);
        });

        It("should remove a stack", [this]() {
            Client->Reset();
            TArray<FName> Names = {FName("test1")};
            Client->CreateStack(Names[0]);
            TEST_TRUE("Get a not empty stacklist", Client->GetStack().Num() > 0);
            TEST_TRUE("Get the stack with name", Client->GetStack().Contains(Names[0]));
            Client->RemoveStack(Names[0]);
            TEST_TRUE("Get an empty stacklist", Client->GetStack().Num() == 0);
        });

        It("should dispatch time in stack and factors", [this]() {
            // TODO implements this test
            TEST_TRUE("Implements this", false);
            TEST_TRUE("Time is synchronized between client>stacks>factors", false);
        });
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS
