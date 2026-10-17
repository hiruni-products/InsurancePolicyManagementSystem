# Group H - Code Responsibility Map

These are the primary responsibilities based on the approved project proposal. Every member should also understand the overall system for the viva.

| Student Number | Primary Part | Main Source Folder / Files |
|---|---|---|
| TG/2024/2167 | GUI Design & Navigation | `GUI/` - `MainForm.h`, `Program.cpp` |
| TG/2024/2175 | Policy Holder Registration, Search & Plan Selection | `Core/PolicyHolderModule/PolicyHolderManager.h` |
| TG/2024/2194 | OOP Design | `Core/OOPDesign/` - `Person.h`, `PolicyHolder.h`, `PolicyPlan.h`, `Claim.h` |
| TG/2024/2283 | Premium Calculation & Claim Functions | `Core/PremiumClaimModule/PremiumClaimManager.h` |
| TG/2024/2293 | Testing & Validation | `Core/Validation/Validation.h`, `TEST_CASES.md` |
| TG/2024/2322 | Documentation | `README.md`, `VIVA_GUIDE.md`, report documentation |

## Shared connector

`Core/InsuranceSystem.h` is a small shared coordinator. It does not contain the full logic of several members. It only connects the separate modules so the GUI can call them through one system object.

## Important

The folders make the primary responsibilities clear, but the final presentation and viva are group activities. Every member should understand the basic project flow:

Register Holder -> Search Holder -> Select Plan -> Calculate Premium -> Submit Claim -> Admin Review -> Update Status -> Customer Views Status

## Separate viva study files

Each member also has a separate study file inside `VIVA_PARTS`:

- TG/2024/2167 -> `VIVA_PARTS/TG2024_2167_GUI.md`
- TG/2024/2175 -> `VIVA_PARTS/TG2024_2175_POLICY_HOLDER.md`
- TG/2024/2194 -> `VIVA_PARTS/TG2024_2194_OOP_DESIGN.md`
- TG/2024/2283 -> `VIVA_PARTS/TG2024_2283_PREMIUM_CLAIMS.md`
- TG/2024/2293 -> `VIVA_PARTS/TG2024_2293_TESTING_VALIDATION.md`
- TG/2024/2322 -> `VIVA_PARTS/TG2024_2322_DOCUMENTATION.md`
