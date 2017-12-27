#include "DynamicMath.h"
#include <iostream>

using namespace std;

double DynamicMath::add(double a, double b)
{
    return a + b;
}

double DynamicMath::sub(double a, double b)
{
    return a - b;
}

double DynamicMath::mul(double a, double b)
{
    return a * b;
}

double DynamicMath::div(double a, double b)
{
    return a / b;
}

void DynamicMath::print()
{
    cout << "Hello My DynamicMath Library!" << endl;
}
