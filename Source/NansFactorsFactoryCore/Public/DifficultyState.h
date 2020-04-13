#pragma once

#include "CoreMinimal.h"

class IDifficultyOperator;
class INDifficultyInterface;
class NNullOperator;

struct FNDifficultyStateOperator
{
    FNDifficultyStateOperator();
    FNDifficultyStateOperator(const INDifficultyInterface* Difficulty);

    float Value = 0.f;
    FName Reason = FName("");
    bool Activate = true;
    IDifficultyOperator* Operator;
    // TODO create  Serialize method which save Value + Operator class and value
};

class NANSFACTORSFACTORYCORE_API NDifficultyState
{
public:
    virtual ~NDifficultyState() {}
    NDifficultyState() {}
    NDifficultyState(float _Time);
    virtual void AddDifficulty(const INDifficultyInterface* Difficulty);
    float GetTime() const;
    virtual float Compute();
    bool bDebug = false;
    const TArray<FNDifficultyStateOperator> GetOperators() const;
    // TODO create a Serialize method which save Time + DifficultyValue +  Operators

protected:
    TArray<FNDifficultyStateOperator> Operators;

private:
    // Difficulty 0 means no difficulty
    float DifficultyValue = 0.f;
    // This value means it has not been initiliazed
    float Time = -1.f;
};
