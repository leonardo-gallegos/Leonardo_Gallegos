#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <random>

std::fstream& GotoLine(std::fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    return file;
}

std::string hang(std::string all, int f) {
    std::string one   = "            O ";
    std::string two   = "\n           /";
    std::string three =  "|" ;
    std::string four  =  "\\";
    std::string five  ="\n            |";
    std::string six   = "\n           /";
    std::string seven = " \\";
    if (f == 0) {
        all += one;
    }
    else if (f == 1) {
        all += two;
    }
    else if (f == 2) {
        all += three;
    }
    else if (f == 3) {
        all += four;
    }
    else if (f == 4) {
        all += five;
    }
    else if (f == 5) {
        all += six;
    }
    else if (f == 6) {
        all += seven;
    }
    return all;
}

std::string randomLine() {
    std::fstream myFile("diccionario.txt");
    std::mt19937_64 gen{ std::random_device()() };
    std::uniform_int_distribution<int> dis{0, 200};
    int lineNumber = dis(gen);
    GotoLine(myFile, lineNumber);
    std::string line;
    myFile >> line;
    return line;
}

int main() {

    std::string line;
    line = randomLine();
    bool again = true;
    while (again) {
        int i = 0;
        int length = line.length();
        std::string code(length, 'X');
        std::cout << "Adivine la palabra:     " << code << std::endl;
        std::string all;
        while (i <= 7) {
            std::string letra;
            std::cout << "Ingrese una letra: ";
            std::cin >> letra;
            if (line.find(letra) != std::string::npos) {
                int pos = line.find(letra);
                code.replace(pos, 1, 1, line[pos]);
                if (code == line) {
                    std::string opt;
                    std::cout << "Felicidades!!! Adivino mi palabra. Desea jugar otra vez? si/no: ";
                    std::cin >> opt;
                    if (opt == "si") {
                        again = true;
                        line = randomLine();
                        break;
                    }
                    else if (opt == "no"){
                        again = false;
                        break;
                    }

                }
            }
            else {
                std::cout << "=========================" << std::endl;
                all = hang(all, i);
                std::cout << all << std::endl;
                std::cout << "=========================";
                i += 1;
                if (i == 7) {
                    std::cout << "\nPerdiste!!!" << "\nLa palabra es " << line << std::endl;
                    again = false;
                    break;
                }
            }

            std::cout << "\n" << code << std::endl;
            std::string opt;
            std::cout << "Revelar palabra? si/no: ";
            std::cin >> opt;
            if (opt == "si") {
                std::cout << "La palabra es " << line << std::endl;
                std::cout << "Desea jugar otra vez? si/no: ";
                std::cin >> opt;
                if (opt == "si") {
                    again = true;
                    line = randomLine();
                    break;
                }
                else if (opt == "no"){
                    again = false;
                    break;
                }
            }
        }
    }
}