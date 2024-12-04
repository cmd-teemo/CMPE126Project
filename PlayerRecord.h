#ifndef PLAYERRECORD_H
#define PLAYERRECORD_H

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "Player.h" // Include the Player class

class PlayerRecord {
private:
    static const int tableSize = 50; // Size of the hash table
    Player* table[50]; // Array of lists for chaining

    // Hash function to calculate index
    int hashFunction(int playerKey) const {
        return playerKey % tableSize;
    }

public:
    PlayerRecord(); // Constructor
    ~PlayerRecord(); // Destructor

    // Function to add a new player
    void addRecord(int key, std::string name, int age, std::string position, double marketValue) {
        
    }

    // Function to display all players
    void displayAllPlayers() const;

    // Function to find a player by key
    Player* findPlayer(int playerKey);
};

#endif // PLAYERRECORD_H