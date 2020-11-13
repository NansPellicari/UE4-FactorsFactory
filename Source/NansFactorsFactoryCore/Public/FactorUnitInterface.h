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
#include "NansTimelineSystemCore/public/Event.h"

class NFactorOperatorInterface;

class NANSFACTORSFACTORYCORE_API NFactorUnitInterface
{
public:
	virtual ~NFactorUnitInterface() {}
	virtual TSharedPtr<NFactorOperatorInterface> GetOperator() const = 0;
	virtual void SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator) = 0;
	virtual float GetFactorUnitValue() const = 0;
	virtual FName GetReason() const = 0;
	virtual void SetFactorUnitValue(float _Value) = 0;
	virtual bool IsActivated() const = 0;
	virtual const FString GetUID() const = 0;
	virtual TSharedPtr<NEventInterface> GetEvent() = 0;
	virtual void Activate(bool _bIsActivated) = 0;
	virtual void PreDelete() = 0;
	virtual void Archive(FArchive& Ar) = 0;
};
