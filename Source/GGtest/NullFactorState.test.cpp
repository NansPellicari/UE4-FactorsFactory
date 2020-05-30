#include "CoreMinimal.h"
#include "GoogleTestApp.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/NullFactorState.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "gtest/gtest.h"

#include <iostream>

class NansFactorsFactoryCoreNullFactorTest : public ::testing::Test
{
protected:
};

TEST_F(NansFactorsFactoryCoreNullFactorTest, ShouldDoNothing)
{
	NNullFactorState* FactorState = new NNullFactorState();
	EXPECT_EQ(FactorState->Compute(), 0);
	FactorState->AddFactor(MakeShareable(new NFactor(2.f, new NAddOperator(), 0, FName("Exhausted"))));
	EXPECT_EQ(FactorState->Compute(), 0);
}
