#include "CoreMinimal.h"
#include "GoogleTestApp.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "gtest/gtest.h"

class NansFactorsFactoryCoreFactorTest : public ::testing::Test
{
protected:
};

TEST_F(NansFactorsFactoryCoreFactorTest, EachNewFactorShouldHaveAFactorerentUUID)
{
	TMap<uint32, NFactor*> Factors;
	for (int I = 0; I < 500; ++I)
	{
		NFactor* Factor = new NFactor(1.f, new NNullOperator(), 0, FName("Reason"));
		// A TMap as unique key compare to TMultiMap
		Factors.Add(Factor->GetUID(), Factor);
	}
	EXPECT_EQ(Factors.Num(), 500);
	Factors.Empty();
}

TEST_F(NansFactorsFactoryCoreFactorTest, ShouldBeAlwaysActivateIfItHasAnUndeterminatedDuration)
{
	NFactor* Factor = new NFactor(1.f, new NNullOperator(), 0, FName("Reason"));
	EXPECT_TRUE(Factor->IsActivated());
	Factor->GetEvent()->NotifyAddTime(1000);
	EXPECT_TRUE(Factor->IsActivated());
	EXPECT_EQ(Factor->GetReason(), FName("Reason"));
}

TEST_F(NansFactorsFactoryCoreFactorTest, CanBeDeactivate)
{
	NFactor* Factor = new NFactor(1.f, new NNullOperator(), 0, FName("Reason"));
	EXPECT_TRUE(Factor->IsActivated());
	Factor->GetEvent()->NotifyAddTime(1000.f);
	EXPECT_TRUE(Factor->IsActivated());
	Factor->Activate(false);
	EXPECT_FALSE(Factor->IsActivated());
	EXPECT_FALSE(Factor->GetEvent()->IsExpired());
}

TEST_F(NansFactorsFactoryCoreFactorTest, ShouldBeDeactivateWhenItsDurationTimeIsReachedAndReturnANullOperator)
{
	NAddOperator* Operator = new NAddOperator();
	NFactor* Factor = new NFactor(1.f, Operator, 2.f, FName("Reason"));
	EXPECT_TRUE(Factor->IsActivated());
	EXPECT_EQ(Factor->GetOperator(), Operator);
	EXPECT_EQ(Factor->GetFactorValue(), 1.f);
	Factor->GetEvent()->NotifyAddTime(2.1f);
	EXPECT_TRUE(Factor->GetEvent()->IsExpired());
	EXPECT_FALSE(Factor->IsActivated());
	EXPECT_NE(Factor->GetOperator(), Operator);
	EXPECT_EQ(Factor->GetFactorValue(), 0);
	EXPECT_NE(static_cast<NNullOperator*>(Factor->GetOperator()), nullptr);
}