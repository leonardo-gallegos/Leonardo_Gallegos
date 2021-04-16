#include <iostream>

int remainder (int a, int n) {
    int r = a - (a / n) * n;
    if (r < 0) {
        r = r + n;
    }
    return r;
}

int mcd(int a, int n) {
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

int main() {
    std::cout << mcd(4864, 3458);
}