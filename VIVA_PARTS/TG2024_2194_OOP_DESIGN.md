# TG/2024/2194 - OOP Designer

**Study file only. This file is not used to build the program.**

## Main responsibility
Design classes, inheritance and encapsulation.

## Main source files
- `Core/Person.h`
- `Core/PolicyHolder.h`
- `Core/PolicyPlan.h`
- `Core/Claim.h`
- `Core/InsuranceSystem.h`

## OOP concepts to study
- Class
- Object
- Constructor
- Encapsulation
- Inheritance
- `private`, `protected`, `public`
- Getter methods

## Inheritance examples
- `PolicyHolder : public Person`
- `LifePolicy : public PolicyPlan`
- `HealthPolicy : public PolicyPlan`
- `VehiclePolicy : public PolicyPlan`

## Encapsulation examples
- PolicyHolder-specific data is private
- Claim data is private
- Public methods are used to access or change data

## Viva sentence
“The system separates data and behavior into classes and uses inheritance and encapsulation to demonstrate OOP.”
