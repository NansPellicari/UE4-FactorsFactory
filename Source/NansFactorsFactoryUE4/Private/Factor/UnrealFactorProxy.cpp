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

#include "Factor/UnrealFactorProxy.h"

#include "Factor/FactorDecorator.h"

void NUnrealFactorProxy::Clear()
{
	Factor.Clear();
}
void NUnrealFactorProxy::SetName(FName _Name)
{
	Factor.SetName(_Name);
}
FName NUnrealFactorProxy::GetName() const
{
	return Factor.GetName();
}

TSharedPtr<NTimelineInterface> NUnrealFactorProxy::GetTimeline() const
{
	return Factor.GetTimeline();
}

float NUnrealFactorProxy::GetTime() const
{
	return Factor.GetTime();
}
TSharedPtr<NFactorUnitInterface> NUnrealFactorProxy::GetFactorUnit(uint32 Key) const
{
	return Factor.GetFactorUnit(Key);
}
TArray<TSharedPtr<NFactorUnitInterface>> NUnrealFactorProxy::GetFactors() const
{
	return Factor.GetFactors();
}
int32 NUnrealFactorProxy::AddFactorUnit(TSharedPtr<NFactorUnitInterface> FactorUnit)
{
	return Factor.AddFactorUnit(FactorUnit);
}
bool NUnrealFactorProxy::HasStateFlag(FString Flag) const
{
	return Factor.HasStateFlag(Flag);
}
bool NUnrealFactorProxy::GetStateFlag(FString Flag) const
{
	return Factor.GetStateFlag(Flag);
}
void NUnrealFactorProxy::SetStateFlag(FString Flag, bool Value)
{
	Factor.SetStateFlag(Flag, Value);
}

void NUnrealFactorProxy::RemoveStateFlag(FString Flag)
{
	Factor.RemoveStateFlag(Flag);
}

void NUnrealFactorProxy::AddFlag(ENFactorFlag Flag)
{
	Factor.AddFlag(Flag);
}

bool NUnrealFactorProxy::HasFlag(ENFactorFlag Flag) const
{
	return Factor.HasFlag(Flag);
}

void NUnrealFactorProxy::RemoveFlag(ENFactorFlag Flag)
{
	Factor.RemoveFlag(Flag);
}

void NUnrealFactorProxy::Debug(bool _bDebug)
{
	Factor.Debug(_bDebug);
}
void NUnrealFactorProxy::SupplyStateWithCurrentData(NFactorStateInterface& State)
{
	Factor.SupplyStateWithCurrentData(State);
}
UNFactorDecorator* NUnrealFactorProxy::GetUnrealObject() const
{
	return &Factor;
}
