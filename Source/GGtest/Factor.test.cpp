#include "CoreMinimal.h"
#include "GoogleTestApp.h"
#include "Mock/FakeTimelineManager.h"
#include "NansFactorsFactoryCore/Public/FactorUnit.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class NansFactorsFactoryCoreFactorTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		Timeline = MakeShareable(new NTimeline(new FakeTimelineManager()));
		Factor = MakeShareable(new NFactor(FName("Dialog"), Timeline));

		Factor->AddFactorUnit(MakeShareable(new NFactorUnit(2.f, MakeShareable(new NAddOperator()), 0, FName("Exhausted"))));
		Factor->AddFactorUnit(MakeShareable(new NFactorUnit(1.5f, MakeShareable(new NMultiplyOperator()), 2, FName("Drunk"))));
		Factor->AddFactorUnit(
			MakeShareable(new NFactorUnit(2.f, MakeShareable(new NAddOperator()), 10, FName("Psychologicaly attacked"))));
	}

	void TearDown() override
	{
		Factor.Reset();
	}

	TSharedPtr<NFactorInterface> Factor;
	TSharedPtr<NTimeline> Timeline;
};

TEST_F(NansFactorsFactoryCoreFactorTest, ShouldRemovesEverySetFlagsAfterGettingTheCurrentState)
{
	Factor->SetName(FName("Test iteration flag"));
	Factor->SetFlag("Flag", true);
	NFactorStateInterface* State = new NFactorState();
	Factor->SupplyStateWithCurrentData(*State);

	try
	{
		Factor->GetFlag("Flag");
		ASSERT_FALSE(true);
	}
	catch (const TCHAR* e)
	{
		EXPECT_STREQ(TCHAR_TO_ANSI(e), "IterationFlags.Contains(Flag)");
	}
}

TEST_F(NansFactorsFactoryCoreFactorTest, FactorShouldGetValidStateAndComputeCorrectlyWhen1secPassed)
{
	Timeline->SetTickInterval(1.f);
	Timeline->NotifyTick();
	NFactorStateInterface* State = new NFactorState();
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->GetTime(), 1.f);
	EXPECT_EQ(State->Compute(), 5.f);
}

TEST_F(NansFactorsFactoryCoreFactorTest, FactorShouldGetValidStateAndComputeCorrectlyWhen3secsPassed)
{
	Timeline->SetTickInterval(3.f);
	Timeline->NotifyTick();
	NFactorStateInterface* State = new NFactorState();
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->GetTime(), 3.f);
	EXPECT_EQ(State->Compute(), 4.f);
}

TEST_F(NansFactorsFactoryCoreFactorTest, FactorShouldGetValidStateAndComputeCorrectlyWhen10_1secsPassed)
{
	Timeline->SetTickInterval(10.1f);
	Timeline->NotifyTick();
	NFactorStateInterface* State = new NFactorState();
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->GetTime(), 10.1f);
	EXPECT_EQ(State->Compute(), 2.f);
}

TEST_F(NansFactorsFactoryCoreFactorTest, FactorShouldGetValidStateAndComputeCorrectlyWhen4secsPassed)
{
	Timeline->SetTickInterval(4.f);
	Timeline->NotifyTick();
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(4.f, MakeShareable(new NAddOperator()), 1.f, FName("Exhausted"))));
	NFactorStateInterface* State = new NFactorState();
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->GetTime(), 4.f);
	EXPECT_EQ(State->Compute(), 8.f);
}

TEST_F(NansFactorsFactoryCoreFactorTest, FactorShouldGetValidStateAndComputeCorrectlyWhen5_1secsPassed)
{
	Timeline->SetTickInterval(5.1f);
	Timeline->NotifyTick();
	NFactorStateInterface* State = new NFactorState();
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->GetTime(), 5.1f);
	EXPECT_EQ(State->Compute(), 4.f);
}
