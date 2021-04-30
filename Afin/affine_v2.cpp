#include "affine_v2.h"
#include <string>
#include <random>

template <typename T>
Affine<T>::Affine() {
    // Asigna un número aleatorio a la clave 'a'
    // generate_keyA();
    // Asigna un número aleatorio a la clave 'a'
    // generate_keyB();
    // Supongamos que las claves generadas
    // aleatoriamente son 'a' = 5 y 'b' = 8
    a = 5;
    b = 8;
}

template <typename T>
Affine<T>::Affine(int keyA, int keyB) {
    // Asigna la clave inversa de 'a' a 'a'
    a = keyA;
    b = keyB;
    inverse_keyA();
}

// Función módulo positivo
template <typename T> 
int Affine<T>::remainder (int a, int n) {
    int r = a - (a / n) * n;
	if (r < 0) {
		r = r + n;
	}
	return r;
}

// Función máximo común divisor
template <typename T>
int Affine<T>::gcd(int a, int n) {
    int r = remainder(a, n);
    while (r != 0) {
        a = n;
        n = r;
        r = remainder(a , n);
        if (r == 0) {
            return n;
        }
    }
    return 1;
}

// Algoritmo extendido de Euclides
template <typename T>
int Affine<T>::gcdExtended(int a, int b, int* x, int* y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int x1, y1;
    int gcd = gcdExtended(remainder(b, a), a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

// Función para generar números aleatorios
// Stephan T. Lavavej (stl) from Microsoft did a talk at Going Native about how to use the 
// new C++11 random functions and why not to use rand().
// When you need a random number, don't call rand() and especially don't say rand() % 100!

// Usar la función rand() para generar números aleatorios es considerado una mala práctica
// por esta razón usaré la libería <random>.
// Nota: Se necesita la versión 9.2 de GCC.
// Más información: https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful
template <typename T>
int Affine<T>::randomNumber() {
    std::random_device generator;
    std::mt19937 engine(generator());
    std::uniform_int_distribution<int> dist(1, 26);
    int randomNumber = dist(engine);
    return randomNumber;
}

// Genera la clave 'a'
template <typename T>
void Affine<T>::generate_keyA()
{
    // Obtiene un número aleatorio de la función randomNumber()
    int keyA = randomNumber();
    // Mientras que el MCD de la clave y la longitud del alfabeto
    // sea diferente de 1, es decir, no son coprimos, se generará
    // una nueva clave hasta que satisfaga la condición
    while (gcd(keyA, alpha.length()) != 1) {
        keyA = randomNumber();
    }
    // Se asigna a 'a' la clave generada
    a = keyA;
}

// Función clave inversa de 'a'
template <typename T>
void Affine<T>::inverse_keyA()
{
    int x;
    int y;
    // Usamos el algoritmo extendido de Euclides para obtener 'x'
    int gcd = gcdExtended(a , alpha.length(), &x, &y);
    // Si el valor de 'x' es menor que 0 o mayor que la longitud
    // alfabeto la clave será igual al módulo de 'x' y alpha.length()
    int keyA = remainder(x, alpha.length());
    // Asignamos la clave inversa a 'a'
    a = keyA;
}

// Genera la clave 'b'
template <typename T>
void Affine<T>::generate_keyB()
{
    // Obtenemos un número aleatorio
    int keyB = randomNumber();
    // Asignamos el número aleatorio a 'b'
    b = keyB;
}

template <typename T>
T Affine<T>::encode()
{
    std::string code;
    std::cout << "Message: ";
    getline(std::cin, msg);
    short int length = msg.length();
    for (int i{0} ; i < length ; i++) {
        int pos = alpha.find(msg[i]);
        if (pos != std::string::npos) {
            int newPos = pos * a + b;
            if (newPos > alpha.length()) {
                newPos = remainder(newPos, alpha.length());
            }
            code.push_back(alpha[newPos]);  
        }          
    }
    return code;
}

template <typename T>
T Affine<T>::decode()
{
    std::string code;
    std::cout << "Message: ";
    getline(std::cin, msg);
    short int length = msg.length();
    for (int i{0} ; i < length ; i++) {
        int pos = alpha.find(msg[i]);
        if (pos != std::string::npos) {
            int newPos = a * (pos - b);
            if ((newPos < 0) || (newPos > alpha.length())) {
                newPos = remainder(newPos, alpha.length());
            }
            code.push_back(alpha[newPos]);  
        }          
    }
    return code;
}
