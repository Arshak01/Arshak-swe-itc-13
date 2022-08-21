#include <iostream>
#include "./vector.hpp"

Vector::Vector() {
	this-> n = 1;
	this-> array = new int[n];
	this-> current = 0;
	this->n++;
}
        
Vector::Vector(int size) {
	this-> n = size; 
	this-> current = 0;
	this-> array = new int[size];
}
        
Vector::Vector(int size, int value) {
	this-> n = size;
	this-> current = n;
	this-> array = new int[current];
	for (int i = 0; i < current; ++i) {
		this->array[i] = value;
	}
}

void Vector::push(int data) {
	if (this->current == this->n) {
		int* temp = new int[this->n += this->n/2];
		for (int i = 0; i < this->n; i++) {
			temp[i] = array[i];
		}
		delete[] array;
		this->n += this->n/2;
		array = temp;
	}
	array[current] = data;
	current++;
}

void Vector::pop() {
	int* newArr = new int[this->n-1];
	for (int i = 0; i < this->n; i++) {
		newArr[i] = array[i];
	}
	delete[] this->array;
	this->array = newArr;
	this->current--;
}
       
void Vector::insert(int index, int data) {
	int* temp = new int[this->current+1];
	if(this-> array) {
		for(int i = 0; i < index; ++i){
			temp[i] = array[i];
		}
		temp[index] = data;
		for(int i = index+1; i < current; ++i){
			temp[i] = array[i];
		}
	}
	++this-> n;
	delete[] array;
	this-> array = temp;
}

void Vector::deleteAtIndex(int index) {
	int* temp = new int[--this->current];
	if(this-> array) {
		for(int i = 0; i < index; ++i){
			temp[i] = array[i];
		}
		for(int i = index; i < current; ++i) {
			temp[i] = array[i+1];
		}
	}
	delete[]array;
	this-> array = temp;
}

int Vector::operator [] (int index) {
	if(index > this->n){
		return this->array[this->n-1];
	}
	if(index <= 0){
		return this->array[0];
	}
	return this->array[index];
}

void Vector::print(){
	std::cout << "Vector elements are: ";
	for (int i = 0; i < current; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

int Vector::size() {
	return this-> current;
}

int Vector::capacity() {
	return this-> n;
}

bool Vector::empty() {
	if(this-> array) {
		return true;
	}
	return false;
}

Vector::~Vector() {
	delete[] this-> array;
}
