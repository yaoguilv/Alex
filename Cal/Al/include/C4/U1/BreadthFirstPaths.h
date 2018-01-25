#ifndef BREADTHFIRSTPAHTS_H
#define BREADTHFIRSTPAHTS_H

#include <queue>
#include "C1/Unit3_Stacks/Bag.h"
#include "C4/U1/Graph.h"
#include "C1/Unit3_Stacks/Stack.h"

class BreadthFirstPaths {
private:
    // Is a shortest path to this vertex known?
    bool * marked;
    // last vertexx on known path to this vertex
    int * edgeTo;
    // source
    int s;

    void bfs(Graph * G, int s)
    {
        queue<int> * myQ = new queue<int>();
        // Mark the source
        marked[s] = true;
        // and put it on the queue.
        myQ->push(s);
        while(0 != myQ->size())
        {
            // Remove next vertex from queue.
            int v = myQ->front();
            myQ->pop();
            for(Bag<int>::Node * myIt = G->adj[v]->first; myIt != nullptr; myIt = myIt->next)
                // for every unmarked adjacent vertex.
                if(!marked[myIt->item])
                {
                    // save last edge on a shortest path.
                    edgeTo[myIt->item] = v;
                    // mark it because path is known.
                    marked[myIt->item] = true;
                    // and add it to the queue.
                    myQ->push(myIt->item);
                }
        }
    }

public:
    BreadthFirstPaths(Graph * G, int s)
    {
        marked = new bool[G->getV()];
        edgeTo = new int[G->getV()];
        this->s = s;
        bfs(G, s);
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
