#include "CoreMinimal.h"
#include "GoogleTestApp.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/FactorUnit.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "gtest/gtest.h"

#include <iostream>

class NansFactorsFactoryCoreStateTest : public ::testing::Test
{
protected:
};

TEST_F(NansFactorsFactoryCoreStateTest, ShouldComputeWithOneOperatorGiven)
{
	float Time = 1;
	NFactorStateInterface* FactorState = new NFactorState();
	FactorState->SetTime(Time);
	NFactorUnitInterface* FactorUnit = new NFactorUnit(2.f, MakeShareable(new NAddOperator()), 0, FName("Exhausted"));
	FactorUnit->GetEvent()->Start(Time);
	FactorState->AddFactorUnit(MakeShareable(FactorUnit));
	EXPECT_EQ(FactorState->Compute(), 2.f);
}

TEST_F(NansFactorsFactoryCoreStateTest, ShouldComputeWithABunchOfOperatorsGiven)
{
	float Time = 1;
	NFactorStateInterface* FactorState = new NFactorState();
	FactorState->SetTime(Time);
	TArray<TSharedPtr<NFactorUnitInterface>> Factors;
	Factors.Add(MakeShareable(new NFactorUnit(2.f, MakeShareable(new NAddOperator()), 0, FName("Exhausted"))));
	Factors.Add(MakeShareable(new NFactorUnit(2.f, MakeShareable(new NMultiplyOperator()), 0, FName("Infinite Drunk"))));

	for (auto FactorUnit : Factors)
	{
		FactorUnit->GetEvent()->Start(Time);
		FactorState->AddFactorUnit(FactorUnit);
	}
	EXPECT_EQ(FactorState->Compute(), 4.f);
}

TEST_F(NansFactorsFactoryCoreStateTest, ShouldComputeWithABunchOfOperatorsGivenAndConsideredNotActivatedOperator)
{
	// Should disable the 2nd operator
	float Time = 3.f;
	NFactorStateInterface* FactorState = new NFactorState();
	FactorState->SetTime(Time);
	// This to get extra infos on test results
	// FactorState->bDebug = true;
	TArray<TSharedPtr<NFactorUnitInterface>> Factors;
	Factors.Add(MakeShareable(new NFactorUnit(2.f, MakeShareable(new NAddOperator()), 0, FName("Exhausted"))));
	Factors.Add(MakeShareable(new NFactorUnit(2.f, MakeShareable(new NMultiplyOperator()), 2, FName("Drunk"))));
	Factors.Add(MakeShareable(new NFactorUnit(2.f, MakeShareable(new NAddOperator()), 0, FName("Afraid"))));

	for (auto FactorUnit : Factors)
	{
		FactorUnit->GetEvent()->Start(0);
		FactorUnit->GetEvent()->NotifyAddTime(Time);
		FactorState->AddFactorUnit(FactorUnit);
	}
	EXPECT_EQ(FactorState->Compute(), 4.f);
	EXPECT_EQ(FactorState->Compute(), 4.f);
}
