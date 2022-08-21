#include "Vector.hpp"
#include <cassert>
#include <iostream>

//To avoid code duplication
void Vector::extender() {
	if(this->length == this->maxSize) {
		this->maxSize = this->maxSize + (this->maxSize / 2);
		int *tmp = new int[this->maxSize];
		for(int i = 0; i < this->length; ++i) {
			tmp[i] = this->vector[i];
		}
		delete[] this->vector;
		this->vector = tmp;
		tmp = NULL;
	  }
}

Vector::Vector() {
	this->vector = new int[this->defSize];
	this->maxSize = defSize;
	this-> length = 0;
}

Vector::Vector(int size, int defaultValue = 0) {
	this->vector = new int[size];
	if(defaultValue == 0) {
		this->length = 0;
	} else {
		this->length = size;
	}
	for(int i = 0; i < size; ++i) {
		this->vector[i] = defaultValue;
	}
	this->maxSize = defSize;
}

int Vector::size() const {
	return this->length;
}

int Vector::capacity() const {
	return this->maxSize;
}

void Vector::push(int val) {
	extender();
	this->vector[length] = val;
	this->length++;
}

void Vector::pop() {
	if(length == 0) {
		return;
	}
	this->length--;
	this->vector[length] = 0;
}

void Vector::insert(int index, int data) {
	extender();
	for(int i = length - 1; i >= index; --i) {
		this->vector[i+1] = this->vector[i];
	}
	this->vector[index] = data;
	this->length++;
}

int& Vector::operator[] (int n) {
	assert(n < this->length);
	return this->vector[n];
}

void Vector::print() {
	for(int i = 0; i < length; ++i) {
		std::cout << "vector[" << i << "] = " << this->vector[i] << std:: endl;
	}
}

Vector::~Vector() {
	delete[] this->vector;
	this->vector = NULL;
}


