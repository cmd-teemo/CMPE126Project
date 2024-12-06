#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <iomanip>

class Player {
private:
    int id;
    std::string name;
    int age;
    std::string position;
    double marketValue;

public:
    // Constructor
    Player(int id, const std::string& name, int age, const std::string& position, double marketValue)
        : id(id), name(name), age(age), position(position), marketValue(marketValue) {}

    // Getters
    int getId() const { return id; }
    const std::string& getName() const { return name; }
    int getAge() const { return age; }
    const std::string& getPosition() const { return position; }
    double getMarketValue() const { return marketValue; }

    // Display player information
    void display() const {
        std::cout << std::fixed << std::setprecision(0)
                  << "ID: " << id
                  << ", Name: " << name
                  << ", Age: " << age
                  << ", Position: " << position
                  << ", Market Value: $" << marketValue << '\n';
    }
};

#endif // PLAYER_H