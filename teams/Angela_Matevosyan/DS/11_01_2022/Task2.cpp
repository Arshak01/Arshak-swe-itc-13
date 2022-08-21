#include <iostream>
#include <stack>
#include <string>

bool ArePair(char opening, char closing) {
	if (opening == '(' && closing == ')')
		return true;
	else if (opening == '{' && closing == '}')
		return true;
	else if (opening == '[' && closing == ']')
		return true;
	return false;
}

bool AreParanthesesBalanced(const std::string& exp) {
	std::stack<char> st;
	for (int i = 0; i < exp.size(); ++i) {
		if (exp[i] == '(' || exp[i] == '{' || exp[i] =='[')
			st.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
			if (st.empty() || !ArePair(st.top(), exp[i]))
				return false;
			else
				st.pop();
		}
	}
	return st.empty();
}

int main() {
	std::string expression;
	std::cout << "Input a bracket expression:\n";
	std::cin >> expression;
	if (AreParanthesesBalanced(expression))
		std::cout << "Correct.\n";
	else
		std::cout << "Not correct.\n";
	return 0;
}
