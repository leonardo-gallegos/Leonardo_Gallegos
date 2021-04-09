#include <iostream>
 
#include <iostream>
 
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
    std::cout << 255%11 << -255%11;
}
