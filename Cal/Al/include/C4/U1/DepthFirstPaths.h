#ifndef DEPTHFIRSTPATHS_H
#define DEPTHFIRSTPATHS_H

#include "C1/Unit3_Stacks/Bag.h"
#include "C4/U1/Graph.h"
#include "C1/Unit3_Stacks/Stack.h"

class DepthFirstPaths {
private:
    // Has dfs() been called for this vertex?
    bool * marked;
    // last vertex on known path to this vertex
    int * edgeTo;
    // source
    int s;

    void dfs(Graph * G, int v)
    {
        marked[v] = true;
        for(Bag<int>::Node * myIt = G->adj[v]->first; myIt != nullptr; myIt = myIt->next)
            if(!marked[myIt->item])
            {
                edgeTo[myIt->item] = v;
                dfs(G, myIt->item);
            }
    }
public:
    DepthFirstPaths(Graph * G, int s)
    {
        marked = new bool[G->getV()];
        edgeTo = new int[G->getV()];
        this->s = s;
        dfs(G, s);
    }

    bool hasPathTo(int v)
    {
        return marked[v];
    }

    Stack<int> * pathTo(int v)
    {
        if(!hasPathTo(v)) return nullptr;
        Stack<int> * path = new Stack<int>();
        for(int x = v; x != s; x = edgeTo[x])
            path->push(x);
        path->push(s);
        return path;
    }
};
#endif
