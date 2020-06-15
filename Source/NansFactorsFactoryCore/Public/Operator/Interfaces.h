#pragma once

#include "CoreMinimal.h"

class NFactorInterface;
class NFactorUnitInterface;

class NANSFACTORSFACTORYCORE_API NFactorOperatorInterface
{
public:
	virtual float Compute(float Lh, float Rh) = 0;
	virtual TSharedPtr<NFactorOperatorInterface> GetInverse() = 0;
	virtual const FName GetName() = 0;
};

class NANSFACTORSFACTORYCORE_API NFactorOperatorWithFactorInterface
{
public:
	virtual void SetFactor(NFactorInterface* Factor) = 0;
	virtual void SetKeyInFactor(uint32 Key) = 0;
};

class NANSFACTORSFACTORYCORE_API NFactorOperatorBreakerInterface
{
public:
	virtual bool IsBreaking() = 0;
};

class NANSFACTORSFACTORYCORE_API NFactorOperatorStopperInterface
{
};

class NANSFACTORSFACTORYCORE_API NFactorOperatorPersistentInterface
{
public:
	virtual float Compute(float Lh, float Rh, TSharedPtr<NFactorUnitInterface> ActualUnit) = 0;
};

class NOperatorUtils
{
public:
	template <typename T>
	static bool IsOperatorWithFactor(T Operator)
	{
		return dynamic_cast<NFactorOperatorWithFactorInterface*>(Operator) != nullptr;
	}
};
