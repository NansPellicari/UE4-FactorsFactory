#pragma once

#include "CoreMinimal.h"
#include "FactorInterface.h"

class IFactorOperator;

namespace NFactorGUID
{
    static uint32 sNextId = 0;
}

class NANSFACTORSFACTORYCORE_API NFactor : public INFactorInterface
{
public:
    NFactor(float _FactorValue, IFactorOperator* _Operator, float _Duration, FName Reason);
    bool IsActivate() const override;
    IFactorOperator* GetOperator() const override;
    float GetFactorValue() const override;
    FName GetReason() const override;
    void AddTime(float Time) override;
    virtual uint32 GetUID() const override;

protected:
    FName Reason;
    float FactorValue;
    IFactorOperator* Operator;
    /** TODO use FGuid::NewGuid().ToString() instead */
    uint32 Id;
    // TODO create a way to set duration depending on different timeline
    // @see https://docs.unrealengine.com/en-US/API/Runtime/Engine/FTimerManager/index.html
    //
    // eg.
    // Should get a timeline which restart when level restart,
    // another is during gameplay only (pause when game in pause or user disconnect)
    // another is as user life, the real time since player began to play
    // ...
    //
    //  In this way we can set mallus or bonus on different way eg.
    // - As a promotionnal event: "Yeah thanks of the st patrick event you have a bonus for making friendship for 2 days !"
    // - In game: User as a vitality mallus cause he talks too much, it is tired so for 2min in game timeline
    //
    // Should be great to create an object "Timeline", link a bilateral connection with a factor
    // When the timeline end or restart, factor are destroy.
    //
    // 0 means infinite
    float Duration = 0.f;

private:
    float DurationSinceActivation = 0.f;
};
