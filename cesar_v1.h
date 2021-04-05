#ifndef CAESAR_H
#define CAESAR_H

template <class T>
class Caesar {

private:
    int key;
    T msg;
    T alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,;:¿?¡!1234567890";
public:
    Caesar(T message, int msgKey);
    T encode();
    T decode();

};

#endif