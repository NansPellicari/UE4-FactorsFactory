
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

FNFactorAttributeCustomization::FNFactorAttributeCustomization()
{
	UFactorSettings::GetFactorNames(FactorsList);
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

	TSharedPtr<FName> InitialSelectedName;

	for (int32 Index = 0; Index < FactorsList.Num(); ++Index)
	{
		if (NameSelected == *FactorsList[Index].Get())
		{
			InitialSelectedName = FactorsList[Index];
		}
	}

	OnAttributeSelected(InitialSelectedName, ESelectInfo::Direct);

	// @formatter:off
	HeaderRow.NameContent()
	[
		StructPropertyHandle->CreatePropertyNameWidget()
	]
	.ValueContent()
	[
		SAssignNew(NameComboBox, SNameComboBox)	   // note you can display any widget here
		.ContentPadding(FMargin(6.0f, 2.0f))
		.OptionsSource(&FactorsList)
		.InitiallySelectedItem(InitialSelectedName)
		.OnSelectionChanged(this, &FNFactorAttributeCustomization::OnAttributeSelected)
	];
	// @formatter:on
}

void FNFactorAttributeCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle,
	class IDetailChildrenBuilder& StructBuilder,
	IPropertyTypeCustomizationUtils& StructCustomizationUtils)
{
}
void FNFactorAttributeCustomization::OnAttributeSelected(TSharedPtr<FName> Selection, ESelectInfo::Type SelectInfo)
{
	if (NameProperty.IsValid() && Selection.IsValid())
	{
		FPropertyAccess::Result Result = NameProperty->SetValueFromFormattedString(Selection->ToString());
	}
}

#undef LOCTEXT_NAMESPACE
