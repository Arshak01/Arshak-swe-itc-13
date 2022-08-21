#include <iostream>
#include <fstream>

int createOrWrite(std::string name, std::string content);
int fileMerger();

int main() {
	createOrWrite("file1.txt", "Name");
	createOrWrite("file2.txt", "Surname");
	fileMerger();
	return 0;
}

int createOrWrite(std::string fileName, std::string content) {

	std::fstream file;
	file.open(fileName);
	int i = 1;
	if (!file) {
		std::cout << "File not created! \n Doing some magic ;)\n";
		std::ofstream outfile(fileName);
		outfile << content << i << std::endl;
		outfile << content << ++i << std::endl;
		outfile << content << ++i << std::endl;
		file.close();
	} else {
		std::cout << "File created \n Doing some magic ;)\n";
		file << content << i << std::endl;
		file << content << ++i << std::endl;
		file << content << ++i << std::endl;
		file.close();
	}
	return 0;
}

int fileMerger() {
	std::ofstream mixed("mixed.txt");
	std::ifstream file1("file1.txt");
	std::ifstream file2("file2.txt");
	std::string line;
	while (std::getline(file1, line)) {
		mixed << line << " ";
		while (std::getline(file2, line)) {
			mixed << line << '\n';
			break;
		}
	}
	file1.close();
	file2.close();
	mixed.close();
	return 0;
}
