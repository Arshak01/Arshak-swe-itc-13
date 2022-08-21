#include <iostream>

class Str {
private:
    char *string;
    int size=0;
    bool isHeaped = false;

public:
    static int counter;
    Str(char *string, int size) {
        this->string = string;
        this->size = size;
        ++counter;
    }

    int length() {
        return this->size;
    }

    static int getObjectsCount() {
        return counter;
    }
    void concat(char *string, int size) {
        this->isHeaped = true;
        char *arr = new char(this->size + size + 1);
        for(int i = 0; i < this->size; ++i) {
            arr[i] = this->string[i];
        }
        for(int i = 0; i <= size; ++i) {
            arr[i + this->size] = string[i];
        }
        this->string = arr;
        this->size += size;
    }
    void print() {
        for(int i = 0; i < size; ++i) {
            std::cout << this->string[i];
        }
        std::cout << std::endl;
    }

    ~Str() {
        --(this->counter);
        if(isHeaped) {
            delete this->string;
            this->string = NULL;
        }
    }
};

int Str::counter = 0;

int main() {
    Str string1("Hello", 5);
    string1.print();
    std::cout << "Len1 = "<< string1.length() << std::endl;
    string1.concat(" World", 6);
    string1.print();
    Str string2("Second hello", 13);
    std::cout << "Len2 = " << string1.length() << std::endl;
    std::cout << "Count = " <<Str::getObjectsCount() << std::endl;
    return 0;
}
