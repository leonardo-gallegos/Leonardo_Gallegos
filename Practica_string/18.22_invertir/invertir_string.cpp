#include <iostream>
#include <string>

int main() {
    std::string cadena1;
    std::cout << "Ingrese una cadena: ";
    std::cin >> cadena1;
    std::string::const_iterator iterador = cadena1.end();
    std::cout << "Cadena invertida: ";
    while (iterador >= cadena1.begin()) {
    std::cout << *iterador;
    iterador--;
    }
    std::cout << std::endl;
    return 0;
    }