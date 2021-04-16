#include "rot13.h"
#include <string>

template <typename T>
Rot13<T>::Rot13(T message, int msgKey) {
    msg = message;
    key = msgKey;
}

template <typename T>
int Rot13<T>::remainder (int a, int n) {
    int r = a - (a / n) * n;
	if (r < 0) {
		r = r + n;
	}
	return r;
}

template <typename T>
T Rot13<T>::encode()
{
    std::string code;
    short int length = msg.length();

    if (key > 25) {
        key = remainder(key, 26);
    }
    for (int i{0} ; i < length ; i++) {
        int pos = alphabet.find(msg[i]);
        int newPos = pos + key;
        if (newPos > 25) {
            newPos = remainder(newPos, 26);
        }
        code.push_back(alphabet[newPos]);
    }
    return code;
}

template <typename T>
T Rot13<T>::decode()
{
    key = -key;
    std::string code;
    short int length = msg.length();

    if (key > 25) {
        key = remainder(key, 26);
    }
    for (int i{0} ; i < length ; i++) {
        int pos = alphabet.find(msg[i]);
        int newPos = pos + key;
        if (newPos < 0) {
            newPos = remainder(newPos, 26);
        }
        code.push_back(alphabet[newPos]);
    }
    return code;
}