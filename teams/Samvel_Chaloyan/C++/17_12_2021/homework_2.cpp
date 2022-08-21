#include <iostream>

void compare(char word[], char chunk[]) {
	bool check = false;
	for (int i = 0; i < 10; ++i) {
		if (word[i] == chunk[0]) {
			check = true;
			if (word[i + 1] == word[1]) {
			for (int j = 1; j < 10; ++j) {
				i++;
				if (word[i] == chunk[j]) { 
					check = true;
				}
			} 
		}
		} else {
			continue;
		}
	}
	if (check == true) {
		std::cout << "The '" << chunk << "' is a subsequnce." << std::endl;
	} else {
		std::cout << "The '" << chunk << "' is NOT a subsequnce." << std::endl;
	}
}

int main() {
	char word[10];
	char chunk[10];
	std::cout << "Enter a word containing maximum 10 letter : ";
	std::cin.getline (word, 10);
	std::cout << "Enter a subsequnce of the word : ";
	std::cin.getline (chunk, 10);
	compare(word, chunk);
	return 0;
}
