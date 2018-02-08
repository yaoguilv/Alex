#ifndef CYCLE_H
#define CYCLE_H

#include "C4/U1/Graph.h"
#include "C1/Unit3_Stacks/Bag.h"

class Cycle {
    private:
        bool * marked;
        bool bHasCycle;

        void dfs(Graph * G, int v, int u)
        {
            marked[v] = true;
            for(Bag<int>::Node * myIt = G->adj[v]->first; myIt != nullptr; myIt = myIt->next)
            {
                if(!marked[myIt->item])
                    dfs(G, myIt->item, v);
                else
                    if(myIt->item != u) bHasCycle = true;
            }
        }
    public:
        Cycle(Graph * G)
        {
            marked = new bool[G->getV()];
            for(int s = 0; s < G->getV(); s++)
                if(!marked[s])
                    dfs(G, s, s);
        }

        bool hasCycle()
        {
            return bHasCycle;
        }
};
#endif
