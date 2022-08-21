#include <iostream>
#include "vector.hpp"

int main() {
	std::cout << "VECTOR TESTING\n\n";
    Vector v(3, 7); 
    std::cout << "Created a Vector object\n";
    v.push(17);
    v.push(4);
    v.push(5);
    std::cout << "Objects elements are: \n";
    v.print();
    
    int len = v.size();
    std::cout << "Size is equal to " << len << "\n";
    int maxLen = v.capacity();
    std::cout << "Capacity is equal to " << maxLen << "\n";
    v.capacity();

    v.pop();
    std::cout << "Deleted the last element.\nNew version of object is: \n";
    v.print();

    int maxLen1 = v.capacity();
    std::cout << "Capacity is equal to " << maxLen1 << "\n";
    v.capacity();

    int len1 = v.size();
    std::cout << "Size is equal to " << len1 << "\n";

    int index1 = v[1];
    std::cout << "The value at index 1 is " << index1 << "\n";
    return 0;
}

