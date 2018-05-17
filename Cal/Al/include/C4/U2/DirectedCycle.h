#ifndef DIRECTEDCYCLE_H
#define DIRECTEDCYCLE_H

#include "C1/Unit3_Stacks/Stack.h"
#include "C4/U2/Digraph.h"
#include "C4/U4/EdgeWeightedDigraph.h"
#include "C4/U4/DirectedEdge.h"

class DirectedCycle {
    private:
        vector<bool> marked;
        vector<int> edgeTo;
        // vertices on a cycle (if one exits)
        Stack<int> * cycle;
        // vertices on recursive call stack
        vector<bool> onStack;

        void dfs(Digraph * G, int v)
        {
            onStack[v] = true;
            marked[v] = true;
            Bag<int>::Node * p = G->adj[v]->first;
            while(nullptr != p)
            {
                int w = p->item;
                if(this->hasCycle())
                    return;
                else if(!marked[w])
                {
                    edgeTo[w] = v;
                    dfs(G, w);
                }
                else if(onStack[w])
                {
                    cycle = new Stack<int>();
                    for(int x = v; x != w; x = edgeTo[x])
                        cycle->push(x);
                    cycle->push(w);
                    cycle->push(v);
                }
                p = p->next;
            }
            onStack[v] = false;
        }

        void dfs(EdgeWeightedDigraph* G, int v)
        {
            onStack[v] = true;
            marked[v] = true;
            Bag<DirectedEdge*> edgeBag;
            G->getAdj(v, edgeBag);
            Bag<DirectedEdge*>::Node* p = edgeBag.first;
            while(nullptr != p)
            {
                DirectedEdge* e = p->item;
                int w = e->to();
                if(this->hasCycle())
                    return;
                else if(!marked[w])
                {
                    edgeTo[w] = v;
                    dfs(G, w);
                }
                else if(onStack[w])
                {
                    cycle = new Stack<int>();
                    for(int x = v; x != w; x = edgeTo[x])
                        cycle->push(x);
                    cycle->push(w);
                    cycle->push(v);
                }
                p = p->next;
            }
            onStack[v] = false;
        }

    public:
        DirectedCycle(Digraph * G)
        {
            cycle = NULL;
            int size = G->getV();
            marked.reserve(size);
            onStack.reserve(size);
            for(int i = 0; i < size; i++)
            {
                marked[i] = false;
                onStack[i] = false;
            }

            edgeTo.reserve(size);
            for(int i = 0; i < size; i++)
            {
                edgeTo[i] = 0;
            }

            for(int i = 0; i < size; i++)
                if(!marked[i])
                    dfs(G, i);
        }

        DirectedCycle(EdgeWeightedDigraph* G)
        {
            cycle = NULL;
            int size = G->getV();
            marked.reserve(size);
            onStack.reserve(size);
            for(int i = 0; i < size; i++)
            {
                marked[i] = false;
                onStack[i] = false;
            }

            edgeTo.reserve(size);
            for(int i = 0; i < size; i++)
            {
                edgeTo[i] = 0;
            }

            for(int i = 0; i < size; i++)
                if(!marked[i])
                    dfs(G, i);
        }


        bool hasCycle()
        {
            return NULL != cycle;
        }

        Stack<int> * getCycle()
        {
            return cycle;
        }

};
#endif
