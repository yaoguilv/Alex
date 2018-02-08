#ifndef TWOCOLOR_H
#define TWOCOLOR_H

#include "C4/U1/Graph.h"
#include "C1/Unit3_Stacks/Bag.h"

class TwoColor {
private:
    bool * marked = nullptr;
    bool * color = nullptr;
    bool isTwoColorable = true;

    void dfs(Graph * G, int v)
    {
        marked[v] = true;
        for(Bag<int>::Node * myIt = G->adj[v]->first; myIt != nullptr; myIt = myIt->next)
            if(!marked[myIt->item])
            {
                color[myIt->item] = !color[v];
                dfs(G, myIt->item);
            }
            else if(color[myIt->item] == color[v]) isTwoColorable = false;
    }
public:
    TwoColor(Graph * G)
    {
        marked = new bool[G->getV()];
        color = new bool[G->getV()];
        for(int s = 0; s < G->getV(); s++)
            if(!marked[s])
                dfs(G, s);
    }

    bool isBipartite()
    {
        return isTwoColorable;
    }
};
#endif
