#include <iostream>
#include <NTL/ZZ.h>

NTL::ZZ mod(NTL::ZZ a, NTL::ZZ n) {
    NTL::ZZ r = a - (a / n) * n;
    if (r < 0) {
        r = r + n;
    }
    return r;
}

NTL::ZZ mcd(NTL::ZZ a, NTL::ZZ b) {
    NTL::ZZ c;
    NTL::ZZ d;
    NTL::ZZ r;

    if (a==0) {
        c = b;
    }
    else {
        c = a;
        d = b;
        while (d != 0) {
            r = c - d * (c/d + NTL::ZZ(1/2));
            c = d;
            d = r;
        }
    }
    return abs(c);
}

int main()
{
    NTL::ZZ a;
    NTL::ZZ b;
    std::cin >> a;
    std::cin >> b;
    std::cout << "Gcd of given numbers is " << mcd(a, b);
    return 0;
}
