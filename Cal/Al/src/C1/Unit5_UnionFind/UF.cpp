#include <iostream>

#include "C1/Unit5_UnionFind/UF.h"

using namespace std;

UF::UF(int N)
{
    count = N;
    id = new int[N];
    initSize = N;
    for(int i = 0; i < N; i++)
    {
        id[i] = i;
    }
}

UF::~UF()
{
    delete[] id;
    id = NULL;
}

int UF::size()
{
    return count;
}

bool UF::connected(int p, int q)
{
    return find(p) == find(q);
}

int UF::find(int p)
{
    return id[p];
}

void UF::unionF(int p, int q)
{
    int pID = find(p);
    int qID = find(q);

    if(pID == qID) return;

    for(int i = 0; i < initSize; i++)
        if(id[i] == pID ) id[i] = qID;
    count--;
}
