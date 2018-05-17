#include "C4/U4/AcylicSP.h"
#include "C1/Unit3_Stacks/Stack.h"

#include <limits>

AcylicSP::AcylicSP(EdgeWeightedDigraph* G, int s)
{
    edgeTo.reserve(G->getV());
    distTo.reserve(G->getV());

    for(int v = 0; v < G->getV(); v++)
    {
        edgeTo.push_back(nullptr);
        distTo[v] = new CDouble(numeric_limits<double>::max());
    }
    distTo[s]->setValue(0.0);

    Topological* top = new Topological(G);

    Stack<int>* order = top->getOrder();
    while(!order->isEmpty())
    {
        int v = order->pop();
        relax(G, v);
    }
}

void AcylicSP::relax(EdgeWeightedDigraph* G, int v)
{
    Bag<DirectedEdge*> edgeBag;
    G->getAdj(v, edgeBag);
    Bag<DirectedEdge*>::Node* myB = edgeBag.first;
    while(nullptr != myB)
    {
        DirectedEdge* e = myB->item;

        int w = e->to();
        if(distTo[w]->getValue() > distTo[v]->getValue() + e->getWeight())
        {
            distTo[w]->setValue(distTo[v]->getValue() + e->getWeight());
            edgeTo[w] = e;
        }

        myB = myB->next;
    }
}

double AcylicSP::getDistTo(int v)
{
    return distTo[v]->getValue();
}

bool AcylicSP::hasPathTo(int v)
{
    return distTo[v]->getValue() < numeric_limits<double>::max();
}

void AcylicSP::pathTo(int v, stack<DirectedEdge*>& path)
{
    if(!hasPathTo(v))
        return;
    for(DirectedEdge* e = edgeTo[v]; e != nullptr; e = edgeTo[e->from()])
        path.push(e);
}
