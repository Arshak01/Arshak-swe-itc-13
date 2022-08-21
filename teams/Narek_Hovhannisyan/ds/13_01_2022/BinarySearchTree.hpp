#include "Node.hpp"

struct BinarySearchTree {
    Node* root;

    BinarySearchTree();

    bool insert(int);

    bool del(int);

    void printPreparation(Node*);

    void print();
};