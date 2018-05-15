#include "util/CDouble.h"

using namespace std;

CDouble::CDouble(double val)
{
    this->value = val;
}

CDouble::~CDouble()
{}

void CDouble::setValue(double val)
{
    this->value = val;
}

int CDouble::compareTo(Comparable * that)
{
    CDouble * thatCDouble = dynamic_cast<CDouble *>(that);
    double result = this->value - thatCDouble->value;
    if(result > 0)
    {
        return +1;
    }
    else if(result < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

double CDouble::getValue()
{
    return this->value;
}
