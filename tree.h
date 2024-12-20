#ifndef TREE_H
#define TREE_H

#include "player.h"
//#include "node.h"
#include <iostream>

class Node {
public:
    Player* value;
    Node* left;
    Node* right;

    Node(Player* player) : value(player), left(nullptr), right(nullptr) {}
}; 

class Tree {
private:
    Node* root;

    Node* insert(Node* node, Player* player) {
        if (!node) {
            return new Node(player);
        }
        if (player->getPlayerAge() < node->value->getPlayerAge()) {
            node->left = insert(node->left, player);
        } else {
            node->right = insert(node->right, player);
        }
        return node;
    }

    void inOrderTraversal(Node* node) const {
        if (node) {
            inOrderTraversal(node->left);
            node->value->displayInfo();
            inOrderTraversal(node->right);
        }
    }

    void freeTree(Node* node) {
        if (node) {
            freeTree(node->left);
            freeTree(node->right);
            if (node->value) {
                delete node->value;
                node->value = nullptr;
            }
            delete node;
        }
    }

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        freeTree(root);
    }

    void addPlayer(Player* player) {
        root = insert(root, player);
    }

    void display() const {
        std::cout << "\n--- Players by Age (Binary Tree In-Order Traversal) ---\n";
        inOrderTraversal(root);
    }
};

#endif // TREE_H