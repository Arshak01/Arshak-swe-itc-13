#include <iostream>
#include "vector.h"

Vector::Vector() {
	this->arr = new int[1];
	this->n = 1;
	this->current = 0;
}

Vector::~Vector() {
	delete[] arr;
}

void Vector::push(int data) {
	if (this->current == this->n) {
		int* temp = new int[2 * this->n];
		for (int i = 0; i < this->n; ++i) {
			temp[i] = arr[i];
		}
		delete[] arr;
		this->n *= 2;
		arr = temp;
	}
	arr[current] = data;
	this->current++;
}

void Vector::insert(int data, int index) {
	if (index == this->n) {
		push(data);
	}
	else {
		this->n++;
		this->current++;
		int arr1[current + 1];
		arr1[index] = data;
		for(int i = 0; i < index; ++i) {
			arr1[i] = arr[i];
		}
		for(int i = index ; i < current + 1; ++i) {
			arr1[i + 1] = arr[i];
		}
		for(int i = 0; i < current; ++i) {
			arr[i] = arr1[i];
		}
	}
}

void Vector::setIndex(int index) {
	if(index < this->current) {
		std::cout << arr[index] << std::endl;
	}
}

void Vector::pop() {
	this->current--;
	}

int Vector::size() {
	return this->current;
	}

int Vector::getN() {
	return this->n;
}

void Vector::print() {
	for (int i = 0; i < this->current; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
