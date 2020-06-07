#include "NullFactor.h"

#include "FactorEvent.h"
#include "NansTimelineSystemCore/public/EventInterface.h"
#include "Operator/Interfaces.h"

NNullFactor::NNullFactor() {}
NNullFactor::~NNullFactor() {}
bool NNullFactor::IsActivated() const
{
	return false;
}
TSharedPtr<FactorOperatorInterface> NNullFactor::GetOperator() const
{
	return nullptr;
}
void NNullFactor::SetOperator(TSharedPtr<FactorOperatorInterface> _Operator) {}
float NNullFactor::GetFactorValue() const
{
	return 0.f;
}
void NNullFactor::SetFactorValue(float _Value) {}
FName NNullFactor::GetReason() const
{
	return NAME_None;
}
const FString NNullFactor::GetUID() const
{
	static const FString ID = "";
	return ID;
}
TSharedPtr<NEventInterface> NNullFactor::GetEvent()
{
	return nullptr;
}
