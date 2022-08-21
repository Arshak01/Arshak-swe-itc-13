#include <iostream>
#include <fstream>

void lineWriter(std::string fileName, std::string line, int lineCount) {
    std::fstream file;
    file.open(fileName, std::ios::out);
    if(!file) {
        std::cout << "File is not created" << std::endl;
    } else {
        for(int i = 0; i < lineCount; ++i) {
            file << line << lineCount << std::endl;
        }
    }
    file.close();
}

void lineMixer(std::string fileName1, std::string fileName2, std::string fileName3, int lineCount) {
    std::string line = " ";
    std::fstream file1, file2, file3;
    file1.open(fileName1, std::ios::in);
    file2.open(fileName2, std::ios::in);
    file3.open(fileName3, std::ios::trunc);
    file3.close();
    file3.open(fileName3, std::ios::out);
    for(int i = 0; i < lineCount; ++i) {
        file1 >> line;
        file3 << line;
        file3 << ' ';
        file2 >> line;
        file3 << line;
        file3 << std::endl;

    }
    file1.close();
    file2.close();
    file3.close();
}

void print(std::string fileName, int lineCount) {
    std::fstream file;
    std::string line = " ";
    file.open(fileName, std::ios::in);
    for(int i = 0; i < lineCount; ++i) {
        getline(file, line);
        std::cout << line << std::endl;
    }
}

int main() {
    int lineCount = 3;
    lineWriter("file1.txt", "Name", lineCount);
    lineWriter("file2.txt", "Surname", lineCount);
    lineMixer("file1.txt", "file2.txt", "file3.txt", lineCount);
    print("file3.txt", lineCount);
    return 0;
}
