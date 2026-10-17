# TG/2024/2293 - Testing & Validation

**Study file only. This file is not used to build the program.**

## Main responsibility
Test functions, inputs, validation and errors.

## Main source files
- `TEST_CASES.md`
- Validation blocks inside `Core/InsuranceSystem.h`
- Numeric input checks inside `GUI/MainForm.h`

## Validation to study
- Empty mandatory holder fields
- Age <= 0
- Phone length not equal to 10
- Duplicate Holder ID
- Holder limit reached
- Coverage amount <= 0
- Invalid policy plan
- Premium before selecting a plan
- Empty Claim ID / Holder ID
- Claim amount <= 0
- Unknown Holder ID for a claim
- Duplicate Claim ID
- Claim limit reached
- Invalid claim status
- Non-numeric age, coverage and claim amount in GUI

## Testing idea
For each test know:
Input -> Expected result -> Actual result -> Pass/Fail
