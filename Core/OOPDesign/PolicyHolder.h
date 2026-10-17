#pragma once

#include <string>

using std::string;
#include "Person.h"

// PolicyHolder inherits common personal details from Person.
class PolicyHolder : public Person
{
private:
    string holderID;
    string address;
    int age;
    string selectedPlan;
    double coverageAmount;
    bool planSelected;

public:
    PolicyHolder()
    {
        holderID = "";
        address = "";
        age = 0;
        selectedPlan = "";
        coverageAmount = 0.0;
        planSelected = false;
    }

    void setHolderDetails(
        string newHolderID,
        string newName,
        string newNIC,
        string newPhone,
        string newAddress,
        int newAge)
    {
        holderID = newHolderID;
        setPersonalDetails(newName, newNIC, newPhone);
        address = newAddress;
        age = newAge;
    }

    void assignPlan(string newPlan, double newCoverageAmount)
    {
        selectedPlan = newPlan;
        coverageAmount = newCoverageAmount;
        planSelected = true;
    }

    string getHolderID() const
    {
        return holderID;
    }

    string getAddress() const
    {
        return address;
    }

    int getAge() const
    {
        return age;
    }

    string getSelectedPlan() const
    {
        return selectedPlan;
    }

    double getCoverageAmount() const
    {
        return coverageAmount;
    }

    bool hasPlan() const
    {
        return planSelected;
    }
};
