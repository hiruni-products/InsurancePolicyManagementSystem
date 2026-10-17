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
    static const int MAX_CLAIMS = 50;
    Claim claims[MAX_CLAIMS];
    int claimCount;

public:
    PremiumClaimManager()
    {
        claimCount = 0;
    }

    int findClaimIndex(string claimID) const
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

    bool calculatePremium(
        bool holderFound,
        const PolicyHolder& holder,
        double& premium,
        string& message) const
    {
        if (!holderFound)
        {
            message = "Policy holder not found.";
            return false;
        }

        if (holder.hasPlan() == false)
        {
            message = "Please select a policy plan first.";
            return false;
        }

        double basePremium = 0.0;
        double coverageRate = 0.0;
        string planName = holder.getSelectedPlan();

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

        double ageFactor = 1.00;

        if (holder.getAge() >= 50)
        {
            ageFactor = 1.25;
        }
        else if (holder.getAge() >= 30)
        {
            ageFactor = 1.10;
        }

        premium =
            (basePremium + holder.getCoverageAmount() * coverageRate)
            * ageFactor;

        message = "Premium calculated successfully.";
        return true;
    }

    bool createClaim(
        string claimID,
        string holderID,
        double claimAmount,
        bool holderExists,
        string& message)
    {
        if (!Validation::claimIDsComplete(claimID, holderID))
        {
            message = "Claim ID and Holder ID are required.";
            return false;
        }

        if (!Validation::positiveAmount(claimAmount))
        {
            message = "Claim amount must be greater than zero.";
            return false;
        }

        if (!holderExists)
        {
            message = "Policy holder not found.";
            return false;
        }

        if (findClaimIndex(claimID) != -1)
        {
            message = "Claim ID already exists.";
            return false;
        }

        if (claimCount >= MAX_CLAIMS)
        {
            message = "Maximum claim limit reached.";
            return false;
        }

        claims[claimCount].createClaim(claimID, holderID, claimAmount);
        claimCount++;

        message = "Claim submitted successfully. Status: Pending.";
        return true;
    }

    bool getClaim(string claimID, Claim& result) const
    {
        int index = findClaimIndex(claimID);

        if (index == -1)
        {
            return false;
        }

        result = claims[index];
        return true;
    }

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

        if (!Validation::validClaimStatus(newStatus))
        {
            message = "Please select a valid claim status.";
            return false;
        }

        claims[index].updateStatus(newStatus);

        message = "Claim status updated successfully.";
        return true;
    }
};
