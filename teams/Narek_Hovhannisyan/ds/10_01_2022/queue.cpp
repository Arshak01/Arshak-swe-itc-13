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

    int getData() const {
        return this->data;
    }

    void setData(int d) {
        this->data = d;
    }

    Node* getPrev() const {
        return this->prev;
    }

    void setPrev(Node* n) {
        this->prev = n;
    }
};

class Queue {
private:
    int size;
    Node* head;
    Node* tail;

public:
    Queue() : size(0) {
        this->head = nullptr;
        this->tail = nullptr;
    }

    int getSize() const {
        return this->size;
    }

    bool isEmpty() const {
        return this->size == 0;
    }

    void push(int val) {
        Node* tmp = new Node(val);
        if (isEmpty()) {
            this->head = tmp;
            this->tail = tmp;
        }
        if (this->size == 1) {
            this->head->setPrev(tmp);
        }
        this->tail->setPrev(tmp);
        this->tail = tmp;
        this->size += 1;
    }

    void shift() {
        if (isEmpty()) {
            std::cout << "there are no elements in the queue";
            return;
        }
        Node* ptr = this->head;
        this->head = this->head->getPrev();
        delete ptr;
        this->size -= 1;
    }

    int front() const {
        try {
            if (!isEmpty()) {
                return this->head->getData();
            } else {
                throw std::string("error! there is no data");
            }
        } 
        catch (std::string s) {
            std::cout << std::endl;
            std::cout << s << std::endl;
            return 0;
        }
    }

    int back() const {
        try {
            if (!isEmpty()) {
                return this->tail->getData();
            } else {
                throw std::string("error! there is no data");
            }
        }
        catch (std::string s) {
            std::cout << std::endl;
            std::cout << s << std::endl;
            return 0;
        }
    }
};

int main() {
    Queue q;
    std::cout << "is empty: " << q.isEmpty() << std::endl;
    q.push(20);
    std::cout << "pushed 20" << std::endl;
    q.push(31);
    std::cout << "pushed 31" << std::endl;
    q.push(50);
    std::cout << "pushed 50" << std::endl;
    q.push(11);
    std::cout << "pushed 11" << std::endl;

    std::cout << "the last element is " << q.back() << std::endl;
    std::cout << "the first element is " << q.front() << std::endl;
    std::cout << std::endl;

    q.shift();
    std::cout << "shift()" << std::endl;
    std::cout << "the first element become " << q.front() << std::endl;
    q.shift();
    std::cout << "shift()" << std::endl;
    std::cout << "the first element become " << q.front() << std::endl;
    q.shift();
    std::cout << "shift()" << std::endl;
    std::cout << "the first element become " << q.front() << std::endl;
    q.shift();
    std::cout << "size = " << q.getSize() << std::endl;
    std::cout << "the first element become " << q.front() << std::endl;

    return 0;
}
