#include <iostream>
#include <fstream>


int main() {
    std::fstream my_file;
    my_file.open("file1.txt", std::ios::out);
    if (!my_file) {
        std::cout << "File not created";
    } else {
        std::cout << "File created";
        my_file << "Name1 \nName2 \nName3 ";
        my_file.close();
    }

    my_file.open("file2.txt", std::ios::out);
    if (!my_file) {
        std::cout << "File not created";
    } else {
        std::cout << "File created";
        my_file << "Surname1 \nSurname2 \nSurName3 ";
        my_file.close();
    }

    std::ifstream ifile("file1.txt", std::ios::in);
    std::ifstream ifile2("file2.txt", std::ios::in);
    std::ofstream ofile("mixFile.txt", std::ios::out | std::ios::app);
    my_file.open("mixFile.txt");
    std::string line;
    if (!ifile.is_open() || !ifile2.is_open()) {
        std::cout << "file not found";
    } else {
        while (std::getline(ifile, line)) {
		    ofile << line << " ";
		    while (std::getline(ifile2, line)) {
			    ofile << line << '\n';
		        	break;
      		}	
        }
     }
     my_file.close();
     ifile.close();
     ifile2.close();
     ofile.close();

    return 0;
}
