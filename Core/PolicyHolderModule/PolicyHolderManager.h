#pragma once

#include <string>

using std::string;

#include "../OOPDesign/PolicyHolder.h"
#include "../Validation/Validation.h"

// Handles policy-holder registration, search and plan selection.
class PolicyHolderManager
{
private:
    static const int MAX_HOLDERS = 50;
    PolicyHolder holders[MAX_HOLDERS];
    int holderCount;

public:
    PolicyHolderManager()
    {
        holderCount = 0;
    }

    int findHolderIndex(string holderID) const
    {
        for (int i = 0; i < holderCount; i++)
        {
            if (holders[i].getHolderID() == holderID)
            {
                return i;
            }
        }

        return -1;
    }

    bool addPolicyHolder(
        string holderID,
        string name,
        string nic,
        string phone,
        string address,
        int age,
        string& message)
    {
        if (!Validation::holderFieldsComplete(holderID, name, nic, phone, address))
        {
            message = "Please fill all policy holder fields.";
            return false;
        }

        if (!Validation::validAge(age))
        {
            message = "Age must be greater than zero.";
            return false;
        }

        if (!Validation::validPhone(phone))
        {
            message = "Phone number must contain 10 digits.";
            return false;
        }

        if (findHolderIndex(holderID) != -1)
        {
            message = "Holder ID already exists.";
            return false;
        }

        if (holderCount >= MAX_HOLDERS)
        {
            message = "Maximum policy holder limit reached.";
            return false;
        }

        holders[holderCount].setHolderDetails(
            holderID,
            name,
            nic,
            phone,
            address,
            age);

        holderCount++;

        message = "Policy holder registered successfully.";
        return true;
    }

    bool getPolicyHolder(string holderID, PolicyHolder& result) const
    {
        int index = findHolderIndex(holderID);

        if (index == -1)
        {
            return false;
        }

        result = holders[index];
        return true;
    }

    bool selectPolicyPlan(
        string holderID,
        string planName,
        double coverageAmount,
        string& message)
    {
        int index = findHolderIndex(holderID);

        if (index == -1)
        {
            message = "Policy holder not found.";
            return false;
        }

        if (!Validation::positiveAmount(coverageAmount))
        {
            message = "Coverage amount must be greater than zero.";
            return false;
        }

        if (!Validation::validPlan(planName))
        {
            message = "Please select a valid policy plan.";
            return false;
        }

        holders[index].assignPlan(planName, coverageAmount);

        message = "Policy plan selected successfully.";
        return true;
    }
};
