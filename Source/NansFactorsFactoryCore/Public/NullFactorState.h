#pragma once

#include "CoreMinimal.h"
#include "NansFactorsFactoryCore/Public/FactorState.h"

class INFactorInterface;

class NANSFACTORSFACTORYCORE_API NNullFactorState : public NFactorState
{
public:
    NNullFactorState();
    virtual void AddFactor(const INFactorInterface* Factor) override;
    virtual float Compute() override;
};
