#pragma once

#include "CoreMinimal.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"

class NFactorInterface;

class NANSFACTORSFACTORYCORE_API NNullFactorState : public NFactorState
{
public:
	NNullFactorState();
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) override;
	virtual float Compute() override;
};
