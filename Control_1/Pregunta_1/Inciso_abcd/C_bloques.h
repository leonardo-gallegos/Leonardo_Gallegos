#ifndef BLOCK_H
#define BLOCK_H

template <class T>
class Block {

private:
    int key;
    T msg;

public:
    Block(T message, int msgKey);
    int remainder(int a, int n);
    T encode();
};

#endif