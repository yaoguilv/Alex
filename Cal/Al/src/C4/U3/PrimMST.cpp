#include "C4/U3/PrimMST.h"
#include "util/CDouble.h"

#include <cmath>

using namespace std;

PrimMST::PrimMST(EdgeWeightedGraph* G)
{
    edgeTo.reserve(G->getV());
    distTo.reserve(G->getV());
    marked.reserve(G->getV());
    for(int v = 0; v < G->getV(); v++)
    {
        edgeTo.push_back(nullptr);
        /* distTo.push_back(std::numeric_limits<double>::infinity()); */

        distTo.push_back(HUGE_VAL);
        marked.push_back(false);
    }
    pq = new IndexMinPQ(G->getV());

    distTo[0] = 0.0;
    // Initial pq with 0, weight 0.
    pq->insert(0, new CDouble(0.0));
    visit(G, pq->delMin());
    while(!pq->isEmpty())
    {
        int VertexMin = pq->min();
        mst.enqueue(edgeTo[VertexMin]);
        weight += edgeTo[VertexMin]->getWeight();
        // Add closed vertex to tree.
        visit(G, pq->delMin());
    }
}

void PrimMST::visit(EdgeWeightedGraph* G, int v)
{
    // Add v to tree; update data structures.
    marked[v] = true;
    vector<Edge*> myEdges;
    G->getAdj(v, myEdges);
    for(vector<Edge*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
    {
        int w = (*it)->other(v);
        // v-w is ineligible.
        if(marked[w])
            continue;
        if((*it)->getWeight() < distTo[w])
        {
            // Edge e is new best connection form tree to w.
            edgeTo[w] = *it;
            distTo[w] = (*it)->getWeight();
            if(pq->contains(w))
                pq->change(w, new CDouble(distTo[w]));
            else
                pq->insert(w, new CDouble(distTo[w]));
        }
    }
}

void PrimMST::getEdges(Queue<Edge*>& qEdges)
{
    while(!mst.isEmpty())
    {
        qEdges.enqueue(mst.dequeue());
    }
}

double PrimMST::getWeight()
{
    return weight;
}
