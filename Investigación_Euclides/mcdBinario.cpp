#include <iostream>
#include <NTL/ZZ.h>

NTL::ZZ mod(NTL::ZZ a, NTL::ZZ n) {
    NTL::ZZ r = a - (a / n) * n;
    if (r < 0) {
        r = r + n;
    }
    return r;
}
 
NTL::ZZ mcdBinario(NTL::ZZ a, NTL::ZZ b) {
    NTL::ZZ g = NTL::ZZ(1);
    while ((mod(a, NTL::ZZ(2)) == 0) && (mod(b, NTL::ZZ(2)) == 0)) {
        a = a / 2;
        b = b / 2;
        g = 2 * g;
    }
    while (a != 0) {
        if (mod(a, NTL::ZZ(2)) == 0) {
            a = a / 2;
        }
        else if (mod(b, NTL::ZZ(2)) == 0) {
            b = b / 2;
        }
        else {
            NTL::ZZ t = abs(a - b) / 2;
            if (a >= b) {
                a = t;
            }
            else {
                b = t;
            }
        }
    }
    return g * b;
}


int main()
{
    NTL::ZZ a;
    NTL::ZZ b;
    std::cin >> a;
    std::cin >> b;
    std::cout << "Gcd of given numbers is " << mcdBinario(a, b);
    return 0;
}
