#ifndef TREE_H
#define TREE_H

#include "player.h"
#include <iostream>

class Node {
public:
    Player* player;
    Node* left;
    Node* right;

    Node(Player* player) : player(player), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    Node* root;

    Node* insert(Node* node, Player* player) {
        if (!node) {
            return new Node(player);
        }
        if (player->getAge() < node->player->getAge()) {
            node->left = insert(node->left, player);
        } else {
            node->right = insert(node->right, player);
        }
        return node;
    }

    void inOrderTraversal(Node* node) const {
        if (node) {
            inOrderTraversal(node->left);
            node->player->display();
            inOrderTraversal(node->right);
        }
    }

    void freeTree(Node* node) {
        if (node) {
            freeTree(node->left);
            freeTree(node->right);
            delete node->player;
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