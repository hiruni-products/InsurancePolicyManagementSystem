# Simple Viva Guide

## Whole project in one sentence

The system registers a policy holder, assigns a policy plan, calculates a simple academic premium, and manages claim status using C++ OOP classes and a Windows Forms GUI.

## Main OOP concepts

### Class
A class is the blueprint that groups data and functions together.
Examples: `Person`, `PolicyHolder`, `PolicyPlan`, `Claim`, `InsuranceSystem`.

### Object
An object is an instance of a class.
Example: `InsuranceSystem system;` in the console demo.

### Encapsulation
Important data is kept `private` and accessed or changed using `public` methods.
Example: `Claim::status` is private and changed using `updateStatus()`.

### Inheritance
A derived class receives accessible members/functions from a base class.
Examples:

```cpp
class PolicyHolder : public Person
class LifePolicy : public PolicyPlan
```

### Constructor
A constructor initializes an object when it is created.
Example: `PolicyHolder()` starts age and coverage at zero.

## System flow

1. Register holder
2. Search holder if needed
3. Select Life / Health / Vehicle plan
4. Enter coverage amount
5. Calculate premium
6. Submit claim
7. Search claim
8. Update claim status

## Why fixed arrays?

The project uses simple fixed arrays instead of advanced containers so the code remains easy to understand and explain at the level of the course.

## Why is the premium formula simple?

The project is an academic software demonstration, not a real commercial insurance calculation. The formula exists only to demonstrate program logic and OOP integration.

## GUI and core logic

The GUI reads values from textboxes and calls functions in `InsuranceSystem`. The core classes do not depend on buttons or textboxes. This separation makes the code easier to test and explain.
