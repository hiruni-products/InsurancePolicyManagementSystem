#pragma once

#include <string>

using std::string;

#include "../OOPDesign/PolicyHolder.h"
#include "../OOPDesign/PolicyPlan.h"
#include "../OOPDesign/Claim.h"
#include "../Validation/Validation.h"

// Handles premium calculation and claim management.
class PremiumClaimManager
{
private:
    // Maximum number of claims stored in the system
    static const int MAX_CLAIMS = 50;
    // Stores all created claim objects
    Claim claims[MAX_CLAIMS];
    // Stores the current number of claims
    int claimCount;

public:
    // Constructor - starts with zero claims
    PremiumClaimManager()
    {
        claimCount = 0;
    }

    // Finds a claim using the Claim ID
    int findClaimIndex(string claimID) const
    {
        // Check each stored claim
        for (int i = 0; i < claimCount; i++)
        {
            if (claims[i].getClaimID() == claimID)
            {
                return i;
            }
        }

        // Return -1 if the claim is not found
        return -1;
    }

    // Calculates the premium for a registered holder
    bool calculatePremium(
        bool holderFound,
        const PolicyHolder& holder,
        double& premium,
        string& message) const
    {
        // Stop if the policy holder does not exist
        if (!holderFound)
        {
            message = "Policy holder not found.";
            return false;
        }

        // A policy plan must be selected before calculation
        if (holder.hasPlan() == false)
        {
            message = "Please select a policy plan first.";
            return false;
        }

        // Values used in the premium formula
        double basePremium = 0.0;
        double coverageRate = 0.0;
        string planName = holder.getSelectedPlan();

        // Get values for the selected policy plan
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

        // Default age factor for holders below 30
        double ageFactor = 1.00;

        // Select the age factor based on holder age
        if (holder.getAge() >= 50)
        {
            ageFactor = 1.25;
        }
        else if (holder.getAge() >= 30)
        {
            ageFactor = 1.10;
        }

        // Apply the academic premium formula
        premium =
            (basePremium + holder.getCoverageAmount() * coverageRate)
            * ageFactor;

        message = "Premium calculated successfully.";
        return true;
    }

    // Creates a new claim for an existing policy holder
    bool createClaim(
        string claimID,
        string holderID,
        double claimAmount,
        bool holderExists,
        string& message)
    {
        // Check whether Claim ID and Holder ID are entered
        if (!Validation::claimIDsComplete(claimID, holderID))
        {
            message = "Claim ID and Holder ID are required.";
            return false;
        }

        // Check whether the claim amount is greater than zero
        if (!Validation::positiveAmount(claimAmount))
        {
            message = "Claim amount must be greater than zero.";
            return false;
        }

        // Stop if the related policy holder does not exist
        if (!holderExists)
        {
            message = "Policy holder not found.";
            return false;
        }

        // Reject a duplicate Claim ID
        if (findClaimIndex(claimID) != -1)
        {
            message = "Claim ID already exists.";
            return false;
        }

        // Check whether the claim array is full
        if (claimCount >= MAX_CLAIMS)
        {
            message = "Maximum claim limit reached.";
            return false;
        }

        // Save the new claim with Pending status
        claims[claimCount].createClaim(claimID, holderID, claimAmount);
        // Increase the number of stored claims
        claimCount++;

        message = "Claim submitted successfully. Status: Pending.";
        return true;
    }

    // Gets an existing claim using the Claim ID
    bool getClaim(string claimID, Claim& result) const
    {
        int index = findClaimIndex(claimID);

        if (index == -1)
        {
            return false;
        }

        // Copy the found claim details to the result
        result = claims[index];
        return true;
    }

    // Updates the status of an existing claim
    bool updateClaimStatus(
        string claimID,
        string newStatus,
        string& message)
    {
        int index = findClaimIndex(claimID);

        if (index == -1)
        {
            message = "Claim not found.";
            return false;
        }

        // Check whether the new status is supported
        if (!Validation::validClaimStatus(newStatus))
        {
            message = "Please select a valid claim status.";
            return false;
        }

        // Save the new claim status
        claims[index].updateStatus(newStatus);

        message = "Claim status updated successfully.";
        return true;
    }
};
