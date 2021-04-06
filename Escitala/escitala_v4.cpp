#include "escitala_v4.h"
#include <string>
#include <iomanip>

template <typename T>
Scytale<T>::Scytale(T message, short int columns, short int rows) {
    msg = message;
    col = columns;
    row = rows;
}

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
