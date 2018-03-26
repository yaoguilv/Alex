#include "C2/U1/MyInt.h"

MyInt::MyInt(int inInt)
{
    value = inInt;
}

int MyInt::getInt()
{
    return value;
}

int MyInt::compareTo(Comparable * that)
{
    MyInt * thatInt = dynamic_cast<MyInt *>(that);
    if(this->value > thatInt->getInt())
        return +1;
    else
        return -1;
    return 0;
}
