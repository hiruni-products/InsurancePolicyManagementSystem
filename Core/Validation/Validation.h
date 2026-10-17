#pragma once

#include <string>

using std::string;

// Reusable input validation rules.
class Validation
{
public:
    static bool holderFieldsComplete(
        string holderID,
        string name,
        string nic,
        string phone,
        string address)
    {
        return holderID != "" &&
               name != "" &&
               nic != "" &&
               phone != "" &&
               address != "";
    }

    static bool validAge(int age)
    {
        return age > 0;
    }

    static bool validPhone(string phone)
    {
        return phone.length() == 10;
    }

    static bool positiveAmount(double amount)
    {
        return amount > 0;
    }

    static bool validPlan(string planName)
    {
        return planName == "Life Insurance" ||
               planName == "Health Insurance" ||
               planName == "Vehicle Insurance";
    }

    static bool claimIDsComplete(string claimID, string holderID)
    {
        return claimID != "" && holderID != "";
    }

    static bool validClaimStatus(string status)
    {
        return status == "Pending" ||
               status == "Under Review" ||
               status == "Approved" ||
               status == "Rejected";
    }
};
