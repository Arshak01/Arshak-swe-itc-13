#include <iostream>
#include "classVector.h"

Vector::Vector() {
	this ->	arr = new int[30];
	this -> capacity = 30;
	this -> current = 0;
}

Vector::Vector(int size) {
	this -> arr = new int[size];
	this -> capacity = size;
}

Vector::~Vector() {
	delete[] this -> arr;
}

int Vector::operator [] (int i) {
	if (i < this -> current) {
		return this -> arr[i];
	} else {
		std::cout << "Does Not Exist!" << std::endl;
	       	exit(1);	
		return 0;
	}
}

void Vector::push(int data) {
	if (this -> current == this -> capacity) {
		int* tmp = new int[2 * this -> capacity];
		for (int i = 0; i < this -> capacity; ++i) {
			tmp[i] = this -> arr[i];
		}

		delete[] this -> arr;
		this -> capacity *= 2;
		this -> arr = tmp;
	}

	this -> arr[this -> current] = data;
	this -> current++;
}

void Vector::pop() {
	this -> current--;
}

void Vector::pushAtIndex(int data, int index) {
	if (index == this -> capacity) {
		push(data);
	} else {
		this -> arr[index] = data;
	}
}

int Vector::currentSize() {
	return this -> current;
}

int Vector::capacitySize() {
	return this -> capacity;
}

void Vector::printVector() {
	for (int i = 0; i < this -> current; ++i) {
		std::cout << this -> arr[i] << " ";
	}
	std::cout << std::endl;
}
