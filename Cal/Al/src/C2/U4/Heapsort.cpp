#include "C2/U4/Heapsort.h"

// just can sort the [1..N] numbers, no 0 number
void Heapsort::sort(Comparable ** a, int arrLen)
{
    // sink method only operate the [1..N] elements
    // because 1*2 = 2,2*2=4... (it is binary tree) ,while 0*2 = 0
    int N = arrLen - 1;
    for(int k = N/2; k >= 1; k--)
        sink(a, k, N);
    while(N > 1)
    {
        exch(a, 1, N--);
        sink(a, 1, N);
    }
}

void Heapsort::sink(Comparable ** a, int k, int N)
{
    while(2 * k <= N)
    {
        int j = 2 * k;
        if(j < N && less(a, j, j + 1)) j++;
        if(!less(a, k, j));
        k = j;
    }
}

bool Heapsort::less(Comparable ** a, int i, int j)
{
    return 0 > a[i]->compareTo(a[j]);
}

void Heapsort::exch(Comparable ** a, int i, int j)
{
    Comparable * t = a[i];
    a[i] = a[j];
    a[j] = t;
}
