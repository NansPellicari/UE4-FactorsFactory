#pragma once

#include "CoreMinimal.h"
#include "Factor/FactorAdapterAbstract.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/FactorInterface.h"

class NANSFACTORSFACTORYUE4_API UnrealFactorProxy : public NFactorInterface
{
public:
	UNFactorAdapterAbstract* Factor;
	UnrealFactorProxy(UNFactorAdapterAbstract* _Factor) : Factor(_Factor) {}
	virtual TSharedPtr<FactorOperatorInterface> GetOperator() const
	{
		mycheck(Factor != nullptr);
		return Factor->GetOperator();
	}
	virtual float GetFactorValue() const
	{
		mycheck(Factor != nullptr);
		return Factor->GetFactorValue();
	}
	virtual FName GetReason() const
	{
		mycheck(Factor != nullptr);
		return Factor->GetReason();
	}
	virtual bool IsActivated() const
	{
		mycheck(Factor != nullptr);
		return Factor->IsActivated();
	}
	virtual uint32 GetUID() const
	{
		mycheck(Factor != nullptr);
		return Factor->GetUID();
	}
	virtual TSharedPtr<NEventInterface> GetEvent()
	{
		mycheck(Factor != nullptr);
		return Factor->GetEvent();
	}

	virtual UNFactorAdapterAbstract* GetUnrealObject()
	{
		return Factor;
	}
};
