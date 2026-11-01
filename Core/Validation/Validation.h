#pragma once

#include <string>

using std::string;

// Reusable input validation rules.
class Validation
{
public:
    // Checks whether all required policy-holder fields are filled
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

    // Checks whether age is greater than zero
    static bool validAge(int age)
    {
        return age > 0;
    }

    // Checks whether the phone text contains 10 characters
    static bool validPhone(string phone)
    {
        return phone.length() == 10;
    }

    // Checks whether an entered amount is greater than zero
    static bool positiveAmount(double amount)
    {
        return amount > 0;
    }

    // Checks whether the selected plan is supported
    static bool validPlan(string planName)
    {
        return planName == "Life Insurance" ||
               planName == "Health Insurance" ||
               planName == "Vehicle Insurance";
    }

    // Checks whether both Claim ID and Holder ID are entered
    static bool claimIDsComplete(string claimID, string holderID)
    {
        return claimID != "" && holderID != "";
    }

    // Checks whether the claim status is supported
    static bool validClaimStatus(string status)
    {
        return status == "Pending" ||
               status == "Under Review" ||
               status == "Approved" ||
               status == "Rejected";
    }
};
