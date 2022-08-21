#include <iostream>

namespace tw{
   void toWordHundred(unsigned int);
   void toWord(unsigned int);
};

int main() {
    unsigned int num = 0;
    std::cout << "Enter a number from 1 to 999 999 999\n num = ";
    std::cin >> num;
    tw::toWord(num);
    return 0;
}

namespace tw {
    //vocabulary
    char voc[3][20][10] = {{"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"},
                        {"", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninty"},
                        {"", "hundred"}};

    //for 1 -> 999
    void toWordHundred(unsigned int num) {
        std::cout << voc[0][num / 100] << ' ';
        if(num / 100 < 10 && num / 100  > 0) {
            std::cout << voc[2][1] << ' ';
        }
        std::cout << voc[1][(num % 100) / 10] << ' ';
        if(num % 100 < 20 && num % 100 > 10) {
            std::cout << voc[0][num % 100] << ' ';
        } else {
            std::cout << voc[0][num % 10] << ' ';
        }
    }

    void toWord(unsigned int num) {
        toWordHundred(num / 1000000);
        if(num > 999999) {
            std::cout << "million" << ' ';
        }
        toWordHundred((num % 1000000) / 1000);
        if(num % 1000000 != 0 && num > 999) {
            std::cout << "thousand" << ' ';
        }
        toWordHundred(num % 1000);
        std::cout << std::endl;
    }

}
