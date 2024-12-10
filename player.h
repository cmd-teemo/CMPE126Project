#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <iomanip>


class Player {
private:
    double playerMarketValue;   // Market value of the player
    int playerKey;             // Unique identifier for the player
    std::string playerName;    // Name of the player
    int playerAge;             // Age of the player
    std::string playerPosition; // Position of the player (e.g., Forward, Defender)
    
    bool EmptySinceStart; // Used for Hash Table
    bool EmptyAfterRemoval; // Used for Hash Table after removal


public:
    // Constructors
    Player() 
        : playerKey(0), playerName("Unknown"), playerAge(0), playerPosition("Unknown"), playerMarketValue(0.0), EmptySinceStart(true), EmptyAfterRemoval(false) {}

    Player(double marketValue, std::string name, int age, std::string position, int key) 
        : playerMarketValue(marketValue), playerName(name), playerAge(age), playerPosition(position),playerKey(key) , EmptySinceStart(false), EmptyAfterRemoval(false) {}

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
        /* std::cout << "Player Key: " << playerKey << std::endl;
        std::cout << "Player Name: " << playerName << std::endl;
        std::cout << "Player Age: " << playerAge << std::endl;
        std::cout << "Player Position: " << playerPosition << std::endl;
        std::cout << "Player Market Value: $" << std::fixed << std::setprecision(0) << playerMarketValue << std::endl; */
        std::cout << std::fixed << std::setprecision(0)
                  << "ID: " << playerKey
                  << ", Name: " << playerName
                  << ", Age: " << playerAge
                  << ", Position: " << playerPosition
                  << ", Market Value: $" << playerMarketValue << '\n';
    }

    bool IsEmptySinceStart() {
        return EmptySinceStart;
    }

    void SetEmptySinceStart(bool value) {
        EmptySinceStart = value;
    }
    bool IsEmptyAfterRemoval() {
        return EmptyAfterRemoval;
    }
    void SetEmptyAfterRemoval(bool value) {
        EmptyAfterRemoval = value;
    }

    bool operator>=(const Player& other) const {
        return playerMarketValue >= other.getPlayerMarketValue();
    }

    bool operator<=(const Player& other) const {
        return playerMarketValue <= other.getPlayerMarketValue();
    }
    bool operator<(const Player& other) const {
        return playerMarketValue < other.getPlayerMarketValue();
    }
    
    bool operator>(const Player& other) const {
        return playerMarketValue > other.getPlayerMarketValue();
    }

    bool operator==(const Player& other) const {
        return playerMarketValue == other.getPlayerMarketValue();
    }
};

#endif // PLAYER_H