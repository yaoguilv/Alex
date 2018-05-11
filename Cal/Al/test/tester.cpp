#include <iostream>
#include <string>
#include <vector>
#include <iterator>

#include "C1/Unit3_Stacks/Bag.h"
#include "C4/U4/DirectedEdge.h"
#include "C4/U4/EdgeWeightedDigraph.h"

using namespace std;

int main(int argc, char ** argv)
{
    string fileName = "/usr/lib/.workspace/Alex/Cal/Al/data/tinyEWD.txt";
    EdgeWeightedDigraph* myEWD = new EdgeWeightedDigraph(fileName);

    cout << myEWD->getV() << endl;
    cout << myEWD->getE() << endl;

    cout << "now vertex 5's follwing edges:" << endl;
    Bag<DirectedEdge*> myBag;
    myEWD->getAdj(5, myBag);

    Bag<DirectedEdge*>::Node* myNode = myBag.first;
    while(nullptr != myNode)
    {
        cout << myNode->item->toString() << endl;
        myNode = myNode->next;
    }

    cout << "now all Edges:" << endl;
    vector<DirectedEdge*> edges;
    myEWD->getEdges(edges);
    for(vector<DirectedEdge*>::iterator it = edges.begin(); it != edges.end(); it++)
    {
        cout << (*it)->toString() << endl;
    }

}
