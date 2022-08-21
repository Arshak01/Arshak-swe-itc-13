#include <iostream>
#include "cfunc.hpp"
#include "Stack.hpp"


bool isOpening(char brace) {
    return (brace == '[' || brace == '{' || brace == '(') ? true : false;

}

bool isClosing(char brace) {
    return (brace == ']' || brace == '}' || brace == ')') ? true : false;
}

char pair(char brace) {
    switch(brace) {
        case ']':
            return '[';
        case '}':
            return '{';
        case ')':
            return '(';
    }
}

bool isCorrect(std::string str) {
    Stack stack;
    //bool isBrace = false;
    unsigned short len = str.length();
    for(int i = 0; i < len; ++i) {
        if(isOpening(str[i])) {
            stack.push(str[i]);
           // isBrace = true;
        } else if(isClosing(str[i])) {
            if(stack.top() == pair(str[i])) {
                stack.pop();
            } else {
				//isBrace = true;
                return false;
            }
        }
    }
    return (stack.isEmpty());
}
