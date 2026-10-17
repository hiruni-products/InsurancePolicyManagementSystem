# TG/2024/2175 - Programmer 1

**Study file only. This file is not used to build the program.**

## Main responsibility
Policy-holder registration, search and policy-plan selection.

## Main source files
- `Core/Person.h`
- `Core/PolicyHolder.h`
- `Core/InsuranceSystem.h`

## Functions to study
From `InsuranceSystem.h`:
- `findHolderIndex()`
- `addPolicyHolder()`
- `getPolicyHolder()`
- `selectPolicyPlan()`

From `PolicyHolder.h`:
- `setHolderDetails()`
- `assignPlan()`
- Getter methods

## What to understand
- `Person -> PolicyHolder` inheritance
- Holder ID, name, NIC, phone, address and age
- Search by Holder ID
- Duplicate Holder ID check
- Age must be greater than zero
- Phone length must be 10 characters
- Coverage amount must be greater than zero
- Available plans: Life, Health and Vehicle

## Simple flow
Register holder -> Search holder -> Select policy plan

## Viva sentence
“My main part is policy-holder registration, search and policy-plan selection.”
