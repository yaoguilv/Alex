#include <string>
#include <sstream>
#include "C1/Unit2_DataAbstraction/Accumulator.h"

using namespace std;

Accumulator::Accumulator()
{
    N = 0;
    total = 0;
}

void Accumulator::addDataValue(double val)
{
    N++;
    total += val;
}

double Accumulator::mean()
{
    return total/N;
}

string Accumulator::toString()
{
    ostringstream outString;
    outString.precision(5);
    outString.width(7);
    outString << this->mean();
    return "Mean (" + to_string(N) + " values): " + outString.str();
}
