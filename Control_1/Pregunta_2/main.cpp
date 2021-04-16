#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cout << "Enter a numeric string: ";
    std::cin >> str;

    int num_1;
    num_1 = std::stoi(str);
    std::cout << "This is a integer: " << num_1 << std::endl;
    return 0;
}