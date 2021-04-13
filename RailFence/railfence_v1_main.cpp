#include <iostream>
#include "railfence_v1.cpp"

int main() {
    std::string msg;
    short int key;
    short int opt;

    std::cout << "Choose an option" << std::endl;
    std::cout << std::right << std::setw(12)
              << "Encode (1)" << std::endl;
    std::cout << std::right << std::setw(12)
              << "Decode (2)" << std::endl;
    std::cout << "Option: ";
    std::cin >> opt;
    std::cin.ignore();

    std::cout << "Key: ";
    std::cin >> key;
    std::cin.ignore();

    std::cout << "Message: ";
    (void) getline(std::cin, msg);

    RailFence<std::string> code_1(msg, key);

    if (opt == 1) {
        std::string code = code_1.encode();
        std::cout << "\nEncoded message: " << code;
    } else {
        std::string code = code_1.decode();
        std::cout << "\nDecoded message: " << code;
    }

    return 0;
}
