#include "railfence_v1.h"
#include <string>

template <typename T>
RailFence<T>::RailFence(T message, short int msgKey) {
    msg = message;
    key = msgKey;
}

template <typename T>
T RailFence<T>::encode() {
    std::string code;
    int x;
    int length = msg.length();
    for (int i{0}; i < key; ++i) {
        int flag = 1;
        if ((i == 0) || (i == key - 1)) {
            x = 2 * (key - 1);
            for (int j{i}; j < length; j += x) {
                code.push_back(msg[j]);
            }
        }
        else {
            int n = i;
            code.push_back(msg[n]);
            while (n < length) {
                if (flag == 1) {
                    x = (key - (i + 1)) * 2;
                    if (n + x < length) {
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
                    if (n + x < length) {
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

template <typename T>
T RailFence<T>::decode() {

    int ini;
    int x;
    int length = msg.length();
    std::string code(length, ' ');
    for (int i{0}; i < key; ++i) {
        int flag = 1;
        int h = key - 1;
        if (i == 0) {
            x = 2 * (h);
            int k = 0;
            for (int j{0}; j < length; j += x) {
                code.replace(j, 1, 1, msg[k]);
                k += 1;
            ini = k;
            }
        }
        else if (i == h) {
            x = 2 * (h);
            int y = h;
            int k = length - 1;
            while (y + x <= k) {
                y += x;
            }
            for (int j{y}; j >= h; j -= x) {
                code.replace(j, 1, 1, msg[k]);
                k -= 1;
            }
        }
        else {
            int n = i;
            while (n < length) {
                if (flag == 1) {
                    x = (key - (i + 1)) * 2;
                    if (n < length) {
                        code.replace(n, 1, 1, msg[ini]);
                        n = n + x;
                        ini += 1;
                        flag = 0;
                    }
                }
                else {
                    break;
                }
                if (flag == 0)  {
                    x = i * 2;
                    if (n < length) {
                        code.replace(n, 1, 1, msg[ini]);
                        n = n + x;
                        ini += 1;
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