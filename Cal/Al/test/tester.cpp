#include <iostream>
#include "C2/U1/MyDate.h"
#include "C2/U4/IndexMinPQ.h"

using namespace std;

int main(int argc, char ** argv)
{
    string fileName = "/usr/lib/.workspace/Alex/Cal/Al/data/tinyEWG.txt";
    EdgeWeightedGraph* G;
    G = new EdgeWeightedGraph(fileName);

    LazyPrimMST* mst = new LazyPrimMST(G);
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

