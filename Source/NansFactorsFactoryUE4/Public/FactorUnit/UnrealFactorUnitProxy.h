#pragma once

#include "CoreMinimal.h"
#include "FactorUnit/FactorUnitAdapter.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/FactorUnitInterface.h"

class NANSFACTORSFACTORYUE4_API NUnrealFactorUnitProxy : public NFactorUnitInterface
{
public:
	UNFactorUnitAdapter* FactorUnit;
	NUnrealFactorUnitProxy(UNFactorUnitAdapter* _FactorUnit) : FactorUnit(_FactorUnit) {}
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() const override;
	virtual void SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator) override;
	virtual float GetFactorUnitValue() const override;
	virtual void SetFactorUnitValue(float _Value) override;
	virtual FName GetReason() const override;
	virtual bool IsActivated() const override;
	virtual const FString GetUID() const override;
	virtual TSharedPtr<NEventInterface> GetEvent() override;
	virtual UNFactorUnitAdapter* GetUnrealObject();
};
