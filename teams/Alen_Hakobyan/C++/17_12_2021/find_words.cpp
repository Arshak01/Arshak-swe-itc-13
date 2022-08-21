#include <iostream>

void compare(char, char);
void flagIs(bool);
char word[6];
char subse[4];
bool flag = false;
int main() {
	std::cout << "Write a word of 5 letters: ";
	std::cin.getline(word,6);
	std::cout << "write a subsequent of 3 letters: ";
	std::cin.getline(subse,4);
	compare(word[6],subse[4]);
	flagIs(flag);
	return 0;
}

void compare(char, char) {
	for(int i = 0; i < 6; ++i) {
		if(word[i] != subse[0]) {
			continue;
		}
		if(word[i] == subse[0]) {
			if(word[i+1] == subse[1]) {
				if(word[i+2] == subse[2]) {
					flag = true;
					break;
				}
			}
		}
	}
}

void flagIs(bool flag) {
	if(flag) {
		std::cout << "Is subse is the subsequence of word? 1" << std::endl;
	}
	else {
		std::cout << "Is subse is the subsequence of word? 0" << std::endl;
	}
}
