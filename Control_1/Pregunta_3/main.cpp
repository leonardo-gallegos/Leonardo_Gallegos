#include <iostream>
#include <string>

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    std::string string_1;
    string_1 = std::to_string(num);
    std::cout << "This is a string: " << string_1 << std::endl;
    return 0;
}