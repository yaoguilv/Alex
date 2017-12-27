#include <string>

#include "Chapter1_Fundamentals/Unit3_Stacks/FixedCapacityStackOfStrings.h"

using namespace std;

FixedCapacityStackOfStrings::FixedCapacityStackOfStrings(int cap)
{
    N = 0;
    a = new string[cap];
}

bool FixedCapacityStackOfStrings::isEmpty()
{
    return N == 0;
}

int FixedCapacityStackOfStrings::size()
{
    return N;
}

void FixedCapacityStackOfStrings::push(string item)
{
    a[N++] = item;
}

string FixedCapacityStackOfStrings::pop()
{
    return a[--N];
}
