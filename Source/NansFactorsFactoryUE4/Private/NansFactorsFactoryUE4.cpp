// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "NansFactorsFactoryUE4.h"

#include "Pin/FactorSettingsPinFactory.h"

#define LOCTEXT_NAMESPACE "FNansFactorsFactoryUE4Module"

void FNansFactorsFactoryUE4Module::StartupModule()
{
    // create your factory and shared pointer to it.
    TSharedPtr<FNFactorSettingsPinFactory> Factory = MakeShareable(new FNFactorSettingsPinFactory());
    // and now register it.
    FEdGraphUtilities::RegisterVisualPinFactory(Factory);
}

void FNansFactorsFactoryUE4Module::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FNansFactorsFactoryUE4Module, NansFactorsFactoryUE4)
