#include "MyVector.hpp"
using namespace std;


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
    cout << "\nAfter insert at 5 index " << endl;
    vector.insert(100, 5);
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
