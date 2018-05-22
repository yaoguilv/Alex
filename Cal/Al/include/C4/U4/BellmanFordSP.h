#ifndef BELLMANFORDSP_H
#define BELLMANFORDSP_H

#include <vector>
#include <iterator>
#include <limits>

#include "C4/U4/DirectedEdge.h"
#include "C1/Unit3_Stacks/Queue.h"
#include "util/CInt.h"

using namespace std;

class BellmanFordSP {
privtae:
    // length of path to v
    vector<bool> distTo;
    // last edge on path to v
    vector<DirectedEdge> edgeTo;
    // Is this vertex on the queue?
    vector<bool> onQ;
    // vertices being relaxed
    Queue<int>* bellQueue;
    // number of calls to relax()
    int cost;
    // negative cycle in edgeTo[]?
    Iterable<DirectedEdge> cycle;

    public:
    BellmanFordSP(EdgeWeightedDigraph* G, int s)
    {
        distTo.reserve(G->getV());
        edgeTo.reserve(G->getV());
        onQ.reserve(G->getV());
        bellQueue = new Queue<CInt*>();
        for(int v = 0; v < G->getV(); v++)
        {
            distTo.push_back(new CInt(numeric_limits<int>::max()));
            edgeTo.push_back(nullptr);
            onQ.push_back(false);
        }
        distTo[s] = 0.0;
        bellQueue.enqueue(new CInt(s));
        onQ[s] = true;
        while(!bellQueue.isEmpty() && !this->hasNegativeCycle())
        {
            int v = bellQueue.dequeue();
        }
    }
};

#endif
