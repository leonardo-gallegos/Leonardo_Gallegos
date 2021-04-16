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
    if (r == 0) {
        return n;
    }
    else {
        return mcd(n, r);
    }
}

int main() {
    std::cout << mcd(4864, 3458);
}