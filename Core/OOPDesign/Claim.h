#pragma once

#include <string>

using std::string;

// Stores one insurance claim.
class Claim
{
private:
    string claimID;
    string holderID;
    double claimAmount;
    string status;

public:
    Claim()
    {
        claimID = "";
        holderID = "";
        claimAmount = 0.0;
        status = "";
    }

    void createClaim(string newClaimID, string newHolderID, double newAmount)
    {
        claimID = newClaimID;
        holderID = newHolderID;
        claimAmount = newAmount;
        status = "Pending";
    }

    void updateStatus(string newStatus)
    {
        status = newStatus;
    }

    string getClaimID() const
    {
        return claimID;
    }

    string getHolderID() const
    {
        return holderID;
    }

    double getClaimAmount() const
    {
        return claimAmount;
    }

    string getStatus() const
    {
        return status;
    }
};
