#include "CoreMinimal.h"
#include "GoogleTestApp.h"
#include "Mock/MockTimelineManager.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/FactorStack.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class NansFactorsFactoryCoreStackTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		Timeline = MakeShareable(new NTimeline(new MockTimelineManager()));
		FactorStack = MakeShareable(new NFactorStack(FName("Dialog"), Timeline));

		FactorStack->AddFactor(MakeShareable(new NFactor(2.f, new NAddOperator(), 0, FName("Exhausted"))));
		FactorStack->AddFactor(MakeShareable(new NFactor(1.5f, new NMultiplyOperator(), 2, FName("Drunk"))));
		FactorStack->AddFactor(MakeShareable(new NFactor(2.f, new NAddOperator(), 10, FName("Psychologicaly attacked"))));
	}

	void TearDown() override
	{
		FactorStack.Reset();
	}

	TSharedPtr<NFactorStack> FactorStack;
	TSharedPtr<NTimeline> Timeline;
};

TEST_F(NansFactorsFactoryCoreStackTest, ShouldRemovesEverySetFlagsAfterGettingTheCurrentState)
{
	FactorStack->SetName(FName("Test iteration flag"));
	FactorStack->SetFlag("Flag", true);
	FactorStack->GetCurrentState();
	try
	{
		FactorStack->GetFlag("Flag");
		ASSERT_FALSE(true);
	}
	catch (const TCHAR* e)
	{
		EXPECT_STREQ(TCHAR_TO_ANSI(e), "IterationFlags.Contains(Flag)");
	}
}

TEST_F(NansFactorsFactoryCoreStackTest, FactorStackShouldGetValidStateAndComputeCorrectlyWhen1secPassed)
{
	Timeline->SetTickInterval(1.f);
	Timeline->NotifyTick();
	auto State = FactorStack->GetCurrentState();
	EXPECT_EQ(State->GetTime(), 1.f);
	EXPECT_EQ(State->Compute(), 5.f);
}

TEST_F(NansFactorsFactoryCoreStackTest, FactorStackShouldGetValidStateAndComputeCorrectlyWhen3secsPassed)
{
	Timeline->SetTickInterval(3.f);
	Timeline->NotifyTick();
	auto State = FactorStack->GetCurrentState();
	EXPECT_EQ(State->GetTime(), 3.f);
	EXPECT_EQ(State->Compute(), 4.f);
}

TEST_F(NansFactorsFactoryCoreStackTest, FactorStackShouldGetValidStateAndComputeCorrectlyWhen10_1secsPassed)
{
	Timeline->SetTickInterval(10.1f);
	Timeline->NotifyTick();
	auto State = FactorStack->GetCurrentState();
	EXPECT_EQ(State->GetTime(), 10.1f);
	EXPECT_EQ(State->Compute(), 2.f);
}

TEST_F(NansFactorsFactoryCoreStackTest, FactorStackShouldGetValidStateAndComputeCorrectlyWhen4secsPassed)
{
	Timeline->SetTickInterval(4.f);
	Timeline->NotifyTick();
	FactorStack->AddFactor(MakeShareable(new NFactor(4.f, new NAddOperator(), 1.f, FName("Exhausted"))));
	auto State = FactorStack->GetCurrentState();
	EXPECT_EQ(State->GetTime(), 4.f);
	EXPECT_EQ(State->Compute(), 8.f);
}

TEST_F(NansFactorsFactoryCoreStackTest, FactorStackShouldGetValidStateAndComputeCorrectlyWhen5_1secsPassed)
{
	Timeline->SetTickInterval(5.1f);
	Timeline->NotifyTick();
	auto State = FactorStack->GetCurrentState();
	EXPECT_EQ(State->GetTime(), 5.1f);
	EXPECT_EQ(State->Compute(), 4.f);
}
