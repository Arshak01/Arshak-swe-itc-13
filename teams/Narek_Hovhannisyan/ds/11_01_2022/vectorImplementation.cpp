#include "vectorImplementation.hpp"
#include <iostream>

Vector::Vector() {}

Vector::Vector(int s) {
    this->size = s;
    this->capacity = s;
    this->arr = new int[s];
}

Vector::Vector(int s, int defaultValue) {
    this->size = s;
    this->capacity = s;
    this->arr = new int[s];
    for (int i = 0; i < s; i++) {
        this->arr[i] = defaultValue;
    }
}

Vector::~Vector() {
    delete[] this->arr;
}

int Vector::getSize() const {
    return this->size;
}

int Vector::getCapacity() const {
    return this->capacity;
}

void Vector::push(int val) {
    if (this->capacity <= this->size) {
        this->capacity *= 2;
    }
    int *tmp = new int[capacity];
    for (int i = 0; i < this->size; i++) {
        tmp[i] = this->arr[i];
    }
    this->size += 1;

    tmp[this->size - 1] = val;
    delete[] this->arr;
    this->arr = tmp;
}

void Vector::pop() {
    this->size -= 1;
    int *tmp = new int[this->capacity];
    for (int i = 0; i < this->size; i++) {
        tmp[i] = this->arr[i];
    }
    delete this->arr;
    this->arr = tmp;
}

void Vector::insert(int index, int value) {
    if (this->capacity <= this->size) {
        this->capacity *= 2;
    }
    int *tmp = new int[this->capacity];
    for (int i = 0; i < index; i++) {
        tmp[i] = this->arr[i];
    }
    tmp[index] = value;
    this->size += 1;
    for (int i = index + 1; i < this->size; i++) {
        tmp[i] = this->arr[i - 1];
    }
    delete[] arr;
    this->arr = tmp;
}

void Vector::vDelete(int index) {
    int *tmp = new int[this->capacity];
    for (int i = 0; i < index; i++) {
        tmp[i] = this->arr[i];
    }
    for (int i = index + 1; i < this->size; i++) {
        tmp[i - 1] = this->arr[i];
    }
    this->size -= 1;
    delete this->arr;
    this->arr = tmp;
}

int Vector::operator [] (int index) {
    return this->arr[index];
}

void Vector::print() const {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->arr[i] << " ";
    }
    std::cout << std::endl;
}

void Vector::autoFill(int from, int to) {
    for (int i = 0; i < this->size; i++) {
        this->arr[i] = rand() % (to - from) + from;
    }
}

void Vector::autoFill() {
    for (int i = 0; i < this->size; i++) {
        this->arr[i] = rand() % 90 + 10;
    }
}