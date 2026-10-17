# Insurance Policy Management System

**Course:** ENT 2162 - Object-Oriented Programming  
**Group:** H  
**University:** University of Ruhuna - Faculty of Technology

## Project purpose

This is a simple GUI-based C++ mini project for the ENT 2162 group project.

The required Group H functions are:

1. Add / search policy holders
2. Select a policy plan
3. Calculate a simplified academic premium
4. Submit, view and update claim status

The project is intentionally kept simple so every group member can understand and explain the code during the viva.

## OOP concepts used

The core code uses the basic concepts taught in the lectures:

- Classes and objects
- `private`, `protected`, and `public` access specifiers
- Member functions
- Constructors
- Inheritance
- Encapsulation through private data and public methods

Advanced features such as databases, networking, templates, smart pointers and STL containers are not required for the core project.

## Folder structure

```text
InsurancePolicyManagementSystem/
|
|-- Core/
|   |-- OOPDesign/
|   |   |-- Person.h
|   |   |-- PolicyHolder.h
|   |   |-- PolicyPlan.h
|   |   `-- Claim.h
|   |-- PolicyHolderModule/
|   |   `-- PolicyHolderManager.h
|   |-- PremiumClaimModule/
|   |   `-- PremiumClaimManager.h
|   |-- Validation/
|   |   `-- Validation.h
|   `-- InsuranceSystem.h
|
|-- GUI/
|   |-- MainForm.h
|   `-- Program.cpp
|
|
|-- InsurancePolicyManagementSystemGUI.vcxproj
|-- TEAM_ROLES.md
|-- TEST_CASES.md
|-- VIVA_GUIDE.md
`-- README.md
```

## Class structure

```text
Person
  |
  `-- PolicyHolder

PolicyPlan
  |-- LifePolicy
  |-- HealthPolicy
  `-- VehiclePolicy

Claim
InsuranceSystem
```

## Simplified premium formula

This formula is only for academic software demonstration.

```text
Premium = (Base Premium + Coverage Amount x Coverage Rate) x Age Factor
```

Plan values:

| Plan | Base Premium | Coverage Rate |
|---|---:|---:|
| Life Insurance | 2500 | 0.0015 |
| Health Insurance | 1800 | 0.0012 |
| Vehicle Insurance | 2200 | 0.0018 |

Age factor:

- Below 30 = 1.00
- 30 to 49 = 1.10
- 50 or above = 1.25


## Opening the GUI

Open `InsurancePolicyManagementSystemGUI.vcxproj` in Visual Studio.

Recommended Visual Studio components:

- Desktop development with C++
- C++/CLI support (Latest MSVC)
- .NET Framework 4.8 SDK
- .NET Framework 4.8 targeting pack

## Main workflow

```text
Register Policy Holder
        |
        v
Select Policy Plan
        |
        v
Calculate Premium
        |
        v
Submit / Search / Update Claim
```

## Viva note

The source code is separated into clear responsibility modules. `InsuranceSystem.h` is only the shared coordinator that connects the modules to the GUI. Primary responsibilities are listed in `TEAM_ROLES.md`, but every group member should understand the complete workflow and the main OOP concepts.
