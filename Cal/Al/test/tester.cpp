#include <iostream>
#include <string>
#include <vector>
#include "C4/U3/Edge.h"
#include "C4/U3/EdgeWeightedGraph.h"

using namespace std;

int main(int argc, char ** argv)
{

    string fileName = "/usr/lib/.workspace/Alex/Cal/Al/data/tinyEWG.txt";
    EdgeWeightedGraph* myGraph = new EdgeWeightedGraph(fileName);
    vector<Edge*> myVEdge;
    vector<Edge*> myEdge;
    myGraph->getAdj(2, myVEdge);
    for(vector<Edge*>::iterator it = myVEdge.begin(); it != myVEdge.end(); it++)
    {
        cout << (*it)->toString() << endl;
    }
    cout << endl;
    myGraph->getEdges(myEdge);
    for(vector<Edge*>::iterator it = myEdge.begin(); it != myEdge.end(); it++)
    {
        cout << (*it)->toString() << endl;
    }
}
#include "C4/U3/LazyPrimMST.h"
