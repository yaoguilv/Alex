#ifndef EDGEWEIGHTEDDIRECTEDCYCLE_H
#define EDGEWEIGHTEDDIRECTEDCYCLE_H

#include <vector>
#include <iterator>

#include "C1/Unit3_Stacks/Stack.h"
#include "C4/U4/DirectedEdge.h"
#include "C4/U4/EdgeWeightedDigraph.h"

using namespace std;

class EdgeWeightedDirectedCycle {
private:
    // marked[v] = has vertex v been marked?
    vector<bool> marked;
    // edgeTo[v] = previous edge on path to v
    vector<DirectedEdge*> edgeTo;
    // = is vertex on stack?
    vector<bool> onStack;
    // directed cycle (or null if no such cycle)
    Stack<DirectedEdge*>* cycle = nullptr;

    void dfs(EdgeWeightedDigraph* G, int v)
    {
        onStack[v] = true;
        marked[v] = true;

        Bag<DirectedEdge*> edgeBag;
        G->getAdj(v, edgeBag);
        Bag<DirectedEdge*>::Node* myB = edgeBag.first;
        while(nullptr != myB)
        {
            DirectedEdge* e = myB->item;
            int w = e->to();
            // short circuit if directed cycle found
            if(nullptr != cycle) return;

            // found new vertex, so recur
            else if(!marked[w])
            {
                edgeTo[w] = e;
                dfs(G, w);
            }

            // trace back directed cycle
            else if(onStack[w])
            {
                cycle = new Stack<DirectedEdge*>();
                while(e->from() != w)
                {
                    cycle->push(e);
                    e = edgeTo[e->from()];
                }
                cycle->push(e);
            }
            myB = myB->next;
        }
        onStack[v] = false;
    }

public:
    EdgeWeightedDirectedCycle(EdgeWeightedDigraph* G)
    {
        marked.reserve(G->getV());
        onStack.reserve(G->getV());
        edgeTo.reserve(G->getV());
        for(int v = 0; v < G->getV(); v++)
        {
            marked.push_back(false);
            edgeTo.push_back(nullptr);
            onStack.push_back(false);
        }

        for(int v = 0; v < G->getV(); v++)
        {
            if(!marked[v])
                dfs(G, v);
        }
    }

    bool hasCycle()
    {
        if(nullptr != cycle)
            return !cycle->isEmpty();
        else
            return false;
    }

    void getCycle(vector<DirectedEdge*>& edges)
    {
        if(nullptr == cycle)
            return;
        while(!cycle->isEmpty())
        {
            edges.push_back(cycle->pop());
        }
    }
};

#endif
