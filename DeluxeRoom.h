#pragma once
#ifndef DELUXE_H
#define DELUXE_H

#include <iostream>
#include<string>
#include "Room.h"

using namespace  std;

class DeluxeRoom : public Room
{
private:
    bool oceanView;
    int numBeds;
    bool balcony;

public:
    DeluxeRoom(int roomNumber, double price, bool oceanView, int numBeds, bool balcony) : Room(roomNumber, price, "Deluxe")
    {
        this->oceanView = oceanView;
        this->numBeds = numBeds;
        this->balcony = balcony;
    }

    void printDetails() override
    {
        std::cout << "Room Number: " << roomNumber << endl;
        std::cout << "Price: " << price << endl;
        std::cout << "Occupied: " << (occupied ? "Yes" : "No") << endl;
        std::cout << "Room Type: " << roomType << endl;
        std::cout << "Ocean View: " << (oceanView ? "Yes" : "No") << endl;
        std::cout << "Number of Beds: " << numBeds << endl;
        std::cout << "Balcony: " << (balcony ? "Yes" : "No") << endl;
    }
};

#endif // !DELUXE_H
