#include <typeinfo>
#include <iostream>

const char *first[20] = {"ZERO", "ONE", "TWO", "THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN",
    "ELEVEN","TWELVE","THIRTEEN","FOURTEEN","FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTTEEN","NINETEEN"};

const char *second[10] = {"", "TEN", "TWENTY", "THIRTY","FORTY","FIFTY","SIXTY","SEVENTY","EIGHTY","NINETY"};

void toWord(int value) {
    if(value < 0) {
        std::cout << "Please write an non-negative number ";
    }else if(value >= 1000000000) {
        toWord(value / 1000000000);
        std::cout << " BILLION ";
        if((value % 1000000000) / 1000 != 0) {
            toWord((value % 1000000000) / 1000000);
            std::cout << " MILLION ";
        }
        if((value % 1000000) / 1000 != 0) {
            toWord((value % 1000000) / 1000);
            std::cout << " THOUSAND";
        }
        if(value % 1000) {
            if(value % 1000 < 100) {
                std::cout << " AND";
            }
            std:: cout << " " ;
            toWord(value % 1000);
        }
    }else if(value >= 1000000) {
        toWord(value / 1000000);
        std::cout << " MILLION ";
        if((value % 1000000) / 1000 != 0) {
            toWord((value % 1000000) / 1000);
            std::cout << " THOUSAND";
        }
        if(value % 1000) {
            if(value % 1000 < 100) {
                std::cout << " AND";
            }
            std:: cout << " " ;
            toWord(value % 1000);
        }
    }else if(value >= 1000) {
        toWord(value/1000);
        std::cout << " THOUSAND";
        if(value % 1000) {
            if(value % 1000 < 100) {
                std::cout << " AND";
            }
            std:: cout << " " ;
            toWord(value % 1000);
        }
    }else if(value >= 100) {
        toWord(value / 100);
        std::cout << " HUNDRED";
        if(value % 100) {
            std::cout << " AND ";
            toWord(value % 100);
        }
    }else if(value >= 20) {
        std::cout << second[value / 10];
        if(value % 10) {
            std::cout << " ";
            toWord(value % 10);
        }
    }else {
        std::cout << first[value];
    }
    return;

}

int main( ) {
    char choice;
    while(true) {
        int number;
        std::cout << "Enter a non-negative number from 1 to 2.147.483.647:  ";
        std::cin >> number;
        while(std::cin.fail()) {
            std::cout << "\n\nNaN, please input a non-negative number" << std::endl;
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cin >> number;
        }
            std::cout << "\n\n Converting number to words: ";
            toWord(number);
            std::cout << std::endl;
            std::cout << "\n\nPress any key to continue or 'q' to quite\n " << std::endl;
            std::cin >> choice;
            if(choice == 'q') {
                break;
            }else {
                continue;
            }
    }
    return 0;
}
