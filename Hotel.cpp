#include "Hotel.h"

int Hotel::getSize()
{
    return rooms.size();
}

int Hotel::findRoom(int roomNum)
{
    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i]->getRoomNumber() == roomNum)
        {
            return i;
        }
    }
    return -1;
}

void Hotel::add1(Room *room)
{
    rooms.push_back(room);

}

void Hotel::addRoom()
{
    int roomNum, price;
    string roomType;
    bool oceanView = false, balcony = false;
    int numBeds = 0;

    cout << "Enter room number: ";
    cin >> roomNum;

    // Check if the room already exists
    if (findRoom(roomNum) != -1)
    {
        cout << "Room already exists!" << endl;
        return;
    }

    cout << "Enter room price: ";
    cin >> price;

    cout << "Enter room type: "<<endl;
    cout << " 1.Standard Room"<<endl;
    cout << " 2.eluxe Room"<<endl;
            int check;
            cout<<" enter your choice: ";
            cin >> check;
            switch(check)
            {
                case 1:
                   roomType = "Standard"; break;
                case 2:
                    roomType = "Deluxe"; break;
                default : roomType="Standard";break;
                    
            }

    if (roomType == "Deluxe")
    {
        cout << "Does the room have an ocean view (true=1 or false=0, please enter number)? ";
        cin >> oceanView;
        cout << "Enter the number of beds: ";
        cin >> numBeds;

        cout << "Does the room have a balcony (true=1 or false=0, please enter number)? ";
        cin >> balcony;

        Room *newRoom = new DeluxeRoom(roomNum, price, oceanView, numBeds, balcony);
        rooms.push_back(newRoom);
    }
    else
    {
        Room *newRoom = new Room(roomNum, price, "Standard");
        rooms.push_back(newRoom);
    }

    cout << "Room added successfully!" << endl;
}

void Hotel::deleteRoom(int roomNumber)
{
    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i]->getRoomNumber() == roomNumber)
        {
            rooms.erase(rooms.begin() + i);
            break;
        }
    }
}

void Hotel::viewRoomList()
{
    cout << "\t\t\tRoom List:" << endl;
    for (Room *room : rooms)
    {
        room->printDetails();
        Sleep(1000);
        cout << endl;
    }
}


vector<Room *> Hotel::findRoomsInBudget(double budget)
{
    vector<Room *> availableRooms;
    for (Room *room : rooms)
    {
        if (!room->isOccupied() && room->getPrice() <= budget)
        {
            availableRooms.push_back(room);
        }
    }
    return availableRooms;
}


vector<Room *> Hotel::searchRoomsByType(std::string roomType)
{
    std::vector<Room *> matchingRooms;
    for (Room *room : rooms)
    {
        if (!room->isOccupied() && room->getRoomType() == roomType)
        {
            matchingRooms.push_back(room);
        }
    }
    return matchingRooms;
}
