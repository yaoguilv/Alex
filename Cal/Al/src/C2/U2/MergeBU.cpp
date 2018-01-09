#include <algorithm>
#include "C2/U2/MergeBU.h"

using namespace std;

Comparable ** MergeBU::aux;

void MergeBU::sort(Comparable ** a, int arrLen)
{
    // Do lg N passes of pairwise merges.
    aux = new Comparable*[arrLen];
    //sz: subarray
    for(int sz = 1; sz < arrLen; sz = sz + sz)
        // lo: subarray index
        for(int lo = 0; lo < arrLen - sz; lo += sz + sz)
            merge(a, lo, lo + sz - 1, min(lo + sz + sz -1, arrLen - 1));
}

void MergeBU::merge(Comparable ** a, int lo, int mid, int hi)
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

bool MergeBU::less(Comparable * v, Comparable * w)
{
    return v->compareTo(w) < 0;
}

void MergeBU::exch(Comparable ** a, int i, int j)
{
    Comparable * t = a[i];
    a[i] = a[j];
    a[j] = t;
}

bool MergeBU::isSorted(Comparable ** a, int arrLen)
{
    for(int i = 1; i< arrLen; i++)
        if(less(a[i], a[i - 1])) return false;
    return true;
}
