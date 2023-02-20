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
};

#endif // !CUSTOMER_H