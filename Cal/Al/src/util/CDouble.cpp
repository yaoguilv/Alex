#include "util/CDouble.h"

using namespace std;

CDouble::CDouble(double val)
{
    this->value = val;
}

void CDouble::setValue(double val)
{
    this->value = val;
}

int CDouble::compareTo(Comparable * that)
{
    CDouble * thatCDouble = dynamic_cast<CDouble *>(that);
    return this->value - thatCDouble->value;
}

double CDouble::getValue()
{
    return this->value;
}
