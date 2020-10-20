#include "CoreMinimal.h"
#include "GoogleTestApp.h"
#include "NansFactorsFactoryCore/Public/FactorStateInRange.h"
#include "NansFactorsFactoryCore/Public/FactorUnit.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "gtest/gtest.h"

#include <iostream>

class NansFactorsFactoryCoreStateInRangeTest : public ::testing::Test
{
protected:
};

TEST_F(NansFactorsFactoryCoreStateInRangeTest, ShouldClampMaxValue)
{
	NFactorStateInRange* FactorState = new NFactorStateInRange(0, 100);
	FactorState->SetTime(1.f);
	// This to get extra infos on test results
	// FactorState->bDebug = true;
	TArray<TSharedPtr<NFactorUnitInterface>> Factors;
	Factors.Add(MakeShareable(new NFactorUnit(20.f, MakeShareable(new NAddOperator()), 0, FName("Add1"))));
	Factors.Add(MakeShareable(new NFactorUnit(80.f, MakeShareable(new NAddOperator()), 0, FName("Add2"))));
	Factors.Add(MakeShareable(new NFactorUnit(20.f, MakeShareable(new NAddOperator()), 0, FName("Add3"))));

	for (auto FactorUnit : Factors)
	{
		FactorUnit->GetEvent()->Start(0);
		FactorState->AddFactorUnit(FactorUnit);
	}

	EXPECT_EQ(FactorState->Compute(), 100.f);
	EXPECT_EQ(FactorState->GetDecimalPercent(), 1.f);
	EXPECT_EQ(FactorState->GetDecimalPercentInRange(), 1.f);
}

TEST_F(NansFactorsFactoryCoreStateInRangeTest, ShouldClampMinValue)
{
	NFactorStateInRange* FactorState = new NFactorStateInRange(-100, 100);
	FactorState->SetTime(1.f);
	// This to get extra infos on test results
	// FactorState->bDebug = true;
	TArray<TSharedPtr<NFactorUnitInterface>> Factors;
	Factors.Add(MakeShareable(new NFactorUnit(20.f, MakeShareable(new NSubtractOperator()), 0, FName("Add1"))));
	Factors.Add(MakeShareable(new NFactorUnit(80.f, MakeShareable(new NSubtractOperator()), 0, FName("Add2"))));
	Factors.Add(MakeShareable(new NFactorUnit(20.f, MakeShareable(new NSubtractOperator()), 0, FName("Add3"))));

	for (auto FactorUnit : Factors)
	{
		FactorUnit->GetEvent()->Start(0);
		FactorState->AddFactorUnit(FactorUnit);
	}

	EXPECT_EQ(FactorState->Compute(), -100.f);
	EXPECT_EQ(FactorState->GetDecimalPercent(), -1.f);
	EXPECT_EQ(FactorState->GetDecimalPercentInRange(), 0.f);
}

TEST_F(NansFactorsFactoryCoreStateInRangeTest, ShouldGetCorretDecimalPercentInRange)
{
	NFactorStateInRange* FactorState = new NFactorStateInRange(-100, 100);
	FactorState->SetTime(1.f);
	// This to get extra infos on test results
	// FactorState->bDebug = true;
	TArray<TSharedPtr<NFactorUnitInterface>> Factors;
	Factors.Add(MakeShareable(new NFactorUnit(50.f, MakeShareable(new NSubtractOperator()), 0, FName("Add1"))));

	for (auto FactorUnit : Factors)
	{
		FactorUnit->GetEvent()->Start(0);
		FactorState->AddFactorUnit(FactorUnit);
	}

	EXPECT_EQ(FactorState->Compute(), -50.f);
	EXPECT_EQ(FactorState->GetDecimalPercent(), -0.5f);
	EXPECT_EQ(FactorState->GetDecimalPercentInRange(), 0.25f);

	FactorState->Clear();
	Factors.Empty();

	Factors.Add(MakeShareable(new NFactorUnit(30.f, MakeShareable(new NSubtractOperator()), 0, FName("Add1"))));

	for (auto FactorUnit : Factors)
	{
		FactorUnit->GetEvent()->Start(0);
		FactorState->AddFactorUnit(FactorUnit);
	}

	EXPECT_EQ(FactorState->Compute(), -30.f);
	EXPECT_EQ(FactorState->GetDecimalPercent(), -0.3f);
	EXPECT_EQ(FactorState->GetDecimalPercentInRange(), 0.35f);

	FactorState->Clear();
	Factors.Empty();

	Factors.Add(MakeShareable(new NFactorUnit(70.f, MakeShareable(new NAddOperator()), 0, FName("Add1"))));

	for (auto FactorUnit : Factors)
	{
		FactorUnit->GetEvent()->Start(0);
		FactorState->AddFactorUnit(FactorUnit);
	}

	EXPECT_EQ(FactorState->Compute(), 70.f);
	EXPECT_EQ(FactorState->GetDecimalPercent(), 0.7f);
	EXPECT_EQ(FactorState->GetDecimalPercentInRange(), 0.85f);
}

TEST_F(NansFactorsFactoryCoreStateInRangeTest, ShouldStillClampAfterAClear)
{
	NFactorStateInRange* FactorState = new NFactorStateInRange(0, 100);
	FactorState->SetTime(1.f);
	// This to get extra infos on test results
	// FactorState->bDebug = true;
	TArray<TSharedPtr<NFactorUnitInterface>> Factors;
	Factors.Add(MakeShareable(new NFactorUnit(20.f, MakeShareable(new NAddOperator()), 0, FName("Add1"))));
	Factors.Add(MakeShareable(new NFactorUnit(80.f, MakeShareable(new NAddOperator()), 0, FName("Add2"))));
	Factors.Add(MakeShareable(new NFactorUnit(20.f, MakeShareable(new NAddOperator()), 0, FName("Add3"))));

	for (auto FactorUnit : Factors)
	{
		FactorUnit->GetEvent()->Start(0);
		FactorState->AddFactorUnit(FactorUnit);
	}

	EXPECT_EQ(FactorState->Compute(), 100.f);
	EXPECT_EQ(FactorState->GetDecimalPercent(), 1.f);
	EXPECT_EQ(FactorState->GetDecimalPercentInRange(), 1.f);

	FactorState->Clear();

	for (auto FactorUnit : Factors)
	{
		FactorUnit->GetEvent()->Start(0);
		FactorState->AddFactorUnit(FactorUnit);
	}

	EXPECT_EQ(FactorState->Compute(), 100.f);
	EXPECT_EQ(FactorState->GetDecimalPercent(), 1.f);
	EXPECT_EQ(FactorState->GetDecimalPercentInRange(), 1.f);
}
