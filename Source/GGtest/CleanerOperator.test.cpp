// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "CoreMinimal.h"
#include "GoogleTestApp.h"
#include "Mock/FakeFactor.h"
#include "Mock/FakeTimelineManager.h"
#include "NansFactorsFactoryCore/Public/FactorUnit.h"
#include "NansFactorsFactoryCore/Public/Operator/CleanerOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "gtest/gtest.h"

#include <iostream>

class NansFactorsFactoryCoreCleanerOperatorTest : public ::testing::Test
{
protected:
	void SetUp() override
	{
		Timeline = MakeShareable(new NTimeline(new FakeTimelineManager()));
		Factor = MakeShareable(new FakeFactor(FName("DifficultyActions"), Timeline));
	}

	void TearDown() override
	{
		Factor.Reset();
	}

	TSharedPtr<FakeFactor> Factor;
	TSharedPtr<NTimeline> Timeline;
};

TEST_F(NansFactorsFactoryCoreCleanerOperatorTest, ShouldCleanEveryPreviousOperators)
{
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(1, MakeShareable(new NAddOperator()), 0, FName("reason1"))));
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(2, MakeShareable(new NAddOperator()), 0, FName("reason2"))));
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(3, MakeShareable(new NAddOperator()), 0, FName("reason3"))));
	Timeline->NotifyTick();

	NFactorStateInterface* State = new NFactorState();

	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->Compute(), 6.f);

	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(0, MakeShareable(new NCleanerOperator()), 0, FName("reason4"))));

	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->Compute(), 0.f);
	EXPECT_EQ(Factor->GetFactors().Num(), 4.f);

	Timeline->NotifyTick();
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->Compute(), 0.f);
	EXPECT_EQ(Factor->GetFactors().Num(), 1.f);
}

TEST_F(NansFactorsFactoryCoreCleanerOperatorTest, ShouldCleanEveryPreviousReducersOperators)
{
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(1, MakeShareable(new NAddOperator()), 0, FName("reason1"))));
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(2, MakeShareable(new NSubtractOperator()), 0, FName("reason2"))));
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(3, MakeShareable(new NAddOperator()), 0, FName("reason3"))));
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(4, MakeShareable(new NSubtractOperator()), 0, FName("reason2"))));
	Timeline->NotifyTick();

	NFactorStateInterface* State = new NFactorState();

	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->Compute(), -2.f);

	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(0, MakeShareable(new NReducersCleanerOperator()), 0, FName("reason4"))));

	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->Compute(), 4.f);
	EXPECT_EQ(Factor->GetFactors().Num(), 5.f);

	Timeline->NotifyTick();
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->Compute(), 4.f);
	EXPECT_EQ(Factor->GetFactors().Num(), 3.f);
}
TEST_F(NansFactorsFactoryCoreCleanerOperatorTest, ShouldCleanEveryPreviousIncreasersOperators)
{
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(1, MakeShareable(new NAddOperator()), 0, FName("reason1"))));
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(2, MakeShareable(new NSubtractOperator()), 0, FName("reason2"))));
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(3, MakeShareable(new NAddOperator()), 0, FName("reason3"))));
	Timeline->NotifyTick();

	NFactorStateInterface* State = new NFactorState();

	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->Compute(), 2.f);

	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(0, MakeShareable(new NIncreasersCleanerOperator()), 0, FName("reason4"))));

	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->Compute(), -2.f);
	EXPECT_EQ(Factor->GetFactors().Num(), 4.f);

	Timeline->NotifyTick();
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->Compute(), -2.f);
	EXPECT_EQ(Factor->GetFactors().Num(), 2.f);
}

TEST_F(NansFactorsFactoryCoreCleanerOperatorTest, ShouldClean3PreviousOrNextIncreasersOperators)
{
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(1, MakeShareable(new NAddOperator()), 0, FName("reason1"))));
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(2, MakeShareable(new NSubtractOperator()), 0, FName("reason2"))));
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(3, MakeShareable(new NAddOperator()), 0, FName("reason3"))));
	Timeline->NotifyTick();

	NFactorStateInterface* State = new NFactorState();

	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->Compute(), 2.f);

	Factor->AddFactorUnit(
		MakeShareable(new NFactorUnit(3, MakeShareable(new NIncreasersCleanerPersistentOperator()), 0, FName("reason4"))));

	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->Compute(), -2.f);
	EXPECT_EQ(Factor->GetFactors().Num(), 4.f);

	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(3, MakeShareable(new NAddOperator()), 0, FName("reason5"))));
	Factor->AddFactorUnit(MakeShareable(new NFactorUnit(3, MakeShareable(new NAddOperator()), 0, FName("reason6"))));

	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->Compute(), -2.f);
	EXPECT_EQ(Factor->GetFactors().Num(), 6.f);

	Timeline->NotifyTick();	   // This should remove all event previously stopped
	Factor->SupplyStateWithCurrentData(*State);
	EXPECT_EQ(State->Compute(), -2.f);
	EXPECT_EQ(Factor->GetFactors().Num(), 2.f);
}
