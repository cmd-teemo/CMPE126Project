#ifndef NODE_H
#define NODE_H

#include <string>


// Node structure for a binary tree
struct Node {
    int id;
    std::string name;
    int age;
    std::string position;
    double marketValue;
    Node* left;
    Node* right;

    Node(int id, std::string  name, int age, std::string  position, double marketValue)
        : id(id), name(std::move(name)), age(age),position(std::move(position)), marketValue(marketValue), left(nullptr), right(nullptr) {}
};

#endif // NODE_H