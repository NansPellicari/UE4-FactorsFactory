// Copyright 2020-present Nans Pellicari (nans.pellicari@gmail.com).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "CoreMinimal.h"
#include "FactorUnit/FactorUnitView.h"
#include "NansCoreHelpers/Public/Misc/NansAssertionMacros.h"
#include "NansFactorsFactoryCore/Public/FactorUnitInterface.h"

class UNFactorDecorator;

class NANSFACTORSFACTORYUE4_API NUnrealFactorUnitProxy : public NFactorUnitInterface
{
public:
	UNFactorUnitView* FactorUnit;
	virtual ~NUnrealFactorUnitProxy() {}
	// TODO make this protected and UNFactorDecorator as friend?
	NUnrealFactorUnitProxy() {}
	NUnrealFactorUnitProxy(UNFactorUnitView* _FactorUnit);
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() override;
	virtual void SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator) override;
	virtual float GetFactorUnitValue() const override;
	virtual void SetFactorUnitValue(float _Value) override;
	virtual FName GetReason() const override;
	virtual bool IsActivated() const override;
	virtual const FString GetUID() const override;
	virtual void Activate(bool _bIsActivated) override;
	virtual TSharedPtr<NEventInterface> GetEvent() override;
	virtual void PreDelete() override;
	void ArchiveWithFactor(FArchive& Ar, UNFactorDecorator* Factor);
	virtual void Archive(FArchive& Ar) override;

private:
	FString FactorUnitClassName;
	FString UID;
	FString OperatorProviderClassName;
};
