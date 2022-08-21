#include <bits/stdc++.h>
#include <iostream>

bool checkBrackets(std::string expration) {  
	std::stack<char> s;
    char check;

    for (int i = 0; i < expration.length(); i++) {
        if (expration[i] == '(' || expration[i] == '[' || expration[i] == '{') {
			s.push(expration[i]);
			continue;
		}
		
		if (s.empty()) {
			return false;
		}

		switch (expration[i]) {
        	case ')':
					check = s.top();
					s.pop();
					if (check == '{' || check == '[') {
               			return false;
					}
					break;
			case '}':
					check = s.top();
					s.pop();
					if (check == '(' || check == '[') {
               			return false;
					}
					break;
			case ']':
					check = s.top();
					s.pop();
					if (check == '(' || check == '{') {
               			return false;
					}
					break;
		}
	}
	return (s.empty());
}
