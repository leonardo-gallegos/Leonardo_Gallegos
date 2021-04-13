#ifndef RAIL_FENCE_H
#define RAIL_FENCE_H

#include <string>
#include <iomanip>

template <class T>
class RailFence {

private:
    T msg;
    short int key;
public:
    RailFence (T message, short int msgKey);
    T encode ();
    T decode ();
};

#endif