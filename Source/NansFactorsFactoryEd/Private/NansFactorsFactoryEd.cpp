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

#include "NansFactorsFactoryEd.h"

#include "Modules/ModuleManager.h"
#include "Pin/FactorSettingsPinFactory.h"
#include "PropertyEditor/Public/PropertyEditorModule.h"

#define LOCTEXT_NAMESPACE "NansFactorsFactoryEdModule"

void FNansFactorsFactoryEdModule::StartupModule()
{
	// create your factory and shared pointer to it.
	FactorSettingsPinFactory = MakeShareable(new FNFactorSettingsPinFactory());
	// and now register it.
	FEdGraphUtilities::RegisterVisualPinFactory(FactorSettingsPinFactory);

	FPropertyEditorModule& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

	// Custom properties
	PropertyModule.RegisterCustomPropertyTypeLayout(
		"FactorAttribute", FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FNFactorAttributeCustomization::MakeInstance));
}

void FNansFactorsFactoryEdModule::ShutdownModule()
{
	FEdGraphUtilities::UnregisterVisualPinFactory(FactorSettingsPinFactory);
	if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
	{
		// unregister properties
		FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyModule.UnregisterCustomPropertyTypeLayout("FactorAttribute");
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FNansFactorsFactoryEdModule, NansFactorsFactoryEd)
