#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int number;
    std::string role; // Changed from status to role

public:
    // Default constructor
    Player() : name("Unknown"), number(0), role("Benched") {} // Default role set to "Bench"

    // Parameterized constructor
    Player(std::string playerName, int playerNumber, std::string playerRole) 
        : name(playerName), number(playerNumber), role(playerRole) {}

    // Function to set player name
    void setName(const std::string& playerName) {
        name = playerName;
    }

    // Function to get player name
    std::string getName() const {
        return name;
    }

    // Function to set player number
    void setNumber(int playerNumber) {
        number = playerNumber;
    }

    // Function to get player number
    int getNumber() const {
        return number;
    }

    // Function to set player role
    void setRole(const std::string& playerRole) {
        role = playerRole;
    }

    // Function to get player role
    std::string getRole() const {
        return role;
    }

    // Method to display player information
    void displayInfo() const {
        std::cout << "Player Name: " << name << std::endl;
        std::cout << "Player Number: " << number << std::endl;
        std::cout << "Player Role: " << role << std::endl; // Updated to role
    }
};

