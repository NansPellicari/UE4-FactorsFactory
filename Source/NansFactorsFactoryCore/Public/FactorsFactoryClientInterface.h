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

class NFactorInterface;
class NFactorUnitInterface;
class NFactorStateInterface;
class NTimelineInterface;

class NANSFACTORSFACTORYCORE_API NFactorsFactoryClientInterface
{
public:
	virtual void CreateFactor(FName FactorName, TSharedPtr<NTimelineInterface> Timeline) = 0;
	virtual void CreateFactor(TArray<FName> FactorNames, TSharedPtr<NTimelineInterface> Timeline) = 0;
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) = 0;
	virtual void RemoveFactor(FName FactorName) = 0;
	virtual void GetState(FName FactorName, NFactorStateInterface& State) = 0;
	virtual TArray<NFactorStateInterface*> GetStates(TArray<FName> FactorNames, NFactorStateInterface* StateTemplate) = 0;
	virtual void AddFactorUnit(FName FactorName, TSharedPtr<NFactorUnitInterface> FactorUnit) = 0;
	virtual void SetDebug(const TArray<FName> FactorNames, bool bDebug) = 0;
};
