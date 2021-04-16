#include <iostream>

/* Función que retorna el residuo positivo de una
 división entre "a" y "n"; en el caso de que el
 residuo sea negativo (división entre un entero
 negativo y un entero positivo) devolverá el valor
 del residuo positivo, es decir, se usará el valor
 del cociente menos una unidad.                 */

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
	
	std::cout << remainder( 255, 11) << std::endl; // Imprime 2
	std::cout << remainder(-255, 11);              // Imprime 9
}

/* Function that returns the positive remainder of
 a division between "a" and "n"; in the case that 
 the remainder is negative (division between a 
 negative integer and a positive integer) it will 
 return the value of the positive remainder, that 
 is, the value of the quotient minus one unit.   */