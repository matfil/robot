//klasa pole
#ifndef POLE_H
#define POLE_H
#include <string>

//takie bardzo bazowe elementy

enum kolor {WHITE, GRAY, BLACK};

class pole
{
public:
    char type;
    std::string way;
    int color;

};
#endif
