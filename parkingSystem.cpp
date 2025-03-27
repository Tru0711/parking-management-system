#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <string>
#include <algorithm>

using namespace std;

// Vehicle class to store vehicle details
class Vehicle {
public:
    string licensePlate;
    string vehicleType;
    string ownerName;
    time_t entryTime;
    int parkingSlot;

    Vehicle(string lp, string vt, string on, time_t et, int ps) 
        : licensePlate(lp), vehicleType(vt), ownerName(on), entryTime(et), parkingSlot(ps) {}

    // Overloading the equality operator
    bool operator==(const Vehicle& other) const {
        return licensePlate == other.licensePlate;
    }
};

// ParkingSlot class to manage parking slot details
class ParkingSlot {
public:
    int slotNumber;
    bool isOccupied;

    ParkingSlot(int sn) : slotNumber(sn), isOccupied(false) {}
};

// User class to manage user details
class User {
public:
    string userID;
    string username;
    string password;

    User(string id, string uname, string pass) : userID(id), username(uname), password(pass) {}
};

// ParkingManagementSystem class to manage the overall system
class ParkingManagementSystem {
private:
    vector<ParkingSlot> slots;
    vector<Vehicle> vehicles;
    vector<User> users;

public:
    ParkingManagementSystem(int totalSlots) {
        for (int i = 1; i <= totalSlots; i++) {
            slots.push_back(ParkingSlot(i));
        }
        loadUsers();
    }

    // Load users from a file
    void loadUsers() {
        ifstream userFile("users.txt");
        string id, uname, pass;
        while (userFile >> id >> uname >> pass) {
            users.push_back(User(id, uname, pass));
        }
        userFile.close();
    }

    // Save users to a file
    void saveUsers() {
        ofstream userFile("users.txt");
        for (auto &user : users) {
            userFile << user.userID << " " << user.username << " " << user.password << endl;
        }
        userFile.close();
    }

    // User registration
    void registerUser (string id, string uname, string pass) {
        users.push_back(User(id, uname, pass));
        saveUsers();
        cout << "User  registered successfully!" << endl;
    }

    // User login
    bool loginUser (string uname, string pass) {
        for (auto &user : users) {
            if (user.username == uname && user.password == pass) {
                return true;
            }
        }
        return false;
    }

    // Display available parking slots
    void displayAvailableSlots() {
        cout << "Available Parking Slots: ";
        for (auto &slot : slots) {
            if (!slot.isOccupied) {
                cout << slot.slotNumber << " ";
            }
        }
        cout << endl;
    }

    // Park a vehicle
    void parkVehicle(string licensePlate, string vehicleType, string ownerName) {
        for (auto &slot : slots) {
            if (!slot.isOccupied) {
                time_t now = time(0);
                vehicles.push_back(Vehicle(licensePlate, vehicleType, ownerName, now, slot.slotNumber));
                slot.isOccupied = true;
                cout << "Vehicle parked in slot: " << slot.slotNumber << endl;
                return;
            }
        }
        cout << "No available slots!" << endl;
    }

    // Remove a vehicle
    void removeVehicle(string licensePlate) {
        for (auto it = vehicles.begin(); it != vehicles.end(); ++it) {
            if (it->licensePlate == licensePlate) {
                for (auto &slot : slots) {
                    if (slot.slotNumber == it->parkingSlot) {
                        slot.isOccupied = false;
                        break;
                    }
                }
                vehicles.erase(it);
                cout << "Vehicle removed from slot: " << it->parkingSlot << endl;
                return;
            }
        }
        cout << "Vehicle not found!" << endl;
    }

    // Calculate parking fees
    void calculateFees(string licensePlate) {
        for (auto &vehicle : vehicles) {
            if (vehicle.licensePlate == licensePlate) {
                time_t now = time(0);
                double duration = difftime(now, vehicle.entryTime) / 3600; // duration in hours
                double fee = duration * 10; // Assuming fee is 10 units per hour
                cout << "Parking fee for vehicle " << licensePlate << ": " << fee << " units." << endl;
                return;
            }
        }
        cout << "Vehicle not found!" << endl;
    }

    // Search for a vehicle
    void searchVehicle(string licensePlate) {
        for (auto &vehicle : vehicles) {
            if (vehicle.licensePlate == licensePlate) {
                cout << "Vehicle found: " << vehicle.licensePlate << ", Owner: " << vehicle.ownerName 
                     << ", Slot: " << vehicle.parkingSlot << endl;
                return;
            }
        }
        cout << "Vehicle not found!" << endl;
    }
};

// Main function to run the Parking Management System
int main() {
    ParkingManagementSystem pms(10); // Initialize with 10 parking slots
    int choice;
    string username, password, licensePlate, vehicleType, ownerName, userID;

    while (true) {
        cout << "1. Register User\n2. Login User\n3. Exit\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter User ID: ";
            cin >> userID;
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            pms.registerUser (userID, username, password);
        } else if (choice == 2) {
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            if (pms.loginUser (username, password)) {
                cout << "Login successful!" << endl;
                while (true) {
                    cout << "1. View Available Slots\n2. Park Vehicle\n3. Remove Vehicle\n4. Calculate Fees\n5. Search Vehicle\n6. Logout\nChoose an option: ";
                    cin >> choice;

                    if (choice == 1) {
                        pms.displayAvailableSlots();
                    } else if (choice == 2) {
                        cout << "Enter License Plate: ";
                        cin >> licensePlate;
                        cout << "Enter Vehicle Type: ";
                        cin >> vehicleType;
                        cout << "Enter Owner Name: ";
                        cin >> ownerName;
                        pms.parkVehicle(licensePlate, vehicleType, ownerName);
                    } else if (choice == 3) {
                        cout << "Enter License Plate: ";
                        cin >> licensePlate;
                        pms.removeVehicle(licensePlate);
                    } else if (choice == 4) {
                        cout << "Enter License Plate: ";
                        cin >> licensePlate;
                        pms.calculateFees(licensePlate);
                    } else if (choice == 5) {
                        cout << "Enter License Plate: ";
                        cin >> licensePlate;
                        pms.searchVehicle(licensePlate);
                    } else if (choice == 6) {
                        cout << "Logging out..." << endl;
                        break;
                    } else {
                        cout << "Invalid option!" << endl;
                    }
                }
            } else {
                cout << "Invalid username or password!" << endl;
            }
        } else if (choice == 3) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid option!" << endl;
        }
    }

    return 0;
}