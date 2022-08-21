#include <iostream>
#include <cstring>
bool isSubSequence(char str1[], char str2[]) {
	int i, j;
	i = j = 0;
	while (str1[i] != '\0') {
		while ((str1[i] != str2[j]) && str2[j] != '\0') {
			++j;
		}
		if (str2[j] == '\0')
			break;
		++j;
		++i;
	}
	if (str1[i] == '\0')
		return 1;
	return 0;
}

int main() {
	int flag;
	char s1[1000];
	char s2[1000];
	std::cout << "Input first string: ";
	std::cin >> s1;
	std::cout << "Input second string: ";
	std::cin >> s2;
	if (strlen(s1) < strlen(s2))
		flag = isSubSequence(s1, s2);
	else
		flag = isSubSequence(s2, s1);
	(flag) ? std::cout << "1" : std::cout << "0";
	std::cout << std::endl;
	return 0;
}
