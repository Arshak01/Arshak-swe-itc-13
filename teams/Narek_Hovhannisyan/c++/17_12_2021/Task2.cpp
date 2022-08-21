#include <iostream>

int isSubstring(std::string strinG, std::string substring) {
    int subLen = substring.length();
    int strLen = strinG.length();

    bool isAllMatch = true;

    for (int i = 0; i <= strLen - subLen; ++i) {
        isAllMatch = true;
        for (int j = 0; j < subLen; ++j) {
            if (strinG[i + j] != substring[j]) {
                isAllMatch = false;
                break;
            }
        }
        if(isAllMatch) return 1;
    }
    return 0;
}

int main() {
    std::string word = " ";
    std::string substring = " ";

    std::cout << "Please type a word: ";
    std::getline(std::cin, word);
    std::cout << "Please type a substring: ";
    std::getline(std::cin, substring);

    std::cout << std::endl;

    std::cout << "word: " << word << std::endl;
    std::cout << "subse: " << substring << std::endl;

    std::cout << "Is '" << substring << "' the subsequence of '";
    std::cout << word << "' ? ";
    std::cout << isSubstring(word, substring);
    std::cout << std::endl;
    return 0;
}