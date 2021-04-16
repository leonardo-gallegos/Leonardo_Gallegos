#include <iostream>
#include <string>

std::string insMitad(std::string ini) {
    std::string ins(6, '*');
    ini.insert(ini.length() / 2, ins);
    return ini;
}

int main() {
    std::string ins = "******";
    
    std::string ini;
    std::cout << "Ingrese una cadena: ";
    std::cin >> ini;
    std::string ini1 = ini;

    std::cout << "Programa en main:   " << ini.insert(ini.length() / 2, ins) << std::endl;

    std::cout << "Usando una funcion: " << insMitad(ini1) << std::endl;
    return 0;
}