#include <iterator>
#include "Chapter1_Fundamentals/Unit2_DataAbstraction/StaticSETofInts.h"

using namespace std;

StaticSETofInts::StaticSETofInts(int* keys, int length)
{
    this->len = length;
    this->a = new int[length];
    int i = 0;
    for(int i = 0; i < length; i++)
    {
        a[i] = *(keys + i);
    }
}

bool StaticSETofInts::contains(int key)
{
    return rank(key) != -1;
}

int StaticSETofInts::rank(int key)
{
    // Binary search.
    int lo = 0;
    int hi = this->len - 1;
    while(lo <= hi)
    {
        // key is in a[lo..hi] or not present.
        int mid = lo + (hi - lo) / 2;
        if(key < a[mid])
            hi = mid - 1;
        else if (key > a[mid])
            lo = mid + 1;
        else
            return mid;
    }
    return -1;
}
