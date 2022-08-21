#include <iostream>
//#include "buildings.hpp"

int countWays(int* arr, int N, int size) {
	if(N < size){
		std::cout << "Returned from cache : " ;
		return arr[N-1];	
	}

	if (N == 1){
		return 4;
	}
 	size = (N-1);
	int buildCount=1, freeSpCount=1; 
	int prevCountB, prevCountS;
	arr[0] = 4;
	for (int i=2; i<=N; i++) {
		prevCountB = buildCount;
		prevCountS = freeSpCount;
		freeSpCount = prevCountB + prevCountS;
		buildCount = prevCountS;
		arr[i-1] = ((freeSpCount + buildCount)*(freeSpCount + buildCount));
	}
	int result = freeSpCount + buildCount; 
	std::cout << "Count of ways is : ";
	return (result*result);
}
