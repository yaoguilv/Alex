#include "util/CInt.h"

CInt::CInt(int inInt)
{
    value = inInt;
}

int CInt::getInt()
{
    return value;
}

int CInt::compareTo(Comparable * that)
{
    CInt * thatInt = dynamic_cast<CInt *>(that);
    if(this->value > thatInt->getInt())
        return +1;
    else
        return -1;
    return 0;
}
