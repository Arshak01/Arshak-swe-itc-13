#include <iostream>
#include <chrono>
using namespace std::chrono;

int uglyLoop(int ind, int* arr, int size) {

    int ind2 = 0;
    int ind3 = 0;
    int ind5 = 0;
    int ugly2 = 2;
    int ugly3 = 3;
    int ugly5 = 5;
    arr[0] = 1;
    
    for(int i = 1; i < ind; ++i) {
        if(ugly2 < ugly3 && ugly2 < ugly5) {
            arr[i] = ugly2;
        }
        else if(ugly3 < ugly5) {
            arr[i] = ugly3;
        }
        else {
            arr[i] = ugly5;
        }
        arr[i] = std::min(ugly2,std::min(ugly3,ugly5));
        
        if (arr[i] == ugly2) {
            ++ind2;
            ugly2 = arr[ind2] * 2;
        }
        if (arr[i] == ugly3) {
            ++ind3;
            ugly3 = arr[ind3] * 3;
        }
        if (arr[i] == ugly5) {
            ++ind5;
            ugly5 = arr[ind5] * 5;
        }
    }
    return arr[ind-1];
}

void print(int* arr, int size){
    std::cout<<std::endl;
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int chechInArray(int* arr, int index, int size){
	if(size <= index){
	    size = sizeof(arr) / sizeof(arr[0]);
		return uglyLoop(index, arr, index);	
	} else {
	    return arr[index];	
	}
}

int main() {
    
    int index = 25;
    int arr[index];
	int size = sizeof(arr) / sizeof(arr[0]);
	auto start = high_resolution_clock::now();
    std::cout << chechInArray(arr, 25, size) << std::endl;
	auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "First call(without cache) : " << duration.count() << std::endl;
    //std::cout <<"size  "<< size << std::endl;
	start = high_resolution_clock::now();
	std::cout << chechInArray(arr, 20, size) << std::endl;
	stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Second call(from cache) : " << duration.count() << std::endl;
   // std::cout <<"size  "<<size<< std::endl;
	start = high_resolution_clock::now();
	std::cout << chechInArray(arr, 40, size) << std::endl;
	stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Third call(without cache) : " << duration.count() << std::endl;
    //std::cout <<"size  "<< size<< std::endl;
  /*  start = high_resolution_clock::now();
	std::cout << chechInArray(arr, 50, size) << std::endl;
	stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << "Third call(without cache) : " << duration.count() << std::endl;
    std::cout <<"size  "<< size<< std::endl; */

    return 0;
}

