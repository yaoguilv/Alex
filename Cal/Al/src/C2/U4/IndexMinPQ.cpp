#include "C2/U4/IndexMinPQ.h"

#include <iostream>

using namespace std;

IndexMinPQ::IndexMinPQ(int NMax)
{
    N = 0;
    keys.reserve(NMax + 1);
    pq.reserve(NMax + 1);
    qp.reserve(NMax + 1);
    for(int i = 0; i <= NMax; i++)
    {
        qp.push_back(-1);
        pq.push_back(-1);
        keys.push_back(nullptr);
    }
}

bool IndexMinPQ::isEmpty()
{
    return 0 == N;
}

bool IndexMinPQ::contains(int k)
{
    return qp[k] != -1;
}

int IndexMinPQ::size()
{
    return N;
}

void IndexMinPQ::insert(int k, Comparable* key)
{
    N++;
    qp[k] = N;
    pq[N] = k;
    keys[k] = key;
    swim(N);
    cout << "now min:" << endl;
    cout << min() << endl;
}

int IndexMinPQ::min()
{
    return pq[1];
}

Comparable* IndexMinPQ::minKey()
{
    return keys[pq[1]];
}

int IndexMinPQ::delMin()
{
    int min = pq[1];
    exch(1, N--);
    sink(1);
    qp[min] = -1;
    keys[pq[N + 1]] = nullptr;
    pq[N + 1] = -1;
    return min;
}

void IndexMinPQ::change(int k, Comparable* key)
{
    keys[k] = key;
    swim(qp[k]);
    sink(qp[k]);
}

void IndexMinPQ::decrease(int k, Comparable* key)
{
    keys[k] = key;
    swim(qp[k]);
}

void IndexMinPQ::increase(int k, Comparable* key)
{
    keys[k] = key;
    sink(qp[k]);
}

bool IndexMinPQ::greater(int i, int j)
{
    return keys[pq[i]]->compareTo(keys[pq[j]]) > 0;
}

void IndexMinPQ::exch(int i, int j)
{
    int swap = pq[i];
    pq[i] = pq[j];
    pq[j] = swap;

    qp[pq[i]] = i;
    qp[pq[j]] = j;
}

void IndexMinPQ::swim(int k)
{
    while(k > 1 && greater(k/2, k))
    {
        exch(k, k/2);
        k = k/2;
    }
}

void IndexMinPQ::sink(int k)
{
    while(2 * k <= N)
    {
        int j = 2 * k;
        if(j < N && greater(j, j + 1)) j++;
        if(!greater(k, j)) break;
        exch(k, j);
        k = j;
    }
}


