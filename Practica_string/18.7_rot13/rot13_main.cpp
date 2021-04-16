#include <iostream>
#include <iomanip>
#include "rot13.cpp"

/* Cierta información en Internet se puede cifrar con un algoritmo simple conocido 
 como “rot13”, el cual rota cada carácter 13 posiciones en el alfabeto. Así, 'a' 
 corresponde a 'n', y 'x' corresponde a 'k'. rot13 es un ejemplo del cifrado de 
 clave simétrica. Con este tipo de cifrado, tanto el que cifra como el que descifra 
 utilizan la misma clave.

 a) Escriba un programa que cifre un mensaje usando rot13.
 b) Escriba un mensaje que descifre el mensaje codificado usando 13 como la clave.
 c) Después de escribir los programas de los incisos (a) y (b), responda brevemente 
 a la siguiente pregunta: si no conociera la clave para el inciso (b), ¿qué tan 
 difícil cree usted que sería quebrantar el código? ¿Qué pasaría si tuviera acceso 
 a un poder de cómputo considerable (por ejemplo, supercomputadoras)? En el 
 ejercicio 18.26 le pediremos que escriba un programa para lograr esto.           */

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

    Rot13<std::string> rot13(msg, key);

    if (opt == 1) {
        std::string code = rot13.encode();
        std::cout << "\nEncoded message: " << code;
    }
    if (opt == 2) {
        std::string code = rot13.decode();
        std::cout << "\nDecoded message: " << code;
    }

    return 0;
}