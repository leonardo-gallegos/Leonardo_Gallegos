#ifndef SCYTALE_H
#define SCYTALE_H

#include <string>
#include <iomanip>

template <class T>
class Scytale {

private:
    short int col;
    short int row;
    short int tmp = 0;
    T msg;
public:
    Scytale(T message, short int columns, short int rows);
    T encode();
    T decode();
};

#endif