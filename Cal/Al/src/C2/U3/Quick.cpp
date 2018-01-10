#include "C2/U3/Quick.h"

void Quick::sort(Comparable ** a, int arrLen)
{
    // Eliminate dependence on input.
    sort(a, 0, arrLen - 1);
}

void Quick::sort(Comparable ** a, int lo, int hi)
{
    if(hi <= lo) return;

    int j = partition(a, lo, hi);
    // Sort left part a[lo .. j-1].
    sort(a, lo, j - 1);
    // Sort right part a[j+1 .. hi].
    sort(a, j + 1, hi);
}

int Quick::partition(Comparable ** a, int lo, int hi)
{
    // Partition into a[lo .. i-1], a[i], a[i+1 .. hi]
    // left and right scan indices
    int i = lo, j = hi + 1;
    // partitioning item
    Comparable * v = a[lo];
    while(true)
    {
        // Scan right, scan left, check for scan complete, and exchange.
        while(less(a[++i], v))
            if(i == hi) break;
        while(less(v, a[--j]))
            if(j == lo) break;
        if(i >= j) break;
        exch(a, i, j);
    }
    // Put v = a[j] into position
    exch(a, lo, j);
    // with a[lo .. j-1] <= a[j] <= a[j+1 .. hi].
    return j;
}

bool Quick::less(Comparable * v, Comparable * w)
{
    return v->compareTo(w) < 0;
}

void Quick::exch(Comparable ** a, int i, int j)
{
    Comparable * t = a[i];
    a[i] = a[j];
    a[j] = t;
}

bool Quick::isSorted(Comparable ** a, int arrLength)
{
    for(int i = 1; i< arrLength; i++)
        if(less(a[i], a[i - 1])) return false;
    return true;
}

