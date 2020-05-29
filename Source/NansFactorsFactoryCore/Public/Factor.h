#pragma once

#include "CoreMinimal.h"
#include "FactorInterface.h"

class IFactorOperator;
class NTimelineEventInterface;

namespace NFactorGUID
{
	static uint32 sNextId = 0;
}

class NANSFACTORSFACTORYCORE_API NFactor : public INFactorInterface
{
public:
	NFactor(float _FactorValue,
		IFactorOperator* _Operator,
		float _Duration,
		FName Reason,
		float _Delay = 0.f,
		TSharedPtr<NTimelineEventInterface> _Event = NULL);
	virtual ~NFactor();
	virtual bool IsActivated() const override;
	virtual IFactorOperator* GetOperator() const override;
	virtual float GetFactorValue() const override;
	virtual FName GetReason() const override;
	virtual uint32 GetUID() const override;
	virtual TSharedPtr<NTimelineEventInterface> GetEvent() override;
	void Activate(bool _bIsActivated);

protected:
	TSharedPtr<NTimelineEventInterface> Event;
	bool bIsActivated = true;
	float FactorValue;
	IFactorOperator* Operator;
	/** TODO use FGuid::NewGuid().ToString() instead */
	uint32 Id;
};
