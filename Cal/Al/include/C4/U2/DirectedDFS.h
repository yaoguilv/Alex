#ifndef DIRECTEDDFS_H
#define DIRECTEDDFS_H

#include "C1/Unit3_Stacks/Bag.h"
#include "C4/U2/Digraph.h"
#include <vector>
#include <iterator>

class DirectedDFS {
private:
    vector<bool> * marked;

    void dfs(Digraph * G, int v)
    {
        marked->at(v) = true;
        Bag<int>::Node * p = G->adj[v]->first;
        while(nullptr != p)
        {
            if(!marked->at(p->item))
                dfs(G, p->item);
            p = p->next;
        }

    }
public:
    DirectedDFS(Digraph * G, int s)
    {
        marked = new vector<bool>();
        marked->reserve(G->getV());
        for(int i = 0; i < G->getV(); i++)
            marked->push_back(0);
        dfs(G, s);
    }

    DirectedDFS(Digraph * G, vector<int>& sources)
    {
        marked = new vector<bool>();
        marked->reserve(G->getV());
        for(int i = 0; i < G->getV(); i++)
            marked->push_back(0);
        for(vector<int>::iterator it = sources.begin(); it != sources.end(); it++)
        {
            if(!marked->at(*it))
                dfs(G, *it);
        }
    }

    bool getMarked(int v)
    {
        return marked->at(v);
    }
};
#endif
