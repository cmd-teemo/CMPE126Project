#ifndef PLAYERRECORD_H
#define PLAYERRECORD_H

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "Player.h" // Include the Player class
#include "tree.h" // Include the Tree Class
#include "node.h" // Include node class

class PlayerRecord {
private:
    static const int tableSize = 50; // Size of the hash table
    Player* table[50]; // Array of lists for chaining
    Tree* playerTree;
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
      //int hashCode = hash(key);

      // First search for the key in the table. If found, update bucket's value.
      for (int i = 0; i < tableSize; i++) {
         int bucketIndex = (key + i ) % tableSize;
         
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
         int bucketIndex = (key + i) % tableSize;
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

   // Get the key's hash codes (FOR DOUBLE HASHING)
      //int hashCode = hash(key);
        Player* value = new Player();
        value->SetEmptySinceStart(false);
        value->SetEmptyAfterRemoval(true);
        for (int i = 0; i < tableSize; i++) {
         int bucketIndex = (key + i ) % tableSize;
         
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
         int bucketIndex = (key + i) % tableSize;
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
    Player* getRecord(int playerKey) {
       //  int hashKey = hash(playerKey); (FOR DOUBLE HASHING)
        for (int i = 0; i < tableSize; i++) {
            int bucketIndex = (playerKey + i) % tableSize;

            // Check if EmptySinceStart, go to next loop
            if (table[bucketIndex]->IsEmptySinceStart()) {
                break;
            }
            // Check if EmptyAfterRemoval is False
            else if(!table[bucketIndex]->IsEmptyAfterRemoval()) {
                if (playerKey == table[bucketIndex]->getPlayerKey()) {
                    // Return the Player pointer from table
                    return table[bucketIndex];
                }
            }
        }

        // For Loop to check empty from start without hash
        for (int i = 0; i < tableSize; i++) {
            int bucketIndex = (playerKey + i) % tableSize;
            if (!table[bucketIndex]->IsEmptyAfterRemoval() && !table[bucketIndex]->IsEmptySinceStart()){
                if (playerKey == table[bucketIndex]->getPlayerKey()) {
                    return table[bucketIndex];
                }
            }
        }
        // IF NOT FOUND RETURN NULLTPR
        return nullptr;
    }
};

#endif // PLAYERRECORD_H