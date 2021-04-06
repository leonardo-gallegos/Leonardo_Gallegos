#include <iostream>
#include "escitala_v3.h"

int main() {
    std::string msg;
    short int col;
    short int row;
    short int opt;
    
    std::cout << "Choose an option" << std::endl;
    std::cout << std::right << std::setw(12)
              << "Encode (1)" << std::endl;
    std::cout << std::right << std::setw(12)
              << "Decode (2)" << std::endl;
    std::cout << "Option: ";
    std::cin >> opt;
    std::cin.ignore();

    std::cout << "Columns: ";
    std::cin >> col;
    std::cin.ignore();

    std::cout << "Rows: ";
    std::cin >> row;
    std::cin.ignore();

    std::cout << "Message: ";
    (void) getline(std::cin, msg);

    Scytale<std::string> code_1(msg, col, row);

    if (opt == 1) {
        std::string code = code_1.encode();
        std::cout << "\nEncoded message: " << code;
    } else {
        std::string code = code_1.decode();
        std::cout << "\nDecoded message: " << code;
    }
    
    return 0;
}
