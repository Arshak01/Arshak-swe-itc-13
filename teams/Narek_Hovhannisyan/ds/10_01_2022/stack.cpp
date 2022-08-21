#include <iostream>

class Node {
private:
    int data;
    Node* prev;
public:
    Node() {}

    Node(int d) {
        this->data = d;
        this->prev = nullptr;
    }

    ~Node() {
        //delete this;
    }

    Node* getPrev() const {
        return this->prev;
    }

    void setPrev(Node* n) {
        this->prev = n;
    }

    int getData() const {
        return this->data;
    }

    void setData(int d) {
        this->data = d;
    }
};

class Stack {
private:
    Node* head;
    int size;
public:
    Stack() : size(0) {
        this->head = nullptr;
    }

    ~Stack() {
    }

    void push(int val) {
        Node* tmp = new Node(val);
        if (this->size == 0) {
            this->head = tmp;
        }
        tmp->setPrev(this->head);
        this->head = tmp;
        this->size += 1;
    }

    void pop() {
        if(isEmpty()) {
            std::cout << "the stack is empty" << std::endl;
            return;
        }
        Node* ptr = this->head;
        this->head = this->head->getPrev();
        delete ptr;
        this->size -= 1;
    }

    int getSize() const {
        return this->size;
    }

    bool isEmpty() const {
        return this->size == 0;
    }

    int top() const {
        return this->head->getData();
    }

};

int main() {
    Stack s;
    std::cout << "just created stack, isEmpty(): " << s.isEmpty() << std::endl;
    s.push(12);
    std::cout << "the top element data is: " << s.top() << std::endl;
    std::cout << "pushed one elenent, isEmpty(): " << s.isEmpty() << std::endl;
    s.pop();
    std::cout << "poped one elenent, isEmpty(): " << s.isEmpty() << std::endl;
    s.push(22);
    std::cout << "pushed 22" << std::endl;
    s.push(41);
    std::cout << "pushed 41" << std::endl;
    s.push(53);
    std::cout << "pushed 53" << std::endl;
    s.push(94);
    std::cout << "pushed 94" << std::endl;
    std::cout << "the top element data is: " << s.top() << std::endl;
    s.pop();
    std::cout << "pop()" << std::endl;
    s.pop();
    std::cout << "pop()" << std::endl;
    std::cout << "the top element data is: " << s.top() << std::endl;
    std::cout << "stack size is " << s.getSize() << std::endl;


    return 0;
 }
