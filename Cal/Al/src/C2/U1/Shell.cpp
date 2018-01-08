#include "C2/U1/Shell.h"
void Shell::sort(Comparable ** a, int arrLen)
{
    // Sort a[] into increasing order.
    int h = 1;
    while(h < arrLen/3)
        h = 3 * h + 1;
    while(h >= 1)
    {
        // h-sort the array.
        for(int i = h; i < arrLen; i++)
        {
            // Insert a[i] among a[i-h], a[i-2*h],a[i-3*h]... .
            for(int j = i; j >= h && less(a[j], a[j - h]); j -= h)
                exch(a, j, j - h);
        }
        h = h/3;
    }
}

bool Shell::less(Comparable * v, Comparable * w)
{
    return v->compareTo(w) < 0;
}

void Shell::exch(Comparable ** a, int i, int j)
{
    Comparable * t = a[i];
    a[i] = a[j];
    a[j] = t;
}

bool Shell::isSorted(Comparable ** a, int arrLength)
{
    for(int i = 1; i< arrLength; i++)
        if(less(a[i], a[i - 1])) return false;
    return true;
}
