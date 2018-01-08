#include "C2/U1/BubbleSort.h"
void BubbleSort::sort(Comparable ** a, int arrLen)
{
    for(int i = 0; i < arrLen - 1; i++)
    {
        for(int j = 0; j < arrLen - 1 - i; j++)
        {
            if(less(a[j + 1], a[j]))
                exch(a, j, j + 1);
        }
    }
}

bool BubbleSort::less(Comparable * v, Comparable * w)
{
    return v->compareTo(w) < 0;
}

void BubbleSort::exch(Comparable ** a, int i, int j)
{
    Comparable * t = a[i];
    a[i] = a[j];
    a[j] = t;
}

bool BubbleSort::isSorted(Comparable ** a, int arrLength)
{
    for(int i = 1; i< arrLength; i++)
        if(less(a[i], a[i - 1])) return false;
    return true;
}
