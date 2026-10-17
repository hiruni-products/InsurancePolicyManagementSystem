#pragma once

#include <string>

using std::string;
#include "Person.h"

// PolicyHolder is a DERIVED CLASS.
// ': public Person' shows public inheritance.
class PolicyHolder : public Person
{
private:
    // These data members are private to demonstrate encapsulation.
    string holderID;
    string address;
    int age;
    string selectedPlan;
    double coverageAmount;
    bool planSelected;

public:
    // Default constructor.
    PolicyHolder()
    {
        holderID = "";
        address = "";
        age = 0;
        selectedPlan = "";
        coverageAmount = 0.0;
        planSelected = false;
    }

    // Public method used when registering a policy holder.
    void setHolderDetails(
        string newHolderID,
        string newName,
        string newNIC,
        string newPhone,
        string newAddress,
        int newAge)
    {
        // Store the unique holder ID.
        holderID = newHolderID;

        // Use a method inherited from Person to store common personal details.
        setPersonalDetails(newName, newNIC, newPhone);

        // Store address and age in this derived class.
        address = newAddress;
        age = newAge;
    }

    // Public method used to connect a plan to this holder.
    void assignPlan(string newPlan, double newCoverageAmount)
    {
        selectedPlan = newPlan;
        coverageAmount = newCoverageAmount;
        planSelected = true;
    }

    // Getter for holder ID.
    string getHolderID() const
    {
        return holderID;
    }

    // Getter for address.
    string getAddress() const
    {
        return address;
    }

    // Getter for age.
    int getAge() const
    {
        return age;
    }

    // Getter for selected plan.
    string getSelectedPlan() const
    {
        return selectedPlan;
    }

    // Getter for coverage amount.
    double getCoverageAmount() const
    {
        return coverageAmount;
    }

    // Returns true only after a plan has been selected.
    bool hasPlan() const
    {
        return planSelected;
    }
};
