#include "DifficultyStack.h"

#include "Difficulty.h"
#include "DifficultyState.h"
#include "NansCommon/Public/Misc/NansAssertionMacros.h"
#include "Operator/Interfaces.h"

UNDifficultyStack::~UNDifficultyStack()
{
    Reset();
}

void UNDifficultyStack::Reset()
{
    Name = NAME_None;
    IterationFlags.Empty();
    Difficulties.Empty();
    Time = 0.f;
}

UNDifficultyStack* UNDifficultyStack::Initialize(FName _Name)
{
    Name = _Name;
    return this;
}

FName UNDifficultyStack::GetName() const
{
    mycheck(Name != NAME_None);
    return Name;
}

float UNDifficultyStack::GetTime() const
{
    mycheck(Name != NAME_None);
    return Time;
}

UNDifficulty* UNDifficultyStack::GetDifficulty(int32 Key) const
{
    mycheck(Name != NAME_None);
    mycheck(Difficulties.IsValidIndex(Key));
    return Difficulties[Key];
}

void UNDifficultyStack::AddDifficulty(UNDifficulty* Difficulty)
{
    mycheck(Name != NAME_None);
    Difficulties.Add(Difficulty);
}

bool UNDifficultyStack::GetFlag(FString Flag) const
{
    mycheck(Name != NAME_None);
    mycheck(IterationFlags.Contains(Flag));
    return IterationFlags[Flag];
}

void UNDifficultyStack::SetFlag(FString Flag, bool value)
{
    mycheck(Name != NAME_None);
    IterationFlags.Add(Flag, value);
}

void UNDifficultyStack::AddTime(float _Time)
{
    mycheck(Name != NAME_None);
    Time += _Time;
    for (auto Diff : Difficulties)
    {
        Diff->AddTime(_Time);
    }
}

UNDifficultyState* UNDifficultyStack::GetCurrentState()
{
    mycheck(Name != NAME_None);
    UNDifficultyState* State = NewObject<UNDifficultyState>()->Initialize(GetTime());
    State->bDebug = bDebug;
    // Need to reset it, values should depend on iteration scope
    IterationFlags.Empty();

    for (int32 Index = 0; Index != Difficulties.Num(); ++Index)
    {
        UNDifficulty* Diff = Difficulties[Index];
        IDifficultyOperatorWithStack* Operator = Cast<IDifficultyOperatorWithStack>(Diff->GetOperator());
        if (Operator)
        {
            Operator->SetStack(this);
            Operator->SetKeyInStack(Index);
        }
        State->AddDifficulty(Diff);
    }

    return State;
}