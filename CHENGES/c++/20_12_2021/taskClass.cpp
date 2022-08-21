#include <iostream>

class CustomString {
	private:
	 	char* stringName;
		int size = 0;
		int counter; 
		static int objCnt;

	public:
		CustomString(char* str, int size) {
			this -> stringName = str;
			this -> size = size;
			counter = ++objCnt;	
		}
	
		int length() { 
			return size;
	       	}	
	  	
		static int getObjectsCount() {
		       	return objCnt; 
		}

		void print() {
			for(int i = 0; i < size; ++i) {
				std::cout << stringName[i]; 
			}
			std::cout << std::endl;
		}
	
		void concat(char* newString, int newSize) {    
			char* temp = new char[size + newSize + 1];
	
    			for (int i = 0; i <= size; ++i) {
        			temp[i] = stringName[i];
    			}
    
    			for (int i = 0; i <= newSize; ++i) {
        			temp[i + newSize] = newString[i];
    			}

    			temp[size + newSize+1] = '\0';
			stringName = temp;
			size = size+newSize+1;
		}

};

int CustomString::objCnt;

int main() {
	CustomString customStr("Hello",5);
	customStr.print();
	std::cout << "Length : " << customStr.length() << std::endl;
	std::cout << "Counter : " << CustomString::getObjectsCount() << std::endl;
	
	customStr.concat("World",5);
	customStr.print();
	std::cout << "Length : " << customStr.length() << std::endl;
	
	//customStr.hasSubString("Helr",4);
	return 0;
}
