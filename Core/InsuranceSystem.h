#pragma once

#include <string>
#include "PolicyHolder.h"
#include "PolicyPlan.h"
#include "Claim.h"

// InsuranceSystem coordinates the main project functions.
// Fixed-size arrays are used to keep the code simple and lecture-friendly.
class InsuranceSystem
{
private:
    // Maximum records stored while the program is running.
    static const int MAX_HOLDERS = 50;
    static const int MAX_CLAIMS = 50;

    // Array of PolicyHolder objects.
    PolicyHolder holders[MAX_HOLDERS];

    // Array of Claim objects.
    Claim claims[MAX_CLAIMS];

    // Current number of saved holders.
    int holderCount;

    // Current number of saved claims.
    int claimCount;

public:
    // Constructor starts both counters at zero.
    InsuranceSystem()
    {
        holderCount = 0;
        claimCount = 0;
    }

    // Search for a policy holder by holder ID.
    // Returns array index if found, otherwise returns -1.
    int findHolderIndex(std::string holderID) const
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

    // Search for a claim by claim ID.
    // Returns array index if found, otherwise returns -1.
    int findClaimIndex(std::string claimID) const
    {
        for (int i = 0; i < claimCount; i++)
        {
            if (claims[i].getClaimID() == claimID)
            {
                return i;
            }
        }

        return -1;
    }

    // Add a new policy holder.
    bool addPolicyHolder(
        std::string holderID,
        std::string name,
        std::string nic,
        std::string phone,
        std::string address,
        int age,
        std::string& message)
    {
        // Basic validation: mandatory text fields cannot be empty.
        if (holderID == "" || name == "" || nic == "" || phone == "" || address == "")
        {
            message = "Please fill all policy holder fields.";
            return false;
        }

        // Age must be positive.
        if (age <= 0)
        {
            message = "Age must be greater than zero.";
            return false;
        }

        // Keep phone validation simple: exactly 10 characters.
        if (phone.length() != 10)
        {
            message = "Phone number must contain 10 digits.";
            return false;
        }

        // Do not allow duplicate holder IDs.
        if (findHolderIndex(holderID) != -1)
        {
            message = "Holder ID already exists.";
            return false;
        }

        // Stop if the fixed array is full.
        if (holderCount >= MAX_HOLDERS)
        {
            message = "Maximum policy holder limit reached.";
            return false;
        }

        // Save the new holder in the next free array position.
        holders[holderCount].setHolderDetails(holderID, name, nic, phone, address, age);

        // Increase the number of stored policy holders.
        holderCount++;

        message = "Policy holder registered successfully.";
        return true;
    }

    // Copy one holder record out of the system for display.
    bool getPolicyHolder(std::string holderID, PolicyHolder& result) const
    {
        int index = findHolderIndex(holderID);

        if (index == -1)
        {
            return false;
        }

        result = holders[index];
        return true;
    }

    // Assign one of the three available plan names to a registered holder.
    bool selectPolicyPlan(
        std::string holderID,
        std::string planName,
        double coverageAmount,
        std::string& message)
    {
        // Find the policy holder first.
        int index = findHolderIndex(holderID);

        if (index == -1)
        {
            message = "Policy holder not found.";
            return false;
        }

        // Coverage amount must be positive.
        if (coverageAmount <= 0)
        {
            message = "Coverage amount must be greater than zero.";
            return false;
        }

        // Only allow the three plan names used in this mini project.
        if (planName != "Life Insurance" &&
            planName != "Health Insurance" &&
            planName != "Vehicle Insurance")
        {
            message = "Please select a valid policy plan.";
            return false;
        }

        // Store plan information inside the selected PolicyHolder object.
        holders[index].assignPlan(planName, coverageAmount);

        message = "Policy plan selected successfully.";
        return true;
    }

    // Calculate an academic demonstration premium.
    bool calculatePremium(
        std::string holderID,
        double& premium,
        std::string& message) const
    {
        // Locate the holder.
        int index = findHolderIndex(holderID);

        if (index == -1)
        {
            message = "Policy holder not found.";
            return false;
        }

        // A plan must be selected before calculating a premium.
        if (holders[index].hasPlan() == false)
        {
            message = "Please select a policy plan first.";
            return false;
        }

        // These variables will receive values from the selected plan object.
        double basePremium = 0.0;
        double coverageRate = 0.0;

        // Read the plan stored inside the policy holder.
        std::string planName = holders[index].getSelectedPlan();

        // Create a derived plan object according to the selected plan.
        if (planName == "Life Insurance")
        {
            LifePolicy plan;
            basePremium = plan.getBasePremium();
            coverageRate = plan.getCoverageRate();
        }
        else if (planName == "Health Insurance")
        {
            HealthPolicy plan;
            basePremium = plan.getBasePremium();
            coverageRate = plan.getCoverageRate();
        }
        else if (planName == "Vehicle Insurance")
        {
            VehiclePolicy plan;
            basePremium = plan.getBasePremium();
            coverageRate = plan.getCoverageRate();
        }

        // Start with the normal age factor.
        double ageFactor = 1.00;

        // Add a small age factor for demonstration purposes.
        if (holders[index].getAge() >= 50)
        {
            ageFactor = 1.25;
        }
        else if (holders[index].getAge() >= 30)
        {
            ageFactor = 1.10;
        }

        // Simple academic formula used only for this mini project.
        premium = (basePremium + holders[index].getCoverageAmount() * coverageRate) * ageFactor;

        message = "Premium calculated successfully.";
        return true;
    }

    // Create a new claim for an existing policy holder.
    bool createClaim(
        std::string claimID,
        std::string holderID,
        double claimAmount,
        std::string& message)
    {
        // Mandatory IDs cannot be empty.
        if (claimID == "" || holderID == "")
        {
            message = "Claim ID and Holder ID are required.";
            return false;
        }

        // Claim amount must be positive.
        if (claimAmount <= 0)
        {
            message = "Claim amount must be greater than zero.";
            return false;
        }

        // Claim must belong to an existing holder.
        if (findHolderIndex(holderID) == -1)
        {
            message = "Policy holder not found.";
            return false;
        }

        // Do not allow duplicate claim IDs.
        if (findClaimIndex(claimID) != -1)
        {
            message = "Claim ID already exists.";
            return false;
        }

        // Stop if the fixed claim array is full.
        if (claimCount >= MAX_CLAIMS)
        {
            message = "Maximum claim limit reached.";
            return false;
        }

        // Create the claim in the next free position.
        claims[claimCount].createClaim(claimID, holderID, claimAmount);

        // Increase saved claim count.
        claimCount++;

        message = "Claim submitted successfully. Status: Pending.";
        return true;
    }

    // Copy a claim out for display.
    bool getClaim(std::string claimID, Claim& result) const
    {
        int index = findClaimIndex(claimID);

        if (index == -1)
        {
            return false;
        }

        result = claims[index];
        return true;
    }

    // Change an existing claim status.
    bool updateClaimStatus(
        std::string claimID,
        std::string newStatus,
        std::string& message)
    {
        // Locate the claim first.
        int index = findClaimIndex(claimID);

        if (index == -1)
        {
            message = "Claim not found.";
            return false;
        }

        // Only allow the four status values used in this project.
        if (newStatus != "Pending" &&
            newStatus != "Under Review" &&
            newStatus != "Approved" &&
            newStatus != "Rejected")
        {
            message = "Please select a valid claim status.";
            return false;
        }

        // Update the private claim status through its public method.
        claims[index].updateStatus(newStatus);

        message = "Claim status updated successfully.";
        return true;
    }
};
