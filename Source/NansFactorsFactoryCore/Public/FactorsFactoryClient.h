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
#include "FactorsFactoryClientInterface.h"

class NFactorInterface;
class NFactorUnitInterface;
class NFactorStateInterface;
class NTimelineInterface;

class NANSFACTORSFACTORYCORE_API NFactorsFactoryClient : public NFactorsFactoryClientInterface
{
public:
	virtual ~NFactorsFactoryClient() {}
	virtual void CreateFactor(const FName& FactorName, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void CreateFactor(TArray<FName> FactorNames, TSharedPtr<NTimelineInterface> Timeline) override;
	virtual void AddFactor(TSharedPtr<NFactorInterface> Factor) override;
	virtual bool HasFactor(const FName& FactorName) const override;
	virtual void RemoveFactor(const FName& FactorName) override;
	virtual void GetState(FName FactorName, NFactorStateInterface& State) override;
	virtual TArray<NFactorStateInterface*> GetStates(TArray<FName> FactorNames, NFactorStateInterface* StateTemplate) override;
	virtual int32 AddFactorUnit(FName FactorName, TSharedPtr<NFactorUnitInterface> FactorUnit) override;
	virtual TSharedPtr<NFactorUnitInterface> GetFactorUnit(FName FactorName, int32 Key) override;
	virtual void SetDebug(const TArray<FName> FactorNames, bool bDebug) override;

protected:
	TMap<FName, TSharedPtr<NFactorInterface>> FactorsList;

private:
};
