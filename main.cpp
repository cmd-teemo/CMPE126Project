
#include "PlayerRecord.h"
#include "tree.h"
#include "player.h"
#include <iostream>
#include <queue>
#include <iomanip>
#include <cctype>
#include <vector>

// Comparator class for priority_queue
class CompareMarketValue {
public:
    bool operator()(Player* a, Player* b) {
        return a->getPlayerMarketValue() < b->getPlayerMarketValue(); // Higher value first
    }
};

int main() {
    PlayerRecord record;
    Tree ageTree;

    // Add players to the record
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

    // Priority queue for shopping cart
    std::priority_queue<Player*, std::vector<Player*>, CompareMarketValue> shoppingCart;

    // Dynamic interaction for user selection
    bool continueShopping = true;
    while (continueShopping) {
        int playerKey;
        Player* selectedPlayer = nullptr;

        // Input player ID
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

        // Add to shopping cart
        char addToCart;
        std::cout << "Add player to shopping cart? (Y/N): ";
        std::cin >> addToCart;

        if (std::toupper(addToCart) == 'Y') {
            shoppingCart.push(selectedPlayer); // Automatically sorted by market value
            ageTree.addPlayer(selectedPlayer); // Add to tree for in-order traversal
            std::cout << "Player added to shopping cart.\n";
        } else {
            std::cout << "Player not added to shopping cart.\n";
        }

        // Ask if user wants to continue
        char lookMore;
        std::cout << "Wanna look more players? (Y/N): ";
        std::cin >> lookMore;

        if (std::toupper(lookMore) != 'Y') {
            continueShopping = false;
        }
    }

    // Display shopping cart
    std::cout << "\n--- Shopping Cart (Sorted by Market Value) ---\n";
    std::priority_queue<Player*, std::vector<Player*>, CompareMarketValue> sortedCart = shoppingCart;
    while (!sortedCart.empty()) {
        sortedCart.top()->displayInfo(); // Top player (highest market value)
        sortedCart.pop();                // Remove after displaying
    }

    // Display binary tree (players sorted by age)
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
