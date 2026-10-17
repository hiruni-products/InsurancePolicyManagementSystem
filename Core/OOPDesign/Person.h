#pragma once

#include <string>

using std::string;

// Base class for common personal details.
class Person
{
protected:
    string name;
    string nic;
    string phone;

public:
    Person()
    {
        name = "";
        nic = "";
        phone = "";
    }

    Person(string newName, string newNIC, string newPhone)
    {
        name = newName;
        nic = newNIC;
        phone = newPhone;
    }

    void setPersonalDetails(string newName, string newNIC, string newPhone)
    {
        name = newName;
        nic = newNIC;
        phone = newPhone;
    }

    string getName() const
    {
        return name;
    }

    string getNIC() const
    {
        return nic;
    }

    string getPhone() const
    {
        return phone;
    }
};
