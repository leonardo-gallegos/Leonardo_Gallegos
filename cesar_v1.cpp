#include "cesar_v1.h"
#include <string>

template <typename T>
Caesar<T>::Caesar(T message, int msgKey) {
    msg = message;
    key = msgKey;
}

template <typename T>
T Caesar<T>::encode()
{
    std::string code;
    int pos;
    short int length = msg.length();
    short int size = alpha.length();
    // For keys greater than 25, we'll obtain the remainder between
    // the key and 25. Explanation: "z" is located in the 25th place
    // of the alpha member, so if we have 26 as a key, that would
    // mean the real key is 1 because it will go around the lower
    // case interval one time (that's 25 slots) and 1 more space.
    if (key > 25) {
        key = key % 25;
    }
    for (int i{0} ; i < length ; ++i) {
        for (int j{0} ; j < size ; ++j) {
            if (msg[i] == alpha[j]) {
                pos = j + key;
                // Lower case interval within the alpha (alphabet
                // and characters) member of Caesar class
                if      (  ((pos > 25) && (j >  0) && (j < 26))
                        || ((pos > 51) && (j > 26) && (j < 52))) {
                        pos = pos - 26;
                }
                // Upper case interval
                else if (  ((pos < 26) && (j > 25) && (j < 52))
                        || ((pos <  0) && (j >  0) && (j <  26))) {
                        pos = pos + 26;
                }
                // Numbers and punctuation marks interval
                else if ((j > 51) && ( j < 70)) {
                        pos = j;
                }
                code.push_back(alpha[pos]);
            }
        }
    }
    return code;
}

template <typename T>
T Caesar<T>::decode()
{
    key = -key;
    return encode();
}