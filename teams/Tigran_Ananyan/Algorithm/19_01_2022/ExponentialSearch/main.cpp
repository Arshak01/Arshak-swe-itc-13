#include <iostream>
#include "ExponentialSearch.hpp"

int main()
{
    int arr[] = {1, 7, 12, 23, 31, 40, 51};
    int size = sizeof(arr)/ sizeof(arr[0]);
    int key = 23;
    int result = exponentialSearch(arr, size, key);
    if(result == -1) {
        std::cout << "\nThere is no  element " << key << " in this array" << std::endl;
    }else {
         std::cout <<"The element is: arr[" << result << "] = " << key << std::endl;
    }
   return 0;
}
