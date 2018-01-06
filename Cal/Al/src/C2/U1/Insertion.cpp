#include "C2/U1/Insertion.h"

void Insertion::sort(Comparable ** a, int arrLen)
{
    // Sort a[] into increasing order.
    for(int i = 1; i < arrLen; i++)
    {
        // Insert a[i] among a[i-1], a[i-2], a[i-3]
        for(int j = i; j > 0 && less(a[j], a[j - 1]); j--)
            exch(a, j, j - 1);
    }
}

void Insertion::exch(Comparable ** a, int i, int j)
{
    Comparable * t = a[i];
    a[i] = a[j];
    a[j] = t;
}

bool Insertion::less(Comparable * v, Comparable * w)
{
    return v->compareTo(w) < 0;
}

bool Insertion::isSorteed(Comparable ** a, int arrLen)
{
    for(int i = 1; i < arrLen; i++)
        if(less(a[i], a[i - 1])) return false;
    return true;
}
