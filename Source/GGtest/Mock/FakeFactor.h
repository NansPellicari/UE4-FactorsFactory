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

#pragma once

#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"
#include "NansFactorsFactoryCore/Public/FactorUnitInterface.h"
#include "NansTimelineSystemCore/Public/Timeline.h"
#include "gmock/gmock.h"

class FakeFactor : public NFactor
{
public:
	FakeFactor(FName _Name, TSharedPtr<NTimeline> _Timeline) : NFactor(_Name, _Timeline) {}
	virtual void SupplyStateWithCurrentData(NFactorStateInterface& State) override
	{
		State.SetTime(0.f);
		State.Clear();
		IterationFlags.Empty();
		AddFactorsToState(State);
	}
};
