#include <iostream>
#include <vector>

int interpolationSearch(std::vector<int>& arr, int key) {
	int low = 0;
	int high = arr.size() - 1;
	
	while((low < high) && (key >= arr[low]) && (key <= arr[high])) {
		if (low == high) {
			if (arr[low] == key) {
				return low;
			}else {
				return -1;
			}
		}	
			
		int position = low + (((key - arr[low]) * (high - low)) / (arr[high] - arr[low]));
		if (arr[position] == key) {
			return position;
		}
		if (arr[position] > key) {
			low = position + 1;
		} else {
			high = position - 1;
		}
	}
	return -1;
}


int main() {
	std::vector<int> arr = {1, 11, 50, 70, 90, 101, 103, 105};
	int index = interpolationSearch(arr, 55);
	if (index != -1)
		std::cout << "Key found at index " << index << "\n";
	else
		std::cout << "Key not found.\n";
    return 0;
}
