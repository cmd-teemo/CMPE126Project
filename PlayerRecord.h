#ifndef PLAYER_RECORD_H
#define PLAYER_RECORD_H

#include "player.h"
#include <vector>
#include <iostream>
#include <string>

class PlayerRecord {
private:
    static const int TABLE_SIZE = 15; // Hash table size
    std::vector<Player*> hashTable[TABLE_SIZE]; // Array of vectors for separate chaining

    // Hash function
    int hashFunction(int id) const {
        return id % TABLE_SIZE;
    }

public:
    ~PlayerRecord() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (size_t j = 0; j < hashTable[i].size(); ++j) {
                if (hashTable[i][j]) {
                    delete hashTable[i][j]; // Free dynamically allocated memory
                    hashTable[i][j] = nullptr; // Nullify the pointer to avoid double deletion
                }
            }
            hashTable[i].clear();
        }
    }

    // Add a player
    bool addRecord(int id, const std::string& name, int age, const std::string& position, double marketValue) {
        int index = hashFunction(id);

        for (size_t i = 0; i < hashTable[index].size(); ++i) {
            if (hashTable[index][i]->getId() == id) {
                std::cerr << "Player with ID " << id << " already exists.\n";
                return false;
            }
        }

        hashTable[index].push_back(new Player(id, name, age, position, marketValue));
        return true;
    }

    // Get a player by ID
    Player* getPlayerById(int id) const {
        int index = hashFunction(id);

        for (size_t i = 0; i < hashTable[index].size(); ++i) {
            if (hashTable[index][i]->getId() == id) {
                return hashTable[index][i];
            }
        }

        return nullptr; // Not found
    }
};

#endif // PLAYER_RECORD_H
