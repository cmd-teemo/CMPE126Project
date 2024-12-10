// Project Assignment: Soccer Player Market
// Rohan Khadka, Cung Sin Mawi, Leo Nguyen
// CMPE 126: Sec 07
// Professor Faramarz Mortezaie
// December 5th, 2024

#include "PlayerRecord.h"
#include "tree.h"
#include <iostream>
#include <queue>
#include <iomanip>
#include <cctype>

int main() {
    PlayerRecord record;
    Tree ageTree;

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

    std::priority_queue<Player*> shoppingCart;

    bool continueShopping = true;
    while (continueShopping) {
        int playerKey;
        Player* selectedPlayer = nullptr;

        do {
            std::cout << "\nEnter player key (1-15): ";
            std::cin >> playerKey;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid number.\n";
                continue;
            }

            selectedPlayer = record.getPlayerById(playerKey);
            if (!selectedPlayer) {
                std::cout << "Invalid player ID. Please try again.\n";
            }
        } while (!selectedPlayer);

        selectedPlayer->displayInfo();

        char addToCart;
        std::cout << "Add player to shopping cart? (Y/N): ";
        std::cin >> addToCart;

        if (std::toupper(addToCart) == 'Y') {
            shoppingCart.push(selectedPlayer);
            ageTree.addPlayer(selectedPlayer);
            std::cout << "Player added to shopping cart.\n";
        } else {
            std::cout << "Player not added to shopping cart.\n";
        }

        char lookMore;
        std::cout << "Wanna look more players? (Y/N): ";
        std::cin >> lookMore;

        if (std::toupper(lookMore) != 'Y') {
            continueShopping = false;
        }
    }

    std::cout << "\n--- Shopping Cart (Sorted by Market Value) ---\n";
    std::priority_queue<Player*> sortedCart = shoppingCart;
    while (!sortedCart.empty()) {
        sortedCart.top()->displayInfo();
        sortedCart.pop();
    }
    ageTree.display();

    std::cout << "\n ---- Which player do you want to purchase? --- \n";
    int purchaseKey;
    std::cin >> purchaseKey;

    bool purchased = false;
    while (!shoppingCart.empty()) {
        Player* player = shoppingCart.top();
        shoppingCart.pop();

        if (player->getPlayerKey() == purchaseKey) {
            std::cout << "Congratulation. You have Purchased : " << player->getPlayerName() << " . Here is his information \n";
            player->displayInfo();
            purchased = true;
            break;
        }
    }

    if (!purchased) {
        std::cout << "Player with ID " << purchaseKey << " is not in your cart.\n";
    }
    std:: cout << "Thank you.\n";

    return 0;
}
