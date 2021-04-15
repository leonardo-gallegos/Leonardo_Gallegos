#include "cesar_v2.h"
#include <string>

template <typename T>
Caesar<T>::Caesar(T message, int msgKey) {
    msg = message;
    key = msgKey;
}

template <typename T>
int Caesar<T>::remainder (int a, int n) {
    int r = a - (a / n) * n;
	if (r < 0) {
		r = r + n;
	}
	return r;
}

template <typename T>
T Caesar<T>::encode()
{
    std::string code;
    short int length = msg.length();
    // For keys greater than 25, we'll obtain the remainder between
    // the key and 26. Explanation: "z" is located in the 25th place
    // of the alpha member, so if we have 26 as a key, that would
    // mean the real key is 0 because it will go around the lower
    // case interval one time (that's 26 slots).
    if (key > 25) {
        key = remainder(key, 26);
    }
    for (int i{0} ; i < length ; i++) {
        if (lowerAlpha.find(msg[i]) != std::string::npos) {
            int pos = lowerAlpha.find(msg[i]);
            int newPos = pos + key;
            if (newPos > 25) {
                newPos = remainder(newPos, 26);
            }
            code.push_back(lowerAlpha[newPos]);
        } 
        else if (upperAlpha.find(msg[i]) != std::string::npos) {
            int pos = upperAlpha.find(msg[i]);
            int newPos = pos + key;
            if (newPos > 25) {
                newPos = remainder(newPos, 26);
            }
            code.push_back(upperAlpha[newPos]);
        }           
        
    }
    return code;
}

template <typename T>
T Caesar<T>::decode()
{
    key = -key;
    std::string code;
    short int length = msg.length();
    // For keys greater than 25, we'll obtain the remainder between
    // the key and 26. Explanation: "z" is located in the 25th place
    // of the alpha member, so if we have 26 as a key, that would
    // mean the real key is 0 because it will go around the lower
    // case interval one time (that's 26 slots).
    if (key > 25) {
        key = remainder(key, 26);
    }
    for (int i{0} ; i < length ; i++) {
        if (lowerAlpha.find(msg[i]) != std::string::npos) {
            int pos = lowerAlpha.find(msg[i]);
            int newPos = pos + key;
            if (newPos < 0) {
                newPos = remainder(newPos, 26);
            }
            code.push_back(lowerAlpha[newPos]);
        } 
        else if (upperAlpha.find(msg[i]) != std::string::npos) {
            int pos = upperAlpha.find(msg[i]);
            int newPos = pos + key;
            if (newPos < 0) {
                newPos = remainder(newPos, 26);
            }
            code.push_back(upperAlpha[newPos]);
        }           
        
    }
    return code;
}