#pragma once

#include "Attribute/FactorStackAttribute.h"
#include "CoreMinimal.h"
#include "Event/FactorEventDecorator.h"
#include "Event/TimelineEventDecorator.h"
#include "NansFactorsFactoryCore/Public/Factor.h"
#include "NansFactorsFactoryCore/Public/FactorInterface.h"
#include "NansFactorsFactoryCore/Public/Operator/FactorOperator.h"
#include "NansFactorsFactoryCore/Public/Operator/Interfaces.h"
#include "NansTimelineSystemUE4/Public/Event/UnrealTimelineEventProxy.h"
#include "Settings/FactorSettings.h"

#include "FactorAdapterAbstract.generated.h"

UCLASS(Abstract, Blueprintable)
class NANSFACTORSFACTORYUE4_API UNFactorAdapterAbstract : public UObject, public INFactorInterface
{
	GENERATED_BODY()
public:
	UNFactorAdapterAbstract() {}

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
	float FactorValue = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
	float Duration = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
	float Delay = 0.f;

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
	FName Reason = NAME_None;

	UPROPERTY(BlueprintReadWrite, Category = "FactorsFactory|Operation")
	FFactorStackAttribute InStack;

	virtual void Init()
	{
		Event = UNTimelineEventDecoratorFactory::CreateObject<UNFactorEventDecorator>(
			this, UNFactorEventDecorator::StaticClass(), Reason);
		TSharedPtr<NTimelineEventInterface> EventProxy = MakeShareable(new UnrealTimelineEventProxy(*Event));
		Factor = MakeShareable(new NFactor(FactorValue, GetConfiguredOperator(), Duration, Reason, Delay, EventProxy));
	}

	TSharedPtr<NFactor> GetFactor()
	{
		return Factor;
	}

	virtual TSharedPtr<NTimelineEventInterface> GetEvent() override
	{
		return Factor->GetEvent();
	};

	virtual IFactorOperator* GetConfiguredOperator() const
	{
		return new NNullOperator();
	}

	virtual IFactorOperator* GetOperator() const override
	{
		return Factor->GetOperator();
	}

	virtual float GetFactorValue() const override
	{
		return Factor->GetFactorValue();
	}

	virtual FName GetReason() const override
	{
		return Factor->GetReason();
	}

	virtual bool IsActivated() const override
	{
		return Factor->IsActivated();
	}

	virtual uint32 GetUID() const override
	{
		return Factor->GetUID();
	}

protected:
	TSharedPtr<NFactor> Factor;

	UPROPERTY()
	UNFactorEventDecorator* Event;
};
