#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;
class Room {
public:
    int roomNumber;
    bool isReserved;
    string guestName;

    Room(int number) : roomNumber(number), isReserved(false) {}

    void reserveRoom(const string& guest) {
        isReserved = true;
        guestName = guest;
    }

    void checkoutRoom() {
        isReserved = false;
        guestName = "";
    }
};

class Hotel {
private:
    vector<Room> rooms;

public:
    Hotel(int numRooms) {
        for (int i = 1; i <= numRooms; ++i) {
            rooms.push_back(Room(i));
        }
    }

    void displayRooms() const {
        cout << "Room\tStatus\tGuest\n";
        for (const auto& room : rooms) {
            cout << room.roomNumber << "\t"
                << (room.isReserved ? "Reserved" : "Available") << "\t"
                << room.guestName << "\n";
        }
    }

    bool checkAvailability(int roomNumber) const {
        return rooms[roomNumber - 1].isReserved;
    }

    void reserveRoom(int roomNumber, const std::string& guest) {
        rooms[roomNumber - 1].reserveRoom(guest);
    }

    void checkoutRoom(int roomNumber) {
        rooms[roomNumber - 1].checkoutRoom();
    }
};

int main() {
    const int numRooms = 10;
    Hotel hotel(numRooms);

    int choice;
    do {
        cout << "\nHotel Management System\n";
        cout << "1. Display Rooms\n";
        cout << "2. Check Room Availability\n";
        cout << "3. Reserve Room\n";
        cout << "4. Checkout\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            hotel.displayRooms();
            break;
        case 2: {
            int roomNumber;
            cout << "Enter room number: ";
            cin >> roomNumber;
            if (hotel.checkAvailability(roomNumber)) {
                cout << "Room " << roomNumber << " is reserved.\n";
            }
            else {
                cout << "Room " << roomNumber << " is available.\n";
            }
            break;
        }
        case 3: {
            int roomNumber;
            string guest;
            cout << "Enter room number: ";
            cin >> roomNumber;
            cout << "Enter guest name: ";
            cin >> guest;
            hotel.reserveRoom(roomNumber, guest);
            cout << "Room " << roomNumber << " reserved for " << guest << ".\n";
            break;
        }
        case 4: {
            int roomNumber;
            cout << "Enter room number: ";
            cin >> roomNumber;
            hotel.checkoutRoom(roomNumber);
            cout << "Guest checked out from Room " << roomNumber << ".\n";
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}