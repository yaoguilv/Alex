#ifndef TOPOLOGICAL_H
#define TOPOLOGICAL_H

#include "C4/U2/Digraph.h"
#include "C4/U2/DirectedCycle.h"
#include "C4/U2/DepthFirstOrder.h"
#include "C1/Unit3_Stacks/Stack.h"

class Topological {
private:
    // topological order
    Stack<int>* order = NULL;

public:
    Topological(Digraph * G)
    {
        DirectedCycle * cyclefinder = new DirectedCycle(G);
        if(!cyclefinder->hasCycle())
        {
            DepthFirstOrder * dfs = new DepthFirstOrder(G);
            order = dfs->getReversePost();
        }
    }

    Stack<int> * getOrder()
    {
        return order;
    }

    bool isDAG()
    {
        return NULL == order;
    }
};

#endif
