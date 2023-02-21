#pragma once

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
#include <string>

using namespace std;

class Customer
{
private:
    string name;
    string phoneNumber;

public:
    Customer(string name, string phoneNumber)
    {
        this->name = name;
        this->phoneNumber = phoneNumber;
    }

    std::string getName()
    {
        return name;
    }

    std::string getPhoneNumber()
    {
        return phoneNumber;
    }
    friend ostream& operator<<(ostream& os, const Customer& customer)
    {
        os << "Name: " << customer.name << endl;
        os << "Phone number: " << customer.phoneNumber << endl;
        return os;
    }
};

#endif // !CUSTOMER_H