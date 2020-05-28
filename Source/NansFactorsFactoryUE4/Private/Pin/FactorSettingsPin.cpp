#include "Pin/FactorSettingsPin.h"

#include "EdGraph/EdGraphPin.h"
#include "EdGraph/EdGraphSchema.h"
#include "SNameComboBox.h"
#include "ScopedTransaction.h"
#include "Settings/FactorSettings.h"

void SNFactorSettingsPin::Construct(const FArguments& InArgs, UEdGraphPin* InGraphPinObj)
{
	SGraphPin::Construct(SGraphPin::FArguments(), InGraphPinObj);
}

TSharedRef<SWidget> SNFactorSettingsPin::GetDefaultValueWidget()
{
	TArray<FNFactorSettings> Settings;
	UFactorSettings::GetConfigs(Settings);
	for (const auto& Setting : Settings)
	{
		CategoryList.Add(MakeShareable(new FName(Setting.Name)));
	}

	Settings.Empty();

	TSharedPtr<FName> InitialSelectedName = GetSelectedName();

	// if no data selected, save the first one
	// Note: Null val is possible if no configured timelines have been created.
	if (!InitialSelectedName.IsValid() && CategoryList.Num() > 0 && CategoryList[0].IsValid())
	{
		InitialSelectedName = CategoryList[0];
		SetPropertyWithName(*InitialSelectedName);
		InitialSelectedName = GetSelectedName();
	}

	return SAssignNew(NameComboBox, SNameComboBox)	  // note you can display any widget here
		.ContentPadding(FMargin(6.0f, 2.0f))
		.OptionsSource(&CategoryList)
		.InitiallySelectedItem(InitialSelectedName)
		.OnComboBoxOpening(this, &SNFactorSettingsPin::OnComboBoxOpening)
		.OnSelectionChanged(this, &SNFactorSettingsPin::OnAttributeSelected);
}
void SNFactorSettingsPin::OnAttributeSelected(TSharedPtr<FName> ItemSelected, ESelectInfo::Type SelectInfo)
{
	if (ItemSelected.IsValid())
	{
		SetPropertyWithName(*ItemSelected);
	}
}

void SNFactorSettingsPin::OnComboBoxOpening()
{
	TSharedPtr<FName> SelectedName = GetSelectedName();
	if (SelectedName.IsValid())
	{
		check(NameComboBox.IsValid());
		NameComboBox->SetSelectedItem(SelectedName);
	}
}

void SNFactorSettingsPin::SetPropertyWithName(const FName& Name)
{
	check(GraphPinObj);
	check(GraphPinObj->PinType.PinSubCategoryObject == FFactorStackAttribute::StaticStruct());

	// To set the property we need to use a FString
	// using this format: (MyPropertyName="My Value")
	FString PinString = TEXT("(Name=\"");
	PinString += *Name.ToString();
	PinString += TEXT("\")");

	FString CurrentDefaultValue = GraphPinObj->GetDefaultAsString();

	if (CurrentDefaultValue != PinString)
	{
		const FScopedTransaction Transaction(
			NSLOCTEXT("GraphEditor", "ChangeFactorSettingsPinValue", "Change Factor Settings Pin Value"));
		GraphPinObj->Modify();

		if (PinString != GraphPinObj->GetDefaultAsString())
		{
			GraphPinObj->GetSchema()->TrySetDefaultValue(*GraphPinObj, PinString);
		}
	}
}

TSharedPtr<FName> SNFactorSettingsPin::GetSelectedName() const
{
	int32 NameCount = CategoryList.Num();
	if (NameCount <= 0)
	{
		return NULL;
	}

	FName Name;
	GetPropertyAsName(Name);

	for (int32 NameIndex = 0; NameIndex < NameCount; ++NameIndex)
	{
		if (Name == *CategoryList[NameIndex].Get())
		{
			return CategoryList[NameIndex];
		}
	}

	return NULL;
}

void SNFactorSettingsPin::GetPropertyAsName(FName& OutName) const
{
	check(GraphPinObj);
	check(GraphPinObj->PinType.PinSubCategoryObject == FFactorStackAttribute::StaticStruct());

	// As we saw in the SNFactorSettingsPin::SetPropertyWithName()
	// The value is saved in the format (MyPropertyName="My Value") as a FString.
	// So we have to retrieve the real value and convert it to a FName
	FString PinString = GraphPinObj->GetDefaultAsString();

	if (PinString.StartsWith(TEXT("(")) && PinString.EndsWith(TEXT(")")))
	{
		PinString = PinString.LeftChop(1);
		PinString = PinString.RightChop(1);
		PinString.Split("=", NULL, &PinString);

		if (PinString.StartsWith(TEXT("\"")) && PinString.EndsWith(TEXT("\"")))
		{
			PinString = PinString.LeftChop(1);
			PinString = PinString.RightChop(1);
		}
	}

	if (!PinString.IsEmpty())
	{
		OutName = *PinString;
	}
}
