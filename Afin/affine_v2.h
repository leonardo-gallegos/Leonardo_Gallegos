#ifndef AFFINE_H
#define AFFINE_H

template <class T>
class Affine {

private:
    int a;
    int b;
    T msg;
    T alpha = "abcdefghijklmnopqrstuvwxyz,.-_ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789()";

public:
    Affine();
    Affine(int a, int b);
    int remainder(int a, int n);
    int gcd(int a, int n);
    int gcdExtended(int a, int b, int* x, int* y);
    int randomNumber();
    void generate_keyA();
    void generate_keyB();
    void inverse_keyA();
    T encode();
    T decode();
};

#endif
