#include "DLList.hpp"
#include <iostream>

Node::Node() {
    this->next = nullptr;
    this->prev = nullptr;
}

Node::Node(int d) {
    this->data = d;
    this->next = nullptr;
    this->prev = nullptr;
}

DLList::DLList() {
    this->head = nullptr;
    this->tail = nullptr;
}
DLList::DLList(const DLList& list) {
    Node* tmp = list.head;
    for (int i = 0; i < list.size; i++) {
        this->pushBack(tmp->data);
        tmp = tmp->next;
        }
}

DLList::~DLList() {
    int count = this->size;
    for (int i = 0; i < count; i++) {
        this->popFront();
    }
    std::cout << "Destruction complite " << std::endl;
}

void DLList::pushBack(int data) {
    Node* newNode = new Node(data);

    if (!this->size) {
        this->head = newNode;
        this->tail = newNode;
        this->size++;
        return;
   	}

    newNode->prev = this->tail;
    this->tail->next = newNode;
    this->tail = newNode;
    this->size++;
}

void DLList::pushFront(int data) {
    Node* newNode = new Node(data);

    if (!this->size) {
        this->head = newNode;
        this->tail = newNode;
        this->size++;
        return;
    }

    newNode->next = this->head;
    this->head->prev = newNode;
    this->head = newNode;
    this->size++;
}

void DLList::popBack() {
    if (!this->size) {
        std::cout << "The list is empty" << std::endl;
        return;
    }

    if (this->size == 1) {
        delete this->head;
        this->size--;
        return;
    }

    this->tail = this->tail->prev;
    delete this->tail->next;
    this->size--;
}

void DLList::popFront() {
    if (!this->size) {
        std::cout << "The list is empty" << std::endl;
        return;
    }

    if (this->size == 1) {
        delete this->head;
        this->size--;
        return;
    }

    this->head = this->head->next;
    delete this->head->prev;
    this->size--;
}

void DLList::insert(int position, int data) {
    if (this->size < position) {
        std::cout << "You can't insert at this position, because of the list size is lower than the position" << std::endl;
        return;
    }

    if (!this->size) {
        pushFront(data);
    }

    if (position == 1) {
        this->pushFront(data);
        return;
    }

    Node* newElement = new Node(data);
    Node* tmp = this->head;
    for (int i = 0; i < position - 1; i++) {
        tmp = tmp->next;
    }

    newElement->prev = tmp->prev;
    newElement->next = tmp;
    tmp->prev = newElement;
    newElement->prev->next = newElement;
    this->size++;

    tmp = nullptr;
}

void DLList::remove(int data) {
    Node* tmp = this->head;
    for (int i = 0; i < this->size; i++) {
        if (tmp->data == data) {
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            delete tmp;
            this->size--;
            return;
        }
        tmp = tmp->next;
    }
    std::cout << "there isn't { " << data << "} element in this list" << std::endl;
}

void DLList::print() {
    if (!this->size) {
        std::cout << "There isn't any element in this list" << std::endl;
        return;
    }

    Node* tmp = this->head;

    for (int i = 0; i < this->size; i++) {
        std::cout << tmp->data << " ";
        tmp = tmp->next;
    }

    std::cout << std::endl;
}
