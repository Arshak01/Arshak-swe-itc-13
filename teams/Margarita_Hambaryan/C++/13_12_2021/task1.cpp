#include <iostream>
namespace custom {

    //Maximum value for the two input numbers
    int max(int num1, int num2) {
        if (num1 > num2) {
            return num1;
        }
        return num2;
	}   

    //Minumum value for the two input numbers
    int min(int num1, int num2) {
        if (num1 < num2) {
            return num1;
        }
        return num2;        
    }   

    //Summary for the two input numbers
    int sum(int num1, int num2) {
        return num1 + num2;
    }   
}

int main() {
    //Inserting the numbers
    std::cout << "Display the input numbers:" << std::endl;
    int num1;
    int num2;
    std::cout << "Insert number 1: ";
    std::cin >> num1;
    std::cout << "Insert number 2: ";
    std::cin >> num2;

    std::cout << "Display the minimum/maximum/sum:" << std::endl;

    //Printing the minumun value
    std::cout << "Min: ";
    std::cout << custom::min(num1, num2) << std::endl;

    //Printing the maximum value
    std::cout << "Max: ";
    std::cout << custom::max(num1, num2) << std::endl;

    //Printing thw sum
    std::cout << "Sum: ";
    std::cout << custom::sum(num1, num2) << std::endl;

    return 0;
}	
