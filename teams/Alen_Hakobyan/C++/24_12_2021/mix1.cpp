#include <iostream>
#include <fstream>

void file1(std::string fName,std::string text);
void file2(std::string fName,std::string text);
void file3(std::string fName1,std::string fName2,std::string fName3);

int main() {
		file1("file1.txt","Name");
		file2("file2.txt","Surname");
		file3("file1.txt","file2.txt","file3.txt");
		return 0;
}

void file1(std::string fName, std::string text) {
	std::fstream fName1;
	fName1.open(fName,std::ios::out);
	if(!fName1) {
		std::cout << " File1 not created!" << std::endl;
	}
	else {
		std::cout << "File1 created successfuly!" << std::endl;
		for(int i = 1; i < 4; ++i) {
			fName1 << text << i << std::endl;
		}
	}
	fName1.close();
}

void file2(std::string fName, std::string text) {
	std::fstream fName2;
	fName2.open(fName,std::ios::out);
	if(!fName2) {
		std::cout << " File2 not created!" << std::endl;
	}
	else {
		std::cout << "File2 created successfuly!" << std::endl;
		for(int i = 1; i < 4; ++i) {
			fName2 << text << i << std::endl;
		}
	}
	fName2.close();
}

void file3(std::string fileName1, std::string fileName2, std::string fileName3) {
	std::fstream fName1;
	std::fstream fName2;
	std::fstream fName3;
	std::string str1,str2;
	fName1.open(fileName1,std::ios::in);
	fName2.open(fileName2,std::ios::in);
	fName3.open(fileName3,std::ios::out);
	if(!fName3) {
		std::cout << " File3 not created!" << std::endl;
	}
	else {
		std::cout << "File3 created successfuly!" << std::endl;
		while(getline(fName1,str1) && getline(fName2,str2)) {
			fName3 << str1 << " ";
			fName3 << str2 << std::endl;
		}
		
	}

	fName1.close();
	fName2.close();
	fName3.close();
}
