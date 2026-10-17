#pragma once

// Standard C++ string type.
#include <string>

using std::string;

// TG/2024/2194 - OOP DESIGN: Person base class, constructors, access specifiers and getters.
// Person is the BASE CLASS.
// It keeps personal details that are common to every policy holder.
class Person
{
protected:
    // protected means a derived class can use these variables directly.
    string name;
    string nic;
    string phone;

public:
    // Default constructor.
    // It starts a Person object with empty values.
    Person()
    {
        name = "";
        nic = "";
        phone = "";
    }

    // Parameterized constructor.
    // It starts a Person object with values given by the user/program.
    Person(string newName, string newNIC, string newPhone)
    {
        name = newName;
        nic = newNIC;
        phone = newPhone;
    }

    // This public method changes all common personal details.
    void setPersonalDetails(string newName, string newNIC, string newPhone)
    {
        name = newName;
        nic = newNIC;
        phone = newPhone;
    }

    // Getter method for name.
    string getName() const
    {
        return name;
    }

    // Getter method for NIC.
    string getNIC() const
    {
        return nic;
    }

    // Getter method for phone number.
    string getPhone() const
    {
        return phone;
    }
};
