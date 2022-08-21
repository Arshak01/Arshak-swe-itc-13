#include <iostream>

void check(bool);

int main() {
    char word[15];
    char sub[5];
    bool flag = false;
    std::cout << "Enter the word 'maximum 15 character': ";
    std::cin >> word;
    std::cout << "Enter the subse '3 character': ";
    std::cin >> sub;
    for(int i = 0; i<15; i++){
    	if (word[i]!= sub[0]){
    		continue;
    	}
    	if(word[i] == sub[0]){
    		if(word[i+1] == sub[1]){
    			if(word[i+2] == sub[2]){
    				flag = true;
    				break;
    			}
    		}
	}
	}
    check(flag);
    
    return 0;
}

void check(bool flag){
	if(flag == true){
	std::cout << "Is subse is the subsequence of word? YES" << std::endl;
	}
	if(flag == false){
	std::cout << "Is subse is the subsequence of word? NO " << std::endl;
	}
	return;
}
