#pragma once

#include "PropertyEditor/Public/IPropertyTypeCustomization.h"

class IPropertyHandle;
class FDetailWidgetRow;
class SNameComboBox;
struct FNFactorSettings;

/**
 * inspired from Engine\Source\Editor\DetailCustomizations\Private\CollisionProfileNameCustomization.cpp
 */
class FNFactorAttributeCustomization : public IPropertyTypeCustomization
{
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	FNFactorAttributeCustomization();
	/** IPropertyTypeCustomization interface */
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> StructPropertyHandle,
		class FDetailWidgetRow& HeaderRow,
		IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> StructPropertyHandle,
		class IDetailChildrenBuilder& StructBuilder,
		IPropertyTypeCustomizationUtils& StructCustomizationUtils) override;

protected:
	void OnAttributeSelected(TSharedPtr<FName> Selection, ESelectInfo::Type SelectInfo);

private:
	TArray<TSharedPtr<FName>> FactorsList;
	TSharedPtr<IPropertyHandle> NameProperty;
	TSharedPtr<SNameComboBox> NameComboBox;
};
