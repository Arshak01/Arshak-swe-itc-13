#include <iostream>

class String {
private:
    char *string;
    int size;
    int counter;
    static int objCount;
public:
    String(char *str, int size) {
        this -> string = str;
        this -> size = size;
        counter = ++objCount;
    }

    int length() {
        return size;
    }

    void print() {
        std::cout << string << std::endl;
    }

    void concat(char *string2, int size2) {
        char* tmp = new char[size + size2 + 1];
        for(int i = 0; i <= size; i++) {
            tmp[i] = string[i];
        }
        for(int i = 0; i <= size2; i++) {
            tmp[i + size2] = string2[i];
        }
        string = tmp;
        size = size + size2 + 1;
    }

    static int getObjCount() {
        return objCount;
    }
};

int String::objCount;

int main() {
    String str("Hello", 5);
    str.print();
    str.concat("World", 5);
    str.print();
    std::cout << "Length: " << str.length() << std::endl;
    std::cout << "Counter: " << String::getObjCount() << std::endl;
    return 0;
}
