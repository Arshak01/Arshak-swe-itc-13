#include <iostream>
#include <fstream>

void mixFilesContents(std::string fName1, std::string fName2, std::string mixedFileName) {
    std::fstream file1;
    file1.open(fName1, std::ios::in);
    std::fstream file2;
    file2.open(fName2, std::ios::in);
    std::fstream mixFile;
    mixFile.open(mixedFileName, std::ios::out);

    std::string str1;
    std::string str2;
    while (std::getline(file1, str1) && std::getline(file2, str2)) {
        mixFile << str1 << " " << str2 << std::endl;
    }

    file1.close();
    file2.close();
    mixFile.close();
}

int main() {
    mixFilesContents("file1.txt", "file2.txt", "mixFile.txt");
    return 0;
}
