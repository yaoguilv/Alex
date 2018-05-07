#include "C2/U4/MinPQ.h"
#include "C4/U3/Edge.h"

using namespace std;

Comparable ** pqmin;

MinPQ::MinPQ(int minN)
{
    pqmin = new Comparable*[minN + 1];
    N = 0;
}

bool MinPQ::isEmpty()
{
    return 0 == N;
}

int MinPQ::size()
{
    return N;
}

void MinPQ::insert(Comparable* v)
{
    pqmin[++N] = v;
    swim(N);
    Edge* myE1 = dynamic_cast<Edge*>(v);
}

Comparable* MinPQ::delMin()
{
    exch(1, N);
    Comparable* min = pqmin[N--];
    sink(1);
    pqmin[N + 1] = nullptr;
    return min;
}

bool MinPQ::greater(int i, int j)
{
    return pqmin[i]->compareTo(pqmin[j]) > 0;
}

void MinPQ::exch(int i, int j)
{
    Comparable* t = pqmin[i];
    pqmin[i] = pqmin[j];
    pqmin[j] = t;
}

void MinPQ::swim(int k)
{
    while(k > 1 && greater(k/2, k))
    {
        exch(k/2, k);
        k = k/2;
    }
}

void MinPQ::sink(int k)
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
