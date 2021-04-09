#include "railfence_v1.h"

template <typename T>
RailFence<T>::RailFence(T message, short int msgKey) {
    msg = message;
    key = msgKey;
}

template <typename T>
T RailFence<T>::encode() {
    std::string code;
    int x = 0;
    int flag = 1;
    int length = msg.length();
    for (int i{0}; i < key; ++i) {
        if ((i == 0) || (i == key - 1)) {
            x = 2 * (key - 1);
            for (int j{i}; j <= length; j += x) {
                code.push_back(msg[j]);
            }
        }
        else {
            int n = i;
            code.push_back(msg[n]);
            while (n <= length) {
                if (flag == 1) {
                    x = (key - (i + 1)) * 2;
                    if (n + x <= length) {
                        code.push_back(msg[n + x]);
                        n = n + x;
                        flag = 0;
                    }
                }
                else {
                    break;
                }
                if (flag == 0)  {
                    x = i * 2;
                    if (n + x <= length) {
                        code.push_back(msg[n + x]);
                        n = n + x;
                        flag = 1;
                    }
                }
                else {
                    break;
                }
            }
        }
    }
    return code;
}