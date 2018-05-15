#ifndef DIJKSTRASP_H
#define DIJKSTRASP_H

#include "C4/U4/DirectedEdge.h"
#include "C4/U4/EdgeWeightedDigraph.h"
#include "C2/U4/IndexMinPQ.h"
#include "util/CDouble.h"
#include <limits>

class DijkstraSP {
    private:
        DirectedEdge* edgeTo;
        double* distTo;
        IndexMinPQ<CDouble>* pq;

    public:
        DijkstraSP(EdgeWeightedDigraph G, int s)
        {
            edgeTo = new DirectedEdge[G.getV()];
            distTo = new CDouble[G.getV()];
            pq = new IndexMinPQ<CDoule>(G.getV());

            for(int v = 0; v < G.getV(); v++)
            {
                CDouble myPOS(std::numeric_limits<double>::max());
                distTo[v] = myPOS;
            }
            distTo[s] = 0.0;

            CDouble myd(0.0);
            pq->insert(s, myd);
            while(!pq->isEmpty())
                relax(G, pq->delMin());
        }

        void relax(EdgeWeightedDigraph G, int v)
        {
            for()
        }

};

#endif
