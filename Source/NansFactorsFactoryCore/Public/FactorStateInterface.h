#pragma once

#include "CoreMinimal.h"

class NFactorOperatorInterface;
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
	TSharedPtr<NFactorOperatorInterface> Operator;
};

class NANSFACTORSFACTORYCORE_API NFactorStateInterface
{
public:
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) = 0;
	virtual void SetTime(float _Time) = 0;
	virtual float GetTime() const = 0;
	virtual float Compute() = 0;
	virtual void Clear() = 0;
	virtual NFactorStateInterface* Clone() = 0;
	virtual void Debug(bool _bDebug) = 0;
	virtual const TArray<FNFactorStateOperator> GetOperators() const = 0;
};
