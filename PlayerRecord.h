#ifndef PLAYERRECORD_H
#define PLAYERRECORD_H

#include <iostream>
#include <string>
#include "player.h" // Include the Player class

class PlayerRecord {
private:
    static const int tableSize = 53; // Size of the hash table
    Player* table[tableSize]; // Array for the hash table

    int hash(int playerKey) const {
        return playerKey % tableSize;
    }

public:
    PlayerRecord() {
        for (int i = 0; i < tableSize; i++) {
            table[i] = nullptr;
        }
    }

    ~PlayerRecord() {
        for (int i = 0; i < tableSize; i++) {
            delete table[i];
            table[i] = nullptr;
        }
    }

    bool addRecord(int key, std::string name, int age, std::string position, double marketValue) {
        Player* value = new Player(key, name, age, position, marketValue );

        for (int i = 0; i < tableSize; i++) {
            int bucketIndex = (key + i) % tableSize;

            if (table[bucketIndex] == nullptr || table[bucketIndex]->IsEmptySinceStart()) {
                delete table[bucketIndex]; // Prevent memory leaks
                table[bucketIndex] = value;
                return true;
            }

            if (table[bucketIndex]->getPlayerKey() == key) {
                delete table[bucketIndex]; // Replace old record
                table[bucketIndex] = value;
                return true;
            }
        }

        delete value; // Clean up if insertion fails
        return false;
    }

    bool removeRecord(int key) {
        for (int i = 0; i < tableSize; i++) {
            int bucketIndex = (key + i) % tableSize;

            if (table[bucketIndex] == nullptr || table[bucketIndex]->IsEmptySinceStart()) {
                break;
            }

            if (!table[bucketIndex]->IsEmptyAfterRemoval() && table[bucketIndex]->getPlayerKey() == key) {
                delete table[bucketIndex];
                table[bucketIndex] = nullptr; // Mark as empty
                return true;
            }
        }
        return false;
    }

    void displayAllPlayers() const {
        for (int i = 0; i < tableSize; i++) {
            if (table[i] != nullptr && !table[i]->IsEmptyAfterRemoval()) {
                std::cout << "Index " << i << ": ";
                table[i]->displayInfo(); // Assuming Player has displayPlayerInfo()
            }
        }
    }

    Player* getPlayerById(int playerKey) {
        for (int i = 0; i < tableSize; i++) {
            int bucketIndex = (playerKey + i) % tableSize;

            if (table[bucketIndex] == nullptr || table[bucketIndex]->IsEmptySinceStart()) {
                break;
            }

            if (!table[bucketIndex]->IsEmptyAfterRemoval() && table[bucketIndex]->getPlayerKey() == playerKey) {
                return table[bucketIndex];
            }
        }
        return nullptr;
    }
};

#endif // PLAYERRECORD_H
