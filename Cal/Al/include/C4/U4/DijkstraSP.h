#ifndef DIJKSTRASP_H
#define DIJKSTRASP_H

#include "C4/U4/DirectedEdge.h"
#include "C4/U4/EdgeWeightedDigraph.h"
#include "C2/U4/IndexMinPQ.h"
#include "util/CDouble.h"
#include "C1/Unit3_Stacks/Bag.h"
#include <stack>
#include <limits>
#include <vector>

using namespace std;

class DijkstraSP {
    private:
        DirectedEdge** edgeTo;
        vector<CDouble> distTo;
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
                if(distTo[w].getValue() > distTo[v].getValue() + e->getWeight())
                {
                    distTo[w] = distTo[v].getValue() + e->getWeight();
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
            distTo.reserve(G.getV());
            pq = new IndexMinPQ(G.getV());

            for(int v = 0; v < G.getV(); v++)
            {
                CDouble myPOS(std::numeric_limits<double>::max());
                distTo.push_back(myPOS);
                edgeTo[v] = nullptr;
            }
            distTo[s] = 0.0;

            CDouble* myd = new CDouble(0.0);
            pq->insert(s, myd);
            while(!pq->isEmpty())
                relax(G, pq->delMin());
        }

        double getDistTo(int v)
        {
            return distTo[v].getValue();
        }

        bool hasPathTo(int v)
        {
            return distTo[v].getValue() < std::numeric_limits<double>::max();
        }

        void getPathTo(int v, stack<DirectedEdge*>& path)
        {
            if(!hasPathTo(v))
                return;
            for(DirectedEdge* e = edgeTo[v]; e != nullptr; e = edgeTo[e->from()])
            {
                path.push(e);
            }
        }

};

#endif
