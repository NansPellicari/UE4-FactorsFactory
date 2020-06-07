#pragma once

#include "CoreMinimal.h"

class NFactorStackInterface;

class NFactorOperatorInterface
{
public:
	virtual float Compute(float Lh, float Rh) = 0;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() = 0;
	virtual const FName GetName() = 0;
};

class NFactorOperatorInterfaceWithStack
{
public:
	virtual void SetStack(NFactorStackInterface* Stack) = 0;
	virtual void SetKeyInStack(uint32 Key) = 0;
};

class OperatorUtils
{
public:
	template <typename T>
	static bool IsOperatorWithStack(T Operator)
	{
		return dynamic_cast<NFactorOperatorInterfaceWithStack*>(Operator) != nullptr;
	}
};
