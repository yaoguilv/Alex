#ifndef KRUSKALMST_H
#define KRUSKALMST_H

#include "C1/Unit3_Stacks/Queue.h"
#include "C4/U3/Edge.h"
#include "C4/U3/EdgeWeightedGraph.h"

class KruskalMST {
private:
    Queue<Edge*> mst;
    double weight;
public:
    KruskalMST(EdgeWeightedGraph* G);
    void getEdges(Queue<Edge*>& qEdges);
    double getWeight();
};

#endif
