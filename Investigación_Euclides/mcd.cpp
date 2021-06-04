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
    NTL::ZZ c = abs(a);
    NTL::ZZ d = abs(b);

    while (d != 0) {
        NTL::ZZ r = mod(c, d);
        c = d;
        d = r;
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
