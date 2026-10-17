# TG/2024/2283 - Programmer 2

**Main working module:** `Core/PremiumClaimModule/PremiumClaimManager.h`

## Main responsibility
Premium calculation and claim-status functions.

## Functions to study
- `findClaimIndex()`
- `calculatePremium()`
- `createClaim()`
- `getClaim()`
- `updateClaimStatus()`

## Supporting OOP classes used by this module
- `Core/OOPDesign/PolicyPlan.h`
- `Core/OOPDesign/Claim.h`
- `Core/OOPDesign/PolicyHolder.h`

## Premium formula
`Premium = (Base Premium + Coverage Amount x Coverage Rate) x Age Factor`

## Claim flow
Submit claim -> Pending -> Admin review -> Under Review / Approved / Rejected

The premium formula is a simplified academic demonstration formula.
