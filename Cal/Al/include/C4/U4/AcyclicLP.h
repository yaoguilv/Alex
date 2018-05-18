#ifndef ACYCLICLP_H
#define ACYCLICLP_H

#include "C4/U2/Topological.h"
#include "C4/U3/Edge.h"
#include "C4/U4/EdgeWeightedDigraph.h"
#include "C4/U4/DirectedEdge.h"
#include "util/CDouble.h"

#include <stack>

using namespace std;

class AcyclicLP {
private:
    vector<DirectedEdge*> edgeTo;
    vector<CDouble*> distTo;

    void relax(EdgeWeightedDigraph* G, int v);
public:
    AcyclicLP(EdgeWeightedDigraph* G, int s);
    double getDistTo(int v);
    bool hasPathTo(int v);
    void pathTo(int v, stack<DirectedEdge*>& path);
};
#endif
