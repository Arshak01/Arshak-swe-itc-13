#include <iostream>  
#include <cstring>

int countDigit(int);		
int convertToWord(int);
int specialFor20_99(int);

int main(){
	char *digit1_9[] = { " " , "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	char *digit11_19[] = { "ten", "eleven", "twelve", "thirteen","fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	char* digit20_90[] = { "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };	
	int number;
	std::cout << "Enter number 0-99: ";
	std::cin >> number;
	convertToWord(number);
	return 0;
}	

int convertToWord(int number) {
	if (countDigit(number) == 1 ) {
		std::cout << digit1_9[number] ;
	}
	if (countDigit(number) == 2 && number <= 19 ) {
		std::cout << digit11_19[number-10] ;
	}
	if (countDigit(number) == 2 && number >= 20 ) {
		std::cout << digit20_90[number/10-2] << " " << digit1_9[specialFor20_99(number)];
	}
	return 0;
}

int countDigit(int n) {
    if (n/10 == 0)
        return 1;
    return 1 + countDigit(n / 10);
}

int specialFor20_99(int number) {
	int count;
    for(int i = 0 ; i <=number; i++) {
        count++;
        if(i == 10 || i == 20 || i == 30 || i == 40 || i == 50 || i == 60 || i == 70 || i == 80 || i == 90) {
            count = 0;
        }
       
    }
	return count;
}
