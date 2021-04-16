#include <iostream>
#include "C_bloques.cpp"

int main() {
    std::string msg;
    std::cout << "Enter a message: ";
    getline(std::cin, msg);

    int key;
    std::cout << "Enter a key: ";
    std::cin >> key;
    std::cin.ignore();

    Block<std::string> Block_1(msg, key);

    std::string code = Block_1.encode();
    std::cout << "\nEncoded message: \n" << code;

    return 0;
}