#include "CoreMinimal.h"
#include "GoogleTestApp.h"
#include "Mock/MockTimelineManager.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/FactorStack.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/FactorStateInterface.h"
#include "NansFactorsFactoryCore/Public/FactorsFactoryClient.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <iostream>

class UNFakeFactorsFactoryClient : public NFactorsFactoryClient
{
public:
	TMap<FName, TSharedPtr<NFactorStackInterface>> GetStack()
	{
		return StacksList;
	};

	void Reset()
	{
		StacksList.Empty();
	}
};

class NansFactorsFactoryCoreClientTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		Timeline = MakeShareable(new NTimeline(new MockTimelineManager()));
		Client = new UNFakeFactorsFactoryClient();
	}

	void TearDown() override
	{
		Client->Reset();
	}

	UNFakeFactorsFactoryClient* Client;
	TSharedPtr<NTimeline> Timeline;
};

TEST_F(NansFactorsFactoryCoreClientTest, ShouldCreateANewStack)
{
	FName Name = FName("test");
	EXPECT_FALSE(Client->GetStack().Num() > 0);
	Client->CreateStack(Name, Timeline);
	EXPECT_TRUE(Client->GetStack().Num() > 0);
	EXPECT_TRUE(Client->GetStack().Contains(Name));
}

TEST_F(NansFactorsFactoryCoreClientTest, ShouldNotCreateTheSameStack)
{
	FName Name = FName("test");
	Client->CreateStack(Name, Timeline);
	try
	{
		Client->CreateStack(Name, Timeline);
		ASSERT_FALSE(true);
	}
	catch (const TCHAR* e)
	{
		EXPECT_STREQ(TCHAR_TO_ANSI(e), "!StacksList.Contains(StackName)");
	}
}

TEST_F(NansFactorsFactoryCoreClientTest, ShouldAddAFactorToAStack)
{
	FName Name = FName("test");
	Client->CreateStack(Name, Timeline);
	Client->AddFactor(Name, MakeShareable(new NFactor(1, MakeShareable(new NAddOperator()), 0, FName("reason1"))));
	EXPECT_EQ(Client->GetStack()[Name]->GetFactor(0)->GetReason(), FName("reason1"));
}

TEST_F(NansFactorsFactoryCoreClientTest, ShouldAddANewFactorTo_2Stacks)
{
	TArray<FName> Names = {FName("test1"), FName("test2")};
	Client->CreateStack(Names, Timeline);
	Client->AddFactor(Names, MakeShareable(new NFactor(1, MakeShareable(new NAddOperator()), 0, FName("reason1"))));
	EXPECT_EQ(Client->GetStack()[Names[0]]->GetFactor(0), Client->GetStack()[Names[1]]->GetFactor(0));
}

TEST_F(NansFactorsFactoryCoreClientTest, ShouldGetAStackSStateAfterAddingFactor)
{
	FName Name = FName("test");
	Client->CreateStack(Name, Timeline);
	Client->AddFactor(Name, MakeShareable(new NFactor(1, MakeShareable(new NAddOperator()), 0, FName("reason1"))));
	NFactorStateInterface* State = new NFactorState();
	Client->GetState(Name, *State);
    EXPECT_EQ(State->GetTime(), 0.f);
}

TEST_F(NansFactorsFactoryCoreClientTest, ShouldGetStackSStatesAfterAddingFactors)
{
	TArray<FName> Names = {FName("test1"), FName("test2")};
	Client->CreateStack(Names, Timeline);
	Client->AddFactor(Names, MakeShareable(new NFactor(1, MakeShareable(new NAddOperator()), 0, FName("reason1"))));
	EXPECT_EQ(Client->GetStates(Names, new NFactorState()).Num(), 2);
	NFactorStateInterface* State = new NFactorState();
	Client->GetState(Names[0], *State);
	EXPECT_EQ(State->Compute(), 1.f);
	Client->GetState(Names[1], *State);
	EXPECT_EQ(State->Compute(), 1.f);
}

TEST_F(NansFactorsFactoryCoreClientTest, CanTAddAFactorWithoutAPreviouslyCreatedStack)
{
	TArray<FName> Names = {FName("test1")};
	NFactor* Factor = new NFactor(2.f, MakeShareable(new NAddOperator()), 0, FName("Reason"));
	try
	{
		Client->AddFactor(Names, MakeShareable(Factor));
		ASSERT_FALSE(true);
	}
	catch (const TCHAR* e)
	{
		EXPECT_STREQ(TCHAR_TO_ANSI(e), "StacksList.Contains(StackName)");
	}
}
TEST_F(NansFactorsFactoryCoreClientTest, CanAddALotOfFactorInOneTime)
{
	TArray<FName> Names = {FName("test1")};
	Client->CreateStack(Names, Timeline);

	for (uint32 I = 0; I < 200; I++)
	{
		NFactor* Factor = new NFactor(2.f, MakeShareable(new NAddOperator()), 0, FName("Reason"));
		Client->AddFactor(Names, MakeShareable(Factor));
	}

	NFactorStateInterface* State = new NFactorState();
    Client->GetState(Names[0], *State);
	EXPECT_EQ(State->Compute(), 400.f);
}

TEST_F(NansFactorsFactoryCoreClientTest, ShouldRemoveAStack)
{
	TArray<FName> Names = {FName("test1")};
	Client->CreateStack(Names, Timeline);
	EXPECT_TRUE(Client->GetStack().Num() > 0);
	EXPECT_TRUE(Client->GetStack().Contains(Names[0]));
	Client->RemoveStack(Names[0]);
	EXPECT_TRUE(Client->GetStack().Num() == 0);
}

TEST_F(NansFactorsFactoryCoreClientTest, ShouldDispatchTimeInStackAndFactors)
{
	TArray<FName> Names = {FName("test1")};
	Client->CreateStack(Names, Timeline);
	float TickInterval = 1.f;
	Timeline->SetTickInterval(TickInterval);
	Timeline->NotifyTick();
	NFactor* Factor = new NFactor(2.f, MakeShareable(new NAddOperator()), 0, FName("Reason"));
	Client->AddFactor(Names, MakeShareable(Factor));
	Timeline->NotifyTick();
	NFactorStateInterface* State = new NFactorState();
	Client->GetStack()[Names[0]]->SupplyStateWithCurrentData(*State);
	// Time should be synchronized between client>stacks>factors
	EXPECT_EQ(Timeline->GetCurrentTime(), State->GetTime());
	EXPECT_EQ(Timeline->GetCurrentTime() - TickInterval, Factor->GetEvent()->GetLocalTime());
}
