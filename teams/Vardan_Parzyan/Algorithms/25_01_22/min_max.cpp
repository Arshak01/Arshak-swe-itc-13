#include <iostream>


int minimum(int* arr,int left,int right){
	if (right-left==1){  
		return arr[left];
	}
   	int mid =(left+right)/2;
   	int first_half =minimum(arr,left,mid);
   	int second_half =minimum(arr,mid,right);
   	if (first_half<second_half){
		return first_half;	
	} else {
		return 	second_half;
	}   
}

int maxsimum(int* arr,int left,int right){
	if (right-left==1){  
		return arr[left];
	}
   	int mid =(left+right)/2;
   	int first_half =maxsimum(arr,left,mid);
   	int second_half =maxsimum(arr,mid,right);
	if (first_half>second_half){
		return first_half;	
	} else {
		return 	second_half;
	}   
}

int main() {
    int array[] = {13,104,396,100,69,420,330,99,45,256};
    int size = sizeof(array)/sizeof(int);
	std::cout << "The largest number in the array is : ";
    std::cout << maxsimum(array, 0, size) << std::endl;
	std::cout << "The smallest number in the array is : ";
	std::cout << minimum(array, 0, size) << std::endl;
    return 0;
}

