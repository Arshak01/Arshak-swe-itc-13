#include <iostream>
#include <fstream>

void file1() {
	try {
		std::fstream file1;
		file1.open("file1.txt", std::ios::out);
		
		if(!file1) {
			throw file1;
		} else {
			for(int i = 1; i <= 3; ++i) {
				file1 << "Name" << i << std::endl;
			}
		}
		file1.close();
	} catch(std::exception& file1) {
		std::cout << "File not created! \n";
	}
}

void file2() {
	try {
		std::fstream file2;
		file2.open("file2.txt", std::ios::out);
		
		if(!file2) {
			throw file2;
		} else {
			for(int i = 1; i <= 3; ++i) {
				file2 << "surname" << i << std::endl;
			}
		}
		file2.close();
	} catch(std::exception& file2) {
		std::cout << "File not created! \n";
	}
}

void file3() {
	try {
		std::fstream file1,file2,file3;
		std::string str1, str2;
		file1.open("file1.txt", std::ios::in);
		file2.open("file2.txt", std::ios::in);
		file3.open("file3.txt", std::ios::out);

		if(!file1 && !file2 && !file3) {
			throw file3;
		} else {
			while(getline(file1, str1) && getline(file2,str2)){
				file3 << str1 << " ";
				file3 << str2 << std::endl;
			}	
		}
		file1.close();
		file2.close();
		file3.close();
	} catch(std::exception& file3) {
		std::cout << "Files not created or readen! \n";
	}
}

int main() {
	file1();	
	file2();
	file3();
	
	return 0;
}
