#pragma once

#include "CoreMinimal.h"

class IFactorOperator;
class NFactorInterface;
class NNullOperator;

struct FNFactorStateOperator
{
	FNFactorStateOperator();
	FNFactorStateOperator(TSharedPtr<NFactorInterface> _Factor);

	TSharedPtr<NFactorInterface> Factor;
	float Value = 0.f;
	FName Reason = FName("");
	bool Activate = true;
	IFactorOperator* Operator;
	// TODO create  Serialize method which save Value + Operator class and value
};

class NANSFACTORSFACTORYCORE_API NFactorState
{
public:
	virtual ~NFactorState() {}
	NFactorState() {}
	NFactorState(float _Time);
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor);
	float GetTime() const;
	virtual float Compute();
	bool bDebug = false;
	const TArray<FNFactorStateOperator> GetOperators() const;
	// TODO create a Serialize method which save Time + FactorValue +  Operators

protected:
	TArray<FNFactorStateOperator> Operators;

private:
	// Factor 0 means no factor
	float FactorValue = 0.f;
	// This value means it has not been initiliazed
	float Time = -1.f;
};
