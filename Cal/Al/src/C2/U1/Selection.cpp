#include "C2/U1/Selection.h"

void Selection::sort(Comparable ** a, int arrLength)
{
    for(int i = 0; i < arrLength; i++)
    {
        int min = i;
        for(int j = i + 1; j < arrLength; j++)
            if(less(a[j], a[min])) min = j;
        exch(a, i, min);
    }
}

bool Selection::less(Comparable * v, Comparable * w)
{
    return v->compareTo(w) < 0;
}

void Selection::exch(Comparable ** a, int i, int j)
{
    Comparable * t = a[i];
    a[i] = a[j];
    a[j] = t;
}

bool Selection::isSorted(Comparable ** a, int arrLength)
{
    for(int i = 1; i< arrLength; i++)
        if(less(a[i], a[i - 1])) return false;
    return true;
}
