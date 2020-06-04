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

#include "Stack/FactorStackDecorator.h"

#include "NansFactorsFactoryCore/Public/FactorStack.h"
#include "NansFactorsFactoryUE4/Public/Factor/FactorAdapterAbstract.h"
#include "NansFactorsFactoryUE4/Public/Factor/UnrealFactorProxy.h"

void UNFactorStackDecorator::Init(FName _Name, TSharedPtr<NTimelineInterface> _Timeline)
{
	Stack = MakeShareable(new NFactorStack(_Name, _Timeline));
}
void UNFactorStackDecorator::Reset()
{
	Stack->Reset();
}
void UNFactorStackDecorator::SetName(FName _Name)
{
	Stack->SetName(_Name);
}
FName UNFactorStackDecorator::GetName() const
{
	return Stack->GetName();
}
float UNFactorStackDecorator::GetTime() const
{
	return Stack->GetTime();
}
TSharedRef<NFactorInterface> UNFactorStackDecorator::GetFactor(uint32 Key) const
{
	return Stack->GetFactor(Key);
}
TArray<TSharedPtr<NFactorInterface>> UNFactorStackDecorator::GetFactors() const
{
	return Stack->GetFactors();
}
void UNFactorStackDecorator::AddFactor(TSharedPtr<NFactorInterface> Factor)
{
	auto Proxy = dynamic_cast<NUnrealFactorProxy*>(Factor.Get());
	mycheckf(Proxy != nullptr, TEXT("You should passed NUnrealFactorProxy inherited stack only"));
	mycheckf(Proxy->GetUnrealObject() != nullptr,
		TEXT("You should instanciate your stack proxy with a UNFactorAdapterAbstract inherited stack"));

	UEFactors.Add(Proxy->GetUnrealObject());

	Stack->AddFactor(Factor);
}
bool UNFactorStackDecorator::HasFlag(FString Flag) const
{
	return Stack->HasFlag(Flag);
}
bool UNFactorStackDecorator::GetFlag(FString Flag) const
{
	return Stack->GetFlag(Flag);
}
void UNFactorStackDecorator::SetFlag(FString Flag, bool Value)
{
	Stack->SetFlag(Flag, Value);
}
void UNFactorStackDecorator::Debug(bool _bDebug)
{
	Stack->Debug(_bDebug);
}
void UNFactorStackDecorator::SupplyStateWithCurrentData(NFactorStateInterface& State)
{
	Stack->SupplyStateWithCurrentData(State);
}
