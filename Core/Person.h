#pragma once

// Standard C++ string type.
#include <string>

// Person is the BASE CLASS.
// It keeps personal details that are common to every policy holder.
class Person
{
protected:
    // protected means a derived class can use these variables directly.
    std::string name;
    std::string nic;
    std::string phone;

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
    Person(std::string newName, std::string newNIC, std::string newPhone)
    {
        name = newName;
        nic = newNIC;
        phone = newPhone;
    }

    // This public method changes all common personal details.
    void setPersonalDetails(std::string newName, std::string newNIC, std::string newPhone)
    {
        name = newName;
        nic = newNIC;
        phone = newPhone;
    }

    // Getter method for name.
    std::string getName() const
    {
        return name;
    }

    // Getter method for NIC.
    std::string getNIC() const
    {
        return nic;
    }

    // Getter method for phone number.
    std::string getPhone() const
    {
        return phone;
    }
};
