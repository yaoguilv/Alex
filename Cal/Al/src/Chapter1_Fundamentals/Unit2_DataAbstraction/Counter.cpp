#include <string>
#include <iostream>
#include "Chapter1_Fundamentals/Unit2_DataAbstraction/Counter.h"

using namespace std;

Counter::Counter(string id)
{
    this->name = id;
    this->count = 0;
}

void Counter::increment()
{
    this->count++;
}

int Counter::tally()
{
    return this->count;
}

string Counter::toString()
{
    return to_string(this->count) + " " + this->name;
}
