#pragma once

#include "CoreMinimal.h"

class NFactorInterface;

class NFactorOperatorInterface
{
public:
	virtual float Compute(float Lh, float Rh) = 0;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() = 0;
	virtual const FName GetName() = 0;
};

class NFactorOperatorInterfaceWithFactor
{
public:
	virtual void SetFactor(NFactorInterface* Factor) = 0;
	virtual void SetKeyInFactor(uint32 Key) = 0;
};

class OperatorUtils
{
public:
	template <typename T>
	static bool IsOperatorWithFactor(T Operator)
	{
		return dynamic_cast<NFactorOperatorInterfaceWithFactor*>(Operator) != nullptr;
	}
};
