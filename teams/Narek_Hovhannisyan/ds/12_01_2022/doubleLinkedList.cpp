#include "doubleLinkedList.hpp"

#include <iostream>

DoubleLinkedList::DoubleLinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& list) {
    Node* tmp = list.head;
    for (int i = 0; i < list.size; i++) {
        this->pushBack(tmp->data);
        tmp = tmp->prev;
    }
}

DoubleLinkedList::~DoubleLinkedList() {
    int count = this->size;
    for (int i = 0; i < count; i++) {
        this->popFront();
        std::cout << "log -------------- size = " << this->size << std::endl;
    }
}

void DoubleLinkedList::pushBack(int data) {
    Node* newNode = new Node(data);

    if (!this->size) {
        this->head = newNode;
        this->tail = newNode;
        this->size++;
        return;
    }

    newNode->next = this->tail;
    this->tail->prev = newNode;
    this->tail = newNode;
    this->size++;
}

void DoubleLinkedList::pushFront(int data) {
    Node* newNode = new Node(data);

    if (!this->size) {
        this->head = newNode;
        this->tail = newNode;
        this->size++;
        return;
    }

    newNode->prev = this->head;
    this->head->next = newNode;
    this->head = newNode;
    this->size++;
}

void DoubleLinkedList::popBack() {
    if (!this->size) {
        std::cout << "the list is empty" << std::endl;
        return;
    }

    if (this->size == 1) {
        delete this->head;
        this->size--;
        return;
    }

    this->tail = this->tail->next;
    delete this->tail->prev;
    this->size--;
}

void DoubleLinkedList::popFront() {
    if (!this->size) {
        std::cout << "the list is empty" << std::endl;
        return;
    }

    if (this->size == 1) {
        delete this->head;
        this->size--;
        return;
    }

    this->head = this->head->prev;
    delete this->head->next;
    this->size--;
}

void DoubleLinkedList::insert(int position, int data) {
    if (this->size < position) {
        std::cout << "you can't insert at " << position;
        std::cout << " position, because of the list size is ";
        std::cout << this->size << std::endl;
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
        tmp = tmp->prev;
    }

    newElement->next = tmp->next;
    newElement->prev = tmp;
    tmp->next = newElement;
    newElement->next->prev = newElement;
    this->size++;

    tmp = nullptr;
}

void DoubleLinkedList::remove(int data) {
    Node* tmp = this->head;
    for (int i = 0; i < this->size; i++) {
        if (tmp->data == data) {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
            this->size--;
            return;
        }
        tmp = tmp->prev;
    }
    std::cout << "there is no " << data << " in the list" << std::endl;
}

void DoubleLinkedList::print() {
    std::cout << "printing double linked list ..." << std::endl;

    if (!this->size) {
        std::cout << "the list is empty" << std::endl;
        return;
    }

    Node* tmp = this->head;

    for (int i = 0; i < this->size; i++) {
        std::cout << tmp->data << " ";
        tmp = tmp->prev;
    }

    std::cout << std::endl;
}
