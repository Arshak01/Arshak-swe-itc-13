#include <iostream>

class String {
private:
    char *string;
    int size;
    int counter = 0;

public:
    String() {

    }

    String(char *word, int size1) {
        string = word;
        size = size1;
        counter += 1;
    }

    ~String() {
        delete string;
    }

    int length() {
        return size;
    }

    void print() {
        std::cout << string << std::endl;
    }

    void concat(char *str2, int size) {
        this->size += size + 1;
        char *result = new char[this->size + size + 1];
        for (int i = 0; i < size; ++i) {
            result[i] = string[i];
        }
        for (int i = 0; i <= size; ++i) {
            result[size + i] = str2[i];
        }
        string = result;
    }

    int getObjectsCount() {
        return counter;
    }

};

int main() {
    String str("Hello", 5);
    str.print();
    str.concat(" World", 5);
    str.print();
    std::cout << str.length() << std::endl;
    std::cout << str.getObjectsCount() << std::endl;
    return 0;
}
