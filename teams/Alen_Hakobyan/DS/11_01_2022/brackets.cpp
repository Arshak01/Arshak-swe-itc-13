#include <iostream>
#include <stack>
#include "brackets.h"

bool checkBrackets(std::string brackets, int size) {
	std::stack<char> st;
	char symbol;
	for(int i = 0; i < size; ++i) {
		if(brackets[i] == '{' || brackets[i] == '(' || brackets[i] == '[') {
			st.push(brackets[i]);
			continue;
		}
		if(st.empty()) {
			std::cout << " Wrong symbol or brackets. Stack is empty!!!" << std::endl;
			return false;
		}
		if(brackets[i] == '}') {
			symbol = st.top();
			st.pop();
			if(symbol == '(' || symbol == '[') {
				return false;
			}
		}
		else if(brackets[i] == ')') {
			symbol = st.top();
			st.pop();
			if(symbol == '{' || symbol == '[') {
				return false;
			}
		}
		else if (brackets[i] == ']') {
			symbol = st.top();
			st.pop();
			if(symbol == '(' || symbol == '{') {
				return false;
			}
		}
	}
	return st.empty();
}
