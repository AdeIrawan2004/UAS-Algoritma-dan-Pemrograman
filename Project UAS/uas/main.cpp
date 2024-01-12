#include <iostream>
#include <vector>

class Guest {
public:
    std::string name;
    int roomNumber;

    Guest(const std::string& n, int room) : name(n), roomNumber(room) {}
};

class Hotel {
private:
    std::vector<Guest> guests;

public:
    void checkIn() {
        std::string name;
        int roomNumber;

        std::cout << "Enter guest name: ";
        std::cin >> name;

        std::cout << "Enter room number: ";
        std::cin >> roomNumber;

        guests.push_back(Guest(name, roomNumber));
        std::cout << name << " has checked in to room " << roomNumber << "." << std::endl;
    }

    void displayGuests() {
        std::cout << "\nGuest List:\n";
        for (const auto& guest : guests) {
            std::cout << "Name: " << guest.name << ", Room: " << guest.roomNumber << std::endl;
        }
        std::cout << std::endl;
    }

    void checkOut() {
        int roomNumber;
        std::cout << "Enter room number to check out: ";
        std::cin >> roomNumber;

        auto it = std::remove_if(guests.begin(), guests.end(),
            [roomNumber](const Guest& guest) { return guest.roomNumber == roomNumber; });

        if (it != guests.end()) {
            guests.erase(it, guests.end());
            std::cout << "Guest from room " << roomNumber << " has checked out." << std::endl;
        }
        else {
            std::cout << "No guest found in room " << roomNumber << "." << std::endl;
        }
    }
};

int main() {
    Hotel hotel;

    int choice;

    do {
        std::cout << "\nHotel Management System\n";
        std::cout << "1. Check In\n";
        std::cout << "2. Display Guests\n";
        std::cout << "3. Check Out\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            hotel.checkIn();
            break;
        case 2:
            hotel.displayGuests();
            break;
        case 3:
            hotel.checkOut();
            break;
        case 0:
            std::cout << "Exiting the program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}