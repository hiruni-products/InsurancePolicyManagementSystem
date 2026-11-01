#pragma once

#include <string>

using std::string;
#include "Person.h"

// PolicyHolder inherits common personal details from Person.
class PolicyHolder : public Person
{
private:
    // Stores policy-holder specific details
    string holderID;
    string address;
    int age;
    string selectedPlan;
    double coverageAmount;
    bool planSelected;

public:
    // Default constructor - starts with empty holder details
    PolicyHolder()
    {
        holderID = "";
        address = "";
        age = 0;
        selectedPlan = "";
        coverageAmount = 0.0;
        planSelected = false;
    }

    // Stores registration details for a policy holder
    void setHolderDetails(
        string newHolderID,
        string newName,
        string newNIC,
        string newPhone,
        string newAddress,
        int newAge)
    {
        // Save the unique Holder ID
        holderID = newHolderID;

        // Save name, NIC and phone using the Person class
        setPersonalDetails(newName, newNIC, newPhone);
        address = newAddress;
        age = newAge;
    }

    // Saves the selected plan and coverage amount
    void assignPlan(string newPlan, double newCoverageAmount)
    {
        selectedPlan = newPlan;
        coverageAmount = newCoverageAmount;
        // Mark that a plan has been selected
        planSelected = true;
    }

    // Returns the Holder ID
    string getHolderID() const
    {
        return holderID;
    }

    // Returns the address
    string getAddress() const
    {
        return address;
    }

    // Returns the age
    int getAge() const
    {
        return age;
    }

    // Returns the selected policy plan
    string getSelectedPlan() const
    {
        return selectedPlan;
    }

    // Returns the coverage amount
    double getCoverageAmount() const
    {
        return coverageAmount;
    }

    // Checks whether a plan has been selected
    bool hasPlan() const
    {
        return planSelected;
    }
};
