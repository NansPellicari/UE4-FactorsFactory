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

#include "CoreMinimal.h"
#include "NansFactorsFactoryCore/Public/FactorStateInterface.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"

class StubFactorState : public NFactorStateInterface
{
public:
	virtual int32 AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit) override
	{
		return -1;
	}
	virtual void SetTime(float _Time) override {}
	virtual float GetTime() const override
	{
		return 0.f;
	}
	virtual float Compute() override
	{
		return 0.f;
	}
	virtual void Clear() override {}
	virtual NFactorStateInterface* Clone() override
	{
		return new StubFactorState(*this);
	}
	virtual void Debug(bool _bDebug) override {}
	virtual const TArray<FNFactorStateOperator> GetOperators() const override
	{
		return {};
	}
};
