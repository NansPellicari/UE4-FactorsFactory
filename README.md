# Factors Factory

Ease and centralized your **factors**<sup>1</sup> management, **retrieve** them to get some player **feedbacks/stats** and **serialized** them for **save/load game**.

> <sup>1</sup> A **factor** is a simple stack composed of **unit** objects which embed a **value**, an **operation** instruction and **lifetime** details. It can be used for **Malus** or **Bonus** factor, **difficulty**, ... >> more details in the [What is a factor?](#23-what-is-a-factor) section.

|                                                                                                       <a href="https://www.buymeacoffee.com/NansUE4" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-green.png" alt="Buy Me A Coffee" height="51" width="217"></a>                                                                                                       |
| :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
| I've decided to make all the code I developed for my games free to use and open source.<br> I am a true believer in the mindset that sharing and collaborating makes the world a better place.<br> The thing is: I'm fulltime dedicated to my project and these open source plugins, for coding I need a looooot of coffee, so please, help me to get my drug :stuck_out_tongue_closed_eyes: !! |

<!-- TOC -->

-   [1. Requirements](#1-requirements)
-   [2. Usages](#2-usages)
    -   [2.1. Many factors](#21-many-factors)
    -   [2.2. When & Where? Ease of use](#22-when--where-ease-of-use)
    -   [2.3. What is a factor?](#23-what-is-a-factor)
        -   [2.3.1. - UNIT](#231---unit)
        -   [2.3.2. - FACTOR (a stack of units)](#232---factor-a-stack-of-units)
        -   [2.3.3. - STATE](#233---state)
-   [3. How to install it?](#3-how-to-install-it)
-   [4. How should I use?](#4-how-should-i-use)
    -   [4.1. As designer](#41-as-designer)
    -   [4.2. As developper](#42-as-developper)
        -   [4.2.1. Implementation details](#421-implementation-details)
-   [5. How can I extend it?](#5-how-can-i-extend-it)
    -   [5.1. As designer](#51-as-designer)
    -   [5.2. As developper](#52-as-developper)
-   [6. Bonus](#6-bonus)
    -   [6.1. How to run tests quickly](#61-how-to-run-tests-quickly)
-   [7. Notes](#7-notes)
-   [8. Contributing and Supporting](#8-contributing-and-supporting)

<!-- /TOC -->

**>> For developers:**

-   [Developers docs](./Docs/Developers.md)

<a id="markdown-1-requirements" name="1-requirements"></a>

## 1. Requirements

-   [NansUE4TestsHelpers](https://github.com/NansPellicari/NansUE4TestsHelpers) (free UE4 plugins)
-   [NansCoreHelpers](https://github.com/NansPellicari/UE4-NansCoreHelpers) (free UE4 plugins)
-   [NansTimelineSystem](https://github.com/NansPellicari/UE4-NansTimelineSystem) (free UE4 plugins)

<a id="markdown-2-usages" name="2-usages"></a>

## 2. Usages

I used this to get a **malus/bonus** system, a **difficulty** factor and an **xp** counter,... sky is the limit!  
The factors factory helps you to create any factor and update or retrieve it **where** and **when** you want.

### 2.2. Many factors

For instance in my game I didn't want to have:

-   the **same** difficulty **factor** for an **AIMING** ability and for a **SOCIAL** skill
-   the same **timeline** for factors: some needs to work during the **level process** (eg "Oh player is drunk, for 1 minutes during the game session he should be affected! :confused: Alcohol ravages..."), others during the **real life timeline** (eg. "Hey bro, thanks to your fidelity, I give you 2 days of bonus on social interactions :kissing_heart:"), etc...  
    See below to see possiblities.

So basically a Factor as a **name** and it is attached to a **Timeline** and can be **updated** in **any moment** and **everywhere**.

> **Be aware of**: When a timeline ends, all attached factors will be reset.

<a id="markdown-23-what-is-a-factor" name="23-what-is-a-factor"></a>

### 2.1. What is a factor?

In this plugin I categorized factor in **3 units of work**:

<a id="markdown-231---unit" name="231---unit"></a>

#### 2.1.1. - UNIT

This is what designers or developpers want to **add on the fly** as a factor's variator.  
Eg.

> 1. Player eat a rotten fruit = **reduce** the **ACTION** capacity's **factor** to **2** after **100 secs** of digestion.
> 2. Player drink alcohol = **divide** actual factor by **4** on **SPEECH** capacity after **50 secs** of absorption.
> 3. Player make a benevolent action = **add** a bonus of **10** on **SOCIAL** skill's **factor**.

A factor **UNIT** is basically composed of:

| A Reason                                                                                            | A Value                                | An Operator                                                                                  | A Duration                                                                                                   | A Delay                                     |
| --------------------------------------------------------------------------------------------------- | -------------------------------------- | -------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------ | ------------------------------------------- |
| Is the **Why** this factor appears (can be used to send feedback to player, to make some stats,...) | **What** amount/degree of factor it is | **How** the value is computed with previous units in the same category (or stack, see below) | Duration of this unit is applied (it is removed for computation after that but saved for stats or feedbacks) | To schedule the start before a unit applies |
| **Using last examples:**                                                                            |
| 1. eat rotten fruit                                                                                 | 2                                      | Substract (**reduce** = **malus** = the inverse of **adding** a **bonus**)                   | 300secs                                                                                                      | 100secs                                     |
| 2. drunk                                                                                            | 4                                      | Divide                                                                                       | 200sec                                                                                                       | 50secs                                      |
| 3. benevolent action                                                                                | 10                                     | Add                                                                                          | 2 days (you can convert in seconds... :smirk:)                                                               | 0                                           |

<a id="markdown-232---factor-a-stack-of-units" name="232---factor-a-stack-of-units"></a>

#### 2.1.2. - FACTOR

A factor is **named** (eg. **ACTION**, **ELOQUENCE**, **REFLEXE**, **SociaL**, **WhatEver**... you decide) to retrieve them easily.  
As designer or developper you can create an **infinite list** of factor add add as many units you want.  
All factors are created in **project settings**.  
A factor relies on a timeline (configured in **project settings** too).  
A factor is a **stack of units**, it saved them no matters their lifetime (for computation) so you can use it to:

-   sends reports
-   gives feedbacks to the player afterwards
-   save them on saved games

<a id="markdown-233---state" name="233---state"></a>

#### 2.1.3. - STATE

This is the **state** of a factor at a given time.  
Every time you ask to get a state, you will have a static state of the factor value, reasons list implied on computation (all units reasons reduce to get a unique reasons list), and the current time you asked for it (depending on the timeline paradigm).

<a id="markdown-22-when--where-ease-of-use" name="22-when--where-ease-of-use"></a>

### 2.3. When & Where? Ease of use

As a designer and a developper I wanted to:

| Needs                                                                                                              | What is my solution                                                                                                                                                       |
| ------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Update a factor in any moment and in every single part of the game (eg. Behavior tree, Blueprint, c++ classes,...) | **1** single **API entry point** saved in the **Game Instance**                                                                                                           |
| Don't have to use my brain too much...                                                                             | **3 mains blueprints nodes** to manage all of this (**create** units & **get** factor's value).                                                                           |
| Easily extend it later                                                                                             | Simple architecture in isolated plugins, use a bunch of interfaces and a lot of tests/specs (see below :exclamation: need details here :exclamation:) to avoid regression |

<a id="markdown-3-how-to-install-it" name="3-how-to-install-it"></a>

## 3. Step by step guide

<a id="markdown-6-bonus" name="6-bonus"></a>

## 6. Bonus

<a id="markdown-61-how-to-run-tests-quickly" name="61-how-to-run-tests-quickly"></a>

### 6.1. How to run tests quickly

<a id="markdown-7-notes" name="7-notes"></a>

## 7. Notes

The clang-file as been inspired by this really helpull gist: https://gist.github.com/intinig/9bba3a3faee80250b781bf916a4ab8b7

<a id="markdown-8-contributing-and-supporting" name="8-contributing-and-supporting"></a>

## 8. Contributing and Supporting

I've decided to make all the code I developed for my games free to use and open source.  
I am a true believer in the mindset that sharing and collaborating makes the world a better place.  
I'll be very glad if you decided to help me to follow my dream.

| How?                                                                                                                                                                               |                                                                                         With                                                                                         |
| :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: |
| **Donating**<br> Because I'm an independant developer/creator and for now I don't have<br> any income, I need money to support my daily needs (coffeeeeee).                        | <a href="https://www.buymeacoffee.com/NansUE4" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-green.png" alt="Buy Me A Coffee" height="51" width="217" ></a> |
| **Contributing**<br> You are very welcome if you want to contribute. I explain [here](./CONTRIBUTING.md) in details what<br> is the most comfortable way to me you can contribute. |                                                                         [CONTRIBUTING.md](./CONTRIBUTING.md)                                                                         |
