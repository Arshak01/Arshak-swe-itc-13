#include <stack>
#include <string>

bool isStringCorrect(std::string str) {
    std::stack<char> stack;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            stack.push(str[i]);
        } else if (!stack.empty()) {
            if (stack.top() == '(' && str[i] == ')'
            || stack.top() == '[' && str[i] == ']'
            || stack.top() == '{' && str[i] == '}') {
                stack.pop();
            } 
        } else {
            return false;
        }  
    }
    return stack.empty();
}
