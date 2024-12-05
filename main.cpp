

#include "PlayerRecord.h"
#include "tree.h"
#include <iostream>
#include <queue>
#include <iomanip>
#include <utility>

// Priority queue structure
struct ShoppingCartPlayer {
    int id;
    std::string name;
    int age;
    double marketValue;

    ShoppingCartPlayer(int id, std::string  name, int age, double marketValue)
        : id(id), name(std::move(name)), age(age), marketValue(marketValue) {}

    bool operator<(const ShoppingCartPlayer& other) const {
        return marketValue < other.marketValue;
    }
};

int main() {
    PlayerRecord record;
    Tree ageTree;

    // Add player records
    record.addRecord(1, "Ronaldo", 39, "Striker", 20000000);
    record.addRecord(2, "Messi", 37, "Left Winger", 15000000);
    record.addRecord(3, "Mbappe", 27, "Striker", 200000000);
    record.addRecord(4, "Haaland", 24, "Striker", 190000000);
    record.addRecord(5, "Vini Jr", 25, "Right Winger", 210000000);
    record.addRecord(6, "Rodrigo", 39, "Striker", 140000000);
    record.addRecord(7, "Wirtz", 21, "Striker", 90000000);
    record.addRecord(8, "Alvarez", 23, "Striker", 50000000);
    record.addRecord(9, "Rashford", 25, "Right Winger", 70000000);
    record.addRecord(10, "Foden", 26, "Left Winger", 100000000);
    record.addRecord(11, "Kane", 33, "Striker", 90000000);
    record.addRecord(12, "Lewandowski", 34, "Striker", 60000000);
    record.addRecord(13, "Yamal", 17, "Left Winger", 200000000);
    record.addRecord(14, "Endrick", 18, "Striker", 75000000);
    record.addRecord(15, "Son", 28, "Right Winger", 20000000);


    std::priority_queue<ShoppingCartPlayer> shoppingCart;

    bool continueShopping = true;
    while (continueShopping) {
        int playerKey;
        std::cout << "\nEnter player key (1-15): ";
        std::cin >> playerKey;

        Player* selectedPlayer = record.getPlayerById(playerKey);
        if (selectedPlayer) {
            std::cout << std::fixed << std::setprecision(0);
            std::cout << "\n--- Player Details ---\n";
            std::cout << "ID: " << selectedPlayer->id
                      << ", Name: " << selectedPlayer->name
                      << ", Age: " << selectedPlayer->age
                      << ", Position: " << selectedPlayer->position
                      << ", Market Value: $" << selectedPlayer->marketValue << '\n';

            char addToCart;
            std::cout << "Add player to shopping cart? (Y/N): ";
            std::cin >> addToCart;

            if (std::toupper(addToCart) == 'Y') {
                ShoppingCartPlayer cartPlayer(selectedPlayer->id, selectedPlayer->name, selectedPlayer->age, selectedPlayer->marketValue);
                shoppingCart.push(cartPlayer);
                ageTree.addPlayer(selectedPlayer->id, selectedPlayer->name, selectedPlayer->age, selectedPlayer->marketValue);
                std::cout << "Player " << selectedPlayer->name << " added to shopping cart.\n";
            } else {
                std::cout << "Player not added to shopping cart.\n";
            }
        } else {
            std::cout << "Player with key " << playerKey << " not found.\n";
        }

        char lookMore;
        std::cout << "Wanna look more players? (Y/N): ";
        std::cin >> lookMore;

        if (std::toupper(lookMore) != 'Y') {
            continueShopping = false;
        }
    }

    std::cout << "\n--- Shopping Cart (Sorted by Market Value) ---\n";
    while (!shoppingCart.empty()) {
        ShoppingCartPlayer p = shoppingCart.top();
        shoppingCart.pop();
        std::cout << "ID: " << p.id << ", Name: " << p.name << ", Market Value: $" << p.marketValue << '\n';
    }

    Tree::display();

    return 0;
}