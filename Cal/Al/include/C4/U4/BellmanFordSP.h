#ifndef BELLMANFORDSP_H
#define BELLMANFORDSP_H

#include <vector>
#include <iterator>
#include <limits>

#include "C4/U4/DirectedEdge.h"
#include "C1/Unit3_Stacks/Queue.h"
#include "util/CInt.h"
#include "C1/Unit3_Stacks/Bag.h"
#include "C4/U4/EdgeWeightedDigraph.h"
#include "C4/U4/EdgeWeightedDirectedCycle.h"

using namespace std;

class BellmanFordSP {
private:
    // length of path to v
    vector<double> distTo;
    // last edge on path to v
    vector<DirectedEdge*> edgeTo;
    // Is this vertex on the queue?
    vector<bool> onQ;
    // vertices being relaxed
    Queue<int>* bellQueue;
    // number of calls to relax()
    int cost;
    // negative cycle in edgeTo[]?
    vector<DirectedEdge*> cycle;

    void relax(EdgeWeightedDigraph* G, int v)
    {
        Bag<DirectedEdge*> edgeBag;
        G->getAdj(v, edgeBag);
        Bag<DirectedEdge*>::Node* myB = edgeBag.first;
        while(nullptr != myB)
        {
            DirectedEdge* e = myB->item;
            int w = e->to();
            if(distTo[w] > distTo[v] + e->getWeight())
            {
                distTo[w] = distTo[v] + e->getWeight();
                edgeTo[w] = e;
                if(!onQ[w])
                {
                    bellQueue->enqueue(w);
                    onQ[w] = true;
                }
            }
            if(cost++ % G->getV() == 0)
                findNegativeCycle();
            myB = myB->next;
        }
    }

    void findNegativeCycle()
    {
        int V = edgeTo.size();
        EdgeWeightedDigraph* spt = new EdgeWeightedDigraph(V);
        for(int v = 0; v < V; v++)
            if(edgeTo[v] != nullptr)
                spt->addEdge(edgeTo[v]);
        EdgeWeightedDirectedCycle* cf = new EdgeWeightedDirectedCycle(spt);

        cf->getCycle(cycle);
    }

public:
    BellmanFordSP(EdgeWeightedDigraph* G, int s)
    {
        distTo.reserve(G->getV());
        edgeTo.reserve(G->getV());
        onQ.reserve(G->getV());
        bellQueue = new Queue<int>();
        for(int v = 0; v < G->getV(); v++)
        {
            distTo.push_back(numeric_limits<int>::max());
            edgeTo.push_back(nullptr);
            onQ.push_back(false);
        }
        distTo[s] = 0.0;
        bellQueue->enqueue(s);
        onQ[s] = true;
        while(!bellQueue->isEmpty() && !this->hasNegativeCycle())
        {
            int v = bellQueue->dequeue();
            onQ[v] = false;
            relax(G, v);
        }
    }

    bool hasNegativeCycle()
    {
        return !cycle.empty();
    }

    void negativeCycle(vector<DirectedEdge*>& cycleEdges)
    {
        for(vector<DirectedEdge*>::iterator it = cycle.begin(); it != cycle.end(); it++)
        {
            cycleEdges.push_back(*it);
        }
    }

    double getDistTo(int v)
    {
        return distTo[v];
    }

    bool hasPathTo(int v)
    {
        return distTo[v] < numeric_limits<double>::max();
    }

    void getPathTo(int v, vector<DirectedEdge*>& edges)
    {
        if(!hasPathTo(v))
            return;
        for(DirectedEdge* e = edgeTo[v]; e != nullptr; e = edgeTo[e->from()])
            edges.push_back(e);
    }
};

#endif
