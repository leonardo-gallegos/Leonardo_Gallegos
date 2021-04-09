#include <iostream>

/* Función que retorna el residuo positivo de una
 división entre "a" y "n"; en el caso de que el
 residuo sea negativo (división entre un entero
 negativo y un entero positivo) devolverá el valor
 del residuo positivo, es decir se usará el valor
 del cociente menos una unidad. */
int remainder (int a, int n) {
	int r;
    int q = a/n;
	if (a > 0) {
		r = a - q * n;
	}
	else {
		r = a - (q - 1) * n;
	}
	return r;
}
 
int main() {
	
	std::cout << remainder( 255, 11); // Prints 2
	std::cout << remainder(-255, 11); // Prints 9
}
