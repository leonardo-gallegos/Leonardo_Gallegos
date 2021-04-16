#include <iostream>
#include <string>

std::string concatenar(std::string strNombre, std::string strApellido) {
    std::string Nombre = strNombre + ' ' + strApellido;
    return Nombre;
}

int main() {
    std::string nombre;
    std::cout << "Ingrese el nombre: ";
    std::cin >> nombre;

    std::string apellido;
    std::cout << "Ingrese el apellido: ";
    std::cin >> apellido;

    std::cout << "Programa en main:   " << nombre + ' ' + apellido;
    std::cout << std::endl;
    std::cout << "Usando una funcion: " << concatenar(nombre, apellido);
    return 0;
}