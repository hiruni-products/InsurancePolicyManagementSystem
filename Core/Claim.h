#pragma once

#include <string>

using std::string;

// TG/2024/2283 - PROGRAMMER 2: claim creation and claim-status functions.
// TG/2024/2194 - OOP DESIGN: Claim class encapsulates claim data.
// Claim stores one insurance claim record.
class Claim
{
private:
    // Private members protect claim data from direct outside access.
    string claimID;
    string holderID;
    double claimAmount;
    string status;

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
    void createClaim(string newClaimID, string newHolderID, double newAmount)
    {
        claimID = newClaimID;
        holderID = newHolderID;
        claimAmount = newAmount;

        // Every new claim begins with Pending status.
        status = "Pending";
    }

    // Public method used to change claim status.
    void updateStatus(string newStatus)
    {
        status = newStatus;
    }

    // Getter for claim ID.
    string getClaimID() const
    {
        return claimID;
    }

    // Getter for policy holder ID.
    string getHolderID() const
    {
        return holderID;
    }

    // Getter for claim amount.
    double getClaimAmount() const
    {
        return claimAmount;
    }

    // Getter for current claim status.
    string getStatus() const
    {
        return status;
    }
};
