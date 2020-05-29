#include "CoreMinimal.h"
#include "GoogleTestApp.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "gtest/gtest.h"

class NansFactorsFactoryCoreStateTest : public ::testing::Test
{
protected:
};

TEST_F(NansFactorsFactoryCoreStateTest, ShouldComputeWithOneOperatorGiven)
{
	float Time = 1;
	NFactorState* FactorState = new NFactorState(Time);
	NFactorInterface* Factor = new NFactor(2.f, new NAddOperator(), 0, FName("Exhausted"));
	Factor->GetEvent()->NotifyAddTime(Time);
	FactorState->AddFactor(MakeShareable(Factor));
	EXPECT_EQ(FactorState->Compute(), 2.f);
}

TEST_F(NansFactorsFactoryCoreStateTest, ShouldComputeWithABunchOfOperatorsGiven)
{
	float Time = 1;
	NFactorState* FactorState = new NFactorState(Time);
	TArray<TSharedPtr<NFactorInterface>> Factors;
	Factors.Add(MakeShareable(new NFactor(2.f, new NAddOperator(), 0, FName("Exhausted"))));
	Factors.Add(MakeShareable(new NFactor(2.f, new NMultiplyOperator(), 0, FName("Infinite Drunk"))));

	for (auto Factor : Factors)
	{
		Factor->GetEvent()->NotifyAddTime(Time);
		FactorState->AddFactor(Factor);
	}
	EXPECT_EQ(FactorState->Compute(), 4.f);
}

TEST_F(NansFactorsFactoryCoreStateTest, ShouldComputeWithABunchOfOperatorsGivenAndConsideredNotActivatedOperator)
{
	// Should disable the 2nd operator
	float Time = 3.f;
	NFactorState* FactorState = new NFactorState(Time);
	// This to get extra infos on test results
	// FactorState->bDebug = true;
	TArray<TSharedPtr<NFactorInterface>> Factors;
	Factors.Add(MakeShareable(new NFactor(2.f, new NAddOperator(), 0, FName("Exhausted"))));
	Factors.Add(MakeShareable(new NFactor(2.f, new NMultiplyOperator(), 2, FName("Drunk"))));
	Factors.Add(MakeShareable(new NFactor(2.f, new NAddOperator(), 0, FName("Afraid"))));

	for (auto Factor : Factors)
	{
		Factor->GetEvent()->NotifyAddTime(Time);
		FactorState->AddFactor(Factor);
	}
	EXPECT_EQ(FactorState->Compute(), 4.f);
	EXPECT_EQ(FactorState->Compute(), 4.f);
}
