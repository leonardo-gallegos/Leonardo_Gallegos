#include <iostream>
#include <iomanip>
#include "affine_v1.cpp"

int main() {
    std::string msg;
    int opt;

    std::cout << "Choose an option" << std::endl;
    std::cout << std::right << std::setw(12)
              << "Encode (1)" << std::endl;
    std::cout << std::right << std::setw(12)
              << "Decode (2)" << std::endl;
    std::cout << "Option: ";
    std::cin >> opt;
    std::cin.ignore();

    if ((opt != 1) && (opt != 2)) {
        return 0;
    }

    std::cout << "Message: ";
    getline(std::cin, msg);

    Affine<std::string> affine(msg);

    if (opt == 1) {
        std::string code = affine.encode();
        std::cout << "\nEncoded message: " << code;
    }
    else if (opt == 2) {
        std::string code = affine.decode();
        std::cout << "\nDecoded message: " << code;
    }
    return 0;
}