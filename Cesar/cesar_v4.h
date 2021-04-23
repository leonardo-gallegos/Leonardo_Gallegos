#ifndef CAESAR_H
#define CAESAR_H

template <class T>
class Caesar {

private:
    int key;
    T msg;
    T lowerAlpha = "abcdefghijklmnopqrstuvwxyz";
    T upperAlpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:
    Caesar(T message, int msgKey);
    int remainder(int a, int n);
    T encode();
    T decode();
    void attack();
};

#endif