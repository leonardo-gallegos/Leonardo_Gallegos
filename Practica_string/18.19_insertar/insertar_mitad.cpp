#include <iostream>
#include <string>

std::string insMitad(std::string ini) {
    std::string ins = "******";
    ini.insert(ini.length() / 2, ins);
    return ini;
}

int main() {
    std::string ins = "******";
    
    std::string ini;
    std::cout << "Ingrese una cadena: ";
    std::cin >> ini;

    ini.insert(ini.length() / 2, ins);
    std::cout << ini << std::endl;

    //std::cout << insMitad(ini) << std::endl;
    return 0;
}