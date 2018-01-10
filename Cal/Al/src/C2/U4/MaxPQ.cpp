#include "C2/U4/MaxPQ.h"
Comparable ** pq;

MaxPQ::MaxPQ(int maxN)
{
    pq = new Comparable*[maxN + 1];
}

bool MaxPQ::isEmpty()
{
    return 0 == N;
}

int MaxPQ::size()
{
    return N;
}

void MaxPQ::insert(Comparable *v)
{
    pq[++N] = v;
    swim(N);
}

Comparable * MaxPQ::delMax()
{
    // Retrieve max key from top.
    Comparable * max = pq[1];
    // Exchange with last item.
    exch(1, N--);
    // Avoid loitering.
    pq[N + 1] = nullptr;
    // Restore heap property.
    sink(1);
    return max;
}

bool MaxPQ::less(int i, int j)
{
    return pq[i]->compareTo(pq[j]) < 0;
}

void MaxPQ::exch(int i, int j)
{
    Comparable * t = pq[i];
    pq[i] = pq[j];
    pq[j] = t;
}

void MaxPQ::swim(int k)
{
    while(k > 1 && less(k/2, k))
    {
        exch(k/2, k);
        k = k/2;
    }
}

void MaxPQ::sink(int k)
{
    while(2 * k <= N)
    {
        int j = 2 * k;
        if(j < N && less(j, j + 1)) j++;
        if(!less(k, j)) break;
        k = j;
    }
}
