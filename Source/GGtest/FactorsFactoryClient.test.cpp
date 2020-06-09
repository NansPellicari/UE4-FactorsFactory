#include "CoreMinimal.h"
#include "GoogleTestApp.h"
#include "Mock/FakeTimelineManager.h"
#include "NansFactorsFactoryCore/Public/FactorUnit.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
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
	TMap<FName, TSharedPtr<NFactorInterface>> GetFactor()
	{
		return FactorsList;
	};

	void Clear()
	{
		FactorsList.Empty();
	}
};

class NansFactorsFactoryCoreClientTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		Timeline = MakeShareable(new NTimeline(new FakeTimelineManager()));
		Client = new UNFakeFactorsFactoryClient();
	}

	void TearDown() override
	{
		Client->Clear();
	}

	UNFakeFactorsFactoryClient* Client;
	TSharedPtr<NTimeline> Timeline;
};

TEST_F(NansFactorsFactoryCoreClientTest, ShouldCreateANewFactor)
{
	FName Name = FName("test");
	EXPECT_FALSE(Client->GetFactor().Num() > 0);
	Client->CreateFactor(Name, Timeline);
	EXPECT_TRUE(Client->GetFactor().Num() > 0);
	EXPECT_TRUE(Client->GetFactor().Contains(Name));
}

TEST_F(NansFactorsFactoryCoreClientTest, ShouldNotCreateTheSameFactor)
{
	FName Name = FName("test");
	Client->CreateFactor(Name, Timeline);
	try
	{
		Client->CreateFactor(Name, Timeline);
		ASSERT_FALSE(true);
	}
	catch (const TCHAR* e)
	{
		EXPECT_STREQ(TCHAR_TO_ANSI(e), "!FactorsList.Contains(FactorName)");
	}
}

TEST_F(NansFactorsFactoryCoreClientTest, ShouldAddAFactorUnitToAFactor)
{
	FName Name = FName("test");
	Client->CreateFactor(Name, Timeline);
	Client->AddFactorUnit(Name, MakeShareable(new NFactorUnit(1, MakeShareable(new NAddOperator()), 0, FName("reason1"))));
	EXPECT_EQ(Client->GetFactor()[Name]->GetFactorUnit(0)->GetReason(), FName("reason1"));
}

TEST_F(NansFactorsFactoryCoreClientTest, ShouldAddANewFactorUnitTo_2Factors)
{
	TArray<FName> Names = {FName("test1"), FName("test2")};
	Client->CreateFactor(Names, Timeline);
	for (const FName& Name : Names)
	{
		Client->AddFactorUnit(Name, MakeShareable(new NFactorUnit(1, MakeShareable(new NAddOperator()), 0, FName("reason1"))));
	}

	EXPECT_EQ(Client->GetFactor()[Names[0]]->GetFactors().Num(), 1);
	EXPECT_EQ(Client->GetFactor()[Names[1]]->GetFactors().Num(), 1);
}

TEST_F(NansFactorsFactoryCoreClientTest, ShouldGetAFactorSStateAfterAddingFactorUnit)
{
	FName Name = FName("test");
	Client->CreateFactor(Name, Timeline);
	Client->AddFactorUnit(Name, MakeShareable(new NFactorUnit(1, MakeShareable(new NAddOperator()), 0, FName("reason1"))));
	NFactorStateInterface* State = new NFactorState();
	Client->GetState(Name, *State);
	EXPECT_EQ(State->GetTime(), 0.f);
}

TEST_F(NansFactorsFactoryCoreClientTest, ShouldNotGetAStateFromAnNonExistantFactor)
{
	FName Name = FName("test");
	NFactorStateInterface* State = new NFactorState();
	Client->GetState(Name, *State);
	EXPECT_EQ(State->GetTime(), -1.f);
}

TEST_F(NansFactorsFactoryCoreClientTest, ShouldGetFactorSStatesAfterAddingFactors)
{
	TArray<FName> Names = {FName("test1"), FName("test2")};
	Client->CreateFactor(Names, Timeline);
	for (const FName& Name : Names)
	{
		Client->AddFactorUnit(Name, MakeShareable(new NFactorUnit(1, MakeShareable(new NAddOperator()), 0, FName("reason1"))));
	}
	EXPECT_EQ(Client->GetStates(Names, new NFactorState()).Num(), 2);
	NFactorStateInterface* State = new NFactorState();
	Client->GetState(Names[0], *State);
	EXPECT_EQ(State->Compute(), 1.f);
	Client->GetState(Names[1], *State);
	EXPECT_EQ(State->Compute(), 1.f);
}

TEST_F(NansFactorsFactoryCoreClientTest, CanTAddAFactorUnitWithoutAPreviouslyCreatedFactor)
{
	TArray<FName> Names = {FName("test1")};
	NFactorUnit* FactorUnit = new NFactorUnit(2.f, MakeShareable(new NAddOperator()), 0, FName("Reason"));
	try
	{
		Client->AddFactorUnit(Names[0], MakeShareable(FactorUnit));
		ASSERT_FALSE(true);
	}
	catch (const TCHAR* e)
	{
		EXPECT_STREQ(TCHAR_TO_ANSI(e), "FactorsList.Contains(FactorName)");
	}
}
TEST_F(NansFactorsFactoryCoreClientTest, CanAddALotOfFactorUnitInOneTime)
{
	TArray<FName> Names = {FName("test1")};
	Client->CreateFactor(Names, Timeline);

	for (uint32 I = 0; I < 200; I++)
	{
		NFactorUnit* FactorUnit = new NFactorUnit(2.f, MakeShareable(new NAddOperator()), 0, FName("Reason"));
		Client->AddFactorUnit(Names[0], MakeShareable(FactorUnit));
	}

	NFactorStateInterface* State = new NFactorState();
	Client->GetState(Names[0], *State);
	EXPECT_EQ(State->Compute(), 400.f);
}

TEST_F(NansFactorsFactoryCoreClientTest, ShouldRemoveAFactor)
{
	TArray<FName> Names = {FName("test1")};
	Client->CreateFactor(Names, Timeline);
	EXPECT_TRUE(Client->GetFactor().Num() > 0);
	EXPECT_TRUE(Client->GetFactor().Contains(Names[0]));
	Client->RemoveFactor(Names[0]);
	EXPECT_TRUE(Client->GetFactor().Num() == 0);
}

TEST_F(NansFactorsFactoryCoreClientTest, ShouldDispatchTimeInFactorAndFactors)
{
	TArray<FName> Names = {FName("test1")};
	Client->CreateFactor(Names, Timeline);
	float TickInterval = 1.f;
	Timeline->SetTickInterval(TickInterval);
	Timeline->NotifyTick();
	NFactorUnit* FactorUnit = new NFactorUnit(2.f, MakeShareable(new NAddOperator()), 0, FName("Reason"));
	Client->AddFactorUnit(Names[0], MakeShareable(FactorUnit));
	Timeline->NotifyTick();
	NFactorStateInterface* State = new NFactorState();
	Client->GetFactor()[Names[0]]->SupplyStateWithCurrentData(*State);
	// Time should be synchronized between client>stacks>factors
	EXPECT_EQ(Timeline->GetCurrentTime(), State->GetTime());
	EXPECT_EQ(Timeline->GetCurrentTime() - TickInterval, FactorUnit->GetEvent()->GetLocalTime());
}
