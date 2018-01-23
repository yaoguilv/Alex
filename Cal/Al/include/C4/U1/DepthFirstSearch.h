#ifndef DEPTHFIRSTSEARCH_H
#define DEPTHFIRSTSEARCH_H

#include "C4/U1/Graph.h"
#include "C1/Unit3_Stacks/Bag.h"

class DepthFirstSearch {
    private:
        bool * marked;
        int count;

        void dfs(Graph * G, int v)
        {
            marked[v] = true;
            count++;

            for(Bag<int>::Node * myIt = G->adj[v]->first; myIt != nullptr; myIt = myIt->next)
                if(!marked[myIt->item]) dfs(G, myIt->item);
        }
    public:
        DepthFirstSearch(Graph * G, int s)
        {
            marked = new bool[G->getV()];
            dfs(G, s);
        }

        bool getMarked(int w)
        {
            return marked[w];
        }

        int getCount()
        {
            return count;
        }
};
#endif
