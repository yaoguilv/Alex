#include "C2/U2/Merge.h"

// static member variable must be defined;
// in .h file , they are only been declared, not been defined
// or there will be error: undefined reference to Merge::aux
// can only been written in .cpp file, or tester.o linking will error: multi-definition
Comparable ** Merge::aux;

void Merge::sort(Comparable ** a, int arrLen)
{
    Merge::aux = new Comparable*[arrLen];
    sort(a, 0, arrLen-1);
}

void Merge::sort(Comparable ** a, int lo, int hi)
{

    // Sort a[lo..hi].
    if(hi <= lo) return;
    int mid = lo + (hi - lo)/2;

    // Sort left half.
    sort(a, lo, mid);
    // Sort right half.
    sort(a, mid + 1, hi);
    // Merge results
    merge(a, lo, mid, hi);
}

void Merge::merge(Comparable ** a, int lo, int mid, int hi)
{
    // Merge a[lo..mid] with a[mid+1..hi].
    int i = lo, j = mid + 1;

    for(int k = lo; k <= hi; k++)
        aux[k] = a[k];

    for(int k = lo; k <= hi; k++)
    {
        if(i > mid)
            a[k] = aux[j++];
        else if(j > hi)
            a[k] = aux[i++];
        else if(less(aux[j], aux[i]))
            a[k] = aux[j++];
        else
            a[k] = aux[i++];
    }
}

bool Merge::less(Comparable * v, Comparable * w)
{
    return v->compareTo(w) < 0;
}

void Merge::exch(Comparable ** a, int i, int j)
{
    Comparable * t = a[i];
    a[i] = a[j];
    a[j] = t;
}

bool Merge::isSorted(Comparable ** a, int arrLength)
{
    for(int i = 1; i< arrLength; i++)
        if(less(a[i], a[i - 1])) return false;
    return true;
}
