#include <iostream>
#include "bracketsCheck.h"
#include "../classStack/classStack.h"

bool bracketsCheck(std::string expression) {
        Stack* s = new Stack();
        for (int i = 0; i < expression.length(); ++i) {
                if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
                        s -> push(expression[i]);
                }

                if (expression[i] == ')' && (s -> topEl() == '{' || s -> topEl() == '[' || s -> isEmpty())) {
                        return false;
                }

                if (expression[i] == '}' && (s -> topEl() == '(' || s -> topEl() == '[' || s -> isEmpty())) {
                        return false;
                }

                if (expression[i] == ']' && (s -> topEl() == '(' || s -> topEl() == '{' || s -> isEmpty())) {
                        return false;
                }

                if (s -> topEl() == '(' && expression[i] == ')') {
                        s -> pop();
                } else if (s -> topEl() == '{' && expression[i] == '}') {
                        s -> pop();
                } else if (s -> topEl() == '[' && expression[i] == ']') {
                        s -> pop();
                } else {
                        continue;
                }
        }
        return (s -> isEmpty());
}
