#include "CoreMinimal.h"
#include "GoogleTestApp.h"
#include "Mock/FakeTimelineManager.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/FactorUnit.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <iostream>

class NBreakerOperator final : public NFactorOperatorBase
{
	virtual float Compute(float Lh, float Rh) override
	{
		return 0;
	}
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override
	{
		static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NNullOperator());
		return Operator;
	}
	virtual const FName GetName() override
	{
		return FName("BreakBreakBreak");
	}
	virtual bool IsBreaking() override
	{
		return true;
	};
};
class NStopperOperator final : public NFactorOperatorBase
{
	virtual bool IsStopper() override
	{
		return true;
	}
	virtual float Compute(float Lh, float Rh) override
	{
		return 0;
	}
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override
	{
		static TSharedPtr<NFactorOperatorInterface> Operator = MakeShareable(new NNullOperator());
		return Operator;
	}
	virtual const FName GetName() override
	{
		return FName("Stopper");
	}
};

class NAddPersistentOperator final : public NFactorOperatorBase
{
public:
	NAddPersistentOperator()
	{
		BaseOp = MakeUnique<NAddOperator>();
	}
	virtual ~NAddPersistentOperator() {}
	virtual float Compute(float Lh, float Rh) override
	{
		return BaseOp->Compute(Lh, Rh);
	}
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() override
	{
		return BaseOp->GetInverse();
	}
	static const FName Name;
	virtual const FName GetName() override
	{
		return Name;
	}
	virtual float PersistentCompute(float Lh, float Rh, TSharedPtr<NFactorUnitInterface> ActualUnit) override
	{
		return BaseOp->Compute(Lh, Rh);
	}
	virtual bool IsPersistent() override
	{
		return true;
	}

private:
	TUniquePtr<NAddOperator> BaseOp;
};

const FName NAddPersistentOperator::Name(TEXT("Persistent Add"));

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
	Factor->SetStateFlag("Flag", true);
	NFactorStateInterface* State = new NFactorState();
	Factor->SupplyStateWithCurrentData(*State);
	try
	{
		Factor->GetStateFlag("Flag");
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

TEST_F(NansFactorsFactoryCoreFactorTest, PersitentFactorShouldComputeOverEachNextValidOperator)
{
	Timeline->SetTickInterval(2.f);
	Timeline->NotifyTick();
	Timeline->NotifyTick();
	Factor->AddFactorUnit(
		MakeShareable(new NFactorUnit(1.f, MakeShareable(new NAddPersistentOperator()), 4.f, FName("Persistent Add"))));
	NFactorStateInterface* State = new NFactorState();
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->GetTime(), 4.f);
	EXPECT_EQ(State->Compute(), 5.f);
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(4.f, MakeShareable(new NAddOperator()), 5.f, FName("Exhausted"))));
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->GetTime(), 4.f);
	EXPECT_EQ(State->Compute(), 10.f);
	Timeline->NotifyTick();
	Timeline->NotifyTick();
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->GetTime(), 8.f);
	EXPECT_EQ(State->Compute(), 8.f);
}

TEST_F(NansFactorsFactoryCoreFactorTest, ABreakerShouldStopNewUnitCalculation)
{
	Timeline->SetTickInterval(1.f);
	Timeline->NotifyTick();
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(2.f, MakeShareable(new NBreakerOperator()), 2, FName("Breaker"))));
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(2.f, MakeShareable(new NAddOperator()), 0, FName("Add not Added"))));
	NFactorStateInterface* State = new NFactorState();
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->GetTime(), 1.f);
	EXPECT_EQ(State->Compute(), 0.f);
	Timeline->NotifyTick();
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->Compute(), 0.f);
	Timeline->NotifyTick();
	// should take count of new Unit when the breaker expires
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->GetTime(), 3.f);
	EXPECT_EQ(State->Compute(), 6.f);
}

TEST_F(NansFactorsFactoryCoreFactorTest, AStopperShouldStopAddingUnit)
{
	Timeline->SetTickInterval(1.f);
	Timeline->NotifyTick();
	TSharedPtr<NFactorUnit> Stopper =
		MakeShareable(new NFactorUnit(0, MakeShareable(new NStopperOperator()), 2, FName("Stopper"), 1.f));
	Factor->AddFactorUnit(Stopper);
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(2.f, MakeShareable(new NAddOperator()), 1, FName("Add should be Added"))));
	NFactorStateInterface* State = new NFactorState();
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->GetTime(), 1.f);
	EXPECT_EQ(State->Compute(), 7.f);

	Timeline->NotifyTick();	   // Stopper start here
	EXPECT_EQ(Stopper->GetEvent()->GetStartedAt(), 2.f);
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(2.f, MakeShareable(new NAddOperator()), 0, FName("Add not Added"))));
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->GetTime(), 2.f);
	EXPECT_EQ(State->Compute(), 0.f);
	Timeline->NotifyTick();
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->GetTime(), 3.f);
	EXPECT_EQ(State->Compute(), 0.f);
	Timeline->NotifyTick();
	Timeline->NotifyTick();
	// the new unit should not be added at all,
	// computation should take only previous Unit in count when the stopper expires
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->GetTime(), 5.f);
	EXPECT_EQ(State->Compute(), 4.f);
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

TEST_F(NansFactorsFactoryCoreFactorTest, ShouldHaveSeveralTimeTheSameFlag)
{
	Factor->SetName(FName("Test flag"));
	Factor->AddFlag(ENFactorFlag::CanNotAddNewUnit);
	Factor->AddFlag(ENFactorFlag::CanNotAddNewUnit);
	EXPECT_TRUE(Factor->HasFlag(ENFactorFlag::CanNotAddNewUnit));
	Factor->RemoveFlag(ENFactorFlag::CanNotAddNewUnit);
	EXPECT_TRUE(Factor->HasFlag(ENFactorFlag::CanNotAddNewUnit));
	Factor->RemoveFlag(ENFactorFlag::CanNotAddNewUnit);
	EXPECT_FALSE(Factor->HasFlag(ENFactorFlag::CanNotAddNewUnit));
}
