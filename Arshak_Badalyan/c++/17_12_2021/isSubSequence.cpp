#include <iostream>

void check(bool flag){
	if(flag == true){
		std::cout << "Is subse is the subsequence of word? 1 " << std::endl;
	}
	if(flag == false){
		std::cout << "Is subse is the subsequence of word? 0 " << std::endl;
	}
	return;
}

int main() {
	char word[10];
	char sub[3];
	bool flag = false;
	std::cout << "Enter the word maximum 10 chars : ";
	std::cin >> word;
	std::cout << "Enter the subse 3 chars : ";
	std::cin >> sub;
	for(int i = 0; i < 10; ++i) {
			if (word[i] != sub[0]) {
				continue;
			}
			if(word[i] == sub[0]) {
					if(word[i+1] == sub[1]) {
							if(word[i+2] == sub[2]) {
									flag = true;
									break;
							}
					}
			}
	}
	check(flag);
	
	return 0;
}
