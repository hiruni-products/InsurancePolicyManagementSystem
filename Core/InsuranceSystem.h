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
    // Handles registration, search and policy plan selection
    PolicyHolderManager holderManager;
    // Handles premium calculation and claim operations
    PremiumClaimManager premiumClaimManager;

public:
    // Forward a holder search request to PolicyHolderManager
    int findHolderIndex(string holderID) const
    {
        return holderManager.findHolderIndex(holderID);
    }

    // Forward a claim search request to PremiumClaimManager
    int findClaimIndex(string claimID) const
    {
        return premiumClaimManager.findClaimIndex(claimID);
    }

    // Forward a registration request to PolicyHolderManager
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

    // Get policy-holder details from PolicyHolderManager
    bool getPolicyHolder(string holderID, PolicyHolder& result) const
    {
        return holderManager.getPolicyHolder(holderID, result);
    }

    // Forward policy plan selection to PolicyHolderManager
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

    // Get the holder and ask PremiumClaimManager to calculate the premium
    bool calculatePremium(
        string holderID,
        double& premium,
        string& message) const
    {
        // Temporary object used to receive the holder details
        PolicyHolder holder;
        bool holderFound = holderManager.getPolicyHolder(holderID, holder);

        return premiumClaimManager.calculatePremium(
            holderFound,
            holder,
            premium,
            message);
    }

    // Check the holder and forward claim creation to PremiumClaimManager
    bool createClaim(
        string claimID,
        string holderID,
        double claimAmount,
        string& message)
    {
        // Check whether the entered Holder ID exists
        bool holderExists =
            holderManager.findHolderIndex(holderID) != -1;

        return premiumClaimManager.createClaim(
            claimID,
            holderID,
            claimAmount,
            holderExists,
            message);
    }

    // Get claim details from PremiumClaimManager
    bool getClaim(string claimID, Claim& result) const
    {
        return premiumClaimManager.getClaim(claimID, result);
    }

    // Forward a claim-status update to PremiumClaimManager
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
