
#include "Customization/FactorAttributeCustomization.h"

#include "PropertyEditor/Public/DetailLayoutBuilder.h"
#include "PropertyEditor/Public/DetailWidgetRow.h"
#include "PropertyEditor/Public/PropertyHandle.h"
#include "SGraphPin.h"
#include "SNameComboBox.h"
#include "Settings/FactorSettings.h"
#include "SlateBasics.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SWidget.h"

#define LOCTEXT_NAMESPACE "FactorsFactoryEd"

TSharedRef<IPropertyTypeCustomization> FNFactorAttributeCustomization::MakeInstance()
{
	return MakeShareable(new FNFactorAttributeCustomization());
}

void FNFactorAttributeCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle,
	class FDetailWidgetRow& HeaderRow,
	IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
	NameProperty = StructPropertyHandle->GetChildHandle(GET_MEMBER_NAME_CHECKED(FFactorAttribute, Name));

	check(NameProperty.IsValid());

	FString Val;
	NameProperty->GetValueAsDisplayString(Val);
	FName NameSelected = FName(*Val);

	TArray<FNFactorSettings> Settings;
	UFactorSettings::GetConfigs(Settings);
	int32 Index = 0;
	FactorsList.Empty();
	TSharedPtr<FName> InitialSelectedName;

	for (const auto& Setting : Settings)
	{
		FactorsList.Add(MakeShareable(new FName(Setting.Name)));
		if (NameSelected == Setting.Name)
		{
			InitialSelectedName = FactorsList[Index];
		}
		Index++;
	}

	Settings.Empty();

	OnAttributeSelected(MakeShareable(new FName(*Val)), ESelectInfo::Direct);

	HeaderRow.NameContent()[StructPropertyHandle->CreatePropertyNameWidget()]
		.ValueContent()[SAssignNew(NameComboBox, SNameComboBox)	   // note you can display any widget here
							.ContentPadding(FMargin(6.0f, 2.0f))
							.OptionsSource(&FactorsList)
							.InitiallySelectedItem(InitialSelectedName)
							.OnSelectionChanged(this, &FNFactorAttributeCustomization::OnAttributeSelected)];
}

void FNFactorAttributeCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle,
	class IDetailChildrenBuilder& StructBuilder,
	IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
}
void FNFactorAttributeCustomization::OnAttributeSelected(TSharedPtr<FName> Selection, ESelectInfo::Type SelectInfo)
{
	if (NameProperty.IsValid())
	{
		FPropertyAccess::Result Result = NameProperty->SetValueFromFormattedString(Selection->ToString());
	}
}

#undef LOCTEXT_NAMESPACE
