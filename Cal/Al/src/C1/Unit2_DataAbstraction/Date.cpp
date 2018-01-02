#include "C1/Unit2_DataAbstraction/Date.h"

using namespace std;

Date::Date(int m, int d, int y)
{
    this->month = m;
    this->day = d;
    this->year = y;
}

int Date::getmonth()
{
    return this->month;
}

int Date::getday()
{
    return this->day;
}

int Date::getyear()
{
    return this->year;
}

string Date::toString()
{
    return to_string(getmonth()) + "/" + to_string(getday()) + "/" + to_string(getyear());
}

