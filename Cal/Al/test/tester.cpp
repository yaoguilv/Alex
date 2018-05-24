#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <stack>
#include <cmath>

#include "C1/Unit3_Stacks/Bag.h"
#include "C4/U4/DirectedEdge.h"
#include "C4/U4/EdgeWeightedDigraph.h"
#include "util/CDouble.h"
#include "util/CString.h"
#include "C4/U4/BellmanFordSP.h"
#include "C4/U4/EdgeWeightedDirectedCycle.h"

using namespace std;

int main(int argc, char ** argv)
{
    string fileName = "/usr/lib/.workspace/Alex/Cal/Al/data/rates.txt";

    ifstream inputFile;
    inputFile.open(fileName, fstream::in | fstream::out);
    vector<string> strArr;

    if(!inputFile.is_open())
    {
        cout << "open file failed!" << endl;
        return 0;
    }

    char buf[256];
    inputFile.getline(buf, 100);
    string strV = buf;
    int V = stoi(strV);
    EdgeWeightedDigraph* G = new EdgeWeightedDigraph(V);
    vector<string> name;

    string sp = " ";
    for(int v = 0; v < V; v++)
    {
        inputFile.getline(buf, 100);
        string strToSplit = buf;
        strArr.clear();
        CString::split(strToSplit, sp, strArr);
        name.push_back(strArr[0]);
        for(int w = 0; w < V; w++)
        {
            double rate = stod(strArr[w + 1]);
            DirectedEdge* e = new DirectedEdge(v, w, log(rate));
            G->addEdge(e);
        }
    }

    BellmanFordSP* spt = new BellmanFordSP(G, 0);
    if(spt->hasNegativeCycle())
    {
        double stake = 1000.0;
        vector<DirectedEdge*> cycleEdges;
        spt->negativeCycle(cycleEdges);
        for(vector<DirectedEdge*>::iterator it = cycleEdges.begin(); it != cycleEdges.end(); it++)
        {
            DirectedEdge* e = *it;
            cout << e->toString() << endl;
            cout << stake << "  " << name[e->from()];
            stake *= exp(-e->getWeight());
            cout << "=" << stake << "  " << name[e->to()] << endl;
        }
    }
    else
        cout << "No arbitrage opportunity" << endl;
    inputFile.close();

    return 0;
}

