#include <iostream>
#include <iomanip>
#include "affine_v2.cpp"

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

    if (opt == 1) {
        // Objeto Emisor
        Affine<std::string> Emitter;
        std::string code = Emitter.encode();
        std::cout << "\nEncoded message: " << code;
    }
    else if (opt == 2) {
        // Objeto Receptor
        Affine<std::string> Receiver(5, 8);
        std::string code = Receiver.decode();
        std::cout << "\nDecoded message: " << code;
    }
    return 0;
}