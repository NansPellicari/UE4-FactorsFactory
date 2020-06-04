#pragma once

#include "CoreMinimal.h"
#include "NansFactorsFactoryCore/Public/FactorStateInterface.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"

class StubFactorState : public NFactorStateInterface
{
public:
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) override {}
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
