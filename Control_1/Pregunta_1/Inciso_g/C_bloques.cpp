#include "C_bloques.h"
#include <string>
#include <vector>


Block::Block(std::string message, int msgKey) {
    msg = std::move(message);
    key = msgKey;
}

int Block::remainder (int a, int n) {
    int r = a - (a / n) * n;
    if (r < 0) {
        r = r + n;
    }
    return r;
}

std::vector<std::string> Block::encode()
{
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
    std::vector<std::string> vector;
    for (int i{0}; i < newLength; i += key) {
        std::string code;
        for (int j{i}; j < i + key; j++) {
            if (j < length) {
                code.push_back(msg[j]);
            }
            else {
                code.push_back('X');
            }
        }
        vector.push_back(code);
    }
    return vector;
}
