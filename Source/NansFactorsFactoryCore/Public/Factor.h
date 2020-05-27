#pragma once

#include "CoreMinimal.h"
#include "FactorInterface.h"

class IFactorOperator;

namespace NFactorGUID
{
	static uint32 sNextId = 0;
}

class NANSFACTORSFACTORYCORE_API NFactor : public INFactorInterface
{
public:
	NFactor(float _FactorValue, IFactorOperator* _Operator, float _Duration, FName Reason, float _Delay = 0.f);
	bool IsActivated() const override;
	IFactorOperator* GetOperator() const override;
	float GetFactorValue() const override;
	FName GetReason() const override;
	virtual uint32 GetUID() const override;
	virtual void AddTime(float Time) override;
	void Activate(bool _bIsActivated);

protected:
	bool bIsActivated = true;
	float FactorValue;
	IFactorOperator* Operator;
	/** TODO use FGuid::NewGuid().ToString() instead */
	uint32 Id;
};
