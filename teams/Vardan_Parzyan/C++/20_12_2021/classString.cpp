#include <iostream>

class CustomStr {
private:
	char* string1;
	int size;
	static int counter;
public:
	CustomStr(char* string1, int size) {
		counter++;
		this -> string1 = string1 ;
		this -> size = size ;
	}
	
	 ~CustomStr() {
        	delete string1;
	 }
	
	void concat(char* string2, int size2) {
		char * tmp = new char[ size + size2 + 1 ];
		for (int i = 0; i <= size; i++) {
        		tmp[i] = string1[i];
        	}
        	for (int i = 0; i <= size2; i++) {
        		tmp[ i + size2 ] = string2[i];
        	}
        	//tmp[size+size2+1] = '\0';
        	this -> size += size2+1;
        	this -> string1 = tmp;
	}
		
	void print() {
		std::cout << string1<<std::endl;
	}
	
	int length() {
		/*int i = 0;
    		while (string1[i])
        		i++;*/
    			return this -> size;
	}
	
	static int getObjectsCount() {
		return counter;
	}
	
	void hasSubString( char* string1, int size ) {
		bool flag = false;
		for(int i = 0; i < this -> size; ++i) {
			if(this -> string1[i] != string1[0]) {
				continue;
			}			
			if(this -> string1[i] == string1[0]) {
				if(this -> string1[i+1] == string1[1]) {
					if(this -> string1[i+2] == string1[2]) {
						flag = true;
						break;
					}
				}
			}
		}
		if(flag){
			std::cout << "Yes" << std::endl;
		} else {
			std::cout << "No" << std::endl;
		}
	}
};

int CustomStr::counter;

int main(){
	CustomStr objName("Hello", 5);
	objName.print();
	objName.concat(" world", 5);
	objName.print();
	std::cout << objName.length()<<std::endl;
	std::cout << CustomStr::getObjectsCount()<<std::endl;
	objName.hasSubString("Hel", 30);
	return 0;;
}
