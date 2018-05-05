#ifndef LAZYPRIMMST_H
#define LAZYPRIMMST_H

#include "C4/U3/EdgeWeightedGraph.h"
#include "C4/U3/Edge.h"
#include "C1/Unit3_Stacks/Queue.h"
#include "C2/U4/MinPQ.h"
#include <vector>
#include <iterator>

using namespace std;

class LazyPrimMST {
private:
    double weight = 0.0;
    // MST vertices
    vector<bool> marked;
    // MST edges
    Queue<Edge*>* mst;
    // crossing (and ineligible) edges
    MinPQ* pq;

    void visit(EdgeWeightedGraph * G, int v)
    {
        // Mark v and add to pq all edges from v to unmarked vertices.
        marked[v] = true;
        vector<Edge*> arrVEdges;
        G->getAdj(v, arrVEdges);
        for(vector<Edge*>::iterator it = arrVEdges.begin(); it != arrVEdges.end(); it++)
        {
            if(!marked[(*it)->other(v)])
                pq->insert(*it);
        }
    }

public:
    LazyPrimMST(EdgeWeightedGraph* G)
    {
        pq = new MinPQ();
        marked.reserve(G->getV());
        for(int i = 0; i < G->getV(); i++)
        {
            marked.push_back(false);
        }
        mst = new Queue<Edge*>();

        // assumes G is connected
        visit(G, 0);
        while(!pq->isEmpty())
        {
            // Get lowest-weight edge from pq.
            Edge* e = pq->delMin();
            int v = e->either(), w = e->other(v);
            // Skip if ineligible.
            if(marked[v] && marked[w]) continue;
            // Add edge to tree.
            mst->enqueue(e);
            weight += e->getWeight();
            // Add vertex to tree(eighter v or w).
            if(!marked[v])
                visit(G, v);
            if(!marked[w])
                visit(G, w);
        }
    }

    void getEdges(Queue<Edge*>& edges)
    {
        while(!mst->isEmpty())
        {
            edges.enqueue(mst->dequeue());
        }
    }

    double getWeight()
    {
        return weight;
    }
};

#endif
