#ifndef PRIMMST_H
#define PRIMMST_H

#include <vector>
#include <iterator>

#include "C4/U3/Edge.h"

class PrimMST {
    private:
        // shortest edge from tree vertex
        vector<Edge*> edgeTo;
        // distTo[w] = edgeTo[w].weight()
        vector<double> distTo;
        // true if v on tree
        vector<bool> marked;
        // eligible crossing edges
        // IndexMinPQ<double> pq;
};
#endif
