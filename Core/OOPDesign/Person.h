#pragma once

#include <string>

using std::string;

// Base class for common personal details.
class Person
{
protected:
    // Common personal details available to child classes
    string name;
    string nic;
    string phone;

public:
    // Default constructor - creates an empty Person object
    Person()
    {
        name = "";
        nic = "";
        phone = "";
    }

    // Constructor - creates a Person with given details
    Person(string newName, string newNIC, string newPhone)
    {
        name = newName;
        nic = newNIC;
        phone = newPhone;
    }

    // Stores the common personal details
    void setPersonalDetails(string newName, string newNIC, string newPhone)
    {
        name = newName;
        nic = newNIC;
        phone = newPhone;
    }

    // Returns the person's name
    string getName() const
    {
        return name;
    }

    // Returns the NIC
    string getNIC() const
    {
        return nic;
    }

    // Returns the phone number
    string getPhone() const
    {
        return phone;
    }
};
