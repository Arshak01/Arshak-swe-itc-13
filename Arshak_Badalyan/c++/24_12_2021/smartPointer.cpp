#include <iostream>

template <class T> 
class SmartPointer {
private:
	T* pData;
public:
	SmartPointer(T* pValue = NULL) {
		this -> pData = pValue;
	}
	~SmartPointer() {
		delete pData;
	}

	T& operator*() {
		return *(this -> pData);
	}

	T* operator->() {
		return this->pData;
	}
};

int main() {

	SmartPointer <float> pData (new float());
	*pData = 2.5;
	std::cout << *pData << std::endl; 
	
	return 0;
}
