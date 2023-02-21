#pragma once

#ifndef HOTEL_H
#define HOTEL_H
#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>
#include "Room.h"
#include "DeluxeRoom.h"

using namespace std;
class Hotel
{
private:
    vector<Room *> rooms;
public:
    vector<Room *> getVectorRoom()
    {
        return rooms;
    }

    int getSize();

    int findRoom(int roomNum);

    void add1(Room *room);

    void addRoom();


    void deleteRoom(int roomNumber);

    void viewRoomList();

    vector<Room *> findRoomsInBudget(double budget);

    vector<Room *> searchRoomsByType(std::string roomType);
};


#endif // !HOTEL_H