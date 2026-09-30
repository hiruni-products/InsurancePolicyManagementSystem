#pragma once

#include <string>

// Claim stores one insurance claim record.
class Claim
{
private:
    // Private members protect claim data from direct outside access.
    std::string claimID;
    std::string holderID;
    double claimAmount;
    std::string status;

public:
    // Default constructor.
    Claim()
    {
        claimID = "";
        holderID = "";
        claimAmount = 0.0;
        status = "";
    }

    // Public method used when a new claim is submitted.
    void createClaim(std::string newClaimID, std::string newHolderID, double newAmount)
    {
        claimID = newClaimID;
        holderID = newHolderID;
        claimAmount = newAmount;

        // Every new claim begins with Pending status.
        status = "Pending";
    }

    // Public method used to change claim status.
    void updateStatus(std::string newStatus)
    {
        status = newStatus;
    }

    // Getter for claim ID.
    std::string getClaimID() const
    {
        return claimID;
    }

    // Getter for policy holder ID.
    std::string getHolderID() const
    {
        return holderID;
    }

    // Getter for claim amount.
    double getClaimAmount() const
    {
        return claimAmount;
    }

    // Getter for current claim status.
    std::string getStatus() const
    {
        return status;
    }
};
