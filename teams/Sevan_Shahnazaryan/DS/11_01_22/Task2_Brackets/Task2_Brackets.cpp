#include <iostream>
#include "Node.hpp"
#include "Stack.hpp"
#include "cfunc.hpp"

int main() {
	std::string str;
	std::string answer;
	std::cin >> str;
	answer = (isCorrect(str)) ? "Correct" : "Not correct";
	std::cout << answer << std::endl;
	return 0;
}
