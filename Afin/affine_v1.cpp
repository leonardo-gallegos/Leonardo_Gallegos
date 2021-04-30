#include "affine_v1.h"
#include <string>
#include <random>

template <typename T>
Affine<T>::Affine(T message) {
    msg = message;
}

template <typename T> 
int Affine<T>::remainder (int a, int n) {
    int r = a - (a / n) * n;
	if (r < 0) {
		r = r + n;
	}
	return r;
}

template <typename T>
void Affine<T>::generate_keyA()
{
    int keyA = randomNumber();
    while (gcd(keyA, alpha.length()) != 1) {
        keyA = randomNumber();
    }
    a = keyA;
}

template <typename T>
void Affine<T>::inverse_keyA()
{
    int x;
    int y;
    int gcd = gcdExtended(a , alpha.length(), &x, &y);
    int keyA = remainder(x, alpha.length());
    a = keyA;
}

template <typename T>
void Affine<T>::generate_keyB()
{
    int keyB = randomNumber();
    b = keyB;
}

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

template <typename T>
int Affine<T>::randomNumber() {
    std::random_device generator;
    std::mt19937 engine(generator());
    std::uniform_int_distribution<int> dist(1, 26);
    int randomNumber = dist(engine);
    return randomNumber;
}

template <typename T>
T Affine<T>::encode()
{
    std::string code;
    (void) generate_keyA();
    (void) generate_keyB();
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
    (void) generate_keyA();
    (void) generate_keyB();
    (void) inverse_keyA();
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
