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
	virtual void SetOperator(TSharedPtr<FactorOperatorInterface> _Operator) override;
	virtual float GetFactorValue() const override;
	virtual void SetFactorValue(float _Value) override;
	virtual FName GetReason() const override;
	virtual bool IsActivated() const override;
	virtual const FString GetUID() const override;
	virtual TSharedPtr<NEventInterface> GetEvent() override;
	virtual UNFactorAdapterAbstract* GetUnrealObject();
};
