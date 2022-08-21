#include <iostream>
#include <stack>
 

bool lineIsExecutable(std::string line) {
    bool isExecutable = true;
    for (int i = 0; i < line.length(); ++i) {
        if ((line[i] == '{') || (line[i] == '}') || (line[i] == '(') || (line[i] == ')') || (line[i] == '[') || (line[i] == ']')) { 
            continue;
        }else {
            isExecutable = false;
            break;
        }
    }
    return isExecutable;
}       
 
 
void checkingBrackets(std::string line) {
    std::stack<char> myStack;
        
    if(lineIsExecutable(line)) {
        for (int i = 0; i < line.length(); ++i) {
            if (myStack.empty()) {
                myStack.push(line[i]);
           } else if (((myStack.top() == '{') && (line[i] == '}')) || ((myStack.top() == '(') && (line[i] == ')')) || ((myStack.top() == '[') && (line[i] == ']'))) {
                myStack.pop();
           } else {
                myStack.push(line[i]);
           }
        }
    
        if (myStack.empty()) {
            std::cout << "Your brackets combination IS correct!\n";
        } else {
            std::cout  << "Your bracket combination is NOT correct!\n";
        }
    } else {
        std::cout << "Your string can contain only brackets. Try again.\n";
    }
}
