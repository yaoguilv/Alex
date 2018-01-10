#include "C2/U3/Quick3way.h"

void Quick3way::sort(Comparable ** a, int arrLen)
{
    // Eliminate dependence on input.
    sort(a, 0, arrLen - 1);
}

void Quick3way::sort(Comparable ** a, int lo, int hi)
{
    if(hi <= lo) return;
    int lt = lo, i = lo + 1, gt = hi;
    Comparable * v = a[lo];
    while(i <= gt)
    {
        int cmp = a[i]->compareTo(v);
        if(cmp < 0) exch(a, lt++, i++);
        else if(cmp > 0) exch(a, i, gt--);
        else i++;
    }
    // Now a[lo .. lt-1] < v = a[lt .. gt] < a[gt+1 .. hi].
    sort(a, lo, lt - 1);
    sort(a, gt + 1, hi);
}

int Quick3way::partition(Comparable ** a, int lo, int hi)
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

bool Quick3way::less(Comparable * v, Comparable * w)
{
    return v->compareTo(w) < 0;
}

void Quick3way::exch(Comparable ** a, int i, int j)
{
    Comparable * t = a[i];
    a[i] = a[j];
    a[j] = t;
}

bool Quick3way::isSorted(Comparable ** a, int arrLength)
{
    for(int i = 1; i< arrLength; i++)
        if(less(a[i], a[i - 1])) return false;
    return true;
}
