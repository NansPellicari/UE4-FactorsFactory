#include "NullFactorUnit.h"

#include "FactorEvent.h"
#include "NansTimelineSystemCore/public/EventInterface.h"
#include "Operator/Interfaces.h"

NNullFactorUnit::NNullFactorUnit() {}
NNullFactorUnit::~NNullFactorUnit() {}
bool NNullFactorUnit::IsActivated() const
{
	return false;
}
TSharedPtr<NFactorOperatorInterface> NNullFactorUnit::GetOperator() const
{
	return nullptr;
}
void NNullFactorUnit::SetOperator(TSharedPtr<NFactorOperatorInterface> _Operator) {}
float NNullFactorUnit::GetFactorUnitValue() const
{
	return 0.f;
}
void NNullFactorUnit::SetFactorUnitValue(float _Value) {}
FName NNullFactorUnit::GetReason() const
{
	return NAME_None;
}
const FString NNullFactorUnit::GetUID() const
{
	static const FString ID = "";
	return ID;
}
TSharedPtr<NEventInterface> NNullFactorUnit::GetEvent()
{
	return nullptr;
}
