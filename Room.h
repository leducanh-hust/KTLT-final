#pragma once
#ifndef ROOM_H
#define ROOM_H
#include<iostream>
#include<string>
#include "Customer.h"

using namespace std;

class Room
{
protected:
    int roomNumber;
    double price;
    bool occupied;
    string roomType;

public:
    Room(int roomNumber, double price, string roomType)
    {
        this->roomNumber = roomNumber;
        this->price = price;
        this->occupied = false;
        this->roomType = roomType;
    }

    virtual void printDetails()
    {
        cout << "Room Number: " << roomNumber << endl;
        cout << "Price: " << price << endl;
        cout << "Occupied: " << (occupied ? "Yes" : "No") << endl;
        cout << "Room Type: " << roomType << endl;
    }

    int getRoomNumber()
    {
        return roomNumber;
    }

    string getRoomType()
    {
        return roomType;
    }

    double getPrice()
    {
        return price;
    }

    virtual bool isOccupied()
    {
        return occupied;
    }

    virtual void book(Customer *customer)
    {
        occupied = true;
        cout << "Room " << roomNumber << " booked by " << customer->getName() << endl;
    }

    virtual void release()
    {
        occupied = false;
        cout << "Room " << roomNumber << " released" << endl;
    }
    friend double PrepareTheBill(Room r);
};

#endif // !ROOM_H

