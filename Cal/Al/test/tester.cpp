#include <iostream>
#include <string>
#include <vector>
#include "C2/U1/MyDate.h"
#include "C2/U4/MinPQ.h"
#include "C1/Unit3_Stacks/Queue.h"
#include "C4/U3/EdgeWeightedGraph.h"
#include "C4/U3/LazyPrimMST.h"

using namespace std;

int main(int argc, char ** argv)
{
    string fileName = "";
    EdgeWeightedGraph* G;
    G = new EdgeWeightedGraph(fileName);

    LazyPrimMST* mst = new LazyPrimMST(G);
    Queue<Edge*> edges;
    mst->getEdges(edges);
    while(!edges.isEmpty())
    {
        Edge* e = mst->dequeue();
        cout << e->toString() << endl;
    }

    cout << mst->getWeight();
}
