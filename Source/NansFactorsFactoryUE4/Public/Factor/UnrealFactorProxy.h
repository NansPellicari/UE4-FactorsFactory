#pragma once

#include "CoreMinimal.h"
#include "Factor/FactorAdapterAbstract.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/FactorInterface.h"

class NANSFACTORSFACTORYUE4_API NUnrealFactorProxy : public NFactorInterface
{
public:
	UNFactorAdapterAbstract* Factor;
	NUnrealFactorProxy(UNFactorAdapterAbstract* _Factor) : Factor(_Factor) {}
	virtual TSharedPtr<FactorOperatorInterface> GetOperator() const override;
	virtual float GetFactorValue() const override;
	virtual FName GetReason() const override;
	virtual bool IsActivated() const override;
	virtual uint32 GetUID() const override;
	virtual TSharedPtr<NEventInterface> GetEvent() override;
	virtual UNFactorAdapterAbstract* GetUnrealObject();
};
