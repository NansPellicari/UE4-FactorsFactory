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

#include "Attribute/FactorAttribute.h"
#include "EdGraph/EdGraphPin.h"
#include "EdGraph/EdGraphSchema.h"
#include "EdGraphSchema_K2.h"
#include "EdGraphUtilities.h"
#include "Pin/FactorSettingsPin.h"
#include "SlateBasics.h"

class FNFactorSettingsPinFactory : public FGraphPanelPinFactory
{
	virtual TSharedPtr<class SGraphPin> CreatePin(class UEdGraphPin* InPin) const override
	{
		const UEdGraphSchema_K2* K2Schema = GetDefault<UEdGraphSchema_K2>();
		/*
		 * Check if pin is struct, and then check if that pin is of struct type we want customize
		 */
		if (InPin->PinType.PinCategory == K2Schema->PC_Struct &&
			InPin->PinType.PinSubCategoryObject == FFactorAttribute::StaticStruct())
		{
			return SNew(SNFactorSettingsPin, InPin);	// and return our customized pin widget ;).
		}
		return nullptr;
	}
};
