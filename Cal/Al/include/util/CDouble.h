#ifndef CDOUBLE_H
#define CDOUBLE_H
#include "Comparable.h"

using namespace std;

class CDouble : public Comparable
{
    private:
        double value;
    public:
        CDouble(double val);
        ~CDouble();
        void setValue(double val);
        double getValue();
        int compareTo(Comparable * that);
};
#endif
