#ifndef KOSARAJUSCC_H
#define KOSARAJUSCC_H

#include "C4/U2/Digraph.h"
#include "C4/U2/DepthFirstOrder.h"
#include "C1/Unit3_Stacks/Stack.h"
#include "C1/Unit3_Stacks/Bag.h"

class KosarajuSCC {
private:
    // reached vertices
    vector<bool> marked;
    // component identifiers
    vector<int> id;
    // number of strong component
    int count;

    void dfs(Digraph* G, int v)
    {
        marked[v] = true;
        id[v] = count;
        Bag<int>::Node* p = G->adj[v]->first;
        while(nullptr != p)
        {
            if(!marked[p->item])
                dfs(G, p->item);
            p = p->next;
        }
    }

public:
    KosarajuSCC(Digraph* G)
    {
        marked.reserve(G->getV());
        id.reserve(G->getV());
        for(int i = 0; i < G->getV(); i++)
        {
            id.push_back(0);
            marked.push_back(false);
        }
        DepthFirstOrder* order = new DepthFirstOrder(G->reverse());
        Stack<int> reversePost = order->getReversePost();
        while(!reversePost.isEmpty())
        {
            int s = reversePost.pop();
            if(!marked[s])
            {
                dfs(G, s);
                count++;
            }
        }
    }

    bool stronglyConnected(int v, int w)
    {
        return id[v] == id[w];
    }

    int id(int v)
    {
        return id[v];
    }

    int count()
    {
        return count;
    }
};

#endif
