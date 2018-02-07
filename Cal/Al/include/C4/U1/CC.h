#ifndef CC_H
#define CC_H

#include "C4/U1/Graph.h"
#include "C1/Unit3_Stacks/Bag.h"

class CC {
    private:
        bool * marked;
        int * id;
        int count = 0;

        void dfs(Graph * G, int v)
        {
            marked[v] = true;
            id[v] = count;
            for(Bag<int>::Node * myIt = G->adj[v]->first; myIt != nullptr; myIt = myIt->next)
                if(!marked[myIt->item])
                    dfs(G, myIt->item);
        }

    public:
        CC(Graph * G)
        {
            marked = new bool[G->getV()];
            id = new int[G->getV()];
            for(int s = 0; s < G->getV(); s++)
                if(!marked[s])
                {
                    dfs(G, s);
                    count++;
                }

        }

        bool connected(int v, int w)
        {
            return id[v] == id[w];
        }

        int getId(int v)
        {
            return id[v];
        }

        int getCount()
        {
            return count;
        }
};
#endif
