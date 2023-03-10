#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

#include "Customer.h"
#include "Room.h"
#include "DeluxeRoom.h"
#include "Hotel.h"
#include "Hotel.cpp"

using namespace std;

double PrepareTheBill(Room r, int nights)
{
    return r.getPrice() * nights;
}

int main()
{
    Hotel hotel;
    // add some rooms
    Room *room1 = new Room(101, 50, "Standard");
    Customer * customer = new Customer("Minh Hieu", "01223343", 101);
    room1->book(customer);
    hotel.addCustomer(customer);

    Room *room2 = new Room(102, 60, "Standard");
    Room *room3 = new DeluxeRoom(201, 100, true, 2, true);
    Room *room4 = new DeluxeRoom(202, 120, false, 1, false);
    hotel.add1(room1);
    hotel.add1(room2);
    hotel.add1(room3);
    hotel.add1(room4);

    int choice;
    do
    {
        cout << endl;
        cout << "\t\t\t\t\t\t***********************************************" << endl;
        cout << "\t\t\t\t\t\t*           HOTEL MANAGEMENT SYSTEM           *" << endl;
        cout << "\t\t\t\t\t\t***********************************************" << endl
             << endl;
        cout << "\t\t\t\t\t\tWelcome to the Hotel Management System!" << endl
             << endl;
        cout << "1. View Room List" << endl;
        cout << "2. Book a Room" << endl;
        cout << "3. Release a Room" << endl;
        cout << "4. Find Rooms in Budget" << endl;
        cout << "5. Search Rooms by Type" << endl;
        cout << "6. Add a room" << endl;
        cout << "7. Delete a Room" << endl;
        cout << "8. Invoice" << endl;
        cout << "9. Print Customer Information" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << endl;
            if (hotel.getSize() == 0)
            {
                cout << "No room has been created yet" << endl;
                Sleep(2000);
            }

            else
            {
                hotel.viewRoomList();
                cout << endl;
                Sleep(1000);
            }
        }

        if (choice == 2)
        {
            int roomNumber;
            string name, phoneNumber;
            cout << "Enter room number: ";
            cin >> roomNumber;
            if (hotel.findRoom(roomNumber) == -1)
                cout << "Room does not exist";
            else
            {
                cout << "Enter customer name: ";
                cin.ignore(100, '\n');
                getline(cin, name);
                cout << "Enter customer phone number: ";
                cin >> phoneNumber;
                Customer *customer = new Customer(name, phoneNumber, roomNumber);
                hotel.addCustomer(customer);
                for (Room *room : hotel.getVectorRoom())
                {
                    if (room->getRoomNumber() == roomNumber && room->isOccupied() == true)
                    {
                        cout << "Room has already been booked! Please choose another room.";
                        break;
                    }
                    if (room->getRoomNumber() == roomNumber && room->isOccupied() == false)
                    {
                        room->book(customer);
                        cout << endl;
                        cout << "Customer Information:" << endl;
                        cout << *customer;
                        break;
                    }
                }
            }
            
            
            
            
            Sleep(2000);
        }
        if (choice == 3)
        {
            cout << "Enter room number: ";
            int roomNumber;
            cin >> roomNumber;
            if (hotel.findRoom(roomNumber) == -1)
                cout << "Room does not exist." << endl;
            else
            {
                for (Room *room : hotel.getVectorRoom())
                {
                    if (room->getRoomNumber() == roomNumber)
                    {
                        room->release();
                        break;
                    }
                }
            }
        }

        if (choice == 4)
        {
            double budget;
            cout << "Enter your budget: ";
            cin >> budget;
            cout << "Available rooms in budget:" << endl;
            for (Room *room : hotel.findRoomsInBudget(budget))
            {
                room->printDetails();
                cout << endl;
            }
            Sleep(3000);
        }

        if (choice == 5)
        {
            string roomType;
            cout << "Enter room type(Deluxe / Standard): ";
            cin >> roomType;
            cout << "Available " << roomType << " rooms:" << endl;
            cout << endl;
            for (Room *room : hotel.searchRoomsByType(roomType))
            {
                room->printDetails();
                cout << endl;
            }
        }

        if (choice == 6)
        {
            hotel.addRoom();
            Sleep(2000);
        }

        if (choice == 7)
        {
            cout << "Enter room number you want to delete: ";
            int roomNum;
            cin >> roomNum;
            hotel.deleteRoom(roomNum);
        }
        if (choice == 8)
        {
            int night;
            int num;
            cout << "Enter room number you want to book: ";
            cin >> num;
            if (hotel.findRoom(num) == -1)
            {
                cout << "Room doesn't exist" << endl;
            }
            else
            {
                cout << "Enter number of nights you want to stay: ";
                cin >> night;
                for (Room *room : hotel.getVectorRoom())
                {
                    if (room->getRoomNumber() == num)
                    {
                        cout << "Your bill is: " << PrepareTheBill(*room, night) << endl;
                    }
                }
            }
        }

        if(choice == 9)
        {
            cout << endl;
            hotel.printCustomer();
        }
        if (choice == 10)
        {
            cout << "Exiting the system..." << endl;
        }

    } while (choice != 10);

    return 0;
}
