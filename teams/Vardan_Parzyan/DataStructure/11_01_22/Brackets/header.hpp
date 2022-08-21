#include <iostream>
#include <stack>
#include <string>
bool checker(std::string brackets){
std::stack<char> ch;
char c1;

    for(int i = 0; i < brackets.length(); i++){
        char c1 = brackets.at(i);
                if (ch.empty()) {
                    ch.push(c1);
                }
        else if (ch.top() == '(' && c1 == ')' || 
                 ch.top() == '{' && c1 == '}' || 
                 ch.top() == '[' && c1 == ']') {
            ch.pop();
        }
        else
            ch.push(c1);
    }

    if (ch.empty()){
        std::cout << "Your injected brackets CLOSE EACH OTHER \n";
        return true;
    } else {
        std::cout << "Your injected brackets DO NOT CLOSE EACH OTHER\n";
        return false;
    }
}

std::string brackets(){
    bool isFine = false;
    std::string str;
    std::cout << "Please insert the brackets only :";
    std::cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if(str[i] == '(' || str[i] == ')' || 
           str[i] == '{' || str[i] == '}' || 
           str[i] == '[' || str[i] == ']' ) {
               isFine = true;
            continue;
        }
        if(str[i] != '(' || str[i] != ')' || 
           str[i] != '{' || str[i] != '}' || 
           str[i] != '[' || str[i] != ']' ) {
            std::cout << "These are not only brackets \n";
            std::cout<<std::endl;
            std::cout << "If you do not know what brackets are, please use Google\n";
            std::cout<<std::endl;
            isFine = false;
            brackets();
            break;
        }
    }
    
    if(isFine){
        std::cout << "Doing some awesome magic \n";
        checker(str);
    }
    return str;
}
    

    
