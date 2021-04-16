#ifndef ROT13_H
#define ROT13_H

template <class T>
class Rot13 {

private:
    int key;
    T msg;
    T alphabet = "abcdefghijklmnopqrstuvwxyz";
public:
    Rot13(T message, int msgKey);
    int remainder(int a, int n);
    T encode();
    T decode();
};

#endif