#ifndef PLAYERRECORD_H
#define PLAYERRECORD_H

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "Player.h" // Include the Player class
#include "heap.h" // Include the Heap Class

class PlayerRecord {
private:
    static const int tableSize = 50; // Size of the hash table
    Player* table[50]; // Array of lists for chaining
    Heap* playersort;
    // Hash function to calculate index
    
    int hash(int playerKey) const {
        return playerKey % tableSize;
    }

public:
    PlayerRecord(); // Constructor
    ~PlayerRecord(); // Destructor

    // Function to add a new player
    

    bool addRecord(int key, std::string name, int age, std::string position, double marketValue) {
        /*
Time Complexity:
        Average case: ( O(1) ) for search, insert, and delete operations.
        Worst case: ( O(n) ) if the table becomes too full.
Space Complexity:
    Auxiliary space is ( O(50)) ).
    */
        // Create a new Player to add.
        Player* value = new Player(key,name,age,position,marketValue);
        value->SetEmptySinceStart(false);

      // Get the key's hash codes
      int hashCode = hash(key);

      // First search for the key in the table. If found, update bucket's value.
      for (int i = 0; i < tableSize; i++) {
         int bucketIndex = (hashCode + i ) % tableSize;
         
         // An empty-since-start bucket implies the key is not in the table
         if (table[bucketIndex]->IsEmptySinceStart()) {
            break;
         }
         
         if (!table[bucketIndex]->IsEmptyAfterRemoval()) {
            // Check if the non-empty bucket has the key
            if (key == table[bucketIndex]->getPlayerKey()) {
               // Update the value
               table[bucketIndex] = value;
               playersort->insert(key); // ********** REPLACE FOR BST
               return true;
            }
         }
      }

      
      // The key is not in the table, so insert into first empty bucket
      for (int i = 0; i < tableSize; i++) {
         int bucketIndex = (hashCode + i) % tableSize;
         if (table[bucketIndex]->IsEmptySinceStart()) {
            table[bucketIndex] = value;
            playersort->insert(key); // ********** REPLACE FOR BST
            return true;
         }
      }
      delete value;
      return false; // no empty bucket found
   }
   // RemoveRecord function
bool removeRecord(int key) {
    /*
Time Complexity:
        Average case: ( O(1) ) for search, insert, and delete operations.
        Worst case: ( O(n) ) if the table becomes too full.
Space Complexity:
    Auxiliary space is ( O(50)) ).
    */
        Player* value = new Player();
        value->SetEmptySinceStart(false);
        value->SetEmptyAfterRemoval(true);
        int hashCode = hash(key);
        for (int i = 0; i < tableSize; i++) {
         int bucketIndex = (hashCode + i ) % tableSize;
         
         // An empty-since-start bucket implies the key is not in the table
         if (table[bucketIndex]->IsEmptySinceStart()) {
            break;
         }
         
         if (!table[bucketIndex]->IsEmptyAfterRemoval()) {
            // Check if the non-empty bucket has the key
            if (key == table[bucketIndex]->getPlayerKey()) {
               // Update the value to null
               table[bucketIndex] = value;
               return true;
            }
         }
      }

      // The key is not in the table, so insert into first empty bucket
      for (int i = 0; i < tableSize; i++) {
         int bucketIndex = (hashCode + i) % tableSize;
         if (table[bucketIndex]->IsEmptySinceStart()) {
            table[bucketIndex] = value;
            return true;
         }
      }
      delete value;
      return false; // no empty bucket found
   }
    // Function to display all players
    void displayAllPlayers() const;

    // Function to find a player by key
    Player* findPlayer(int playerKey);
};

#endif // PLAYERRECORD_H