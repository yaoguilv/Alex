#ifndef PRIMMST_H
#define PRIMMST_H

#include <vector>
#include <iterator>

#include "C4/U3/Edge.h"
#include "C2/U4/IndexMinPQ.h"
#include "C1/Unit3_Stacks/Queue.h"
#include "C4/U3/EdgeWeightedGraph.h"

class PrimMST {
private:
    // shortest edge from tree vertex
    vector<Edge*> edgeTo;
    // distTo[w] = edgeTo[w].weight()
    vector<double> distTo;
    // true if v on tree
    vector<bool> marked;
    // eligible crossing edges
    IndexMinPQ* pq;

    Queue<Edge*> mst;

    double weight;

public:
    PrimMST(EdgeWeightedGraph* G);

    void visit(EdgeWeightedGraph* G, int v);

    void getEdges(Queue<Edge*>& qEdges);

    double getWeight();
};
#endif
