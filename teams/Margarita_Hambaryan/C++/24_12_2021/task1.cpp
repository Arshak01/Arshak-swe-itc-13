#include<iostream>
#include<fstream>

void createFile(std::string fileName, std::string line) {
    std::fstream file;
    file.open(fileName, std::ios_base::app);
    if (!file) {
        std::cout << "File not created:( \n";
    } else {
        std::cout << "'" << line << "' added to a file " << fileName <<"\n";
        file << line << "\n"; 
        file.close();
    }   
}

void createMix(std::string fileName1, std::string FileName2, std::string fileName3) {
    std::fstream f1; 
    std::fstream f2; 
    std::fstream f3; 
    std::string str1; 
    std::string str2;

    f1.open("file1.txt", std::ios::in);
    f2.open("file2.txt", std::ios::in);
    f3.open("file3.txt", std::ios::out);
    while(getline(f2, str2)) {
        f3 << str1 << " ";
        while(getline(f2, str2)) {
            f3 << str2 << "\n";
            break;
        }
    }
    f1.close();
    f2.close();
    f3.close();
}

int main() {
    createFile("file1.txt", "Name1");
    createFile("file1.txt", "Name2");
    createFile("file1.txt", "Name3");

    createFile("file2.txt", "Surname1");
    createFile("file2.txt", "Surname2");
    createFile("file2.txt", "Surname3");

    createMix("file1.txt", "file2.txt", "file3.txt");

    return 0;
}

