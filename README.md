
# Parking Management System

## Overview

The Parking Management System is a C++ application that allows users to manage parking slots, including adding, removing, and viewing parked vehicles. The system keeps track of parking fees and provides real-time updates on parking availability. This project demonstrates the use of object-oriented programming, file handling, and basic user authentication.

## Features

- **User  Registration and Login**: Users can register and log in to the system.
- **View Available Parking Slots**: Displays the current status of parking slots (available/occupied).
- **Park a Vehicle**: Allows users to park a vehicle and assign it to a parking slot.
- **Remove a Vehicle**: Allows users to remove a vehicle from a parking slot.
- **Calculate Parking Fees**: Automatically calculates fees based on the duration of parking.
- **Search for Vehicles**: Allows users to search for a vehicle by license plate number.
- **Admin Panel**: An admin interface to manage parking slots and view statistics.

## Installation

1. **Clone the Repository**:
   - Run the following command to clone the repository:
     ```
     git clone https://github.com/Tru0711/parking-management-system.git
     cd parking-management-system
     ```

2. **Compile the Code**:
   - Make sure you have a C++ compiler installed (like g++). Compile the code using:
     ```
     g++ -o parking_management_system main.cpp
     ```

3. **Run the Application**:
   - Execute the compiled program:
     ```
     ./parking_management_system
     ```

## Usage

1. **Register a User**: Choose option 1 to register a new user. You will need to provide a User ID, Username, and Password.
2. **Login**: Choose option 2 to log in with your credentials.
3. **Manage Vehicles**: After logging in, you can:
   - View available parking slots (Option 1)
   - Park a vehicle (Option 2)
   - Remove a vehicle (Option 3)
   - Calculate parking fees (Option 4)
   - Search for a vehicle (Option 5)
   - Logout (Option 6)

## File Structure

```
parking-management-system/
│
├── main.cpp                # Main application code
├── users.txt               # User data file (created automatically)
└── README.md               # Project documentation
```

## Contributing

Contributions are welcome! If you have suggestions for improvements or new features, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- This project was developed as part of a learning exercise in C++ programming and object-oriented design.


