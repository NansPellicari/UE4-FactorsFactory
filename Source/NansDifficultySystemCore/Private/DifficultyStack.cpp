#include "DifficultyStack.h"

#include "DifficultyInterface.h"
#include "DifficultyState.h"
#include "NansCommon/Public/Misc/NansAssertionMacros.h"
#include "Operator/Interfaces.h"

#include <typeinfo>

NDifficultyStack::~NDifficultyStack()
{
    Reset();
}

void NDifficultyStack::Reset()
{
    Name = NAME_None;
    IterationFlags.Empty();
    Difficulties.Empty();
    Time = 0.f;
}

NDifficultyStack::NDifficultyStack(FName _Name)
{
    Name = _Name;
}

FName NDifficultyStack::GetName() const
{
    mycheck(Name != NAME_None);
    return Name;
}

void NDifficultyStack::SetName(FName _Name)
{
    Name = _Name;
}

float NDifficultyStack::GetTime() const
{
    mycheck(Name != NAME_None);
    return Time;
}

INDifficultyInterface* NDifficultyStack::GetDifficulty(uint32 Key) const
{
    mycheck(Name != NAME_None);
    mycheck(Difficulties.IsValidIndex(Key));
    return Difficulties[Key];
}

void NDifficultyStack::AddDifficulty(INDifficultyInterface* Difficulty)
{
    mycheck(Name != NAME_None);
    Difficulties.Add(Difficulty);
}

bool NDifficultyStack::HasFlag(FString Flag) const
{
    mycheck(Name != NAME_None);
    return IterationFlags.Contains(Flag);
}

bool NDifficultyStack::GetFlag(FString Flag) const
{
    mycheck(Name != NAME_None);
    mycheck(IterationFlags.Contains(Flag));
    return IterationFlags[Flag];
}

void NDifficultyStack::SetFlag(FString Flag, bool value)
{
    mycheck(Name != NAME_None);
    IterationFlags.Add(Flag, value);
}

void NDifficultyStack::AddTime(float _Time)
{
    mycheck(Name != NAME_None);
    Time += _Time;
    for (auto Diff : Difficulties)
    {
        Diff->AddTime(_Time);
    }
}

void NDifficultyStack::AddDifficultiesToState(NDifficultyState* State)
{
    for (int32 Index = 0; Index != Difficulties.Num(); ++Index)
    {
        INDifficultyInterface* Diff = Difficulties[Index];
        IDifficultyOperatorWithStack* Operator = dynamic_cast<IDifficultyOperatorWithStack*>(Diff->GetOperator());
        if (Operator != nullptr)
        {
            Operator->SetStack(this);
            Operator->SetKeyInStack(Index);
        }
        State->AddDifficulty(Diff);
    }
}

NDifficultyState* NDifficultyStack::GetCurrentState()
{
    mycheckf(Name != NAME_None, TEXT("Should set a name before calling %s"), ANSI_TO_TCHAR(__FUNCTION__));
    NDifficultyState* State = new NDifficultyState(GetTime());
    State->bDebug = bDebug;
    // Need to reset it, values should depend on iteration scope
    IterationFlags.Empty();

    AddDifficultiesToState(State);
    return State;
}