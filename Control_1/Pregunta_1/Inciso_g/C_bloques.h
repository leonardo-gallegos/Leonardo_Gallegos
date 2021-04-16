#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <vector>

class Block {

private:
    int key;
    std::string msg;

public:
    Block(std::string message, int msgKey);
    static int remainder(int a, int n);
    std::vector <std::string> encode();
};

#endif