#pragma once

#include <string>

using std::string;

// Stores one insurance claim.
class Claim
{
private:
    // Stores the details of one claim
    string claimID;
    string holderID;
    double claimAmount;
    string status;

public:
    // Default constructor - starts with an empty claim
    Claim()
    {
        claimID = "";
        holderID = "";
        claimAmount = 0.0;
        status = "";
    }

    // Creates a new claim with Pending status
    void createClaim(string newClaimID, string newHolderID, double newAmount)
    {
        claimID = newClaimID;
        holderID = newHolderID;
        claimAmount = newAmount;
        status = "Pending";
    }

    // Changes the current claim status
    void updateStatus(string newStatus)
    {
        status = newStatus;
    }

    // Returns the Claim ID
    string getClaimID() const
    {
        return claimID;
    }

    // Returns the related Holder ID
    string getHolderID() const
    {
        return holderID;
    }

    // Returns the claim amount
    double getClaimAmount() const
    {
        return claimAmount;
    }

    // Returns the current claim status
    string getStatus() const
    {
        return status;
    }
};
