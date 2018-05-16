#ifndef DIJKSTRASP_H
#define DIJKSTRASP_H

#include "C4/U4/DirectedEdge.h"
#include "C4/U4/EdgeWeightedDigraph.h"
#include "C2/U4/IndexMinPQ.h"
#include "util/CDouble.h"
#include "C1/Unit3_Stacks/Bag.h"
#include "C1/Unit3_Stacks/Stack.h"
#include <limits>


class DijkstraSP {
    private:
        DirectedEdge** edgeTo;
        CDouble* distTo;
        IndexMinPQ* pq;

        void relax(EdgeWeightedDigraph G, int v)
        {
            Bag<DirectedEdge*> edgeBag;
            G.getAdj(v, edgeBag);
            Bag<DirectedEdge*>::Node* myB = edgeBag.first;
            while(nullptr != myB)
            {
                DirectedEdge* e = myB->item;
                int w = e->to();
                if(distTo[w] > distTo[v].getValue() + e->getWeight())
                {
                    distTo[w] = distTo[v] + e->getWeight();
                    edgeTo[w] = e;
                    if(pq->contains(w))
                        pq->change(w, new CDouble(distTo[w]));
                    else
                        pq->insert(w, new CDouble(distTo[w]));
                }
                myB = myB->next;
            }
        }

    public:
        DijkstraSP(EdgeWeightedDigraph G, int s)
        {
            edgeTo = new DirectedEdge*[G.getV()];
            distTo = new CDouble[G.getV()];
            pq = new IndexMinPQ<CDoule>(G.getV());

            for(int v = 0; v < G.getV(); v++)
            {
                CDouble myPOS(std::numeric_limits<double>::max());
                distTo[v] = myPOS;
                edgeTo[v] = nullptr;
            }
            distTo[s] = 0.0;

            CDouble myd(0.0);
            pq->insert(s, myd);
            while(!pq->isEmpty())
                relax(G, pq->delMin());
        }

        double getDistTo(int v)
        {
            return distTo[v];
        }

        bool hasPathTo(int v)
        {
            return distTo[v] < std::numeric_limits<double>::max();
        }

        void getPathTo(int v, Stack<DirectedEdge*>& path)
        {
            if(!hasPathTo(v))
                path = nullptr;
            path = new Stack<DirectedEdge*>();
            for(DirectedEdge* e = edgeTo[v]; e != nullptr; e = edgeTo[e->from()])
            {
                path.push(e);
            }
        }

};

#endif
