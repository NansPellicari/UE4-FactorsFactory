#include "CoreMinimal.h"
#include "GoogleTestApp.h"
#include "Mock/MockTimelineManager.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/ResetOperator.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class FakeResetOperator : public NResetOperator
{
public:
	uint32 GetKeyInStack()
	{
		return KeyInStack;
	}
	bool HasStack()
	{
		return MyStack != nullptr;
	}
};

class FakeFactorStack : public NFactorStack
{
public:
	FakeFactorStack(FName _Name, TSharedPtr<NTimeline> _Timeline) : NFactorStack(_Name, _Timeline) {}
	virtual NFactorState* GetCurrentState() override
	{
		NFactorState* State = new NFactorState(0.f);
		AddFactorsToState(State);
		return State;
	}
};

class NansFactorsFactoryCoreResetOperatorTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		Timeline = new NTimeline(new MockTimelineManager());
		FactorStack = new FakeFactorStack(FName("Dialog"), MakeShareable(Timeline));

		FactorStack->AddFactor(MakeShareable(new NFactor(2, new NAddOperator(), 0, FName("reason1"))));
		FactorStack->AddFactor(MakeShareable(new NFactor(3, new NAddOperator(), 0, FName("reason2"))));
	}

	void TearDown() override
	{
		FactorStack->Reset();
	}

	FakeFactorStack* FactorStack;
	NTimeline* Timeline;
};

TEST_F(NansFactorsFactoryCoreResetOperatorTest, ShouldCheckIfIsAnOperatorWithStackOrNot)
{
	// Some factors to be reset
	FakeResetOperator* Operator = new FakeResetOperator();
	EXPECT_EQ(Operator->GetName(), NResetOperator::Name);
	EXPECT_FALSE(OperatorUtils::IsOperatorWithStack(new NNullOperator()));
	EXPECT_TRUE(OperatorUtils::IsOperatorWithStack(Operator));
}

TEST_F(NansFactorsFactoryCoreResetOperatorTest, ShouldTriggerAnErrorIfTryingToSetAKeyBeforeHavingAStack)
{
	// Some factors to be reset
	FakeResetOperator* Operator = new FakeResetOperator();
	try
	{
		Operator->SetKeyInStack(0);
		EXPECT_TRUE(false);
	}
	catch (const TCHAR* e)
	{
		EXPECT_STREQ(TCHAR_TO_ANSI(e), "MyStack != nullptr");
	}
}

TEST_F(NansFactorsFactoryCoreResetOperatorTest, ShouldResetTheLastFactorSetInTheStack)
{
	// Some factors to be reset
	FakeResetOperator* Operator = new FakeResetOperator();

	FactorStack->AddFactor(MakeShareable(new NFactor(1, Operator, 0, FName("Magic potion"))));
	EXPECT_EQ(FactorStack->GetCurrentState()->Compute(), 2.f);
	EXPECT_TRUE(Operator->HasStack());
	EXPECT_TRUE(Operator->GetKeyInStack() > 0);
	EXPECT_TRUE(FactorStack->HasFlag(FakeResetOperator::GetResetIdFlag(FactorStack->GetFactor(1))));
}

TEST_F(NansFactorsFactoryCoreResetOperatorTest, ShouldResetTheFirstFactorSetInTheStack)
{
	// Some factors to be reset
	FakeResetOperator* Operator = new FakeResetOperator();

	FactorStack->AddFactor(MakeShareable(new NFactor(2, Operator, 0, FName("Magic potion"))));

	EXPECT_EQ(FactorStack->GetCurrentState()->Compute(), 3.f);
	EXPECT_TRUE(FactorStack->HasFlag(FakeResetOperator::GetResetIdFlag(FactorStack->GetFactor(0))));
}

TEST_F(NansFactorsFactoryCoreResetOperatorTest, ShouldResetTheFirstAndLastFactorSetInTheStack)
{
	// Some factors to be reset
	FakeResetOperator* Operator = new FakeResetOperator();

	FactorStack->AddFactor(MakeShareable(new NFactor(1, Operator, 0, FName("Magic potion"))));
	FactorStack->AddFactor(MakeShareable(new NFactor(2, Operator, 0, FName("Magic potion"))));

	EXPECT_EQ(FactorStack->GetCurrentState()->Compute(), 0.f);
	EXPECT_TRUE(FactorStack->HasFlag(FakeResetOperator::GetResetIdFlag(FactorStack->GetFactor(0))));
	EXPECT_TRUE(FactorStack->HasFlag(FakeResetOperator::GetResetIdFlag(FactorStack->GetFactor(1))));
}
