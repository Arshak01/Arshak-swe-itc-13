#include <iostream>
class MyVector {
private:

	int* arr;
	unsigned int capacity;
	unsigned int currentSize;

public:

    MyVector() {
	arr = new int[0];
	capacity = 0;
	currentSize = 0;
    }

    MyVector(int size, int defaultValue){
    	arr = new int[size];
    	capacity = size;
    	currentSize = size;
    	for(int i = 0; i <= size; i++){
    		arr[i] = defaultValue;
    	}
    }

    void push(int value) {
        if (currentSize == capacity) {
            int *temp = new int[++capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
       arr[currentSize] = value;
       currentSize++;
    }

    void insert(int data, int index) {
        if (index == capacity)
            push(data);
        else
        capacity++;
        currentSize++;
        int newArray[currentSize+1];
        newArray[index] = data;
            for(int i = 0; i<index; i++){
                newArray[i] = arr[i];      
            }
            for (int i = index; i < currentSize+1; i++){
                newArray[i + 1] = arr[i];
            }
            for(int i = 0; i < currentSize; i++){
                arr[i] = newArray[i];
            }   
    }
    void deleteElement(int index){
    	for (int i = index; i <= capacity; i++){
    		arr[i] = arr[i + 1];
    	}
    	currentSize--;
    	capacity--;
    }

    int getElement(int index){
        if (index < currentSize)
            return arr[index];
    }

    void pop() {
	deleteElement(currentSize); 
	}

    int size() {
	return currentSize; 
	}

    int getCapacity() { 
	return capacity; 
	}

    void print() {
    	std::cout << "Vector elements : ";
	for (int i = 0; i < currentSize; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    ~MyVector() {
	delete[] arr;
	}

};

