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

#include "Stack/UnrealFactorStackProxy.h"

#include "Stack/FactorStackDecorator.h"

void NUnrealFactorStackProxy::Clear()
{
	Stack.Clear();
}
void NUnrealFactorStackProxy::SetName(FName _Name)
{
	Stack.SetName(_Name);
}
FName NUnrealFactorStackProxy::GetName() const
{
	return Stack.GetName();
}

TSharedPtr<NTimelineInterface> NUnrealFactorStackProxy::GetTimeline() const
{
	return Stack.GetTimeline();
}

float NUnrealFactorStackProxy::GetTime() const
{
	return Stack.GetTime();
}
TSharedRef<NFactorInterface> NUnrealFactorStackProxy::GetFactor(uint32 Key) const
{
	return Stack.GetFactor(Key);
}
TArray<TSharedPtr<NFactorInterface>> NUnrealFactorStackProxy::GetFactors() const
{
	return Stack.GetFactors();
}
void NUnrealFactorStackProxy::AddFactor(TSharedPtr<NFactorInterface> Factor)
{
	Stack.AddFactor(Factor);
}
bool NUnrealFactorStackProxy::HasFlag(FString Flag) const
{
	return Stack.HasFlag(Flag);
}
bool NUnrealFactorStackProxy::GetFlag(FString Flag) const
{
	return Stack.GetFlag(Flag);
}
void NUnrealFactorStackProxy::SetFlag(FString Flag, bool Value)
{
	Stack.SetFlag(Flag, Value);
}
void NUnrealFactorStackProxy::Debug(bool _bDebug)
{
	Stack.Debug(_bDebug);
}
void NUnrealFactorStackProxy::SupplyStateWithCurrentData(NFactorStateInterface& State)
{
	Stack.SupplyStateWithCurrentData(State);
}
UNFactorStackDecorator* NUnrealFactorStackProxy::GetUnrealObject() const
{
	return &Stack;
}
