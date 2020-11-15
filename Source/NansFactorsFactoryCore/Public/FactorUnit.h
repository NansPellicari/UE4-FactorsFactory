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
#include "FactorUnitInterface.h"

class NFactorOperatorInterface;
class NEventInterface;

namespace NFactorUnitGUID
{
	static uint32 sNextId = 0;
}

class NANSFACTORSFACTORYCORE_API NFactorUnit : public NFactorUnitInterface
{
public:
	NFactorUnit(float _FactorUnitValue,
		TSharedPtr<NFactorOperatorInterface> _Operator,
		float _Duration,
		FName Reason,
		float _Delay = 0.f,
		TSharedPtr<NEventInterface> _Event = NULL);
	NFactorUnit(float _FactorUnitValue, TSharedPtr<NFactorOperatorInterface> _Operator, TSharedPtr<NEventInterface> _Event);
	virtual ~NFactorUnit();
	virtual bool IsActivated() const override;
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() override;
	virtual void SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator) override;
	virtual float GetFactorUnitValue() const override;
	virtual FName GetReason() const override;
	virtual void SetFactorUnitValue(float _Value) override;
	virtual const FString GetUID() const override;
	virtual TSharedPtr<NEventInterface> GetEvent() override;
	virtual void Activate(bool _bIsActivated) override;
	virtual void PreDelete() override;
	virtual void Archive(FArchive& Ar) override;

protected:
	TSharedPtr<NEventInterface> Event;
	bool bIsActivated = true;
	float FactorUnitValue;
	TSharedPtr<NFactorOperatorInterface> Operator;

	/** This is used only for serialization */
	FString UID;
};
