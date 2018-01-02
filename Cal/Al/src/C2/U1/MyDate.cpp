#include "C2/U1/MyDate.h"

MyDate::MyDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

int MyDate::getDay()
{
    return day;
}

int MyDate::getMonth()
{
    return month;
}

int MyDate::getYear()
{
    return year;
}

int MyDate::compareTo(MyDate * that)
{
    if(this->year > that->year) return +1;
    if(this->year < that->year) return -1;
    if(this->month > that->month) return +1;
    if(this->month < that->month) return -1;
    if(this->day > that->day) return +1;
    if(this->day < that->day) return -1;
    return 0;
}

string MyDate::toString()
{
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}
