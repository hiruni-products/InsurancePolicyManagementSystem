#pragma once

#include <string>

using std::string;

#include "PolicyHolderModule/PolicyHolderManager.h"
#include "PremiumClaimModule/PremiumClaimManager.h"

// Shared coordinator.
// It connects the separate modules used by the GUI.
class InsuranceSystem
{
private:
    PolicyHolderManager holderManager;
    PremiumClaimManager premiumClaimManager;

public:
    int findHolderIndex(string holderID) const
    {
        return holderManager.findHolderIndex(holderID);
    }

    int findClaimIndex(string claimID) const
    {
        return premiumClaimManager.findClaimIndex(claimID);
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
        return holderManager.addPolicyHolder(
            holderID,
            name,
            nic,
            phone,
            address,
            age,
            message);
    }

    bool getPolicyHolder(string holderID, PolicyHolder& result) const
    {
        return holderManager.getPolicyHolder(holderID, result);
    }

    bool selectPolicyPlan(
        string holderID,
        string planName,
        double coverageAmount,
        string& message)
    {
        return holderManager.selectPolicyPlan(
            holderID,
            planName,
            coverageAmount,
            message);
    }

    bool calculatePremium(
        string holderID,
        double& premium,
        string& message) const
    {
        PolicyHolder holder;
        bool holderFound = holderManager.getPolicyHolder(holderID, holder);

        return premiumClaimManager.calculatePremium(
            holderFound,
            holder,
            premium,
            message);
    }

    bool createClaim(
        string claimID,
        string holderID,
        double claimAmount,
        string& message)
    {
        bool holderExists =
            holderManager.findHolderIndex(holderID) != -1;

        return premiumClaimManager.createClaim(
            claimID,
            holderID,
            claimAmount,
            holderExists,
            message);
    }

    bool getClaim(string claimID, Claim& result) const
    {
        return premiumClaimManager.getClaim(claimID, result);
    }

    bool updateClaimStatus(
        string claimID,
        string newStatus,
        string& message)
    {
        return premiumClaimManager.updateClaimStatus(
            claimID,
            newStatus,
            message);
    }
};
