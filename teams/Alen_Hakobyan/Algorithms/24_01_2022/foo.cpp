#include <iostream>
#include <vector>

int pow(int n, int m);
int sqrt(int n);
int powSum(int v, const int k, int i, unsigned int _v_i, std::vector<int> combsList[], unsigned int _v_size);

int main(){
	unsigned int n, k = 0, size = 1000;
    std::vector<int> combsList[size];
    std::cout << "Give me k & n " << std::endl;
    std::cin >> n; 
    std::cin >> k; 
    int result = powSum(n,k,1,0,combsList,size);
    std::cout << "For " << n << "^" << k << " combination count is " << result << std::endl;
	return 0;
}

int pow(int n, int m) {
	if(m == 1) {
		return n;
	}
	if(m == 0) {
		return 1;
	}
	return n*pow(n,m-1);
}

int sqrt(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	int i = 1;
	int result = 1;
	while (result <= n) {
		i++;
		result = i * i;
	}
	return i - 1;
}

void printACombination(std::vector<int> v){
    std::cout << "Combination is : ";
    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

void printElements(std::vector<int> v[], int _v_size){
    for (int i = 0; i < _v_size; ++i) {
        if (v[i].size() == 0 ) continue;
        std::cout << "Elements at index " << i << ": ";
        for (auto it = v[i].begin(); it != v[i].end(); it++) {
           std::cout << *it << ' ';
        }
        std::cout << std::endl;
    }
}

int getFreeIndex(std::vector<int> v[], int _v_size, int _v_i = 0){
    for (int i = 0; i < _v_size; ++i) {
        if (v[i].size() == 0 ) {
            for (auto it = v[_v_i].begin(); it != v[_v_i].end(); it++) {
                v[i].push_back(*it);
            }
            if (v[i].size() == 0) v[i].push_back(0);
            return i;
        }
    }
    return -1;
}

int powSum(int v, const int k, int i, unsigned int _v_i, std::vector<int> combsList[], unsigned int _v_size) {
    unsigned _v_free_left = getFreeIndex(combsList,_v_size,_v_i);
    unsigned _v_free_right = getFreeIndex(combsList,_v_size,_v_i);
    combsList[_v_free_left].push_back(i);
    
    int value = v - pow(i,k);
    if (value < 0 ) { 
        combsList[_v_i].clear(); 
        return 0; 
    }
    if (value == 0 ) {
        combsList[_v_i].push_back(i);
        printACombination(combsList[_v_i]);
        return 1;
    }
    
    return powSum(value, k, i+1, _v_free_left,  combsList,_v_size) 
        +  powSum(v,     k, i+1, _v_free_right, combsList,_v_size);
}
