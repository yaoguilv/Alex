#include <iostream>
#include <string>
#include <vector>
#include "util/CDouble.h"
#include "C2/U4/IndexMinPQ.h"
#include "C1/Unit3_Stacks/Queue.h"
#include "C4/U3/EdgeWeightedGraph.h"
#include "C4/U3/KruskalMST.h"

using namespace std;

int main(int argc, char ** argv)
{
    string fileName = "/usr/lib/.workspace/Alex/Cal/Al/data/tinyEWG.txt";
    EdgeWeightedGraph* G;
    G = new EdgeWeightedGraph(fileName);

    KruskalMST* mst = new KruskalMST(G);
    Queue<Edge*> edges;
    mst->getEdges(edges);
    cout << "outpu mst:" << endl;
    while(!edges.isEmpty())
    {
        Edge* e = edges.dequeue();
        cout << e->toString() << endl;
    }

    cout << mst->getWeight() << endl;
}
