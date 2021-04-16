#include "C_bloques.h"
#include <string>

template <typename T>
Block<T>::Block(T message, int msgKey) {
    msg = message;
    key = msgKey;
}

template <typename T>
int Block<T>::remainder (int a, int n) {
    int r = a - (a / n) * n;
	if (r < 0) {
		r = r + n;
	}
	return r;
}

template <typename T>
T Block<T>::encode()
{
    std::string code;
    int length = msg.length();
    int q = length / key;
    int r = remainder(length, key);
    int newLength;
    if ((r > 0) && (r < key)) {
        newLength = q * key + key;
    }
    else {
        newLength = length;
    }
    for (int i{0}; i < newLength; i += key) {
        for (int j{i}; j < i + key; j++) {
            if (j < length) {
                code.push_back(msg[j]);
            }
            else {
                code.push_back('X');
            }
        }
        code.push_back('\n');
    }
    return code;
}
