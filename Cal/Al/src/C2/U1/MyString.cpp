#include "C2/U1/MyString.h"

MyString::MyString(string inStr)
{
    str = inStr;
}

string MyString::getStr()
{
    return str;
}

int MyString::compareTo(Comparable * that)
{
    MyString * thatStr = dynamic_cast<MyString *>(that);
    if(this->str > thatStr->str)
        return +1;
    else if(this->str < thatStr->str)
        return -1;
    return 0;
}

string MyString::toString()
{
    return str;
}
