#include <iostream>
#include <algorithm>
#include <vector>

void print(std::vector<int> arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr.at(i) << " ";
    }   
}

std::vector<int> merge(std::vector<int>& left, std::vector<int>& right) {
	std::vector<int> merged;
	int leftIndex = 0;
	int rightIndex = 0;
	while(leftIndex < left.size() && rightIndex < right.size()) {
		if (left[leftIndex] <= right[rightIndex]) {
			merged.push_back(left[leftIndex++]);
		} else {
			merged.push_back(right[rightIndex++]);
		}
	}
	while(leftIndex < left.size()) {
		merged.push_back(left[leftIndex++]);
	} 
	
	while(rightIndex < right.size()) {
		merged.push_back(right[rightIndex++]);
	} 
	return merged;
} 

void mergeSort(std::vector<int>& arr) {
	if (arr.size() <= 1) {
		return;
	}
	int n = arr.size() / 2;
	std::vector<int> left;
	std::vector<int> right;
	for(int i = 0; i < n; ++i) {
		left.push_back(arr[i]);
	}
	for(int i = n; i < arr.size(); ++i) {
		right.push_back(arr[i]);
	}
	mergeSort(left);
	mergeSort(right);

	arr = merge(left, right);
}

int main() {
	std::vector<int> arr = {5, 8, 20, 4, 17, 9, 50, 3, 7};

	std::cout << "Before sorting\n";
	print(arr);
	mergeSort(arr);
	std::cout << "\nAfter sorting\n";
	print(arr);
	std::cout << "\n";

    return 0;
}    

