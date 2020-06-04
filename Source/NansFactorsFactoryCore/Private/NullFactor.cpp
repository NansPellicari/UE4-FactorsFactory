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
float NNullFactor::GetFactorValue() const
{
	return 0.f;
}
FName NNullFactor::GetReason() const
{
	return NAME_None;
}
uint32 NNullFactor::GetUID() const
{
	return 0;
}
TSharedPtr<NEventInterface> NNullFactor::GetEvent()
{
	return nullptr;
}
