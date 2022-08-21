#include <cstring>
#include <iostream>

int isSubSequence(char str[], char sub[], int strLen, int subLen) {
    bool isAllMatch = true;
    for (int i = 0; i <= strLen - subLen; ++i) {
        isAllMatch = true;
        for (int j = 0; j < subLen; ++j) {
            if (str[i + j] != sub[j]) {
                isAllMatch = false;
                break;
            }
        }
        if(isAllMatch) return 1;
    }
    return 0;
}

int main() {
    char str[1000] = " ";
    char sub[1000] = " ";
    std::cout << "Please the word: ";
    std::cin >> str;
    std::cout << "Please type the subsesque: ";
    std::cin >> sub;
    int strLen = strlen(str);
    int subLen = strlen(sub);
    std::cout << "Is the input subsesque correct? ([1] for true and [0] for false) | ";
    std:: cout << isSubSequence(str, sub, strLen, subLen) << std::endl;
    return 0;
}


