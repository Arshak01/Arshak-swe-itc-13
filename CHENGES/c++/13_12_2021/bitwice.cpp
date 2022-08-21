#include <iostream>

void bitwiceOper(int n1, int n2, char n3) {
        int bitOr;
        int bitAnd;
        int bitXor;
        int shiftRight;
        int shiftLeft;

	switch(n3) {
        	case '|' : {
               		std::cout << "Bitwice | ";
                       	bitOr = n1 | n2;
                       	std::cout << bitOr << std::endl;
               	} break;
                case '&' : {
                	std::cout << "Bitwice & ";
                        bitAnd = n1 & n2;
                        std::cout << bitAnd << std::endl;
                } break;
                case '^' : {
                        std::cout << "Bitwice ^ ";
                        bitXor = n1 ^ n2;
			std::cout << bitXor << std::endl;
                } break;
                case '>' : {
                        std::cout << "Bitwice >> ";
			shiftRight = n1 >> n2;
			std::cout << shiftRight << std::endl;		
   		} break;
                case '<' : {
                        std::cout << "Bitwice << ";
                        shiftLeft = n1 << n2;
                        std::cout << shiftLeft << std::endl;
                } break;
                default : { 
      			std::cout << "Input right operation";
                }
        }
}

int main() {
        int n1;
        int n2;
        char n3;
        std::cout << "Entry first number : ";
        std::cin >> n1;
        std::cout << "Entry second number : ";
        std::cin >> n2;
        std::cout << "Entry bitwise operators | & ^ > < ";
        std::cin >> n3;
	bitwiceOper(n1, n2, n3);
        return 0;
}
