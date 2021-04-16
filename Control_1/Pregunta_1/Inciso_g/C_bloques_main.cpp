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

    Block Block_1(msg, key);

    std::vector<std::string> code = Block_1.encode();
    std::cout << "\nEncoded message: \n";

    std::vector<std::string>::iterator it;
    it = code.begin();

    std::cout << "My vector contains: ";
    for (it = code.begin(); it < code.end(); it++) {
        if (it == code.begin()) {
            std::cout << "[ " << *it;
        }
        else if (it == code.end() - 1) {
            std::cout << *it << " ]";
        }
        else {
            std::cout << *it << ", ";
        }
    }

    return 0;
}