#pragma once

#include "CoreMinimal.h"
#include "Factor/FactorAdapterAbstract.h"
#include "NansFactorsFactoryCore/Public/FactorInterface.h"

class NANSFACTORSFACTORYUE4_API UnrealFactorProxy : public INFactorInterface
{
public:
	UNFactorAdapterAbstract& Factor;
	UnrealFactorProxy(UNFactorAdapterAbstract& _Factor) : Factor(_Factor) {}
	virtual IFactorOperator* GetOperator() const
	{
		return Factor.GetOperator();
	}
	virtual float GetFactorValue() const
	{
		return Factor.GetFactorValue();
	}
	virtual FName GetReason() const
	{
		return Factor.GetReason();
	}
	virtual bool IsActivated() const
	{
		return Factor.IsActivated();
	}
	virtual uint32 GetUID() const
	{
		return Factor.GetUID();
	}
	virtual TSharedPtr<NEventInterface> GetEvent()
	{
		return Factor.GetEvent();
	}
};
