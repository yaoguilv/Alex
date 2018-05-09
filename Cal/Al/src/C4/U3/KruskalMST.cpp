#include "C4/U3/KruskalMST.h"
#include "C2/U4/MinPQ.h"
#include "C1/Unit5_UnionFind/UF.h"

#include <vector>
#include <iterator>

KruskalMST::KruskalMST(EdgeWeightedGraph* G)
{
    weight = 0;
    vector<Edge*> myEdges;
    G->getEdges(myEdges);
    MinPQ* pq = new MinPQ(G->getE());
    for(vector<Edge*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
    {
        pq->insert(*it);
    }
    UF* uf = new UF(G->getV());

    while(!pq->isEmpty() && mst.size() < G->getV() - 1)
    {
        // Get min weight edge on pq and its vertices.
        Edge* e = dynamic_cast<Edge*>(pq->delMin());
        int v = e->either(), w = e->other(v);
        // Ignore ineligible edges.
        if(uf->connected(v, w))
            continue;
        // Merge components.
        uf->unionF(v, w);
        // Add edge to mst.
        mst.enqueue(e);
        weight += e->getWeight();
    }

}

void KruskalMST::getEdges(Queue<Edge*>& qEdges)
{
    while(!mst.isEmpty())
    {
        qEdges.enqueue(mst.dequeue());
    }
}

double KruskalMST::getWeight()
{
    return weight;
}
