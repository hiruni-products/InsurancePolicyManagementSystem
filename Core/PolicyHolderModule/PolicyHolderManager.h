#pragma once

#include <string>

using std::string;

#include "../OOPDesign/PolicyHolder.h"
#include "../Validation/Validation.h"

// Handles policy-holder registration, search and plan selection.
class PolicyHolderManager
{
private:
    // Maximum number of policy holders
    static const int MAX_HOLDERS = 50;

    // Stores all registered policy holders
    PolicyHolder holders[MAX_HOLDERS];

    // Stores the current number of registered holders
    int holderCount;

public:
    // Constructor - starts with zero registered holders
    PolicyHolderManager()
    {
        holderCount = 0;
    }

    // Finds a policy holder using the Holder ID
    int findHolderIndex(string holderID) const
    {
        // Check each stored policy holder
        for (int i = 0; i < holderCount; i++)
        {
            // Compare the stored Holder ID with the entered ID
            if (holders[i].getHolderID() == holderID)
            {
                // Return the array position if the holder is found
                return i;
            }
        }

        // Return -1 if the holder is not found
        return -1;
    }

    // Registers a new policy holder
    bool addPolicyHolder(
        string holderID,
        string name,
        string nic,
        string phone,
        string address,
        int age,
        string& message)
    {
        // Check whether all required fields are filled
        if (!Validation::holderFieldsComplete(holderID, name, nic, phone, address))
        {
            message = "Please fill all policy holder fields.";
            return false;
        }

        // Check whether the age is valid
        if (!Validation::validAge(age))
        {
            message = "Age must be greater than zero.";
            return false;
        }

        // Check whether the phone text has the required length
        if (!Validation::validPhone(phone))
        {
            message = "Phone number must contain 10 digits.";
            return false;
        }

        // Check whether the Holder ID already exists
        if (findHolderIndex(holderID) != -1)
        {
            message = "Holder ID already exists.";
            return false;
        }

        // Check whether the holder array is full
        if (holderCount >= MAX_HOLDERS)
        {
            message = "Maximum policy holder limit reached.";
            return false;
        }

        // Save the new policy holder details
        holders[holderCount].setHolderDetails(
            holderID,
            name,
            nic,
            phone,
            address,
            age);

        // Increase the number of registered holders
        holderCount++;

        // Registration completed successfully
        message = "Policy holder registered successfully.";
        return true;
    }

    // Gets an existing policy holder using the Holder ID
    bool getPolicyHolder(string holderID, PolicyHolder& result) const
    {
        // Find the holder position in the array
        int index = findHolderIndex(holderID);

        // Return false if the holder is not found
        if (index == -1)
        {
            return false;
        }

        // Copy the found holder details to the result
        result = holders[index];

        // Search completed successfully
        return true;
    }

    // Assigns a policy plan to a registered holder
    bool selectPolicyPlan(
        string holderID,
        string planName,
        double coverageAmount,
        string& message)
    {
        // Find the registered policy holder
        int index = findHolderIndex(holderID);

        // Stop if the holder does not exist
        if (index == -1)
        {
            message = "Policy holder not found.";
            return false;
        }

        // Check whether the coverage amount is greater than zero
        if (!Validation::positiveAmount(coverageAmount))
        {
            message = "Coverage amount must be greater than zero.";
            return false;
        }

        // Check whether the selected policy plan is valid
        if (!Validation::validPlan(planName))
        {
            message = "Please select a valid policy plan.";
            return false;
        }

        // Save the selected plan and coverage amount
        holders[index].assignPlan(planName, coverageAmount);

        // Plan selection completed successfully
        message = "Policy plan selected successfully.";
        return true;
    }
};
