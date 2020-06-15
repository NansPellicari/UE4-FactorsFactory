#include "CoreMinimal.h"
#include "GoogleTestApp.h"
#include "Mock/FakeFactor.h"
#include "Mock/FakeTimelineManager.h"
#include "NansFactorsFactoryCore/Public/FactorUnit.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/ResetOperator.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <iostream>

class FakeResetOperator : public NResetOperator
{
public:
	uint32 GetKeyInFactor()
	{
		return KeyInFactor;
	}
	bool HasFactor()
	{
		return MyFactor != nullptr;
	}
};

class NansFactorsFactoryCoreResetOperatorTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		Timeline = MakeShareable(new NTimeline(new FakeTimelineManager()));
		Factor = MakeShareable(new FakeFactor(FName("Dialog"), Timeline));

		Factor->AddFactorUnit(MakeShareable(new NFactorUnit(2, MakeShareable(new NAddOperator()), 0, FName("reason1"))));
		Factor->AddFactorUnit(MakeShareable(new NFactorUnit(3, MakeShareable(new NAddOperator()), 0, FName("reason2"))));
	}

	void TearDown() override
	{
		Factor.Reset();
	}

	TSharedPtr<FakeFactor> Factor;
	TSharedPtr<NTimeline> Timeline;
};

TEST_F(NansFactorsFactoryCoreResetOperatorTest, ShouldCheckIfIsAnOperatorWithFactorOrNot)
{
	// Some factors to be reset
	FakeResetOperator* Operator = new FakeResetOperator();
	EXPECT_EQ(Operator->GetName(), NResetOperator::Name);
	EXPECT_FALSE(NOperatorUtils::IsOperatorWithFactor(new NNullOperator()));
	EXPECT_TRUE(NOperatorUtils::IsOperatorWithFactor(Operator));
}

TEST_F(NansFactorsFactoryCoreResetOperatorTest, ShouldTriggerAnErrorIfTryingToSetAKeyBeforeHavingAFactor)
{
	// Some factors to be reset
	FakeResetOperator* Operator = new FakeResetOperator();
	try
	{
		Operator->SetKeyInFactor(0);
		EXPECT_TRUE(false);
	}
	catch (const TCHAR* e)
	{
		EXPECT_STREQ(TCHAR_TO_ANSI(e), "MyFactor != nullptr");
	}
}

TEST_F(NansFactorsFactoryCoreResetOperatorTest, ShouldResetTheLastFactorUnitSetInTheFactor)
{
	// Some factors to be reset
	FakeResetOperator* Operator = new FakeResetOperator();

	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(1, MakeShareable(Operator), 0, FName("Magic potion"))));
	NFactorStateInterface* State = new NFactorState();
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->Compute(), 2.f);
	EXPECT_TRUE(Operator->HasFactor());
	EXPECT_TRUE(Operator->GetKeyInFactor() > 0);
	EXPECT_TRUE(Factor->HasStateFlag(FakeResetOperator::GetResetIdFlag(Factor->GetFactorUnit(1))));
}

TEST_F(NansFactorsFactoryCoreResetOperatorTest, ShouldResetTheFirstFactorUnitSetInTheFactor)
{
	// Some factors to be reset
	FakeResetOperator* Operator = new FakeResetOperator();

	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(2, MakeShareable(Operator), 0, FName("Magic potion"))));

	NFactorStateInterface* State = new NFactorState();
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->Compute(), 3.f);
	EXPECT_TRUE(Factor->HasStateFlag(FakeResetOperator::GetResetIdFlag(Factor->GetFactorUnit(0))));
}

TEST_F(NansFactorsFactoryCoreResetOperatorTest, ShouldResetTheFirstAndLastFactorUnitSetInTheFactor)
{
	// Some factors to be reset
	FakeResetOperator* Operator = new FakeResetOperator();

	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(1, MakeShareable(Operator), 0, FName("Magic potion"))));
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(2, MakeShareable(Operator), 0, FName("Magic potion"))));
	NFactorStateInterface* State = new NFactorState();
	Factor->SupplyStateWithCurrentData(*State);

	EXPECT_EQ(State->Compute(), 0.f);
	EXPECT_TRUE(Factor->HasStateFlag(FakeResetOperator::GetResetIdFlag(Factor->GetFactorUnit(0))));
	EXPECT_TRUE(Factor->HasStateFlag(FakeResetOperator::GetResetIdFlag(Factor->GetFactorUnit(1))));
}
