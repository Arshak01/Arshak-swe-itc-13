#include "vector.hpp"
#include <iostream>

Vector::Vector() {}

Vector::Vector(int size) {
	m_capacity = size;
	m_size = size;
    m_arr = new int[size];
}

Vector::Vector(int size, int defaultValue) {
	m_capacity = size;
	m_size = size;
    m_arr = new int[size];
	for (int i = 0; i < size; ++i) {
		m_arr[i] = defaultValue;
    }
}

void Vector::push(int val) {
	if (m_size == m_capacity) {
		m_capacity *= 2;
	int* temp = new int[m_capacity];
	for (int i = 0; i < m_size; ++i) {
		temp[i] = m_arr[i];
	}
	delete[] m_arr;
	m_arr = temp;
	}
    m_arr[m_size] = val;
    ++m_size;
}

void Vector::pop() {
	--m_size;
	}

void Vector::insert(int index, int data) {
	if (m_capacity = m_size) {
		m_capacity *= 2;
	}
	int* temp = new int[m_capacity];
	for (int i = 0; i < index; i++) {
    	temp[i] = m_arr[i];
    }
  	temp[index] = data;
	++m_size;
    for (int i = index + 1; i < m_size; ++i) {
        temp[i] = m_arr[i - 1];
   	}
    delete[] m_arr;
    m_arr = temp;
}

int Vector::size() {
	return m_size;
}

int Vector::capacity() {
	return m_capacity;
}

int Vector::operator [] (int n) {
            return m_arr[n];
}

void Vector::print() {
	for (int i = 0; i < m_size; ++i) {
		std::cout << m_arr[i] << " ";
	}
    std::cout << "\n";
}
