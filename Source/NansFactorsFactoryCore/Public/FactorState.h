#pragma once

#include "CoreMinimal.h"
#include "FactorStateInterface.h"

class NFactorOperatorInterface;
class NFactorInterface;
class NNullOperator;

class NANSFACTORSFACTORYCORE_API NFactorState : public NFactorStateInterface
{
public:
	bool bDebug = false;
	virtual ~NFactorState() {}
	NFactorState() {}
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) override;
	virtual float GetTime() const override;
	virtual void SetTime(float _Time) override;
	virtual float Compute() override;
	virtual void Clear() override;
	virtual NFactorStateInterface* Clone() override;
	virtual void Debug(bool _bDebug) override;
	virtual const TArray<FNFactorStateOperator> GetOperators() const override;

protected:
	TArray<FNFactorStateOperator> Operators;

private:
	// Factor 0 means no factor
	float FactorValue = 0.f;
	// This value means it has not been initiliazed
	float Time = -1.f;
};
