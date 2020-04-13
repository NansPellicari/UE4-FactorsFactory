# Difficulty System

## Why this repo?

### To get a difficulty system plugins of course!

And here it is! I'm glad you are here and I hope your uses will ease by this documentation.  
I try to create the most documentation as I can to help you using or extending it for your needs, and if it's not clear enough, send me some feedbacks on my [repo](https://github.com/NansPellicari/UE4-NansFactorsFactory), I'll be glad to help you!  

### To see how to use some Unreal libraries

Cool, this is why I made this plugin free!  
At the age of its creation, there was a deep lack of documentation on somes Unreal (very helpfull) libraries.  
I've struggled too much digging on the code, forums, blogs or wikis to not share what I've found for people who planned to struggled too :D !  
Then I hope:
* it'll helps you in your Epic's journey 
* I don't miss too much in code implementations! Otherwise I'll be so glad if you want to help me:

### To help me

#### Github contribution

#### Coffee contribution

## What is it for?

It is designed to add some **factors** (malus or bonus) on skills, ability or whatever, **to the player** depending on events, actors, spawns, or whatever he **meet**.

The difficulty system helps to add/get/reset difficulties **where** and **when** you want and **organized** them.

### Organized?

By that I mean **categorized** them.  
For instance in my game I didn't want to have:
* the **same** difficulty **factor** for an **AIMING** ability and for a **SOCIAL** skill
* the same **timeline** for difficulties: some needs to work during the **level process** (eg "Oh player is drunk, for 1 minutes during the game session he should be affected! :confused: Alcohol ravages..."), others during the **real life timeline** (eg. "Hey bro, thanks to your fidelity, I give you 2 days of bonus on social interactions :kissing_heart:"), etc...  
See below to see possiblities.

So basically a Difficulty is attached to a **Category** (a named STACK as we see below) and also to a **Timeline**.  

> **Be aware of**: When a timeline ends, all attached difficulties will be removed. Be worried if you reference a difficulty (not a recommended behavior BTW).

### When & Where? Ease of use

As a designer and a developper I wanted to:

| Needs | What is my solution |
| -- | -- |
| Create a difficulty in any moment and in every single part of the game (eg. Behavior tree, Blueprint, c++ classes,...) | **1** single **API entry point** saved in the **Game Instance** |
| Don't have to use my brain too much... | **2 mains blueprints nodes** to manage all of this (**adding & getting**), getting a difficulty always return a value (see my considerations [here](./Source/NansFactorsFactoryUE4/Public/DifficultyFactory.h)) |
| Easily extend it later | Simple architecture in isolated plugins, use a bunch of interfaces (more "as if" interface cause of c++ limitation) and a lot of tests/specs (see below or [code](./Source/NansFactorsFactoryCore/Private/Specs/Difficulty.spec.cpp) directly) to avoid regression |

### What is a difficulty?

I like to categorize difficulty in **3 units of work**:

#### 1 - UNIT

This is what designers or developpers want to **add to the player** as a **malus** or a **bonus**.  
Eg.
> 1) Player eat a rotten fruit = **add** a malus of **2** on **ACTION** capacities.  
> 2) Player drink alcohol = **multiply** all difficulty's by **4** **malus** on **SPEECH** and **REFLEXES** capacities.  
> 3) Player make a benevolent action = **add** a bonus of **10** on **SOCIAL** skill.

A difficulty **UNIT** is basically composed of:

| A Reason | A Value | An Operator | A Duration | A Timeline Label |
| -- | -- | -- | -- | -- |
| Is the **Why** this difficulty appears (can be used to send feedback to player, to make some stats,...) | **What** amount/degree of difficulty it is  | **How** the value is computed with previous difficulties in the same category (or stack, see below) | Duration of this difficulty applies (it's use [NullOperator](./Source/NansFactorsFactoryCore/Private/Operator/DifficultyOperator.cpp) after that) | To indicates on which timeline this difficulty lies on |
| **Using last examples:** |
| 1. eat rotten fruit | 2 | Add | 300sec | level |
| 2. drunk | 4 | Multiply | 200sec | level |
| 3. benevolent action | 10 | Substract (the inverse of **adding** a **difficulty**) | 2 days (you can convert in seconds...) | world |

#### 2 - STACK

This represents a **category** of difficulty (eg. **ACTION**, **ELOQUENCE**, **REFLEXE**, **SociaL**, **WhatEver**... you decide). As designer or developper you can create an **infinite list** of categories (stack) add add as many difficulties you want.  
A stack can be created **on the fly**, just in adding a new difficulty.  
Aside of the **categorized ability**, it register every difficulty you've add, so you can use it to:
* sends reports
* gives feedbacks to the player afterwards
* saves on saved games
* or whatever you want.

#### 3 - STATE

This is the **factor** you can play with as a designer or a developer.  
Every time you ask to get a state, you will have a static state of the difficulty amount, reasons list on the asked category(ies) (stack(s)).

## How to install it?

## How should I use?

### As designer


### As developper

#### Implementation details
 
 * there is a [proto in javascript](../JsProto/proto.js) to test quickly the system
 * Core [Class diagram](./Docs/Core/ClassDiagram.md)

## How can I extend it?

### As designer
### As developper

## Bonus
### How to run tests quickly

## Notes

The clang-file as been inspired by this really helpull gist: https://gist.github.com/intinig/9bba3a3faee80250b781bf916a4ab8b7


## Improvements

### > Core testing by Google Test

For my game projects I can use this repo to get GGtests: `git@github.com:NansPellicari/UE4-GoogleTest.git`  
(For procedure see: `https://github.com/NansPellicari/UE4WithGoogle`)  
But i'm stuck trying to create GGtests in plugins.
It seems to be a problem with the **gmock** lib which can't be compiled in shared DLL, but my knowledge in c++, the Engine builder and GGtest are too low. Here a clue maybe: https://groups.google.com/forum/#!topic/googlemock/Ejyq8M736Ec
