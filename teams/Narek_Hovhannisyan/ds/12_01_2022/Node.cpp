#include "Node.hpp"

Node::Node() {
        this->next = nullptr;
        this->prev = nullptr;
}

Node::Node(int d) {
    this->data = d;
    this->next = nullptr;
    this->prev = nullptr;
}