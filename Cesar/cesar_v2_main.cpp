#include <iostream>
#include <iomanip>
#include "cesar_v2.cpp"

/* Caesar cipher using lower case and upper case.

   Cifrado César usando minúsculas y mayúsculas. */

int main() {
    std::string msg;
    int key;
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

    std::cout << "Key: ";
    std::cin >> key;
    std::cin.ignore();

    std::cout << "Message: ";
    getline(std::cin, msg);

    Caesar<std::string> csr(msg, key);

    if (opt == 1) {
        std::string code = csr.encode();
        std::cout << "\nEncoded message: " << code;
    }
    if (opt == 2) {
        std::string code = csr.decode();
        std::cout << "\nDecoded message: " << code;
    }

    return 0;
}
