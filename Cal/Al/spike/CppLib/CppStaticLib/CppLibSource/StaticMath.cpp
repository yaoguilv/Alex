#include "StaticMath.h"
#include <iostream>

using namespace std;

double StaticMath::add(double a, double b)
{
    return a + b;
}

double StaticMath::sub(double a, double b)
{
    return a - b;
}

double StaticMath::mul(double a, double b)
{
    return a * b;
}

double StaticMath::div(double a, double b)
{
    return a / b;
}

void StaticMath::print()
{
    cout << "Hello My StaticMath Library!" << endl;
}
