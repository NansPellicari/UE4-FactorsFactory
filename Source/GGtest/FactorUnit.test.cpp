#include "CoreMinimal.h"
#include "GoogleTestApp.h"
#include "NansFactorsFactoryCore/Public/FactorUnit.h"
#include "NansFactorsFactoryCore/Public/NullFactorUnit.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "gtest/gtest.h"

#include <iostream>

class NansFactorsFactoryCoreFactorUnitTest : public ::testing::Test
{
protected:
};

TEST_F(NansFactorsFactoryCoreFactorUnitTest, EachNewFactorUnitShouldHaveAFactorUniterentUUID)
{
	TMap<FString, NFactorUnit*> Factors;
	for (int I = 0; I < 500; ++I)
	{
		NFactorUnit* FactorUnit = new NFactorUnit(1.f, MakeShareable(new NNullOperator()), 0, FName("Reason"));
		// A TMap as unique key compare to TMultiMap
		Factors.Add(FactorUnit->GetUID(), FactorUnit);
	}
	EXPECT_EQ(Factors.Num(), 500);
	Factors.Empty();
}

TEST_F(NansFactorsFactoryCoreFactorUnitTest, NullFactorUnitShouldAlwaysReturnNullValues)
{
	NNullFactorUnit* FactorUnit = new NNullFactorUnit();
	EXPECT_FALSE(FactorUnit->IsActivated());
	EXPECT_EQ(FactorUnit->GetEvent(), nullptr);
	EXPECT_EQ(FactorUnit->GetReason(), NAME_None);
	EXPECT_EQ(FactorUnit->GetFactorUnitValue(), 0.f);
	FactorUnit->SetFactorUnitValue(10.f);
	EXPECT_EQ(FactorUnit->GetFactorUnitValue(), 0.f);
	EXPECT_EQ(FactorUnit->GetOperator(), nullptr);
	EXPECT_TRUE(FactorUnit->GetUID().IsEmpty());
	FactorUnit->SetOperator(MakeShareable(new NAddOperator()));
	EXPECT_EQ(FactorUnit->GetOperator(), nullptr);
}
TEST_F(NansFactorsFactoryCoreFactorUnitTest, ShouldBeAlwaysActivateIfItHasAnUndeterminatedDuration)
{
	NFactorUnit* FactorUnit = new NFactorUnit(1.f, MakeShareable(new NNullOperator()), 0, FName("Reason"));
	FactorUnit->GetEvent()->Start(0);
	EXPECT_TRUE(FactorUnit->IsActivated());
	FactorUnit->GetEvent()->NotifyAddTime(1000);
	EXPECT_TRUE(FactorUnit->IsActivated());
	EXPECT_EQ(FactorUnit->GetReason(), FName("Reason"));
}

TEST_F(NansFactorsFactoryCoreFactorUnitTest, CanBeDeactivate)
{
	NFactorUnit* FactorUnit = new NFactorUnit(1.f, MakeShareable(new NNullOperator()), 0, FName("Reason"));
	FactorUnit->GetEvent()->Start(0);
	EXPECT_TRUE(FactorUnit->IsActivated());
	FactorUnit->GetEvent()->NotifyAddTime(1000.f);
	EXPECT_TRUE(FactorUnit->IsActivated());
	FactorUnit->Activate(false);
	EXPECT_FALSE(FactorUnit->IsActivated());
	EXPECT_TRUE(FactorUnit->GetEvent()->IsExpired());
}

TEST_F(NansFactorsFactoryCoreFactorUnitTest, ShouldBeDeactivateWhenItsDurationTimeIsReached)
{
	TSharedPtr<NAddOperator> Operator = MakeShareable(new NAddOperator());
	NFactorUnit* FactorUnit = new NFactorUnit(1.f, Operator, 2.f, FName("Reason"));
	FactorUnit->GetEvent()->Start(0);
	EXPECT_TRUE(FactorUnit->IsActivated());
	EXPECT_EQ(FactorUnit->GetOperator().Get(), Operator.Get());
	EXPECT_EQ(FactorUnit->GetFactorUnitValue(), 1.f);
	FactorUnit->GetEvent()->NotifyAddTime(2.1f);
	EXPECT_TRUE(FactorUnit->GetEvent()->IsExpired());
	EXPECT_FALSE(FactorUnit->IsActivated());
}
