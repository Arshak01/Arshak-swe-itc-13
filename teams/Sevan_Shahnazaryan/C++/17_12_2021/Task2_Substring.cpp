#include <iostream>
#include <string>

bool compare(char[], char[], int, int);

bool isSub(char str1[], char str2[], int len1, int len2);

int len(char[], int);

int main() {
    int num = 0;
    int len1 = 0;
    int len2 = 0;
    std::cout << "Enter word size: ";
    std::cin >> num;
    std::cin.ignore();
    char str1[num] = "";
    char str2[num] = "";
    std::cout << "Enter word: ";
    std::cin.getline(str1, num);
    std::cout << "Enter subsequence: ";
    std::cin.getline(str2, num);
    len1 = len(str1, num);
    len2 = len(str2, num);
    std::cout << "Is subsequence a part of the word? " << isSub(str1, str2, len1, len2) << std::endl;
    return 0;
}

bool compare(char str1[], char str2[], int len, int k) {
    int j = -1;
    for(int i = k; i < k + len; ++i){
        ++j;
        if(str1[i] != str2[j]) {
            return false;
        }
    }
    return true;
}

bool isSub(char str1[], char str2[], int len1, int len2) {
    for(int i = 0; i < len1; ++i) {
        if(compare(str1, str2, len2, i)) {
            return true;
        }
    }
    return false;
}

int len(char arr[], int num) {
    int count = 0;
    for(int i = 0; i < num; ++i){
        if(arr[i] != 0) {
            ++count;
        }
    }
    return count;
}
