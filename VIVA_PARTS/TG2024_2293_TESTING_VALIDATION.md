# TG/2024/2293 - Testing & Validation

**Main working module:** `Core/Validation/Validation.h`

## Main responsibility
Input validation and system testing.

## Validation functions to study
- `holderFieldsComplete()`
- `validAge()`
- `validPhone()`
- `positiveAmount()`
- `validPlan()`
- `claimIDsComplete()`
- `validClaimStatus()`

## Testing file
- `TEST_CASES.md`

## Also understand
The GUI performs simple numeric conversion checks with `TryParse` before sending values to the core modules.

For each test know:
Input -> Expected result -> Actual result -> Pass/Fail
