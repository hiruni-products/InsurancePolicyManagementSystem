# TG/2024/2175 - Programmer 1

**Main working module:** `Core/PolicyHolderModule/PolicyHolderManager.h`

## Main responsibility
Policy-holder registration, search and policy-plan selection.

## Functions to study
- `findHolderIndex()`
- `addPolicyHolder()`
- `getPolicyHolder()`
- `selectPolicyPlan()`

## Supporting OOP classes used by this module
- `Core/OOPDesign/Person.h`
- `Core/OOPDesign/PolicyHolder.h`

## What to understand
- Holder registration
- Search by Holder ID
- Duplicate Holder ID check
- Age and phone validation
- Plan selection
- Coverage amount validation
- How `PolicyHolderManager` calls methods of `PolicyHolder`

## Simple flow
Register holder -> Search holder -> Select policy plan
