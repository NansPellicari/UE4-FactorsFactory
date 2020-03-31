#include "DifficultySystemClient.h"
#include "Misc/AutomationTest.h"
#include "NansCommon/Public/Specs/NansCommonHelpers.h"
#include "NansDifficultySystemCore/Public/Difficulty.h"
#include "NansDifficultySystemCore/Public/DifficultyStack.h"
#include "NansDifficultySystemCore/Public/DifficultyState.h"
#include "NansDifficultySystemCore/Public/Operator/DifficultyOperator.h"
#include "NullDifficultyState.h"

#if WITH_DEV_AUTOMATION_TESTS

class UNMockDifficultySystemClient : public UNDifficultySystemClient
{
public:
    TMap<FName, UNDifficultyStack*> GetStack()
    {
        return StacksList;
    };

    void Reset()
    {
        StacksList.Empty();
    }
};

BEGIN_DEFINE_SPEC(DifficultySystemClientSpec,
    "NansDifficultySystem.UE4.DifficultySystemClient.Spec",
    EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
UNMockDifficultySystemClient* Client;
END_DEFINE_SPEC(DifficultySystemClientSpec)
void DifficultySystemClientSpec::Define()
{
    Client = NewObject<UNMockDifficultySystemClient>();
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

        It("should add a difficulty to a stack", [this]() {
            FName Name = FName("test");
            Client->CreateStack(Name);
            UNDifficulty* Diff = NewObject<UNDifficulty>();
            Client->AddDifficulty(Name, Diff->Initialize(1, NewObject<UNAddOperator>(), 0, FName("reason1")));
            TEST_EQUAL("The new stack should have the new difficulty recently added",
                Client->GetStack()[Name]->GetDifficulty(0)->GetReason(),
                FName("reason1"))
        });

        It("should add a new difficulty to 2 stacks", [this]() {
            TArray<FName> Names = {FName("test1"), FName("test2")};
            Client->CreateStack(Names[0]);
            Client->CreateStack(Names[1]);
            UNDifficulty* Diff = NewObject<UNDifficulty>();
            Client->AddDifficulty(Names, Diff->Initialize(1, NewObject<UNAddOperator>(), 0, FName("reason1")));
            TEST_EQUAL("The 1st and the second stack should have the same new difficulty recently added",
                Client->GetStack()[Names[0]]->GetDifficulty(0),
                Client->GetStack()[Names[1]]->GetDifficulty(0));
        });
        It("should get a stack's state after adding difficulty", [this]() {
            FName Name = FName("test");
            Client->CreateStack(Name);
            UNDifficulty* Diff = NewObject<UNDifficulty>();
            Client->AddDifficulty(Name, Diff->Initialize(1, NewObject<UNAddOperator>(), 0, FName("reason1")));
            TEST_NOT_NULL("Should get a state", Client->GetState(Name));
        });
        It("should get stack's states after adding difficulties", [this]() {
            TArray<FName> Names = {FName("test1"), FName("test2")};
            Client->CreateStack(Names[0]);
            Client->CreateStack(Names[1]);
            UNDifficulty* Diff = NewObject<UNDifficulty>();
            Client->AddDifficulty(Names, Diff->Initialize(1, NewObject<UNAddOperator>(), 0, FName("reason1")));
            TEST_EQUAL("Should get 2 states", Client->GetStates(Names).Num(), 2);
        });
    });
}

#endif    // WITH_DEV_AUTOMATION_TESTS