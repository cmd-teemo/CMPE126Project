#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player {
private:
    int playerKey;             // Unique identifier for the player
    std::string playerName;    // Name of the player
    int playerAge;             // Age of the player
    std::string playerPosition; // Position of the player (e.g., Forward, Defender)
    double playerMarketValue;   // Market value of the player

public:
    // Constructors
    Player() 
        : playerKey(0), playerName("Unknown"), playerAge(0), playerPosition("Unknown"), playerMarketValue(0.0) {}

    Player(int key, std::string name, int age, std::string position, double marketValue) 
        : playerKey(key), playerName(name), playerAge(age), playerPosition(position), playerMarketValue(marketValue) {}

    // Setters
    void setPlayerKey(int key) {
        playerKey = key;
    }

    void setPlayerName(const std::string& name) {
        playerName = name;
    }

    void setPlayerAge(int age) {
        playerAge = age;
    }

    void setPlayerPosition(const std::string& position) {
        playerPosition = position;
    }

    void setPlayerMarketValue(double marketValue) {
        playerMarketValue = marketValue;
    }

    // Getters
    int getPlayerKey() const {
        return playerKey;
    }

    std::string getPlayerName() const {
        return playerName;
    }

    int getPlayerAge() const {
        return playerAge;
    }

    std::string getPlayerPosition() const {
        return playerPosition;
    }

    double getPlayerMarketValue() const {
        return playerMarketValue;
    }

    // Display player information
    void displayInfo() const {
        std::cout << "Player Key: " << playerKey << std::endl;
        std::cout << "Player Name: " << playerName << std::endl;
        std::cout << "Player Age: " << playerAge << std::endl;
        std::cout << "Player Position: " << playerPosition << std::endl;
        std::cout << "Player Market Value: $" << playerMarketValue << std::endl;
    }
};

#endif // PLAYER_H