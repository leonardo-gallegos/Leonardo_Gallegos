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
    Scytale(T message, short int columns, short int rows) {
        msg = message;
        col = columns;
        row = rows;
    }
    T encode();
    T decode();

};

template <typename T>
T Scytale<T>::encode()
{
    T strCode;

    for (int i{0}; i < col; ++i)
    {
        int k = i;
        for (int j{0}; j < row; ++j)
        {
            if (k > msg.length())
                strCode.push_back(' ');
            else
                strCode.push_back(msg[k]);
            k = k + col;
        }
    }
    return strCode;
}

template <typename T>
T Scytale<T>::decode()
{
    tmp = col;
    col = row;
    row = tmp;
    return encode();
}

#endif
