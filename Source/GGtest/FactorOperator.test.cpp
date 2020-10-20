#include "CoreMinimal.h"
#include "GoogleTestApp.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "gtest/gtest.h"

#include <iostream>

class NansFactorsFactoryCoreOperatorTest : public ::testing::Test
{
protected:
};

TEST_F(NansFactorsFactoryCoreOperatorTest, ShouldComputeWithANullOperator)
{
	NNullOperator* Operator = new NNullOperator();

	EXPECT_EQ(Operator->GetName(), NNullOperator::Name);
	EXPECT_EQ(Operator->Compute(1, 2), 1.f);
	EXPECT_EQ(Operator->Compute(1, 2), Operator->GetInverse()->Compute(1, 5));
}

TEST_F(NansFactorsFactoryCoreOperatorTest, ShouldComputeWithAnAddOperator)
{
	NAddOperator* Operator = new NAddOperator();

	EXPECT_EQ(Operator->GetName(), NAddOperator::Name);
	EXPECT_EQ(Operator->Compute(1, 2), 3.f);
}

TEST_F(NansFactorsFactoryCoreOperatorTest, ShouldComputeWithAnAddOperatorGetInverseReturnedObject)
{
	NAddOperator* Operator = new NAddOperator();
	auto Inverse = Operator->GetInverse();

	EXPECT_NE(Operator, nullptr);
	EXPECT_NE(Inverse, nullptr);
	EXPECT_EQ(Inverse->Compute(1, 2), -1.f);
}

TEST_F(NansFactorsFactoryCoreOperatorTest, ShouldComputeWithASubsctractOperator)
{
	NSubtractOperator* Operator = new NSubtractOperator();

	EXPECT_EQ(Operator->GetName(), NSubtractOperator::Name);
	EXPECT_EQ(Operator->Compute(1, 2), -1.f);
}

TEST_F(NansFactorsFactoryCoreOperatorTest, ShouldComputeWithASubsctractOperatorGetInverseReturnedObject)
{
	NSubtractOperator* Operator = new NSubtractOperator();

	EXPECT_EQ(Operator->GetInverse()->Compute(1, 2), 3.f);
}

TEST_F(NansFactorsFactoryCoreOperatorTest, ShouldComputeWithAMultiplyOperator)
{
	NMultiplyOperator* Operator = new NMultiplyOperator();

	EXPECT_EQ(Operator->GetName(), NMultiplyOperator::Name);
	EXPECT_EQ(Operator->Compute(1, 2), 2.f);
}

TEST_F(NansFactorsFactoryCoreOperatorTest, ShouldComputeWithAMultiplyOperatorGetInverseReturnedObject)
{
	NMultiplyOperator* Operator = new NMultiplyOperator();

	EXPECT_EQ(Operator->GetInverse()->Compute(1, 2), 0.5f);
}

TEST_F(NansFactorsFactoryCoreOperatorTest, ShouldComputeWithADivideOperator)
{
	NDividerOperator* Operator = new NDividerOperator();

	EXPECT_EQ(Operator->GetName(), NDividerOperator::Name);
	EXPECT_EQ(Operator->Compute(1, 2), 0.5f);
}

TEST_F(NansFactorsFactoryCoreOperatorTest, ShouldComputeWithADivideOperatorGetInverseReturnedObject)
{
	NDividerOperator* Operator = new NDividerOperator();

	EXPECT_EQ(Operator->GetInverse()->Compute(1, 2), 2.f);
}
TEST_F(NansFactorsFactoryCoreOperatorTest, ShouldComputeWithMaxOperator)
{
	NMaxOperator* Operator = new NMaxOperator();

	EXPECT_EQ(Operator->Compute(1, 2), 1.f);
	EXPECT_EQ(Operator->Compute(3, 2), 2.f);
}
TEST_F(NansFactorsFactoryCoreOperatorTest, ShouldComputeWithMinOperator)
{
	NMinOperator* Operator = new NMinOperator();

	EXPECT_EQ(Operator->Compute(1, 2), 2.f);
	EXPECT_EQ(Operator->Compute(3, 2), 3.f);
}
