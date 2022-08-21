#include <iostream>

using namespace std;

class MyVector {
private:

	int* arr = new int[0];
	int capacity = 0;
	int currentSize = 0;
 
public:

    MyVector() {
        
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
    cout << "Vector elements : ";
        for (int i = 0; i < currentSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    ~MyVector(){
    	delete[] arr;
    	this->arr = nullptr;
    }
       
};
 
int main() {
    cout << "Create with Arguments (5,0) " << endl;
    MyVector vector1(5,0);
    cout << "Vector size : " << vector1.size() << endl;
    cout << "Vector capacity : " << vector1.getCapacity() << endl;
    vector1.print();
    cout << endl;
    cout << "====================================" << endl;
    MyVector vector;
    for (int i = 0; i < 10; i++){
    vector.push(i);
    } 
    cout << "Element at 1st index : " << vector.getElement(1) << endl;
    cout << "Element at 5th index : " << vector.getElement(5) << endl;
    cout << "Element at 9th index : " << vector.getElement(9) << endl;
    cout << endl;
    cout << "Vector size : " << vector.size() << endl;
    cout << "Vector capacity : " << vector.getCapacity() << endl;
    vector.print();
    cout << "\nAfter insert " << endl;
    vector.insert(100, 10);
    cout << "Vector size : " << vector.size() << endl;
    cout << "Vector capacity : " << vector.getCapacity() << endl;
    vector.print() ;
    vector.pop();
    cout << "\nAfter deleting last element" << endl;
    cout << "Vector size : " << vector.size() << endl;
    cout << "Vector capacity : " << vector.getCapacity() << endl;
    vector.print();
    cout << "\nAfter deleting 'n' element " << endl;
    vector.deleteElement(4);
    cout << "Vector size : " << vector.size() << endl;
    cout << "Vector capacity : " << vector.getCapacity() << endl;
    vector.print();
    
    return 0;
}


