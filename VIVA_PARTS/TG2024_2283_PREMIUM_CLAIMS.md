# TG/2024/2283 - Programmer 2

**Study file only. This file is not used to build the program.**

## Main responsibility
Premium calculation and claim-status functions.

## Main source files
- `Core/PolicyPlan.h`
- `Core/Claim.h`
- `Core/InsuranceSystem.h`

## Functions to study
- `calculatePremium()`
- `createClaim()`
- `getClaim()`
- `updateClaimStatus()`
- `findClaimIndex()`

## Premium formula
`Premium = (Base Premium + Coverage Amount x Coverage Rate) x Age Factor`

## Plan values
- Life: base 2500, rate 0.0015
- Health: base 1800, rate 0.0012
- Vehicle: base 2200, rate 0.0018

## Age factor
- Below 30: 1.00
- 30-49: 1.10
- 50 or above: 1.25

## Claim flow
Submit claim -> Pending -> Admin review -> Under Review / Approved / Rejected

## Important
The premium formula is a simplified academic demonstration formula, not a real commercial insurance formula.
