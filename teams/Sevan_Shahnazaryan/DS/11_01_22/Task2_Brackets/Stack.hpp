#ifndef STACK
#define STACK
#include "Node.hpp"

class Stack {
private:
    unsigned int length;
    Node *head;

public:
    Stack();

    void pop();

    void push(char val);

    int size() const;

    bool isEmpty() const;

    char top() const;

    void print();

    ~Stack();

};

#endif
