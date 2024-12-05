#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <iostream>
#include <iomanip> // For formatting output

class Tree {
private:
    Node* root{};

    static Node* insert(const Node* node, int id, const std::string& name, int age, double marketValue) {
        if (!node) {
            return new Node(id, name, age, marketValue);
        }
        if (age < node->age) {
            node->left = insert(node->left, id, name, age, marketValue);
        } else {
            node->right = insert(node->right, id, name, age, marketValue);
        }
        return node;
    }

    static void inOrderTraversal(const Node* node) {
        if (node) {
            inOrderTraversal(node->left);
            std::cout << std::fixed << std::setprecision(0); // Ensure fixed-point notation
            std::cout << "ID: " << node->id << ", Name: " << node->name
                      << ", Age: " << node->age << ", Market Value: $" << node->marketValue << '\n';
            inOrderTraversal(node->right);
        }
    }

    static void deleteTree(const Node* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    Tree() : root(nullptr){}

    ~Tree() {
        deleteTree(root);
    }

    void addPlayer(int id, const std::string& name, int age, double marketValue) {
        root = insert(root, id, name, age, marketValue);
    }

    static void display() {
        std::cout << "\n--- Players by Age (Binary Tree In-Order Traversal) ---\n";
        inOrderTraversal(root);
    }
};

#endif // TREE_H
