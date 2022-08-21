#include <stack>
#include <string>

bool BracketsChecker(std::string BrStr) {
    char c;
    std::stack<char> s;

    for(int i = 0; i < BrStr.length(); i++) {
        if(BrStr[i] == '(' || BrStr[i] == '[' || BrStr[i] == '{') {
            s.push(BrStr[i]);
            continue;
        }

        if(s.empty()) {
            return false;
        }

        switch(BrStr[i]){
        case ')':
            c = s.top();
            s.pop();
            if(c == '{' || c == '[') {
                return false;
            }
            break;
        case '}':
            c = s.top();
            s.pop();
            if(c == '(' || c == '[') {
                return false;
            }
            break;
         case ']':
             c = s.top();
             s.pop();
             if(c == '{' || c == '(') {
                 return false;
             }
             break;
        }
    }
    return s.empty();
}
