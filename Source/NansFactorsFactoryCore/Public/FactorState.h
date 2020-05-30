#pragma once

#include "CoreMinimal.h"
#include "FactorStateInterface.h"

class FactorOperatorInterface;
class NFactorInterface;
class NNullOperator;

class NANSFACTORSFACTORYCORE_API NFactorState : public NFactorStateInterface
{
public:
	bool bDebug = false;
	virtual ~NFactorState() {}
	NFactorState() {}
	NFactorState(float _Time);
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) override;
	virtual float GetTime() const override;
	virtual float Compute() override;
	virtual void Debug(bool _bDebug) override;
	virtual const TArray<FNFactorStateOperator> GetOperators() const override;
	// TODO create a Serialize method which save Time + FactorValue +  Operators

protected:
	TArray<FNFactorStateOperator> Operators;

private:
	// Factor 0 means no factor
	float FactorValue = 0.f;
	// This value means it has not been initiliazed
	float Time = -1.f;
};
