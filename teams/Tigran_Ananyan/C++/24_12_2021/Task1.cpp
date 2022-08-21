#include <iostream>
#include <fstream>
#include <stdexcept>

int writeToFile(std::string filePath, std::string value) {
    std::ofstream fout;
    try {
        fout.open(filePath, std::ofstream::app);
        fout << value << std::endl;
        std::cout << "you have successfully declared your data" << std::endl;
    }
    catch(const std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
    fout.close();
    return 0;
}

int fileMixer() {
    std::ofstream mixedFile("mixed.txt");
    std::ifstream file1("file1.txt");
    std::ifstream file2("file2.txt");
   // file1.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    //file2.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    std::string str;

   // try {
   
        while (std::getline(file1, str)) {
	    	mixedFile << str << " ";
	    	while (std::getline(file2, str)) {
                mixedFile << str << '\n';
                break;
	    }
     }
     std::cout << "you have successfully mixed your data" << std::endl;
   // }catch(const std::ifstream::failure &ex) {
   //     std::cerr << "Error: " << ex.what() << std::endl;
   // }

    file1.close();
    file2.close();
    mixedFile.close();
    return 0;
}

int main() {
   writeToFile("file1.txt", "Karen");
   writeToFile("file1.txt", "Aren");
   writeToFile("file2.txt", "Abrahamyan");
   writeToFile("file2.txt", "Abgaryan");
   fileMixer();
    return 0;
}
